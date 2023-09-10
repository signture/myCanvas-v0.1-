#include "all.h"
extern int lines[NUM][3];
extern float lines_k[NUM];
extern int circles[NUM][3];
extern int triangles[NUM][4];


void move_line(int pos);

void move()
{
	int pos;
	Shape sp;
	sp = judge(&pos);
	switch (sp)
	{
	case Line:
		move_line(pos);

	case Triangle:

	case Circle:

	case nothing:
		return;

	}
}


void move_line(int pos)
{
	int x1 = lines[pos][0], y1 = lines[pos][1];
	int x2 = lines[pos][2];
	int y2 = lines_k[pos] * (x2 - x1) + y1;
	int x0, y0;
	int x, y;
	int vt_x, vt_y;
	MOUSEMSG msg;
	boolean stop_moveline = false;

	while (!stop_moveline)
	{
		msg = GetMouseMsg();
		if (msg.uMsg == WM_LBUTTONDOWN)
		{
			x0 = msg.x, y0 = msg.y;


			while (!stop_moveline)
			{
				msg = GetMouseMsg();
				x = msg.x, y = msg.y;

				vt_x = x - x0, vt_y = y - y0;


				line(x1 + vt_x, y1 + vt_y, x2 + vt_x, y2 + vt_y);
				if (msg.uMsg == WM_LBUTTONUP)
				{
					lines[pos][0] = x1 + vt_x;
					lines[pos][1] = y1 + vt_y;
					lines[pos][2] = x2 + vt_x;
					lines[pos][3] = y2 + vt_y;
					stop_moveline = true;
				}
			}
		}
	}
	return;
}