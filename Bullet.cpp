#include "Bullet.h"

/* 
 * Constructor when data is not provided 
 */
Bullet::Bullet()
{
	/* Initialize basic data */
	x = 0;
	y = 0;
	vx = SPEED_BASIC;
	vy = SPEED_BASIC;
	width = AREA_BASIC; 
	height = AREA_BASIC;
}

/* 
 * Constructor when data is provided
 * Check if area size(higher than AREA_MIN and lower than AREA_MAX ),
 * speeds(from SPEED_MIN to SPEED_MAX ) and coordinates(not outside the border) are adequate
 */
Bullet::Bullet(double x1, double y1, double v1, double v2, int w, int h)
{
	
	//check if the area size is correct
	if(w < AREA_MIN || w > AREA_MAX || h < AREA_MIN || h > AREA_MAX)
	{
		width = AREA_BASIC;
		height = AREA_BASIC;
	}

	//check if coordinates are correct
	if(x1 < 0 || x1 > w || y1 < 0 || y1 > h)
	{
		x = w / 2;
		y = h / 2;
	}

	//check if the speed is correct
	if(v1 > INIT_SPEED_MAX || v1 < INIT_SPEED_MIN || v2 > INIT_SPEED_MAX || v2 < INIT_SPEED_MIN)
	{
		vx = SPEED_BASIC;
		vy = SPEED_BASIC;
	}
	
}

/*
 * Give all the info about Bullet object.
 * Return the double array with size 6.
 * Content: [position x, position y, speed x, speed y, area width, area height]
 */
double* Bullet::info()
{
	double* tmp = new double[6];
	/* Save all data in the array */
	tmp[0] = x;
	tmp[1] = y;
	tmp[2] = vx;
	tmp[3] = vy;
	tmp[4] = width;
	tmp[5] = height;
	return tmp;
}

/*
 * Move bullet taking into account the gravity forces
 * Return the rounded coordinats of the position of the bullet object
 * Format: [x,y]
 */
int* Bullet::move(int time)
{
	//change of x position
	double deltaX = time * vx;

	//change of y position
	//just subtract distance from free falling from the distance of moving straight
	double deltaY = time * vy - GRAVITY * pow(time, 2) / 2;

	//only vy changes
	//calculate change of the vy
	double deltaVY = -(GRAVITY * time);

	/* Update position and speed */
	x += deltaX;
	y += deltaY;
	vy += deltaVY;

	//if outside the border - delete object
	if(checkBorder())
	{
		return nullptr;
	}

	//create array and store there rounded coordinates values
	int* tmp = new int[2];
	tmp[0] = round(x);
	tmp[1] = round(y);

	return tmp;
}

/*
 * Check if object is still within allowed borders(width, height)
 * Return true if outside the borders
 */
bool Bullet::checkBorder()
{
	if(x > width || x < 0 || y > height || y < 0)
	{
		return true;
	}

	return false;
}
