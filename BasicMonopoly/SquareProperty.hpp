
/**************************************************************************************************

	Project: Basic Monopoly

	   File: SquareProperty.hpp

	 Author: Simon Rybicki

	   Date: 04/03/19

	Version: 1.0

	   Info: Defines the Property square on the monopoly board.

**************************************************************************************************/

#ifndef _SQUARE_PROPERTY_H
#define _SQUARE_PROPERTY_H

#include "Square.hpp"

const int DOUBLE_RENT = 2;  // Multiplier for a standard rent cost.

class CSquareProperty : public ISquare
{

public:

	// Constructor. 
	// Sets the type of square and name of the square.
	// Sets the cost, rent, group type of the property.
	// Marks the property as not owned and no player owner.
	// Marks the property as not mortgaged.
	// Param: Type of square, Name of square.
	// Return:
	CSquareProperty(ESquareType squareType, std::string sqaureName, int squareCost, int squareRent,
		            EPropertyGroup propertyGroup);

	// Destructor.
	// Param: 
	// Return:
	~CSquareProperty();

	// Checks if the property is owned.
	// Player will buy the property if they are not in debt.
	// Or the player will pay a fee if the property is already owned.
	// Param: Player (pointer).
	// Return: Player (pointer).
	Player PlayerLanded(Player pPlayer);

	// Gets the cost of the property.
	// Param:
	// Return: Property cost.
	int GetCost();

	// Checks if the property is mortgaged.
	// Param:
	// Return: True if the property is mortgaged.
	bool IsMortgaged();

	// Sets the mortgage status of the property.
	// Param: Mortgage status.
	// Return:
	void SetMortgagedStatus(bool status);

private:

	// Cost of the property.
	int mCost;

	// Rest price of the property.
	int mRent;

	// Group type of the property.
	EPropertyGroup mGroup;

	// Flag to mark if the property is owned by a player.
	bool mIsOwned;

	// Player (pointer) that owns the property.
	CPlayer* mpOwner;

	// Flag to mark if the property is mortgaged.
	bool mIsMortgaged;

};

#endif  // _SQUARE_PROPERTY_H