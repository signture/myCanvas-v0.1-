#include "all.h"

extern int lines[NUM][5];
extern int circles[NUM][3];
extern int triangles[NUM][4];



//the struct of the file will be one line with all the number of one line, one circle and one triangle.

Status load()
{
	Status st = FATAL;
	FILE* fp;
	errno_t err = fopen_s(&fp,"test.txt", "r");
	if (fp == NULL)
		return st;
	for (int i = 0; i < 10; i++)
	{
		fscanf_s(fp, "%d %d %d %d %d %d %d %d %d %d %d %d\n", &lines[i][0], &lines[i][1], &lines[i][2], &lines[i][3], &lines[i][4], &circles[i][0], &circles[i][1], &circles[i][2], &triangles[i][0], &triangles[i][1], &triangles[i][2], &triangles[i][3]);
	}
	draw();
	fclose(fp);
	fp = NULL;
	st = SUCCESS;
	return st;
}


Status save()
{
	Status st = FATAL;
	FILE* fp;
	errno_t err = fopen_s(&fp, "test.txt", "w");
	if (fp == NULL)
		return st;
	for (int i = 0; i < 10; i++)
	{
		fprintf_s(fp, "%d %d %d %d %d %d %d %d %d %d %d %d\n", lines[i][0], lines[i][1], lines[i][2], lines[i][3], lines[i][4], circles[i][0], circles[i][1], circles[i][2], triangles[i][0], triangles[i][1], triangles[i][2], triangles[i][3]);
	}
	fclose(fp);
	fp = NULL;
	st = SUCCESS;
	return st;
}