#include "text.h"

Label::Label()
{
	saved = false;
	started = false;
	text = "";
	text_size = 0;
}

void Label::draw()
{
	shape_color.color();
	if (!saved)
	{
		glBegin(GL_LINE_LOOP);
		{
			glVertex2i(start_point.x, start_point.y);
			glVertex2i(end_point.x, start_point.y);
			glVertex2i(end_point.x, end_point.y);
			glVertex2i(start_point.x, end_point.y);
		}
		glEnd();
		glRasterPos2d(start_point.x, start_point.y + 5);
		for (int i = 0; i < text_size; i++)
			glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, text[i]);
	}
	else
	{
		glRasterPos2d(start_point.x, start_point.y + 5);
		for (int i = 0; i < text_size; i++)
			glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, text[i]);
	}
}

bool Label::save()
{
	return false;
}

void Label::set_start(Point start, Color color, bool fill)
{
	// hard codded canvas dimensions sorry!
	if (start.y + 90 > 500 || start.x + 20 > 500)
		return;
	started = true;
	shape_color = color;
	start_point = start;
}

void Label::change(Point end, Color color, bool fill)
{
	if (!saved & started)
	{
		shape_color = color;
		end_point.x = end.x - start_point.x - 10 <= 0 ? start_point.x + 10 : end.x;
		end_point.y = start_point.y + 15;
	}
}

Drawable *Label::make_new()
{
	if (!saved)
		return this;
	else
		return new Label();
}

bool Label::write(unsigned char letter)
{
	int letter_num = int(letter);
	if (letter_num == 13)
		saved = true;
	else if (letter_num == 8 && text_size > 0)
	{
		text_size--;
		text.pop_back();
	}
	else if (!saved)
	{
		int box_size = end_point.x - start_point.x;
		box_size = box_size < 0 ? box_size * -1 : box_size;
		if ((text_size + 1) * 7 > box_size)
			saved = true;
		else
		{
			text.push_back(letter);
			text_size++;
		}
	}
	return saved;
}

void print_xy(float x, float y, const char *text, void *font)
{
	glRasterPos2d(x, y);
	int text_length = strlen(text);
	for (int i = 0; i < text_length; i++)
	{
		if (text[i] == '\n')
		{
			y -= 3.5;
			x = 2;
			glRasterPos2d(2, y);
		}
		else if (text[i] == '\t')
		{
			x += 4;
			glRasterPos2d(x, y);
		}
		else
		{
			x += 2;
			glutBitmapCharacter(font, text[i]);
		}
	}
}

Point print_file(Point boundaries, Point window_size, const string &text, void *font)
{
	float ratio_x = window_size.x / boundaries.x * 1.0;
	float ratio_y = window_size.y / boundaries.y * 1.0;

	float text_x;
	float text_y;

	if (font == GLUT_BITMAP_8_BY_13)
	{
		text_x = 8.0 / ratio_x;
		text_y = 13.0 / ratio_y;
	}
	else if (font == GLUT_BITMAP_9_BY_15)
	{
		text_x = 9.0 / ratio_x;
		text_y = 15.0 / ratio_y;
	}
	else if (font == GLUT_BITMAP_HELVETICA_10)
	{
		text_x = -1.0;
		text_y = 2.0;
	}
	else if (font == GLUT_BITMAP_HELVETICA_12)
	{
		text_x = -1.0;
		text_y = 2.5;
	}
	else if (font == GLUT_BITMAP_HELVETICA_18)
	{
		text_x = -1.0;
		text_y = 3.5;
		boundaries.y -= 1.0;
	}
	else if (font == GLUT_BITMAP_TIMES_ROMAN_10)
	{
		text_x = -1.0;
		text_y = 1.5;
		boundaries.y += 0.7;
	}
	else if (font == GLUT_BITMAP_TIMES_ROMAN_24)
	{
		text_x = -1.0;
		text_y = 4.0;
		boundaries.y -= 1.5;
	}

	float x = 2;
	float y = boundaries.y - 4.0;
	glRasterPos2d(x, y);
	for (auto iterator = text.cbegin(); iterator != text.cend(); ++iterator)
	{
		if (*iterator == '\n')
		{
			y -= text_y + 0.5;
			x = 2;
			glRasterPos2d(2, y);
		}
		else if (*iterator == '\t')
		{
			glutBitmapCharacter(font, ' ');
			glutBitmapCharacter(font, ' ');
			glutBitmapCharacter(font, ' ');
			x += text_x * 3.0;
		}
		else
		{
			x += text_x;
			glutBitmapCharacter(font, *iterator);
		}
	}

	if (text_x < 0)
	{
		glutBitmapCharacter(font, '|');
		return Point();
	}
	else
		return Point(x, y);
}