#include "circles.h"

Circle::Circle()
{
	radius = -1;
	saved = false;
	started = false;
}

Circle::Circle(float x, float y, float radius)
{
	this->start_point = Point(x, y);
	this->radius = radius;
}

Circle::Circle(Point center, float radius)
{
	this->start_point = center;
	this->radius = radius;
}

Circle::Circle(const Circle &v)
{
	this->start_point = v.start_point;
	this->radius = v.radius;
	this->shape_color = v.shape_color;
}

void Circle::set_color(int r, int g, int b)
{
	set_color(Color(r, g, b));
}

void Circle::set_color(Color color)
{
	shape_color = color;
}

void Circle::draw()
{
	shape_color.color();
	glBegin(filled ? GL_POLYGON : GL_LINE_LOOP);
	{
		for (int i = 0; i < 100; i++)
		{
			float theta = 2.0f * 3.1415926f * i / 100;
			float x = radius * cosf(theta);
			float y = radius * sinf(theta);
			glVertex2f(x + start_point.x, y + start_point.y);
		}
	}
	glEnd();
}

void Circle::save()
{
	saved = true;
}

void Circle::set_start(Point start, Color color, bool fill)
{
	started = true;
	shape_color = color;
	start_point = start;
}

void Circle::change(Point end, Color color, bool fill)
{
	if (!saved & started)
	{
		shape_color = color;
		filled = fill;
		int x_diff = end.x - start_point.x;
		int y_diff = end.y - start_point.y;
		// hard codded canvas dimensions sorry!
		int tmp_radius = sqrt(x_diff * x_diff + y_diff * y_diff);
		if (start_point.y + tmp_radius + 75 < 500 && start_point.y - tmp_radius - 10 > 0 &&
			 start_point.x - tmp_radius - 10 > 0 && start_point.x + tmp_radius + 10 < 500)
			radius = tmp_radius;
	}
}

Drawable *Circle::make_new()
{
	return new Circle();
}

void draw_circle_(float cx, float cy, float radius, bool isSolid)
{
	glBegin(isSolid ? GL_POLYGON : GL_LINE_LOOP);
	{
		for (int i = 0; i < 100; i++)
		{
			float theta = 2.0f * 3.1415926f * i / 100;
			float x = radius * cosf(theta);
			float y = radius * sinf(theta);
			glVertex2f(x + cx, y + cy);
		}
	}
	glEnd();
}