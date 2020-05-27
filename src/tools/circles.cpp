#include"circles.h"

Circle::Circle()
{
    this->radius = -1;
}

Circle::Circle(float x, float y, float radius)
{
    this->center = Point(x,y);
    this->radius = radius;
}

Circle::Circle(Point center, float radius)
{
    this->center = center;
    this->radius = radius;
}

Circle::Circle(const Circle &v)
{
    this->center = v.center;
    this->radius = v.radius;
    this->r = v.r;
    this->g = v.g;
    this->b = v.b;
}

void Circle::set_color(int r, int g, int b)
{
    this->r = r;
    this->g = g;
    this->b = b;
}

void draw_circle_(float cx,float cy,float radius,bool isSolid)
{
    if (isSolid) glBegin(GL_POLYGON);
    else glBegin(GL_LINE_LOOP); 
    {
        for (int i = 0; i < 100; i++){ 
            float theta = 2.0f * 3.1415926f * i / 100;
            float x = radius*cosf(theta);
            float y = radius*sinf(theta);
            glVertex2f(x+cx,y+cy);
        } 
    } glEnd();
}