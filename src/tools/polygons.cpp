#include"polygons.h"

void draw_polygon_(bool isSolid, Point vertex, ...)
{
    if(isSolid) glBegin(GL_POLYGON);
    else glBegin(GL_LINE_LOOP);
    {  
        va_list ap;
        va_start(ap,vertex);
        {
            while (!vertex.invalid)
            {
                glVertex2f(vertex.x,vertex.y);

                // cout << "X=" << vertex.x << " Y=" << vertex.y <<"\n";
                vertex = *va_arg(ap,Point*);
            }

        } va_end(ap);
	} glEnd();
}

void draw_equilateral_(float x,float y,float size,int sideNum,int degree,bool isSolid){

    float degreeR = degree*3.1415926f/180.0f;

    if (isSolid) glBegin(GL_POLYGON);
    else glBegin(GL_LINE_LOOP); 
    {
        for (int i = 0; i < sideNum; i++)
        {
            float theta = degreeR + 2.0f*3.1415926f*i/sideNum;
            float xl = size*(cosf(theta));
            float yl = size*(sinf(theta));

            glVertex2f(x+xl,y+yl);
            // glColor3f(0.0,1.0,1.0);   
        }
    } glEnd();

}

Point xy(double x,double y)
{
    Point v(x,y);
    return v;
}