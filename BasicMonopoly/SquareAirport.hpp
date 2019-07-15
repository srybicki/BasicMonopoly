
/**************************************************************************************************

	Project: Basic Monopoly

	   File: SquareAirport.hpp

	 Author: Simon Rybicki

	   Date: 04/03/19

	Version: 1.0

	   Info: Defines the Airport square on the monopoly board.

**************************************************************************************************/

#ifndef _SQUARE_AIRPORT_H
#define _SQUARE_AIRPORT_H

#include "Square.hpp"

const int AIRPORT_PRICE = 200;  // Cost to buy any airport on the board.
const int AIRPORT_FEE = 10;     // Fee to pay for an airport that is owned by another player.

class CSquareAirport : public ISquare
{

public:

	// Constructor. 
    // Sets the type of square and name of the square.
	// Marks the airport as not owned and no player owner.
	// Param: Type of square, Name of square.
	// Return:
	CSquareAirport(ESquareType squareType, std::string squareName);

	// Destructor.
	// Param: 
	// Return:
	~CSquareAirport();

	// Checks if the airport is owned.
	// Player will buy the airport if they are not in debt.
	// Or the player will pay a fee if the airport is already owned.
	// Param: Player (pointer).
	// Return: Player (pointer).
	Player PlayerLanded(Player pPlayer);

private:

	// Flag to mark if the airport is owned by a player.
	bool mIsOwned;

	// The player (pointer) that owns the airport.
	CPlayer* mpOwner;

};

#endif  // _SQUARE_AIRPORT_H