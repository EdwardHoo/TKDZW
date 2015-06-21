#pragma once
#include "object.h"
#include <string>
class player :
	public object
{
public:
	player(std::string name, int tk);
	~player();
private:
	std::string Name;
	int Tank_Type;
};

