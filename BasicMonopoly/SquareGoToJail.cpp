
/**************************************************************************************************

	Project: Basic Monopoly

	   File: SquareGoToJail.cpp

	 Author: Simon Rybicki

	   Date: 04/03/19

	Version: 1.0

	   Info: Implements the Go To Jail square on the monopoly board.

**************************************************************************************************/

#include "SquareGoToJail.hpp"

// Constructor.
// Sets the type of square and name of the square.
CSquareGoToJail::CSquareGoToJail(ESquareType squareType, std::string squareName)
{
	mType = squareType;
	mName = squareName;
}

// Destructor.
CSquareGoToJail::~CSquareGoToJail() { }

// Player moves to the jail position on the monopoly board.
// Player loses some money.
Player CSquareGoToJail::PlayerLanded(Player pPlayer)
{
	pPlayer->SetPosition(JAIL_POSITION);
	std::cout << "\n " << pPlayer->GetName() << " goes to Jail";
	pPlayer->SetMoney(-JAIL_FEE);
	std::cout << "\n " << pPlayer->GetName() << " pays " << POUND << JAIL_FEE;

	return move(pPlayer);
}