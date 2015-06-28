#pragma once
#include "position.h"
#include <string>
class object {
public:
	object(int x, int y, int speed, int direction);
	object();
	position P;
	int speed;
	int FacingDirection;
};