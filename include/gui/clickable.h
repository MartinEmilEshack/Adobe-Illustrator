#ifndef _CLICKABLE_H_
#define _CLICKABLE_H_

#ifdef __APPLE__
#include<GLUT/glut.h>
#else
#include<GL/glut.h>
#endif

#include<functional>

#include"point.h"

using namespace std;

class Clickable
{
	public:
		function<void()> on_click;

		Clickable() {}
		~Clickable() {}

		virtual void draw() = 0;
		virtual bool check(Point mouse_point,bool clicked) = 0;
		virtual void set_behavior(function<void()> on_click) = 0;
		virtual void run() = 0;
};

#endif