#ifndef _PEN_H_
#define _PEN_H_

#ifdef __APPLE__
#include<GLUT/glut.h>
#else
#include<GL/glut.h>
#endif

#include <vector>

#include"point.h"
#include "drawable.h"

using namespace std;

class Pen : public Drawable
{
	private:
		vector<Point> points;
		
	public:
		Pen();
		~Pen() {}
		
		void draw();
		void save();
		void set_start(Point start, Color color, bool fill);
		void change(Point end, Color color, bool fill);
		Drawable* make_new();
};

#endif