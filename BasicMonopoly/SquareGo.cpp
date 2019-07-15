
/**************************************************************************************************

	Project: Basic Monopoly

	   File: SquareGo.cpp

	 Author: Simon Rybicki

	   Date: 04/03/19

	Version: 1.0

	   Info: Implements the GO square on the monopoly board.

**************************************************************************************************/

#include "SquareGo.hpp"

// Constructor.
// Sets the type of square and name of the square.
CSquareGo::CSquareGo(ESquareType squareType, std::string squareName)
{
	mType = squareType;
	mName = squareName;
}

// Destructor.
CSquareGo::~CSquareGo() { }

// Nothing happens to the player.
Player CSquareGo::PlayerLanded(Player pPlayer)
{
	return std::move(pPlayer);
}