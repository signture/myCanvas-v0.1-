#include "all.h"

extern int lines[NUM][5];
extern int circles[NUM][4];
extern int triangles[NUM][4];

int judge_line(int x, int y);
int judge_circle(int x, int y);
int judge_triangle(int x, int y);


boolean cross(int x1, int y1, int x2, int y2)
{
	boolean toward = true;
	int result = 0;
	result = x1 * y2 - y1 * x2;
	if (result < 0)
		toward = false;
	return toward;
}



Shape judge(int * pos)
{
	int x, y;
	int shape;
	Shape sp = nothing;
	MOUSEMSG msg;
	boolean stop_checking = false;
	boolean judge_contain = false;


	while (!stop_checking)
	{
		msg = GetMouseMsg();
		if (msg.uMsg == WM_LBUTTONDOWN)
		{
			x = msg.x, y = msg.y;
			shape = judge_line(x, y);
			if (shape >= 0)
			{
				sp = LIne;
				*pos = shape;
				lines[shape][4] = 1;
				draw();
				return sp;
			}
			shape = judge_circle(x, y);
			if (shape >= 0)
			{
 				sp = Circle;
				*pos = shape;
				circles[shape][3] = 1;
				draw();
				return sp;
			}
			shape = judge_triangle(x, y);
			if (shape >= 0)
			{
				sp = Triangle;
				*pos = shape;
				return sp;
			}
		}
	}


	return sp;
}


int judge_line(int x, int y)
{
	int is_line = -1;
	int i = 0;
	float k = 0;

	while (lines[i][0])
	{
		if (((x > lines[i][0] - 3)^( x < lines[i][2] + 3)))
		{
			i++;
			continue;
		}
		k = (static_cast<float>(lines[i][1]) - y) / (lines[i][0] - x);
		if ((y - lines[i][1]) >= (x - lines[i][0]) * k - 2 || (y - lines[i][1]) <= (x - lines[i][0]) * k + 2)
			return i;
		i++;
	}
	return is_line;
}


int judge_circle(int x, int y)
{
	int is_circle = -1;
	int i = 0;
	int radius;

	while (circles[i][0])
	{
		radius = sqrt((pow(fabs(circles[i][0] - x), 2) + (pow(fabs(circles[i][1] - y), 2))));
		if (radius <= circles[i][2])
		{
			return i;
		}
		i++;
	}
	return is_circle;
}


int judge_triangle(int x, int y)
{
	int is_triangle = -1;
	int i = 0;
	int vt1_x, vt1_y;
	int vt2_x, vt2_y;
	int vt3_x, vt3_y;
	boolean cross1 = false;
	boolean cross2 = false;

	while (triangles[i][0])
	{
		if (!((y <= triangles[i][1]) ^ (y >= triangles[i][3])))
		{
			vt1_x = x - triangles[i][0];
			vt1_y = y - triangles[i][1];
			vt2_x = triangles[i][2] - triangles[i][0];
			vt2_y = triangles[i][3] - triangles[i][1];
			vt3_x = -vt2_x;
			vt3_y = vt2_y;
			cross1 = cross(vt1_x, vt1_y, vt2_x, vt2_y);
			cross2 = cross(vt1_x, vt1_y, vt3_x, vt3_y);
			if(cross1 ^ cross2)
				return i;
		}
		i++;
	}



	return is_triangle;
}

