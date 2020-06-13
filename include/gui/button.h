#ifndef _BUTTON_H_
#define _BUTTON_H_

#ifdef __APPLE__
#include<GLUT/glut.h>
#else
#include<GL/glut.h>
#endif

#include<string>

#include"point.h"
#include"clickable.h"
#include"color.h"
#include"text.h"

class Button: public Clickable
{
	private:
		// state
		bool in_range = false;
		bool is_clicked = false;
		
		// properties
		Point top;
		Point bottom;
		Point text;
		Color main;
		Color hover;
		Color clicked = Color();
		string label;	

		// constants
		int button_width = 25;
		int button_hight = 10;

	public:
		Button(string label, Point button_center);
		Button(const Button& b);
		~Button(){}

		void set_main_color(Color main);
		void set_hover_color(Color hover);
		void set_clicking_color(Color clicked);
		// void set_behavior(void (*on_click)());
		void set_text_coordinates(int x, int y);
		void set_behavior(function<void()> on_click);

		void run();
		void draw();
		bool check(Point mouse_point, bool clicked);
};

#endif
