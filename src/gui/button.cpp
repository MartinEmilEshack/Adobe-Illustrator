#include "button.h"

Button::Button(string label, Point button_center) : 
	main(255, 255, 255),
	hover(238, 236, 225),
	clicked(196, 189, 151)
{
	this->label = label;
	this->top.x = button_center.x - button_width;
	this->top.y = button_center.y + button_hight;
	this->bottom.x = button_center.x + button_width;
	this->bottom.y = button_center.y - button_hight;
	this->text.x = top.x;
	this->text.y = bottom.y;
	this->index = 0;
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

void Button::set_text_coordinates(int x, int y)
{
	this->text.x += x;
	this->text.y += y;
}

void Button::set_behavior(function<void()> on_click)
{
	this->on_click = on_click;
}

bool Button::stick_with(int *sticky)
{
	choice_link = sticky;
	index = *choice_link + 1;
	*choice_link = index;
	return true;
}

void Button::run()
{
	if (on_click)
		this->on_click();
}

void Button::draw()
{
	glColor3ub(0, 0, 0);
	glRecti(top.x, top.y, bottom.x, bottom.y);
	
	if (is_clicked)
		clicked.color();
	else if (choice_link && *choice_link == index)
		clicked.color();
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
		if (choice_link && clicked) *choice_link = index;
		if (on_click && clicked) on_click();
	}
	else
		in_range = false;
	return in_range;
}