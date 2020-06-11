#include"color.h"

Color::Color(int r, int g, int b)
{
	this->r = r;
	this->g = g;
	this->b = b;
}

Color::Color(const Color& c)
{
	this->r = c.r;
	this->g = c.g;
	this->b = c.b;
}

void Color::color()
{
	glColor3ub(r,g,b);
}