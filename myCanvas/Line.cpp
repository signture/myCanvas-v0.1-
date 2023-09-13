#include"all.h"

class Line {
private:
	int x0, y0;
	int x, y;
	int style;
	float k;

public:
	void draw();
	void move();
	void judge();
};