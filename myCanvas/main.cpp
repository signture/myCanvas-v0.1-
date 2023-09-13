#include"all.h"

int lines[NUM][4] = { 0 };
int circles[NUM][3] = { 0 };
int triangles[NUM][4] = { 0 };


int main() {
    //open a window
    initgraph(640, 480); 
    //present a line of words to the button
    RECT r = { 0,0,640,480 };
    drawtext(_T("mode: 1:line 2:circle 3:triangle q:quit"), &r, DT_SINGLELINE | DT_BOTTOM);
    boolean stop_drawing = false;
    BITMAP bm;


    while (!stop_drawing)
    {
        switch (getchar())
        {
        case QUIT:
            stop_drawing = true;
            break;
        case LINE:
            drawline();
            break;
        case CIRCLE:
            drawcircle();
            break;
        case MOVE:
            move();
        case TRIANGLE:
            drawtriangle();
        }
    }

    //wait for click
    //_getch(); 

    saveimage(_T("E:\\test.bmp"));

    closegraph(); // 关闭图形界面 

    return 0;

}