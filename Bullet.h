#ifndef BULLET_H
#define BULLET_H

#include <cmath>

const double GRAVITY = 9.8 / 100;
const int AREA_MIN = 200;
const int AREA_MAX = 2000;
const int AREA_BASIC = 400;
const double INIT_SPEED_MAX = 10;
const double INIT_SPEED_MIN = 1;
const double SPEED_BASIC = 1;

class Bullet{
private:
	//position
	double x, y;
	//speed direction
	double vx, vy;
	//area size
	int width, height;

public:
	//basic case when no data provided
	Bullet();
	//initialise with data provided
	Bullet(double x1, double y1, double vx, double vy, int w, int h);

	//get basic info about bullet
	double* info();

	//move bullet
	int* move(int time);

	//check if object outside the borders
	bool checkBorder();

};

#endif