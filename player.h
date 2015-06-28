#pragma once
#include "object.h"
#include <string>
class player :
	public object
{
public:
	player(std::string name, int tk);
	~player();
	std::string Name;
	int Tank_Type;
	int HP;
	bool alive;
	bool inGame;
};

