// TKDZM.cpp : Defines the entry point for the console application.
//

#include "header.h"

int main() {
	cout << "Main function running..." << endl;
	cout << "Starting Initialization..." << endl;
	Game_Initial(0, 0);
	cout << "Adding player1..." << endl;
	Player_AddToList("Edward", 15, 1);
	cout << "List size:" << Player_List.size() << endl;
	vector<Player>::iterator It = Player_List.begin();
	cout << "Player1:" << (*It).Get_Name() << endl;

	Arena Arena1(100, 100, 1);
	(*It).Load_ToGame(&Arena1);
	cout << "ListInArena size:" << Arena1.Get_PlayerQuan() << endl;
	//(*It).Exit_FromGame();
	//cout << "ListInArena size:" << Arena1.Get_PlayerQuan() << endl;

	int a;
	while(true) {
		cin >> a;
		(*It).Move(a);
		cout << "Moved!" << endl;
		cout << "Current Position:" << (*It).Get_Position().X << "," << (*It).Get_Position().Y << endl;
	}

	return 0;
}

int Game_Initial(int mode, int extra) {
	Game_Mode = mode;
	Game_Extra = extra;
	Player_List.empty();
	cout << "List size:" << Player_List.size() << endl;
	Player_Quan = 0;
	cout << "Game Initialized." << endl;
	return 0;
}

int Player_AddToList(string name, int tank_type, int color) {
	Player New(name, tank_type, color);
	Player_List.push_back(New);
	Player_Quan++;
	return Player_List.size();
}

int Get_TankSpeed(int Tank_Type) {
	return Tank_Type;
}