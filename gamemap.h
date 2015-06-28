#pragma once
#include "grid.h"
#include "bullet.h"
#include "player.h"
class gamemap
{
public:
	gamemap();
	gamemap(grid g);
	bool Add_Player(player* p);
	bool Add_Bullet(bullet* b);
	bool Remove_Player(player* p);
	bool Remove_Bullet(bullet* b);
	bool Load_Grid(grid g);
	bool Change_Block(position xy, int to_type);
	bool Change_Player_Stat(std::string who, int HP, bool _null);
	bool Change_Player_Stat(std::string who, int direction);
	bool Move_Player(std::string who, position to_xy);
	bool Move_Bullet(std::string whose, int id, position to_xy);

	std::string Get_Sum_For_Send();
	~gamemap();

	grid Game_Grid;
	std::vector<player> Players_List;
	std::vector<bullet> Bullets_List;
};

