
/**************************************************************************************************

	Project: Basic Monopoly

	   File: SquarePenalty.cpp

	 Author: Simon Rybicki

	   Date: 04/03/19

	Version: 1.0

	   Info: Implements the Penalty square on the monopoly board.

**************************************************************************************************/

#include "SquarePenalty.hpp"

// Constructor.
// Sets the type of square and name of the square.
CSquarePenalty::CSquarePenalty(ESquareType squareType, std::string squareName)
{
	mType = squareType;
	mName = squareName;
}

// Destructor.
CSquarePenalty::~CSquarePenalty() { }

// Creates a random penatly event.
// Player loses money from the penatly event.
Player CSquarePenalty::PlayerLanded(Player pPlayer)
{
	SPenaltyEvent penaltyEvent = PENALTY_EVENTS[RandomDice() - 1];
	pPlayer->SetMoney(-penaltyEvent.mMoney);
	std::cout << "\n " << penaltyEvent.mDescription << POUND << penaltyEvent.mMoney << ".";

	return std::move(pPlayer);
}