#ifdef __APPLE__
#include<GLUT/glut.h>
#else
#include<GL/glut.h>
#endif

#include<iostream>

#include"point.h"

using namespace std;

int phy_width = 500;
int phy_hight = 500;
int logWidth = 100;
int logHeight = 100;

Point center(logWidth/2, logHeight/2);

float random_x()
{
	return rand() % (logWidth-1) + 1;
}

float random_y()
{
	return rand() % (logHeight-1) + 1;
}

void rgb(int r,int g,int b)
{
	glColor3ub(r,g,b);
}

void init2D(float r, float g, float b)
{
	glClearColor(r,g,b,0);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0,logWidth,0,logHeight);
}

void display()
{
	glClear(GL_COLOR_BUFFER_BIT);

	rgb(255, 255, 255);
	

	glutSwapBuffers();
	glFlush();
}

int main(int argc, char *argv[])
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
	glutInitWindowSize(phy_width,phy_hight);
	glutInitWindowPosition(750,100);
	glutCreateWindow("Adobe Illustrator");
	init2D(0.0,0.0,0.0);
	glutDisplayFunc(display);

	glutMainLoop();

	return 0;
}