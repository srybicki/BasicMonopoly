
/**************************************************************************************************

	Project: Basic Monopoly

	   File: SquareFactory.hpp

	 Author: Simon Rybicki

	   Date: 04/03/19

	Version: 1.0

	   Info: Defines a square factory to create square objects.

**************************************************************************************************/

#ifndef _SQUARE_FACTORY_H
#define _SQUARE_FACTORY_H

#include "SquareProperty.hpp"
#include "SquareGo.hpp"
#include "SquareAirport.hpp"
#include "SquareBonus.hpp"
#include "SquarePenalty.hpp"
#include "SquareJail.hpp"
#include "SquareGoToJail.hpp"
#include "SquareFreeParking.hpp"

#include <memory>
#include <sstream>

// Creates a new monopoly board square based on the type of square.
// Param: Type of square, Square data from read file.
// Return: Square (pointer).
Square CreateSquare(ESquareType squareType, std::istringstream& readLineStream);

#endif  // _SQUARE_FACTORY_H