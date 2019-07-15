
/**************************************************************************************************

	Project: Basic Monopoly

	   File: SquarePenalty.hpp

	 Author: Simon Rybicki

	   Date: 04/03/19

	Version: 1.0

	   Info: Defines the Penalty square on the monopoly board.

**************************************************************************************************/

#ifndef _SQUARE_PENALTY_H
#define _SQUARE_PENALTY_H

#include "Square.hpp"

// Defines a penalty event type.
struct SPenaltyEvent
{
	std::string mDescription;
	int mMoney;
};

// Maximum number of penalties.
const int MAX_PENALTIES = 6;

// List of different penalty events.
const SPenaltyEvent PENALTY_EVENTS[MAX_PENALTIES] =
{
	{ "Pay food bill. Player loses ",      20 },
	{ "Pay phone bill. Player loses ",     50 },
	{ "Pay heating bill. Player loses ",  100 },
	{ "Pay vehicle tax. Player loses ",   150 },
	{ "Pay fuel bill. Player loses ",     200 },
	{ "Pay windfall bill. Player loses ", 300 }
};

class CSquarePenalty : public ISquare
{

public:

	// Constructor. 
	// Sets the type of square and name of the square.
	// Param: Type of square, Name of square.
	// Return:
	CSquarePenalty(ESquareType squareType, std::string squareName);

	// Destructor.
	// Param: 
	// Return:
	~CSquarePenalty();

	// Creates a random penatly event.
	// Player loses money from the penatly event.
	// Param: Player (pointer).
	// Return: Player (pointer).
	Player PlayerLanded(Player pPlayer);

};

#endif  // _SQUARE_PENALTY_H