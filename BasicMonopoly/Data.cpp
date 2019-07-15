
/**************************************************************************************************

	Project: Basic Monopoly

	   File: Data.cpp

	 Author: Simon Rybicki

	   Date: 04/03/19

	Version: 1.1

	   Info: Implements a data manager class.

**************************************************************************************************/

#include "Data.hpp"

// Constructor.
CData::CData() { }

// Destructor.
CData::~CData() { }

// Reads the monopoly board data from a file.
// Creates all the sqaure objects on the monopoly board.
bool CData::LoadMonopolyData(std::string fileName, Squares& pBoardSquares)
{
	if (!FileExists(fileName))
	{
		std::cout << "\n Error: Unable to find " << fileName;
		return BAD_READ;
	}

	std::ifstream monopolyFile(fileName);

	if (!monopolyFile.is_open())
	{
		std::cout << "\n Error: Unable to open " << fileName;
		return BAD_READ;
	}
	else
	{
		std::string readLine;
		std::istringstream readLineStream;
		int squareType;

		while (std::getline(monopolyFile, readLine))
		{
			readLineStream.str(readLine);
			readLineStream >> squareType;
			pBoardSquares.push_back(CreateSquare(static_cast<ESquareType>(squareType), readLineStream));

			readLineStream.str("");
			readLineStream.clear();
		}

		monopolyFile.close();

		return GOOD_READ;
	}
}

// Checks if a file is accessible.
bool CData::FileExists(std::string fileName)
{
	const std::ifstream file(fileName);

	return file.good();
}