#include<graphics.h>
#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<wingdi.h>
#include<Windows.h>

#define LINE '1'
#define CIRCLE '2'
#define TRIANGLE '3'
#define MOVE '4'
#define QUIT 'q'
#define NUM 10
//extern int lines[4][100] = { 0 };


enum Shape
{
	Line,Circle,Triangle,nothing
};


void drawline();
void drawcircle();
void drawtriangle();
Shape judge(int* pos);
void move();
void draw();