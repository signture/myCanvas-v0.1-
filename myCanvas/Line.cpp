#include"all.h"

void Line::draw()
{
		if (selected)
			style = PS_DASH;
		else
			style = PS_SOLID;
		setlinestyle(style);
		line(x0, y0, x, y);
}

void Line::init_cor(int x, int y)
{
	x0 = x, y0 = y;
}

void Line::change_cor(int x, int y)
{
	this->x = x, this->y = y;
}

void Lines::init(int num)
{
	lines = new Line[num];
}

void Lines::release()
{
	delete(lines);
}
