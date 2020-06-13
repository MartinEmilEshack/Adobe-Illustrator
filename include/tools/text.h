#ifndef _TEXT_H_
#define _TEXT_H_

#ifdef __APPLE__
#include<GLUT/glut.h>
#else
#include<GL/glut.h>
#endif

#include<string>
#include<cstring>

#include"point.h"
#include "drawable.h"

using namespace std;

class Label : public Drawable
{
	private:
		int text_size;
		string text;
		Point end_point = Point();

	public:
		Label();
		~Label() {}

		void draw();
		bool save();
		void set_start(Point start, Color color, bool fill);
		void change(Point end, Color color, bool fill);
		Drawable* make_new();

		bool write(unsigned char letter);
};

void print_xy(float x,float y,const char* text,void* font);

Point print_file(Point boundaries,Point pixels_size,const string& text,void* font);

#endif