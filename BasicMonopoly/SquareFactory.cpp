
/**************************************************************************************************

	Project: Basic Monopoly

	   File: SquareFactory.cpp

	 Author: Simon Rybicki

	   Date: 04/03/19

	Version: 1.0

	   Info: Implements square factory to create square objects.

**************************************************************************************************/

#include "SquareFactory.hpp"

// Creates a new monopoly board square based on the type of square.
Square CreateSquare(ESquareType squareType, std::istringstream& readLineStream)
{
	switch (squareType)
	{
		case Property:
		{
			std::string squareName;
			std::string namePart;
			int cost;
			int rent;
			int group;

			readLineStream >> squareName;
			squareName.append(" ");
			readLineStream >> namePart;
			squareName.append(namePart);
			readLineStream >> cost;
			readLineStream >> rent;
			readLineStream >> group;

			Square pPropertySquare(new CSquareProperty(squareType, squareName, cost, rent, static_cast<EPropertyGroup>(group)));
			return move(pPropertySquare);
		}
		case Go:
		{
			std::string squareName;
			readLineStream >> squareName;

			Square pGoSquare(new CSquareGo(squareType, squareName));
			return std::move(pGoSquare);
		}
		case Airport:
		{
			std::string squareName;
			std::string namePart;

			readLineStream >> squareName;
			squareName.append(" ");
			readLineStream >> namePart;
			squareName.append(namePart);

			Square pAirportSquare(new CSquareAirport(squareType, squareName));
			return std::move(pAirportSquare);
		}
		case Bonus:
		{
			std::string squareName;
			readLineStream >> squareName;

			Square pBonusSquare(new CSquareBonus(squareType, squareName));
			return std::move(pBonusSquare);
		}
		case Penalty:
		{
			std::string squareName;
			readLineStream >> squareName;

			Square pPenaltySquare(new CSquarePenalty(squareType, squareName));
			return std::move(pPenaltySquare);
		}
		case Jail:
		{
			std::string squareName;
			readLineStream >> squareName;

			Square pJailSquare(new CSquareJail(squareType, squareName));
			return std::move(pJailSquare);
		}
		case GoToJail:
		{
			std::string squareName;
			std::string namePart;

			readLineStream >> squareName;
			squareName.append(" ");
			readLineStream >> namePart;
			squareName.append(namePart);
			squareName.append(" ");
			readLineStream >> namePart;
			squareName.append(namePart);

			Square pGoToJailSquare(new CSquareGoToJail(squareType, squareName));
			return std::move(pGoToJailSquare);
		}
		case FreeParking:
		{
			std::string squareName;
			std::string namePart;

			readLineStream >> squareName;
			squareName.append(" ");
			readLineStream >> namePart;
			squareName.append(namePart);

			Square pFreeParkingSquare(new CSquareFreeParking(squareType, squareName));
			return std::move(pFreeParkingSquare);
		}
		default:
			return nullptr;
	}
}