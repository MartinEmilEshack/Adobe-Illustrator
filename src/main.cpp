#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <vector>

#include "point.h"
#include "color.h"
#include "button.h"
#include "radio_button.h"
#include "canvas.h"
#include "line.h"
#include "polygons.h"
#include "circles.h"
#include "pen.h"
#include "text.h"

int phy_width = 500;
int phy_hight = 500;
int logWidth = 500;
int logHeight = 500;

int selected_radio_color = 0;
int selected_drawing_button = 0;

Drawable *shape;
bool shape_fill;
Color selected_color = Color(0, 0, 0);
vector<Drawable *> shapes;

Button line = Button("Line", Point(35, logHeight - 20));
Button rect = Button("Rect", Point(95, logHeight - 20));
Button circle = Button("Circle", Point(155, logHeight - 20));
Button fill_btn = Button("Fill", Point(215, logHeight - 20));
Button pen = Button("Pen", Point(35, logHeight - 50));
Button text = Button("Text", Point(95, logHeight - 50));
Button undo = Button("Undo", Point(155, logHeight - 50));
Button no_fill = Button("No Fill", Point(215, logHeight - 50));

RadioButton red = RadioButton(Point(265, logHeight - 35));
RadioButton green = RadioButton(Point(295, logHeight - 35));
RadioButton blue = RadioButton(Point(325, logHeight - 35));
RadioButton yellow = RadioButton(Point(355, logHeight - 35));
RadioButton orange = RadioButton(Point(385, logHeight - 35));
RadioButton purple = RadioButton(Point(415, logHeight - 35));
RadioButton white = RadioButton(Point(445, logHeight - 35));
RadioButton black = RadioButton(Point(475, logHeight - 35));

Canvas canvas = Canvas(Point(10, logHeight - 75), Point(logWidth - 10, 10));

// android functions :3
void on_create();
void on_resume();
// mouse functions
void KeyboardInput(unsigned char key, int mouse_x, int mouse_y);
void mouse_point(int x, int y);
void mouse_clicked_point(int x, int y);
void mouse_state(int btn_name, int btn_state, int x, int y);
void mouse_check(Point logical_xy, bool clicked);

// useles functions
Color rgb(int r, int g, int b)
{
	return Color(r, g, b);
}

int main(int argc, char *argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
	glutInitWindowSize(phy_width, phy_hight);
	glutInitWindowPosition(750, 100);
	glutCreateWindow("Adobe Illustrator");
	glClearColor(1.0, 1.0, 1.0, 0);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0, logWidth, 0, logHeight);

	glutMotionFunc(mouse_clicked_point);
	glutPassiveMotionFunc(mouse_point);
	glutMouseFunc(mouse_state);
	glutKeyboardFunc(KeyboardInput);
	glutDisplayFunc(on_resume);

	on_create();
	glutMainLoop();
	return 0;
}

void KeyboardInput(unsigned char key, int mouse_x, int mouse_y)
{
	Point logical_xy = Point::scale_point(
		 mouse_x, mouse_y, logWidth, logHeight, phy_width, phy_hight);
	Label *label = dynamic_cast<Label *>(shape);
	if (label && canvas.check(logical_xy, false))
	{
		if (label->write(key))
			shapes.push_back(shape);
		shape = label->make_new();
		glutPostRedisplay();
	}
}

void mouse_point(int x, int y)
{
	Point logical_xy = Point::scale_point(
		 x, y, logWidth, logHeight, phy_width, phy_hight);
	mouse_check(logical_xy, false);
	glutPostRedisplay();
}

void mouse_clicked_point(int x, int y)
{
	Point logical_xy = Point::scale_point(
		 x, y, logWidth, logHeight, phy_width, phy_hight);
	if (canvas.check(logical_xy, true))
		shape->change(logical_xy, selected_color, shape_fill);
	glutPostRedisplay();
}

void mouse_state(int btn_name, int btn_state, int x, int y)
{
	Point logical_xy = Point::scale_point(
		 x, y, logWidth, logHeight, phy_width, phy_hight);
	if (btn_name + btn_state == 0) // left click down
	{
		mouse_check(logical_xy, true);
		if (canvas.check(logical_xy, true))
		{
			shape->set_start(logical_xy, selected_color, shape_fill);
			shape->change(logical_xy, selected_color, shape_fill);
		}
	}
	else if (btn_name + btn_state == 1) // left click up
	{
		mouse_check(logical_xy, false);
		if (canvas.check(logical_xy, false))
		{
			if (shape->save())
			{
				shapes.push_back(shape);
				shape = shape->make_new();
			}
		}
	}
	else if (btn_name + btn_state == 2) // right click down
		return;
	else // right click up
		return;
	glutPostRedisplay();
}

void mouse_check(Point logical_xy, bool clicked)
{
	line.check(logical_xy, clicked);
	rect.check(logical_xy, clicked);
	circle.check(logical_xy, clicked);
	pen.check(logical_xy, clicked);
	text.check(logical_xy, clicked);
	undo.check(logical_xy, clicked);
	fill_btn.check(logical_xy, clicked);
	no_fill.check(logical_xy, clicked);

	red.check(logical_xy, clicked);
	green.check(logical_xy, clicked);
	blue.check(logical_xy, clicked);
	yellow.check(logical_xy, clicked);
	orange.check(logical_xy, clicked);
	purple.check(logical_xy, clicked);
	white.check(logical_xy, clicked);
	black.check(logical_xy, clicked);
}

void on_create()
{
	text.set_text_coordinates(15, 6);
	text.stick_with(&selected_drawing_button);
	text.set_behavior([]() {
		delete shape;
		shape = new Label();
	});

	pen.set_text_coordinates(15, 6);
	pen.stick_with(&selected_drawing_button);
	pen.set_behavior([]() {
		delete shape;
		shape = new Pen();
	});

	circle.set_text_coordinates(12, 6);
	circle.stick_with(&selected_drawing_button);
	circle.set_behavior([]() {
		delete shape;
		shape = new Circle();
	});

	rect.set_text_coordinates(15, 6);
	rect.stick_with(&selected_drawing_button);
	rect.set_behavior([]() {
		delete shape;
		shape = new Rectangle();
	});

	line.set_text_coordinates(15, 6);
	line.stick_with(&selected_drawing_button);
	line.set_behavior([]() {
		delete shape;
		shape = new Line();
	});
	line.run();

	fill_btn.set_text_coordinates(19, 6);
	fill_btn.set_behavior([]() {
		shape_fill = true;
		fill_btn.set_main_color(rgb(196, 189, 151));
		fill_btn.set_hover_color(rgb(196, 189, 151));
		no_fill.set_main_color(rgb(255, 255, 255));
	});

	undo.set_text_coordinates(12, 6);
	undo.set_behavior([]() {
		if (!shapes.empty())
		{
			Drawable *rubbish = shapes.back();
			shapes.pop_back();
			delete rubbish;
		}
	});

	no_fill.set_text_coordinates(10, 6);
	no_fill.set_behavior([]() {
		shape_fill = false;
		no_fill.set_main_color(rgb(196, 189, 151));
		no_fill.set_hover_color(rgb(196, 189, 151));
		fill_btn.set_main_color(rgb(255, 255, 255));
	});
	no_fill.run();

	//colors
	red.set_main_color(rgb(237, 28, 36));
	red.link_with(&selected_radio_color);
	red.set_behavior([]() {
		selected_color = red.main;
	});

	green.set_main_color(rgb(146, 208, 80));
	green.link_with(&selected_radio_color);
	green.set_behavior([]() {
		selected_color = green.main;
	});

	blue.set_main_color(rgb(0, 176, 240));
	blue.link_with(&selected_radio_color);
	blue.set_behavior([]() {
		selected_color = blue.main;
	});

	yellow.set_main_color(rgb(255, 255, 0));
	yellow.link_with(&selected_radio_color);
	yellow.set_behavior([]() {
		selected_color = yellow.main;
	});

	orange.set_main_color(rgb(228, 108, 10));
	orange.link_with(&selected_radio_color);
	orange.set_behavior([]() {
		selected_color = orange.main;
	});

	purple.set_main_color(rgb(111, 47, 159));
	purple.link_with(&selected_radio_color);
	purple.set_behavior([]() {
		selected_color = purple.main;
	});

	white.set_main_color(rgb(255, 255, 255));
	white.link_with(&selected_radio_color);
	white.set_behavior([]() {
		selected_color = white.main;
	});

	black.set_main_color(rgb(0, 0, 0));
	black.link_with(&selected_radio_color);
	black.set_behavior([]() {
		selected_color = black.main;
	});
}

void on_resume()
{
	glClear(GL_COLOR_BUFFER_BIT);

	line.draw();
	rect.draw();
	circle.draw();
	pen.draw();
	text.draw();
	undo.draw();
	fill_btn.draw();
	no_fill.draw();

	red.draw();
	green.draw();
	blue.draw();
	yellow.draw();
	orange.draw();
	purple.draw();
	white.draw();
	black.draw();

	canvas.draw();

	for (auto i = shapes.begin(); i != shapes.end(); i++)
		(*i)->draw();
	shape->draw();

	glutSwapBuffers();
	glFlush();
}