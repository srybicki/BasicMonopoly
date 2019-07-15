
/**************************************************************************************************

	Project: Basic Monopoly

	   File: SquareBonus.hpp

	 Author: Simon Rybicki

	   Date: 04/03/19

	Version: 1.0

	   Info: Defines the Bonus square on the monopoly board.

**************************************************************************************************/

#ifndef _SQUARE_BONUS_H
#define _SQUARE_BONUS_H

#include "Square.hpp"

// Defines a bonus event type.
struct SBonusEvent
{
	std::string mDescription;
	int mMoney;
};

// Maximum number of bonuses.
const int MAX_BONUSES = 6;

// List of different bonus events.
const SBonusEvent BONUS_EVENTS[MAX_BONUSES] =
{
	{ "Find some money. Player gains ",  20 },
	{ "Win competition. Player gains ",  50 },
	{ "Tax rebate. Player gains ",      100 },
	{ "Win lottery. Player gains ",     150 },
	{ "Bequest. Player gains ",         200 },
	{ "Birthday. Player gains ",        300 }
};

class CSquareBonus : public ISquare
{

public:

	// Constructor. 
	// Sets the type of square and name of the square.
	// Param: Type of square, Name of square.
	// Return:
	CSquareBonus(ESquareType squareType, std::string squareName);

	// Destructor.
	// Param: 
	// Return:
	~CSquareBonus();

	// Creates a random bonus event.
	// Player recieves money from the bonus event.
	// Param: Player (pointer).
	// Return: Player (pointer).
	Player PlayerLanded(Player pPlayer);

};

#endif  // _SQUARE_BONUS_H