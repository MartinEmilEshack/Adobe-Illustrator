#include "radio_button.h"

RadioButton::RadioButton(Point radio_button_center)
{
	this->top.x = radio_button_center.x - width;
	this->top.y = radio_button_center.y + hight;
	this->bottom.x = radio_button_center.x + width;
	this->bottom.y = radio_button_center.y - hight;
	this->choice = 0;
	this->index = 0;
	this->choice_link = &choice;
}

RadioButton::RadioButton(const RadioButton &rb)
{
	this->main = rb.main;
	this->activated = rb.activated;
	this->hover = rb.hover;

	this->top = rb.top;
	this->bottom = rb.bottom;

	this->in_range = rb.in_range;
	this->choice = rb.choice;
	if ((rb.choice_link) == &(rb.choice))
		this->choice_link = &choice;
	else
		this->choice_link = rb.choice_link;
	this->index = rb.index;

	this->on_click = rb.on_click;
}

RadioButton::RadioButton(RadioButton &&rb)
{
	main = rb.main;
	activated = rb.activated;
	hover = rb.hover;

	top = rb.top;
	bottom = rb.bottom;

	in_range = rb.in_range;
	choice = rb.choice;
	if ((rb.choice_link) == &(rb.choice))
		choice_link = &choice;
	else
		choice_link = rb.choice_link;
	index = rb.index;

	on_click = rb.on_click;

	rb.in_range = false;
	rb.choice = 0;
	rb.choice_link = 0;
	rb.choice_link = nullptr;
	rb.index = 0;
	rb.on_click = nullptr;
}

RadioButton::~RadioButton()
{
	// *(choice_link) = -1;
	// delete choice_link;
}

RadioButton &RadioButton::operator=(const RadioButton &rb)
{
	if (this != &rb)
	{
		delete choice_link;
		main = rb.main;
		activated = rb.activated;
		hover = rb.hover;

		top = rb.top;
		bottom = rb.bottom;

		in_range = rb.in_range;
		choice = rb.choice;
		if ((rb.choice_link) == &(rb.choice))
			choice_link = &choice;
		else
			choice_link = rb.choice_link;
		index = rb.index;

		on_click = rb.on_click;
	}
	return *this;
}

RadioButton &RadioButton::operator=(RadioButton &&rb)
{
	if (this != &rb)
	{
		delete choice_link;
		main = rb.main;
		activated = rb.activated;
		hover = rb.hover;

		top = rb.top;
		bottom = rb.bottom;

		in_range = rb.in_range;
		choice = rb.choice;
		if ((rb.choice_link) == &(rb.choice))
			choice_link = &choice;
		else
			choice_link = rb.choice_link;
		index = rb.index;

		on_click = rb.on_click;

		rb.in_range = false;
		rb.choice = 0;
		rb.choice_link = 0;
		rb.choice_link = nullptr;
		rb.index = 0;
		rb.on_click = nullptr;
	}
	return *this;
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

void RadioButton::set_behavior(void (*on_click)())
{
	this->on_click = on_click;
}

bool RadioButton::link_with(RadioButton *radio_button)
{
	// cout << choice_link << '|' << (*radio_button).choice_link << '\n';
	choice_link = (*radio_button).choice_link;
	// cout << choice_link << '|' << (*radio_button).choice_link << '\n';
	// cout << *choice_link << '|' << *(*radio_button).choice_link << '\n';
	index = (*radio_button).index + 1;
	return true;
}

void RadioButton::draw()
{
	// choice = *choice_link;
	// cout << choice_link << " dd\n";
	choice = *choice_link;
	if (choice == index)
		activated.color();
	else if (in_range)
		hover.color();
	else
		glColor3ub(0, 0, 0);
	glRecti(top.x, top.y, bottom.x, bottom.y);

	main.color();
	glRecti(top.x + 2, top.y - 2, bottom.x - 2, bottom.y + 2);
}

bool RadioButton::check(Point mouse_point, bool clicked)
{
	if (mouse_point.x >= top.x && mouse_point.x <= bottom.x &&
		 mouse_point.y <= top.y && mouse_point.y >= bottom.y)
	{
		in_range = true;
		if (clicked)
		{
			// if(choice_link == NULL) *choice_link = choice;
			*choice_link = index;
			choice = index;
			(*(this->on_click))();
		}
	}
	else
		in_range = false;
	return in_range;
}
