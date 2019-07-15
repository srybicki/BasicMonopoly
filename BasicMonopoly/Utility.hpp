
/**************************************************************************************************

	Project: Basic Monopoly

	   File: Utility.hpp

	 Author: Simon Rybicki

	   Date: 10/03/19

	Version: 1.1

	   Info: Contains ascii code for pound sign, 
	         the random seed and random number functions.

**************************************************************************************************/

#ifndef _UTILITY_H
#define _UTILITY_H

#include <iostream>
#include <ctime>

static const unsigned char POUND = 156;  // Pound sign character ascii value.

// Sets the random seed value.
// Param:
// Return:
static void SeedRandom()
{
	srand(static_cast<unsigned int>(time(NULL)));
}

// Generates a random number in the range 1 .. 6
// Param:
// Return: Random number.
static int RandomDice()
{
	return static_cast<int>(static_cast<double> (rand()) / (RAND_MAX + 1) * 6.0f + 1);
}

// Generates a random number in a range.
// Param: Lowest number, Highest number.
// Return: Random number.
static int RandomRange(const int min, const int max)
{
	return ((rand() % (max - min + 1)) + min);
}

#endif  // _UTILITY_H