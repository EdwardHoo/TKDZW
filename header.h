#pragma once

#include <stdio.h>
#include <tchar.h>
#include <map>
#include <vector>
#include <string>

//for debug issue
#include <iostream>
using namespace std;

//three foundamental elements of the game
class Player; //can be seen as a single tank
class Position; //(x,y)
class Arena;    //an arena for the tanks to move around, featured by its length and width

int Get_TankSpeed(int Tank_Type);  //as designed, each tank has its own speed; for early developing, the speed of the tank equals to its type number

class Position {
public:
	Position(int x, int y);
	Position();
	int Set(int x, int y);
	int X, Y;
};

class Player {
public:
	Player(string name, int tank_type, int color);
	string Get_Name();
	Position Get_Position();
	int Load_ToGame(Arena* _arena); //use this function to load a player(tank) to the destinated Arena
	int Exit_FromGame(); //use this to get it out

	int Move(int direction); //1 = up, 2 = down, 3 = left, 4 = right, the tank will more an amount of its speed of pixals in the arena to the selected direction; boundary issue has been considered within

private:
	string Name; //THIS IS THE IDENTIFY OF EACH PLAYER, NO SAME NAME ALLOWED. ALL PLAYERS WILL BE CALLED ACCORDING TO THEIR NAMES
	int Tank_Type;
	int color;
	bool isInGame; //whether the player is in an Arena or not, which shows whether this player is in game or not
	Position CurrentP; //current position of the player in the Arena
	Arena* inWhichArena; //A pointer to the Arena the player is situated in, will be a void pointer when isInGame is false
};

class Arena {
public:
	Arena(int length, int width, int type);
	int Load_Player(Player P);           //Simply do not use these two functions
	int Erase_Player(string name);
	int Get_PlayerQuan();			//how many players are there in this Arena?
	int Get_Length();              //how big this arena is?
	int Get_Width();
private:
	int Length; //in pixals
	int Width;
	int Type;
	bool isValid;
	map<string, Player> Player_InArena;    //each Arena has its own list(map) of the players inside
};

//Variables for the whole game
int Game_Mode;
int Game_Extra;
vector<Player> Player_List;               //an important list to storage all the players connected
int Player_Quan = 0;                      

int Game_Initial(int mode, int extra);
int Player_AddToList(string name, int tank_type, int color); //add a new player to the main list


Position::Position(int x, int y) {
	this->X = x;
	this->Y = y;
}

Position::Position() {
	this->X = 0;
	this->Y = 0;
}

int Position::Set(int x, int y) {
	this->X = x;
	this->Y = y;
	return 1;
}


Player::Player(string name, int tank_type, int color) {
	this->Name = name;
	this->Tank_Type = tank_type;
	this->color = color;
	this->isInGame = 0;
	this->CurrentP.Set(0, 0);
}

string Player::Get_Name() {
	return this->Name;
}

Position Player::Get_Position(){
	return this->CurrentP;
}

int Player::Load_ToGame(Arena* _arena) {
	if (isInGame) {
		return 0;
	}
	isInGame = 1;
	inWhichArena = _arena;
	(*_arena).Load_Player(*this);
	CurrentP.Set(0, 0);
	return 1;
}

int Player::Exit_FromGame() {
	if (!isInGame) {
		return 0;
	}
	isInGame = 0;
	(*inWhichArena).Erase_Player(this->Name);
	inWhichArena = 0;
	return 1;
}

int Player::Move(int direction) {
	int temp = 0;
	switch (direction) {
	case 1:
		temp = (*(this->inWhichArena)).Get_Length() - Get_TankSpeed(this->Tank_Type);
		if (this->CurrentP.Y > temp) {
			this->CurrentP.Y = (*(this->inWhichArena)).Get_Length();
			return 1;
		}
		else {
			this->CurrentP.Y += Get_TankSpeed(this->Tank_Type);
		}

		return 1;
	
	case 2:
		if (this->CurrentP.Y < Get_TankSpeed(this->Tank_Type)) {
			this->CurrentP.Y = 0;
			return 1;
		}
		else {
			this->CurrentP.Y -= Get_TankSpeed(this->Tank_Type);
		}

		return 1;
	
	case 3:
		if (this->CurrentP.X < Get_TankSpeed(this->Tank_Type)) {
			this->CurrentP.X = 0;
			return 1;
		}
		else {
			this->CurrentP.X -= Get_TankSpeed(this->Tank_Type);
		}
		return 1;
	
	case 4:
		temp = (*(this->inWhichArena)).Get_Width() - Get_TankSpeed(this->Tank_Type);
		if (this->CurrentP.X > temp) {
			this->CurrentP.X = (*(this->inWhichArena)).Get_Width();
			return 1;
		}
		else {
			this->CurrentP.X += Get_TankSpeed(this->Tank_Type);
		}
		return 1;
	
	default:
		return 0;
	}
	return 0;

}

Arena::Arena(int length, int width, int type){
	this->Length = length;
	this->Width = width;
	this->Type = type;
	isValid = 0;
	Player_InArena.empty();
}

int Arena::Load_Player(Player P) {
	vector<Player>::iterator It = Player_List.begin();
	for (; It != Player_List.end(); It++) {
		if ((*It).Get_Name() == P.Get_Name()) {
			Player_InArena.insert(map<string, Player>::value_type(P.Get_Name(), P));
			return Player_InArena.size();
		}
	}
	return 0;
}

int Arena::Erase_Player(string name) {
	int Occ = Player_InArena.count(name);
	if (Occ == 0) {
		return 0;
	}
	Player_InArena.erase(name);
	return 1;
}

int Arena::Get_PlayerQuan() {
	return this->Player_InArena.size();
}

int Arena::Get_Length() {
	return this->Length;
}

int Arena::Get_Width() {
	return this->Width;
}


// TODO: reference additional headers your program requires here
