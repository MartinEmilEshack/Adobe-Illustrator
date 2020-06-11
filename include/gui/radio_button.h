#ifndef _RADIO_BUTTON_H_
#define _RADIO_BUTTON_H_

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <iostream>

#include "color.h"
#include "point.h"
#include "clickable.h"

using namespace std;

class RadioButton : public Clickable
{
	private:
		Color main;
		Color activated;
		Color hover;

		Point top;
		Point bottom;
		int width = 10; // 10/2
		int hight = 10;

		bool in_range = false;
		int choice = -1;
		int *choice_link;
		int index;

	public:
		RadioButton(Point radio_button_center);
		RadioButton(const RadioButton &rb);
		RadioButton(RadioButton &&rb) noexcept(false); // = default
		~RadioButton();

		RadioButton &operator=(const RadioButton &rb);
		RadioButton &operator=(RadioButton &&rb) noexcept(false); // = default

		void set_main_color(Color main);
		void set_hover_color(Color hover);
		void set_activated_color(Color clicked);
		void set_behavior(void (*on_click)());
		bool link_with(RadioButton* radio_button);

		void draw();
		bool check(Point mouse_point, bool clicked);
};

#endif