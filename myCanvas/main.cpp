#include"all.h"

int lines[NUM][5] = { 0 };
int circles[NUM][4] = { 0 };
int triangles[NUM][4] = { 0 };


int main() {
    //open a window
    initgraph(840, 840);
    setbkcolor(RGB(100, 100, 100));
    cleardevice();
    //present a line of words to the button
    RECT r = { 0,0,840,840 };
    //drawtext(_T("mode: 1:line 2:circle 3:triangle q:quit"), &r, DT_SINGLELINE | DT_BOTTOM);
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
        case TRIANGLE:
            drawtriangle();
            break;
        case MOVE:
            move();
            break;
        case LOAD:
            if (load() == SUCCESS)
                printf("success");
            break;
        case SAVE:
            if (save() == SUCCESS)
                printf("success");
            break;
        default:
            break;
        }
    }

    //wait for click
    //_getch(); 

    saveimage(_T("E:\\ccode\\myCanvas(v0.1)\\myCanvas\\resource\\test.bmp"));

    closegraph(); // 关闭图形界面 

    return 0;

}