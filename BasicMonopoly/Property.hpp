
/**************************************************************************************************

	Project: Basic Monopoly

	   File: Property.hpp

	 Author: Simon Rybicki

	   Date: 10/03/19

	Version: 1.0

	   Info: Lists all property groups and totals.

**************************************************************************************************/

#ifndef _PROPERTY_H
#define _PROPERTY_H

#include <vector>

// List of total number of properties for each group.
const int TOTAL_RED_GROUP = 2;
const int TOTAL_GREY_GROUP = 2;
const int TOTAL_BROWN_GROUP = 2;
const int TOTAL_ORANGE_GROUP = 3;
const int TOTAL_YELLOW_GROUP = 2;
const int TOTAL_GREEN_GROUP = 2;
const int TOTAL_BLUE_GROUP = 3;
const int TOTAL_PURPLE_GROUP = 2;

// Maximum number of property groups.
const int MAX_GROUPS = 8;

// Collection of all the property group totals 
// (index based on group type number 0..7).
const int GROUP_PROPERTY_TOTALS[MAX_GROUPS]
{
	TOTAL_RED_GROUP,
	TOTAL_GREY_GROUP,
	TOTAL_BROWN_GROUP,
	TOTAL_ORANGE_GROUP,
	TOTAL_YELLOW_GROUP,
	TOTAL_GREEN_GROUP,
	TOTAL_BLUE_GROUP,
	TOTAL_PURPLE_GROUP
};

// List of property group types with index number.
enum EPropertyGroup
{
	Red = 0,
	Grey = 1,
	Brown = 2,
	Orange = 3,
	Yellow = 4,
	Green = 5,
	Blue = 6,
	Purple = 7
};

// IMPORTANT: Forward declaration so the compiler knows about the property square.
class CSquareProperty;

// List of properties owned or morgaged by the player.
using Properties = std::vector<CSquareProperty*>;

#endif  // _PROPERTY_H