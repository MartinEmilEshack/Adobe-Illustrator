#ifndef _LINE_H_
#define _LINE_H_

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include "point.h"
#include "drawable.h"

class Line : public Drawable
{
	private:
		Point end_point;

	public:
		Line();
		~Line() {}

		void draw();
		void save();
		void set_start(Point start, Color color, bool fill);
		void change(Point end, Color color, bool fill);
		Drawable* make_new();
};

#endif