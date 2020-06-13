#ifndef _COLOR_H_
#define _COLOR_H_

#ifdef __APPLE__
#include<GLUT/glut.h>
#else
#include<GL/glut.h>
#endif

class Color
{
	public:
		int r = -1, g = -1, b = -1;

		Color(){}
		Color(int r, int g, int b);
		~Color(){}

		void color(); // the verb ( ͡° ͜ʖ ͡°)
};

#endif