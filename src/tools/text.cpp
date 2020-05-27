#include "text.h"

void print_xy(float x, float y,const char* text, void* font)
{
    glRasterPos2d(x,y);
    int text_length = strlen(text);
    for (int i = 0; i < text_length; i++)
    {
        if(text[i] == '\n') 
        {
            y-=3.5;
            x = 2;
            glRasterPos2d(2,y);
        }
        else if (text[i] == '\t')
        {
            x+=4;
            glRasterPos2d(x,y);
        } 
        else 
        {
            x+=2;
            glutBitmapCharacter(font,text[i]);
        }
    }
}

Point print_file(Point boundaries,Point window_size,const string& text,void* font)
{
    float ratio_x = window_size.x/boundaries.x*1.0;
    float ratio_y = window_size.y/boundaries.y*1.0;

    float text_x;
    float text_y;

    if(font == GLUT_BITMAP_8_BY_13){
        text_x = 8.0/ratio_x;
        text_y = 13.0/ratio_y;
    }
    else if(font == GLUT_BITMAP_9_BY_15){
        text_x = 9.0/ratio_x;
        text_y = 15.0/ratio_y;
    } 
    else if(font == GLUT_BITMAP_HELVETICA_10){
        text_x = -1.0;
        text_y = 2.0;
    }
    else if(font == GLUT_BITMAP_HELVETICA_12){
        text_x = -1.0;
        text_y = 2.5;
    }
    else if(font == GLUT_BITMAP_HELVETICA_18){
        text_x = -1.0;
        text_y = 3.5;
        boundaries.y -= 1.0;
    }
    else if(font == GLUT_BITMAP_TIMES_ROMAN_10){
        text_x = -1.0;
        text_y = 1.5;
        boundaries.y += 0.7;
    }
    else if(font == GLUT_BITMAP_TIMES_ROMAN_24){
        text_x = -1.0;
        text_y = 4.0;
        boundaries.y -= 1.5;
    }

    float x = 2;
    float y = boundaries.y-4.0;
    glRasterPos2d(x,y);
    for (auto iterator = text.cbegin(); iterator != text.cend(); ++iterator)
    {
        if(*iterator == '\n') 
        {
            y-=text_y+0.5;
            x = 2;
            glRasterPos2d(2,y);
        }
        else if (*iterator == '\t')
        {
            glutBitmapCharacter(font,' ');
            glutBitmapCharacter(font,' ');
            glutBitmapCharacter(font,' ');
            x+=text_x*3.0;
        }
        else 
        {
            x+=text_x;
            glutBitmapCharacter(font,*iterator);
        }
    }

    if(text_x < 0){
        glutBitmapCharacter(font,'|');
        return Point();
    } else return Point(x,y);
}