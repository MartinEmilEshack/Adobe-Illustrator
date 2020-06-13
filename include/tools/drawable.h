#ifndef _DRAWABLE_H_
#define _DRAWABLE_H_

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include "point.h"
#include "color.h"

class Drawable
{
	protected:
		bool saved;
		bool filled;
		Point start_point;
		Color shape_color;
	
	public:
		bool started;

		Drawable() {}
		virtual ~Drawable() {};
	
		virtual void draw() = 0;
		virtual bool save() = 0;
		virtual void set_start(Point start, Color color, bool fill) = 0;
		virtual void change(Point end, Color color,bool fill) = 0;
		virtual Drawable* make_new() = 0;
};

#endif