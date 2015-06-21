#pragma once

class object {
public:
	object(int x, int y, int speed, int direction);
	object();
	int x, y;
	int speed;
	int FacingDirection;
};