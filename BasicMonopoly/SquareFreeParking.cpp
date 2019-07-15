
/**************************************************************************************************

	Project: Basic Monopoly

	   File: SquareFreeParking.cpp

	 Author: Simon Rybicki

	   Date: 04/03/19

	Version: 1.0

	   Info: Implements the Free Parking square on the monopoly board.

**************************************************************************************************/

#include "SquareFreeParking.hpp"

// Constructor. 
// Sets the type of square and name of the square.
CSquareFreeParking::CSquareFreeParking(ESquareType squareType, std::string squareName)
{
	mType = squareType;
	mName = squareName;
}

// Destructor.
CSquareFreeParking::~CSquareFreeParking() { }

// Nothing happens to the player.
Player CSquareFreeParking::PlayerLanded(Player pPlayer)
{
	std::cout << "\n " << pPlayer->GetName() << " is resting";

	return move(pPlayer);
}