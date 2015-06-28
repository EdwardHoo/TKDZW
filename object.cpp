#include "object.h"

object::object(int x, int y, int speed, int direction) {
	this->P.x = x;
	this->P.y = y;
	this->speed = speed;
	this->FacingDirection = direction;
}

object::object() {
	this->P.x = 0;
	this->P.y = 0;
	this->speed = 0;
	this->FacingDirection = 0;
}