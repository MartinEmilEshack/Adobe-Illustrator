#include "canvas.h"

Canvas::Canvas(Point top, Point bottom)
{
	this->top = top;
	this->bottom = bottom;
}

void Canvas::draw()
{
	glColor3ub(0, 0, 0);
	glRecti(top.x, top.y, bottom.x, bottom.y);
	glColor3ub(255, 255, 255);
	glRecti(top.x + 1, top.y - 1, bottom.x - 1, bottom.y + 1);
}

bool Canvas::check(Point mouse_point, bool clicked)
{
	in_range = mouse_point.x >= top.x && mouse_point.x <= bottom.x &&
				  mouse_point.y <= top.y && mouse_point.y >= bottom.y;
	// if (clicked && in_range) (*(this->on_click))();
	return in_range;
}

// void Canvas::set_behavior(void (*on_click)())
// {
// 	this->on_click = on_click;
// 	(*(this->on_click))();
// }

void Canvas::set_behavior(function<void()> on_click)
{
	this->on_click = on_click;
	// this->on_click();
}

void Canvas::run()
{
	if (on_click)
		this->on_click();
	on_click = []() { return; };
	// (*(this->on_click))();
}