#include"all.h"

void drawline()
{
	int x0, y0;
	int x, y;
	int bkcolor = getbkcolor();
	int initLineColor = getlinecolor();
	boolean stop_drawline = false;
	
	while (!stop_drawline)
	{
		MOUSEMSG msg = GetMouseMsg();
		if (msg.uMsg == WM_LBUTTONDOWN)
		{
			//get the inital coordinate
			x0 = msg.x, y0 = msg.y;
			x = x0, y = y0;
			while (!stop_drawline)
			{
				//clean the existed line to reach the effect of animition( we cover the line with the same line but with the background clolr)
				setlinecolor(bkcolor);
				line(x0, y0, x, y);
				setlinecolor(initLineColor);

				msg = GetMouseMsg();
				x = msg.x, y = msg.y;
				//draw a line
				line(x0, y0, x, y);
				if (msg.uMsg == WM_LBUTTONUP)
				{
					//present the final line
					stop_drawline = true;

					//remenber it in the line arrery
					int i = 0;
					/*while (lines[i++][0])
					{
					}
					lines[i][0] = x0;
					lines[i][1] = y0;
					lines[i][2] = x;
					lines[i][3] = y;
					*/
					break;
				}
			}
		}
	}
}


void drawcircle()
{
	float x0, y0;
	float x, y;
	double radius = 0;
	int bkcolor = getbkcolor();
	int initCircleColor = getlinecolor();
	boolean stop_drawingcircle = false;
	MOUSEMSG msg;

	while (!stop_drawingcircle)
	{
		msg = GetMouseMsg();
		if (msg.uMsg == WM_LBUTTONDOWN)
		{
			x0 = msg.x, y0 = msg.y;
			x = x0, y = y0;
			while (!stop_drawingcircle)
			{
				//cover the circle
				//clearcircle(x0, y0, radius); //This method can only cover the circle while you are pulling it make it bigger but can not cover those smaller
				//it will not only cover the circle but also cover the line or other thing besides
				setcolor(bkcolor);
				circle(x0, y0, radius);
				setcolor(initCircleColor);
				 

				//draw a circle
				msg = GetMouseMsg();
				x = msg.x, y = msg.y;
				radius = sqrt((pow(fabs(x0 - x), 2) + (pow(fabs(y0 - y),2))));
				circle(x0, y0, radius);
				if (msg.uMsg == WM_LBUTTONUP)
				{
					stop_drawingcircle = true;
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

	while (!stop_drawtriangle)
	{
		msg = GetMouseMsg();
		if (msg.uMsg == WM_LBUTTONDOWN)
		{
			x0 = msg.x, y0 = msg.y;
			x = x0, y = y0;
			while (!stop_drawtriangle)
			{
				msg = GetMouseMsg();
				x = msg.x, y = msg.y;
				pts[0] = { x0,y0 };
				pts[1] = { x,y };
				pts[2] = { 2 * x0 - x,y };
				polygon(pts, 3);
				if (msg.uMsg == WM_LBUTTONUP)
				{
					stop_drawtriangle = true;
					break;
				}
			}
		}
	}

}