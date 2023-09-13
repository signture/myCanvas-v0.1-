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


class Line {
private:
	int x0, y0;
	int x, y;
	int style = PS_SOLID;
	float k;

public:
	boolean selected = false;
	void draw();
	void init_cor(int x,int y);
	void change_cor(int x, int y);
};

class Lines
{
public:
	Line* lines;
	void init(int num);
	void release();
};

enum Shape
{
	LIne,Circle,Triangle,nothing
};


void drawline();
void drawcircle();
void drawtriangle();
Shape judge(int* pos);
void move();
void draw();