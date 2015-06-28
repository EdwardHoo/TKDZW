#include "bullet.h"


bullet::bullet(int d, std::string h, int id)
{
	damage = d;
	host = h;
	this->id = id;
}


bullet::~bullet()
{
}
