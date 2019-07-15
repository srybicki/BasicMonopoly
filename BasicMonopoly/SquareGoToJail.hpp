
/**************************************************************************************************

	Project: Basic Monopoly

	   File: SquareGoToJail.hpp

	 Author: Simon Rybicki

	   Date: 04/03/19

	Version: 1.0

	   Info: Defines the Go To Jail square on the monopoly board.

**************************************************************************************************/

#ifndef _SQUARE_GO_TO_JAIL_H
#define _SQUARE_GO_TO_JAIL_H

#include "Square.hpp"

const int JAIL_POSITION = 6;  // Position of the jail square on the monopoly board.
const int JAIL_FEE = 50;      // Fee to pay for going to jail.

class CSquareGoToJail : public ISquare
{

public:

	// Constructor. 
	// Sets the type of square and name of the square.
	// Param: Type of square, Name of square.
	// Return:
	CSquareGoToJail(ESquareType squareType, std::string squareName);

	// Destructor.
	// Param: 
	// Return:
	~CSquareGoToJail();

	// Player moves to the jail position on the monopoly board.
	// Player loses some money.
	// Param: Player (pointer).
	// Return: Player (pointer).
	Player PlayerLanded(Player pPlayer);

};

#endif  // _SQUARE_GO_TO_JAIL_H