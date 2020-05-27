#include"point.h"

Point::Point(){
    this->x = 0.0;
    this->y = 0.0;
    this->invalid = true;
}

Point::Point(float x,float y)
{
    this->x = x;
    this->y = y;
    this->invalid = false;
}

Point::Point(const Point &v)
{
    x = v.x;
    y = v.y;
    invalid = v.invalid;
}

Point Point::getFinal()
{
    Point fin(0.0,0.0);
    fin.invalid = true;
    return fin;
}

void draw_point(float x,float y){
    glBegin(GL_POINTS);
    {
        glPointSize(1.0);
        glVertex2f(x, y);
    }
    glEnd();
}

void draw_point(float x,float y,float size){
    glPointSize(size);
    glBegin(GL_POINTS);
    {
        glVertex2f(x, y);
    }
    glEnd();
}