
/**************************************************************************************************

	Project: Basic Monopoly

	   File: SquareJail.cpp

	 Author: Simon Rybicki

	   Date: 04/03/19

	Version: 1.0

	   Info: Implements the Jail square on the monopoly board.

**************************************************************************************************/

#include "SquareJail.hpp"

// Constructor.
// Sets the type of square and name of the square.
CSquareJail::CSquareJail(ESquareType squareType, std::string squareName)
{
	mType = squareType;
	mName = squareName;
}

// Destructor.
CSquareJail::~CSquareJail() { }

// Nothing happens to the player.
Player CSquareJail::PlayerLanded(Player pPlayer)
{
	std::cout << "\n " << pPlayer->GetName() << " is just visiting";

	return move(pPlayer);
}