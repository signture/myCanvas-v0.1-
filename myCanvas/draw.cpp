#include"all.h"

extern int lines[NUM][5];
extern int circles[NUM][3];
extern int triangles[NUM][4];


void drawline()
{
	int bkcolor = getbkcolor();
	int initLineColor = getlinecolor();
	boolean stop_drawline = false;				
	int i = 0;

	while (lines[i][0])
	{
		i++;
	}
	
	//BeginBatchDraw();

	while (!stop_drawline)
	{
		MOUSEMSG msg = GetMouseMsg();
		if (msg.uMsg == WM_LBUTTONDOWN)
		{
			//get the inital coordinate
			lines[i][0] = msg.x, lines[i][1] = msg.y;
			while (!stop_drawline)
			{
				//clean the existed line to reach the effect of animition( we cover the line with the same line but with the background clolr)
				//setlinecolor(bkcolor);
				//line(x0, y0, x, y);
				//setlinecolor(initLineColor);

				msg = GetMouseMsg();
				lines[i][2] = msg.x, lines[i][3] = msg.y;
				//draw a line
				//line(x0, y0, x, y);

				draw();

				//FlushBatchDraw();
				if (msg.uMsg == WM_LBUTTONUP)
				{
					//present the final line
					stop_drawline = true;
					//EndBatchDraw();
					//remenber it in the line arrery
					
					break;
				}
			}
		}
	}
}


void drawcircle()
{
	int x0, y0;
	int x, y;
	int radius = 0;
	int bkcolor = getbkcolor();
	int initCircleColor = getlinecolor();
	boolean stop_drawingcircle = false;
	MOUSEMSG msg;

	int i = 0;
	while (circles[i][0])
	{
		i++;
	}

	//BeginBatchDraw();

	while (!stop_drawingcircle)
	{
		msg = GetMouseMsg();
		if (msg.uMsg == WM_LBUTTONDOWN)
		{
			circles[i][0] = msg.x, circles[i][1] = msg.y;
			x0 = circles[i][0], y0 = circles[i][1];
			while (!stop_drawingcircle)
			{
				//cover the circle
				//clearcircle(x0, y0, radius); //This method can only cover the circle while you are pulling it make it bigger but can not cover those smaller
				//it will not only cover the circle but also cover the line or other thing besides

				//setcolor(bkcolor);
				//circle(x0, y0, radius);
				//setcolor(initCircleColor);
				 

				//draw a circle
				msg = GetMouseMsg();
				x = msg.x, y = msg.y;
				radius = sqrt((pow(fabs(x0 - x), 2) + (pow(fabs(y0 - y),2))));
				//FlushBatchDraw();
				//circle(x0, y0, radius);

				circles[i][2] = radius;
				draw();

				if (msg.uMsg == WM_LBUTTONUP)
				{
					stop_drawingcircle = true;
					circles[i][2] = radius;
					break;
				}
			}
		}
	}

}

void drawtriangle()
{
	int x0, y0;
	int x, y;
	int bkcolor = getbkcolor();
	int initTriangleColor = getcolor();
	boolean stop_drawtriangle = false;
	MOUSEMSG msg;
	POINT pts[3];
	int i = 0;
	while (triangles[i][0])
	{
		i++;
	}



	while (!stop_drawtriangle)
	{
		msg = GetMouseMsg();
		if (msg.uMsg == WM_LBUTTONDOWN)
		{
			triangles[i][0] = msg.x, triangles[i][1] = msg.y;
			while (!stop_drawtriangle)
			{
				msg = GetMouseMsg();
				triangles[i][2] = msg.x, triangles[i][3] = msg.y;
				draw();
				if (msg.uMsg == WM_LBUTTONUP)
				{
					stop_drawtriangle = true;
					return;
				}
			}
		}
	}

}


void draw()
{
	BeginBatchDraw();
	cleardevice();
	int i = 0;
	POINT pts[3];


		while (lines[i][0])
		{
			if (lines[i][4])
				setlinestyle(PS_DASH);
			else
				setlinestyle(PS_SOLID);
			line(lines[i][0], lines[i][1], lines[i][2], lines[i][3]);//lines_k[i] * (lines[i][2] - lines[i][0]) + lines[i][1]
			i++;
		}
		i = 0;
		while (circles[i][0])
		{
			circle(circles[i][0], circles[i][1], circles[i][2]);
			i++;
		}
		i = 0;
		//draw triangles
		while (triangles[i][0])
		{
			pts[0] = { triangles[i][0],triangles[i][1] };
			pts[1] = { triangles[i][2],triangles[i][3] };
			pts[2] = { 2 * triangles[i][0] - triangles[i][2],triangles[i][3] };
			polygon(pts, 3);
			i++;
		}

		FlushBatchDraw();



	EndBatchDraw();
}