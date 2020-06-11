#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <iostream>
#include <vector>

#include "point.h"
#include "color.h"
#include "button.h"
#include "radio_button.h"

using namespace std;

int phy_width = 500;
int phy_hight = 500;
int logWidth = 500;
int logHeight = 500;

Point center(logWidth / 2, logHeight / 2);
int selected_radio_color = 0;
Color selected_color = Color(0, 0, 0);
// selected_shape

Button line = Button("Line", Point(35, logHeight - 20));
Button rect = Button("Rect", Point(95, logHeight - 20));
Button circle = Button("Circle", Point(155, logHeight - 20));
Button pen = Button("Pen", Point(215, logHeight - 20));
Button text = Button("Text", Point(35, logHeight - 50));
Button undo = Button("Undo", Point(95, logHeight - 50));
Button fill_btn = Button("Fill", Point(155, logHeight - 50));
Button no_fill = Button("No Fill", Point(215, logHeight - 50));

RadioButton red = RadioButton(Point(265, logHeight - 35));
RadioButton green = RadioButton(Point(295, logHeight - 35));
RadioButton blue = RadioButton(Point(325, logHeight - 35));
RadioButton yellow = RadioButton(Point(355, logHeight - 35));
RadioButton orange = RadioButton(Point(385, logHeight - 35));
RadioButton purple = RadioButton(Point(415, logHeight - 35));
RadioButton white = RadioButton(Point(445, logHeight - 35));
RadioButton black = RadioButton(Point(475, logHeight - 35));

// vector<shape> shapes;

// android functions :3
void on_create();
void on_resume();
// mouse functions
void mouse_point(int x, int y);
void mouse_clicked_point(int x, int y);
void mouse_state(int btn_name, int btn_state, int x, int y);

// useles functions
Color rgb(int r, int g, int b)
{
	return Color(r, g, b);
}

void bla()
{
	cout << "no no don't touch me there!\n";
}

void bla2()
{
	cout << "This is my no no square\n";
}

void color_bla()
{
	cout << "coloring\n";
}

void color_bla2()
{
	cout << "coloring 2\n";
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
	glutDisplayFunc(on_resume);

	on_create();
	glutMainLoop();
	return 0;
}

void mouse_point(int x, int y)
{
	Point logical_xy = Point::scale_point(x, y, logWidth, logHeight, phy_width, phy_hight);
	bool hovered =
		 rect.check(logical_xy, false) |
		 line.check(logical_xy, false) |
		 circle.check(logical_xy, false) |
		 pen.check(logical_xy, false) |
		 text.check(logical_xy, false) |
		 undo.check(logical_xy, false) |
		 fill_btn.check(logical_xy, false) |
		 no_fill.check(logical_xy, false) |

		 red.check(logical_xy, false) |
		 green.check(logical_xy, false) |
		 blue.check(logical_xy, false) |
		 yellow.check(logical_xy, false) |
		 orange.check(logical_xy, false) |
		 purple.check(logical_xy, false) |
		 white.check(logical_xy, false) |
		 black.check(logical_xy, false);
	glutPostRedisplay();
}

void mouse_clicked_point(int x, int y) {}

void mouse_state(int btn_name, int btn_state, int x, int y)
{
	Point logical_xy = Point::scale_point(x, y, logWidth, logHeight, phy_width, phy_hight);
	if (btn_name + btn_state == 0) // left click down
	{
		bool button_clicked =
			 line.check(logical_xy, true) |
			 rect.check(logical_xy, true) |
			 circle.check(logical_xy, true) |
			 pen.check(logical_xy, true) |
			 text.check(logical_xy, true) |
			 undo.check(logical_xy, true) |
			 fill_btn.check(logical_xy, true) |
			 no_fill.check(logical_xy, true) ;

			 red.check(logical_xy, true) |
			 green.check(logical_xy, true) |
			 blue.check(logical_xy, true) |
			 yellow.check(logical_xy, true) |
			 orange.check(logical_xy, true) |
			 purple.check(logical_xy, true) |
			 white.check(logical_xy, true) |
			 black.check(logical_xy, true);
	}
	else if (btn_name + btn_state == 1) // left click up
		bool button_released =
			 line.check(logical_xy, false) |
			 rect.check(logical_xy, false) |
			 circle.check(logical_xy, false) |
			 pen.check(logical_xy, false) |
			 text.check(logical_xy, false) |
			 undo.check(logical_xy, false) |
			 fill_btn.check(logical_xy, false) |
			 no_fill.check(logical_xy, false) |

			 red.check(logical_xy, false) |
			 green.check(logical_xy, false) |
			 blue.check(logical_xy, false) |
			 yellow.check(logical_xy, false) |
			 orange.check(logical_xy, false) |
			 purple.check(logical_xy, false) |
			 white.check(logical_xy, false) |
			 black.check(logical_xy, false);
	else if (btn_name + btn_state == 2) // right click down
		return;
	else // right click up
		return;
	glutPostRedisplay();
}

void on_create()
{
	rect.set_main_color(rgb(255, 255, 255));
	rect.set_hover_color(rgb(238, 236, 225));
	rect.set_clicking_color(rgb(196, 189, 151));
	rect.set_behavior(bla);
	rect.set_text_coordinates(15, 6);

	line.set_main_color(rgb(255, 255, 255));
	line.set_hover_color(rgb(238, 236, 225));
	line.set_clicking_color(rgb(196, 189, 151));
	line.set_behavior(bla2);
	line.set_text_coordinates(15, 6);

	circle.set_main_color(rgb(255, 255, 255));
	circle.set_hover_color(rgb(238, 236, 225));
	circle.set_clicking_color(rgb(196, 189, 151));
	circle.set_behavior(bla);
	circle.set_text_coordinates(15, 6);

	pen.set_main_color(rgb(255, 255, 255));
	pen.set_hover_color(rgb(238, 236, 225));
	pen.set_clicking_color(rgb(196, 189, 151));
	pen.set_behavior(bla2);
	pen.set_text_coordinates(15, 6);

	text.set_main_color(rgb(255, 255, 255));
	text.set_hover_color(rgb(238, 236, 225));
	text.set_clicking_color(rgb(196, 189, 151));
	text.set_behavior(bla);
	text.set_text_coordinates(15, 6);

	undo.set_main_color(rgb(255, 255, 255));
	undo.set_hover_color(rgb(238, 236, 225));
	undo.set_clicking_color(rgb(196, 189, 151));
	undo.set_behavior(bla2);
	undo.set_text_coordinates(15, 6);

	fill_btn.set_main_color(rgb(255, 255, 255));
	fill_btn.set_hover_color(rgb(238, 236, 225));
	fill_btn.set_clicking_color(rgb(196, 189, 151));
	fill_btn.set_behavior(bla);
	fill_btn.set_text_coordinates(15, 6);

	no_fill.set_main_color(rgb(255, 255, 255));
	no_fill.set_hover_color(rgb(238, 236, 225));
	no_fill.set_clicking_color(rgb(196, 189, 151));
	no_fill.set_behavior(bla2);
	no_fill.set_text_coordinates(15, 6);

	//colors
	red.set_main_color(rgb(237, 28, 36));
	red.set_hover_color(rgb(153, 217, 234));
	red.set_activated_color(rgb(181, 230, 29));
	red.set_behavior(color_bla);
	red.link_with(&selected_radio_color);

	green.set_main_color(rgb(146, 208, 80));
	green.set_hover_color(rgb(153, 217, 234));
	green.set_activated_color(rgb(181, 230, 29));
	green.set_behavior(color_bla2);
	green.link_with(&selected_radio_color);

	blue.set_main_color(rgb(0, 176, 240));
	blue.set_hover_color(rgb(153, 217, 234));
	blue.set_activated_color(rgb(181, 230, 29));
	blue.set_behavior(color_bla);
	blue.link_with(&selected_radio_color);

	yellow.set_main_color(rgb(255, 255, 0));
	yellow.set_hover_color(rgb(153, 217, 234));
	yellow.set_activated_color(rgb(181, 230, 29));
	yellow.set_behavior(color_bla2);
	yellow.link_with(&selected_radio_color);

	orange.set_main_color(rgb(228, 108, 10));
	orange.set_hover_color(rgb(153, 217, 234));
	orange.set_activated_color(rgb(181, 230, 29));
	orange.set_behavior(color_bla2);
	orange.link_with(&selected_radio_color);

	purple.set_main_color(rgb(111, 47, 159));
	purple.set_hover_color(rgb(153, 217, 234));
	purple.set_activated_color(rgb(181, 230, 29));
	purple.set_behavior(color_bla2);
	purple.link_with(&selected_radio_color);

	white.set_main_color(rgb(255, 255, 255));
	white.set_hover_color(rgb(153, 217, 234));
	white.set_activated_color(rgb(181, 230, 29));
	white.set_behavior(color_bla2);
	white.link_with(&selected_radio_color);

	black.set_main_color(rgb(0, 0, 0));
	black.set_hover_color(rgb(153, 217, 234));
	black.set_activated_color(rgb(181, 230, 29));
	black.set_behavior(color_bla2);
	black.link_with(&selected_radio_color);
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

	glutSwapBuffers();
	glFlush();
}