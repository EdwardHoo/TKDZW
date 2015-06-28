#include "player.h"


player::player(std::string name, int tk) {
	Name = name;
	Tank_Type = tk;
	HP = 100;
	alive = true;
	inGame = false;
}


player::~player()
{
}

