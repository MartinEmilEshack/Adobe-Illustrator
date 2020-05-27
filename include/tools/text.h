#ifndef _TEXT_H_
#define _TEXT_H_

#ifdef __APPLE__
#include<GLUT/glut.h>
#else
#include<GL/glut.h>
#endif

#include<iostream>
#include<string.h>

#include"point.h"

using namespace std;

void print_xy(float x,float y,const char* text,void* font);

Point print_file(Point boundaries,Point pixels_size,const string& text,void* font);

#endif