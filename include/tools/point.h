#ifndef _POINT_H_
#define _POINT_H_

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

class Point
{
	public:
		bool invalid = false;
		float x;
		float y;
	
		Point();
		Point(float x, float y);
		Point(const Point &v);
	
		~Point() {}
	
		static Point getFinal();
		static Point scale_point(
			 int x, int y,
			 int new_width, int new_height,
			 int current_width, int current_hight);
};

void draw_point(float x, float y);
void draw_point(float x, float y, float size);

#endif