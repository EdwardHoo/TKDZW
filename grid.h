#pragma once
#include <vector>
#include "block.h"

class grid {
public:
	grid(int L, int W);
	std::vector<std::vector<block>> The_Grid;
	bool setBlock(int X, int Y, int block_type);
	grid operator= (grid g);

	int Length;
	int Width;
};