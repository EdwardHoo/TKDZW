#include "object.h"

object::object(int x, int y, int speed, int direction) {
	this->x = x;
	this->y = y;
	this->speed = speed;
	this->FacingDirection = direction;
}

object::object() {
	this->x = 0;
	this->y = 0;
	this->speed = 0;
	this->FacingDirection = 0;
}