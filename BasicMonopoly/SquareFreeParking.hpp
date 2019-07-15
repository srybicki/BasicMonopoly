
/**************************************************************************************************

	Project: Basic Monopoly

	   File: SquareFreeParking.hpp

	 Author: Simon Rybicki

	   Date: 04/03/19

	Version: 1.0

	   Info: Defines the Free Parking square on the monopoly board.

**************************************************************************************************/

#ifndef _SQUARE_FREE_PARKING_H
#define _SQUARE_FREE_PARKING_H

#include "Square.hpp"

class CSquareFreeParking : public ISquare
{

public:

	// Constructor. 
	// Sets the type of square and name of the square.
	// Param: Type of square, Name of square.
	// Return:
	CSquareFreeParking(ESquareType squareType, std::string squareName);

	// Destructor.
	// Param: 
	// Return:
	~CSquareFreeParking();

	// Nothing happens to the player.
	// Param: Player (pointer).
	// Return: Player (pointer).
	Player PlayerLanded(Player pPlayer);

};

#endif  // _SQUARE_FREE_PARKING_H