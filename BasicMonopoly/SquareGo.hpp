
/**************************************************************************************************

	Project: Basic Monopoly

	   File: SquareGo.hpp

	 Author: Simon Rybicki

	   Date: 04/03/19

	Version: 1.0

	   Info: Defines the GO square on the monopoly board.

**************************************************************************************************/

#ifndef _SQUARE_GO_H
#define _SQUARE_GO_H

#include "Square.hpp"

class CSquareGo : public ISquare
{

public:

	// Constructor. 
	// Sets the type of square and name of the square.
	// Param: Type of square, Name of square.
	// Return:
	CSquareGo(ESquareType squareType, std::string squareName);

	// Destructor.
	// Param: 
	// Return:
	~CSquareGo();

	// Nothing happens to the player.
	// Param: Player (pointer).
	// Return: Player (pointer).
	Player PlayerLanded(Player pPlayer);

};

#endif  // _SQUARE_GO_H