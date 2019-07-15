
/**************************************************************************************************

	Project: Basic Monopoly

	   File: Square.hpp

	 Author: Simon Rybicki

	   Date: 04/03/19

	Version: 1.0

	   Info: Interface for all square type classes.

**************************************************************************************************/

#ifndef _SQUARE_H
#define _SQUARE_H

#include "Player.hpp"

// List of square types that are on the monopoly board.
enum ESquareType
{
	Property = 1,
	Go = 2,
	Airport = 3,
	Bonus = 4,
	Penalty = 5,
	Jail = 6,
	GoToJail = 7,
	FreeParking = 8
};

class ISquare
{

public:

	// Destructor.
	// Param: 
	// Return:
	virtual ~ISquare() { }

	// Gets the type of square.
	// Param: 
	// Return:
	virtual ESquareType GetType()
	{
		return mType;
	};

	// Gets the name of the square.
	// Param: 
	// Return:
	virtual std::string GetName()
	{
		return mName;
	};

	// Performs an event unique to the type of square the player has laneded on.
	// Param: Player (pointer).
	// Return: Player (pointer).
	virtual Player PlayerLanded(Player pPlayer) = 0;

protected:

	// Type of square on the monopoly board.
	ESquareType mType;

	// Name of the square.
	std::string mName;

};

// Define a square smart pointer.
using Square = std::unique_ptr<ISquare>;

// Defines a list of square smart pointers.
using Squares = std::vector<std::unique_ptr<ISquare>>;

#endif  // _SQUARE_H