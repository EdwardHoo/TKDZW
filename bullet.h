#pragma once
#include "object.h"
class bullet :
	public object
{
public:
	bullet(int d, std::string h, int id);
	~bullet();
	int damage;
	std::string host;
	int id;
};

