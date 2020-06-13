#include "polygons.h"

Rectangle::Rectangle()
{
	saved = false;
	started = false;
}

void Rectangle::draw()
{
	shape_color.color();
	if (filled)
		glRecti(start_point.x, start_point.y, end_point.x, end_point.y);
	else
	{
		glBegin(GL_LINE_LOOP);
		{
			glVertex2i(start_point.x, start_point.y);
			glVertex2i(end_point.x, start_point.y);
			glVertex2i(end_point.x, end_point.y);
			glVertex2i(start_point.x, end_point.y);
		}
		glEnd();
	}
}

void Rectangle::save()
{
	saved = true;
}

void Rectangle::set_start(Point start, Color color, bool fill)
{
	filled = fill;
	started = true;
	shape_color = color;
	start_point = start;
}

void Rectangle::change(Point end, Color color, bool fill)
{
	if (!saved & started)
	{
		filled = fill;
		shape_color = color;
		end_point = end;
	}
}

Drawable *Rectangle::make_new()
{
	return new Rectangle();
}

void draw_polygon_(bool isSolid, Point vertex, ...)
{
	glBegin(isSolid ? GL_POLYGON : GL_LINE_LOOP);
	{
		va_list ap;
		va_start(ap, vertex);
		{
			while (!vertex.invalid)
			{
				glVertex2f(vertex.x, vertex.y);
				vertex = *va_arg(ap, Point *);
			}
		}
		va_end(ap);
	}
	glEnd();
}

void draw_equilateral_(float x, float y, float size, int sideNum, int degree, bool isSolid)
{
	float degreeR = degree * 3.1415926f / 180.0f;
	glBegin(isSolid ? GL_POLYGON : GL_LINE_LOOP);
	{
		for (int i = 0; i < sideNum; i++)
		{
			float theta = degreeR + 2.0f * 3.1415926f * i / sideNum;
			float xl = size * (cosf(theta));
			float yl = size * (sinf(theta));
			glVertex2f(x + xl, y + yl);
		}
	}
	glEnd();
}

Point xy(double x, double y)
{
	Point v(x, y);
	return v;
}