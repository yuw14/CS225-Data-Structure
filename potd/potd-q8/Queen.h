#pragma once
#include "Piece.h"
#include<string>


class Queen :public Piece {
public:
	Queen();
	std::string getType();
};
