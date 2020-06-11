#ifndef _CLICKABLE_H_
#define _CLICKABLE_H_

#ifdef __APPLE__
#include<GLUT/glut.h>
#else
#include<GL/glut.h>
#endif

#include"point.h"

class Clickable
{
	public:
		void (*on_click)();

		Clickable(){}
		virtual ~Clickable() = 0;

		virtual void draw() = 0;
		virtual bool check(Point mouse_point,bool clicked) = 0;
		virtual void set_behavior(void (*on_click)()) = 0;
};

#endif