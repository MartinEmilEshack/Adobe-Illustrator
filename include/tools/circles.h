#ifndef _CIRCLES_H_
#define _CIRCLES_H_

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <stdlib.h>
#include <stdarg.h>
#include <math.h>

#include "point.h"
#include "polygons.h"
#include "math.h"

class Circle : public Drawable
{
	public:
		float radius;
		
		Circle();
		Circle(float x, float y, float radius);
		Circle(Point center, float radius);
		Circle(const Circle &v);

		~Circle() {}

		void set_color(Color color);
		inline void set_color(int r, int g, int b);

		void draw();
		void save();
		void set_start(Point start, Color color, bool fill);
		void change(Point end, Color color, bool fill);
		Drawable *make_new();
};

#define draw_circle(cx, cy, radius) draw_circle_(cx, cy, radius, false)
#define draw_circle_solid(cx, cy, radius) draw_circle_(cx, cy, radius, true)

void draw_circle_(float cx, float cy, float radius, bool isSolid);

#endif