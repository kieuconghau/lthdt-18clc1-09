#pragma once

class cObstacle
{
public:
	cObstacle();
	virtual ~cObstacle();

protected:
	unsigned int* X;
	unsigned int* Y;
};