#ifndef _RADIO_BUTTON_H_
#define _RADIO_BUTTON_H_

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include "color.h"
#include "point.h"
#include "clickable.h"

using namespace std;

class RadioButton : public Clickable
{
	private:
		Color hover;
		Color activated;

		Point top;
		Point bottom;
		int width = 10; // 20/2
		int hight = 10;

		bool in_range = false;
		int *choice_link;
		int index;

	public:
		Color main;
		
		RadioButton(Point radio_button_center);
		~RadioButton(){}

		void set_main_color(Color main);
		void set_hover_color(Color hover);
		void set_activated_color(Color clicked);
		void set_behavior(function<void()> on_click);
		bool link_with(int* radio_color);

		void draw();
		void run();
		bool check(Point mouse_point, bool clicked);
};

#endif