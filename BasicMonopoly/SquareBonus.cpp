
/**************************************************************************************************

	Project: Basic Monopoly

	   File: SquareBonus.cpp

	 Author: Simon Rybicki

	   Date: 04/03/19

	Version: 1.0

	   Info: Implements the Bonus square on the monopoly board.

**************************************************************************************************/

#include "SquareBonus.hpp"

// Constructor.
// Sets the type of square and name of the square.
CSquareBonus::CSquareBonus(ESquareType squareType, std::string squareName)
{
	mType = squareType;
	mName = squareName;
}

// Destructor.
CSquareBonus::~CSquareBonus() { }

// Creates a random bonus event.
// Player recieves money from the bonus event.
Player CSquareBonus::PlayerLanded(Player pPlayer)
{
	SBonusEvent bonusEvent = BONUS_EVENTS[RandomDice() - 1];
	pPlayer->SetMoney(bonusEvent.mMoney);
	std::cout << "\n " << bonusEvent.mDescription << POUND << bonusEvent.mMoney << ".";

	return std::move(pPlayer);
}