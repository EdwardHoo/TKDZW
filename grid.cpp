#include "grid.h"

grid::grid(int L, int W) {
	The_Grid.empty();
	std::vector<block> temp;
	block EmptyBlock(0);
	temp.empty();
	for (int i = 0; i < L; i++) {
		The_Grid.push_back(temp);
		for (int j = 0; j < W; j++) {
			The_Grid[i].push_back(EmptyBlock);
		}
	}
	Length = L;
	Width = W;
}

bool grid::setBlock(int X, int Y, int block_type) {
	if (X < 0 || Y < 0)
		return false;
	if (X >(Length - 1) || Y >(Width - 1))
		return false;
	The_Grid[X][Y].Block_Type = block_type;
	return true;
}