
#include "gamemap.h"


gamemap::gamemap() : Game_Grid(0, 0) {
	Players_List.empty();
	Bullets_List.empty();
}

gamemap::gamemap(grid g) : Game_Grid(g) {
	Players_List.empty();
	Bullets_List.empty();
}

bool gamemap::Add_Player(player* p) {
	std::vector<player>::iterator It = Players_List.begin();
	for (; It != Players_List.end(); It++) {
		if ((*It).Name == (*p).Name) {
			return false;
		}
	}
	Players_List.push_back(*p);
	(*p).inGame = true;
	return true;
}

bool gamemap::Add_Bullet(bullet* b) {
	std::vector<player>::iterator It = Players_List.begin();
	for (; It != Players_List.end(); It++) {
		if ((*It).Name == (*b).host) {
			Bullets_List.push_back(*b);
			return true;
		}
	}
	return false;
}

bool gamemap::Remove_Player(player* p) {
	std::vector<player>::iterator It = Players_List.begin();
	for (; It != Players_List.end(); It++) {
		if ((*It).Name == (*p).Name) {
			Players_List.erase(It);
			(*p).inGame = false;
			return true;
		}
	}
	return false;
}

bool gamemap::Remove_Bullet(bullet* b) {
	std::vector<bullet>::iterator It = Bullets_List.begin();
	for (; It != Bullets_List.end(); It++) {
		if ((*It).id == (*b).id && (*It).host == (*b).host) {
			Bullets_List.erase(It);
			(*b).~bullet();
			return true;
		}
	}
	return false;
}

bool gamemap::Load_Grid(grid g) {
	Game_Grid = g;
	return true;
}
bool gamemap::Change_Block(position xy, int to_type) {
	return Game_Grid.setBlock(xy.x, xy.y, to_type);
}

bool gamemap::Change_Player_Stat(std::string who, int HP, bool _null) {
	std::vector<player>::iterator It = Players_List.begin();
	for (; It != Players_List.end(); It++) {
		if ((*It).Name == who) {
			(*It).HP = HP;
			return true;
		}
	}
	return false;
}

bool gamemap::Change_Player_Stat(std::string who, int direction) {
	std::vector<player>::iterator It = Players_List.begin();
	for (; It != Players_List.end(); It++) {
		if ((*It).Name == who) {
			(*It).FacingDirection = direction;
			return true;
		}
	}
	return false;
}

bool gamemap::Move_Player(std::string who, position to_xy) {
	std::vector<player>::iterator It = Players_List.begin();
	for (; It != Players_List.end(); It++) {
		if ((*It).Name == who) {
			(*It).P.x = to_xy.x;
			(*It).P.y = to_xy.y;
			return true;
		}
	}
	return false;
}

bool gamemap::Move_Bullet(std::string whose, int id, position to_xy) {
	std::vector<bullet>::iterator It = Bullets_List.begin();
	for (; It != Bullets_List.end(); It++) {
		if ((*It).id == id && (*It).host == whose) {
			(*It).P.x = to_xy.x;
			(*It).P.y = to_xy.y;
			return true;
		}
	}
	return false;
}

std::string Get_Sum_For_Send() {
	std::string rtrn = "blah";
	return rtrn;
}

gamemap::~gamemap()
{
}
