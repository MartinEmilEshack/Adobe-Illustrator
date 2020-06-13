#include "line.h"

Line::Line()
{
	saved = false;
	started = false;
}

void Line::draw()
{
	shape_color.color();
	glBegin(GL_LINES); 
	{
		glVertex2i(start_point.x, start_point.y);
		glVertex2i(end_point.x, end_point.y);
	}
	glEnd();
}

void Line::save()
{
	saved = true;
}

void Line::set_start(Point start, Color color, bool fill)
{
	started = true;
	shape_color = color;
	start_point = start;
}

void Line::change(Point end, Color color, bool fill)
{
	if (!saved && started)
	{
		shape_color = color;
		end_point = end;
	}
}

Drawable* Line::make_new()
{
	return new Line();
}
