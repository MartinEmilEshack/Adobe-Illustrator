#ifndef _POLYGONS_H_
#define _POLYGONS_H_

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <stdarg.h>
#include <math.h>
// #include<iostream>

// using namespace std;

#include "point.h"
#include "color.h"
#include "drawable.h"

class Rectangle : public Drawable
{
	private:
		Point end_point;

	public:
		Rectangle();

		void draw();
		void save();
		void set_start(Point start, Color color, bool fill);
		void change(Point end, Color color, bool fill);
		Drawable *make_new();
};

#define draw_polygon(...) draw_polygon_(false, __VA_ARGS__, Point::getFinal())
#define draw_polygon_solid(...) draw_polygon_(true, __VA_ARGS__, Point::getFinal())

void draw_polygon_(bool isSolid, Point n, ...);

#define draw_equilateral(x, y, size, sideNum) draw_equilateral_(x, y, size, sideNum, 0, false)
#define draw_equilateral_solid(x, y, size, sideNum) draw_equilateral_(x, y, size, sideNum, 0, true)

#define draw_equilateral_rotate(x, y, size, sideNum, degree) draw_equilateral_(x, y, size, sideNum, degree, false)
#define draw_equilateral_solid_rotate(x, y, size, sideNum, degree) draw_equilateral_(x, y, size, sideNum, degree, true)

void draw_equilateral_(float x, float y, float size, int sideNum, int degree, bool isSolid);

Point xy(double x, double y);

#endif