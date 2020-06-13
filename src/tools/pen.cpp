#include "pen.h"

Pen::Pen::Pen()
{
	saved = false;
	started = false;
}

void Pen::Pen::draw()
{
	shape_color.color();
	glPointSize(1.0);
	if (true) // continuous line drawing
	{
		if (points.size() == 2)  // draws one point
		{
			glBegin(GL_POINTS);
			{
				glVertex2f(points.begin()->x, points.begin()->y);
			}
			glEnd();
		}
		else
		{
			glBegin(GL_LINE_STRIP);
			{
				for (auto i = points.begin(); i != points.end(); i++)
					glVertex2f((*i).x, (*i).y);
			}
			glEnd();
		}
	}
	else // old bad line drawing each point at a time
	{
		glBegin(GL_POINTS);
		{
			for (auto i = points.begin(); i != points.end(); i++)
				glVertex2f((*i).x, (*i).y);
		}
		glEnd();
	}
}

void Pen::Pen::save()
{
	saved = true;
}

void Pen::Pen::set_start(Point start, Color color, bool fill)
{
	started = true;
	points.push_back(start);
	shape_color = color;
}

void Pen::Pen::change(Point end, Color color, bool fill)
{
	if (!saved & started)
	{
		points.push_back(end);
		shape_color = color;
	}
}

Drawable *Pen::Pen::make_new()
{
	return new Pen();
}
