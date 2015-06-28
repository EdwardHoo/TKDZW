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

grid grid::operator= (grid g) {
	Length = g.The_Grid.size();
	if (Length == 0) {
		Width = 0;
		return *this;
	}
	Width = g.The_Grid[0].size();
	std::vector<block> tmp;
	The_Grid.empty();
	for (int i; i < Length; i++) {
		tmp.empty();
		for (int j; j < Width; j++) {
			tmp.push_back(g.The_Grid[i][j]);
		}
		g.The_Grid.push_back(tmp);
	}
	return *this;
}