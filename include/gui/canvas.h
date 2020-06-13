#ifndef _CANVAS_H_
#define _CANVAS_H_

#ifdef __APPLE__
#include<GLUT/glut.h>
#else
#include<GL/glut.h>
#endif

#include"point.h"
#include "clickable.h"

class Canvas : Clickable
{
	private:
		bool in_range;

		Point top;
		Point bottom;

	public:
		Canvas(Point top, Point bottom);
		~Canvas() {}

		void draw();
		bool check(Point mouse_point,bool clicked);
		void set_behavior(function<void()> on_click);
		void run();
};

#endif