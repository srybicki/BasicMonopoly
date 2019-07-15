
/**************************************************************************************************

	Project: Basic Monopoly

	   File: Data.hpp

	 Author: Simon Rybicki

	   Date: 04/03/19

	Version: 1.1

	   Info: Defines a data manager class.

**************************************************************************************************/

#ifndef _DATA_H
#define _DATA_H

#include "SquareFactory.hpp"

#include <fstream>

const bool BAD_READ = false;  // Represents a failed file read.
const bool GOOD_READ = true;  // Represents a successful file read.

class CData
{

public:

	// Constructor.
	// Param:
	// Return:
	CData();

	// Destructor.
	// Param:
	// Return:
	~CData();

	// Reads the monopoly board data from a file.
	// Creates all the sqaure objects on the monopoly board.
	// Param: Name of monopoly file, Monopoly board squares list.
	// Return: True if file read is successful.
	bool LoadMonopolyData(std::string fileName, Squares& pBoardSquares);

private:

	// Checks if a file is accessible.
	// Param: Name of file.
	// Return: True if file is accessible.
	bool FileExists(std::string fileName);

};

// Defines a data smart pointer.
using Data = std::unique_ptr<CData>;

#endif  // _DATA_H