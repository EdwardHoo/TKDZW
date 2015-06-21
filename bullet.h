#pragma once
#include "object.h"
class bullet :
	public object
{
public:
	bullet(int d);
	~bullet();
	int damage;
};

