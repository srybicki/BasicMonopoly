
/**************************************************************************************************

	Project: Basic Monopoly

	   File: SquareJail.hpp

	 Author: Simon Rybicki

	   Date: 04/03/19

	Version: 1.0

	   Info: Defines the Jail square on the monopoly board.

**************************************************************************************************/

#ifndef _SQUARE_JAIL_H
#define _SQUARE_JAIL_H

#include "Square.hpp"

class CSquareJail : public ISquare
{

public:

	// Constructor. 
	// Sets the type of square and name of the square.
	// Param: Type of square, Name of square.
	// Return:
	CSquareJail(ESquareType squareType, std::string squareName);

	// Destructor.
	// Param: 
	// Return:
	~CSquareJail();

	// Nothing happens to the player.
	// Param: Player (pointer).
	// Return: Player (pointer).
	Player PlayerLanded(Player pPlayer);

};

#endif  // _SQUARE_JAIL_H