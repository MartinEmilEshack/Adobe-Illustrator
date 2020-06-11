#include "button.h"

Button::Button(string label, Point button_center)
{
	this->label = label;
	this->top.x = button_center.x-button_width;
	this->top.y = button_center.y+button_hight;
	this->bottom.x = button_center.x+button_width;
	this->bottom.y = button_center.y-button_hight;
	this->text.x = top.x;
	this->text.y = bottom.y;
}

Button::Button(const Button &b)
{
	this->in_range = b.in_range;
	this->is_clicked = b.is_clicked;

	this->top = b.top;
	this->bottom = b.bottom;

	this->main = b.main;
	this->hover = b.hover;
	this->clicked = b.clicked;

	this->label = b.label;
	this->on_click = b.on_click;
}

void Button::set_main_color(Color main)
{
	this->main = main;
}

void Button::set_hover_color(Color hover)
{
	this->hover = hover;
}

void Button::set_clicking_color(Color clicked)
{
	this->clicked = clicked;
}

void Button::set_behavior(void (*on_click)())
{
	this->on_click = on_click;
}

void Button::set_text_coordinates(int x, int y)
{
	this->text.x += x;
	this->text.y += y;
}

void Button::draw()
{
	glColor3ub(0, 0, 0);
	glRecti(top.x, top.y, bottom.x, bottom.y);

	if (is_clicked && clicked.r > -1)
		clicked.color();
	else if (is_clicked)
		main.color();
	else if (in_range)
		hover.color();
	else
		main.color();
	glRecti(top.x + 1, top.y - 1, bottom.x - 1, bottom.y + 1);

	glColor3ub(0, 0, 0);
	print_xy(text.x, text.y, label.c_str(), GLUT_BITMAP_HELVETICA_10);
}

bool Button::check(Point mouse_point, bool clicked)
{
	if (mouse_point.x >= top.x && mouse_point.x <= bottom.x &&
		 mouse_point.y <= top.y && mouse_point.y >= bottom.y)
	{
		in_range = true;
		is_clicked = clicked;
		if (clicked) (*(this->on_click))();
	}
	else
		in_range = false;
	return in_range;
}