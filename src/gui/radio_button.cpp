#include "radio_button.h"

RadioButton::RadioButton(Point radio_button_center) : 
	hover(153, 217, 234),
	activated(181, 230, 29)
{
	this->top.x = radio_button_center.x - width;
	this->top.y = radio_button_center.y + hight;
	this->bottom.x = radio_button_center.x + width;
	this->bottom.y = radio_button_center.y - hight;
	this->index = 0;
}

void RadioButton::set_main_color(Color main)
{
	this->main = main;
}

void RadioButton::set_hover_color(Color hover)
{
	this->hover = hover;
}

void RadioButton::set_activated_color(Color activated)
{
	this->activated = activated;
}

void RadioButton::set_behavior(function<void()> on_click)
{
	this->on_click = on_click;
}

bool RadioButton::link_with(int *radio_color)
{
	choice_link = radio_color;
	index = *choice_link + 1;
	*choice_link = index;
	return true;
}

void RadioButton::draw()
{
	if (*choice_link == index)
		activated.color();
	else if (in_range)
		hover.color();
	else
		glColor3ub(0, 0, 0);
	glRecti(top.x, top.y, bottom.x, bottom.y);
	main.color();
	glRecti(top.x + 2, top.y - 2, bottom.x - 2, bottom.y + 2);
}

void RadioButton::run()
{
	if (on_click)
		this->on_click();
}

bool RadioButton::check(Point mouse_point, bool clicked)
{
	if (mouse_point.x >= top.x && mouse_point.x <= bottom.x &&
		 mouse_point.y <= top.y && mouse_point.y >= bottom.y)
	{
		in_range = true;
		if (clicked)
		{
			*choice_link = index;
			if (on_click)
				on_click();
		}
	}
	else
		in_range = false;
	return in_range;
}