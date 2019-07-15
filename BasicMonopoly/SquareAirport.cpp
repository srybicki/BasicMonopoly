
/**************************************************************************************************

	Project: Basic Monopoly

	   File: SquareAirport.cpp

	 Author: Simon Rybicki

	   Date: 04/03/19

	Version: 1.0

	   Info: Implements the Airport square on the monopoly board.

**************************************************************************************************/

#include "SquareAirport.hpp"

// Constructor. 
// Sets the type of square and name of the square.
// Marks the airport as not owned and no player owner.
CSquareAirport::CSquareAirport(ESquareType squareType, std::string squareName)
{
	mType = squareType;
	mName = squareName;
	mIsOwned = false;
	mpOwner = nullptr;
}

// Destructor.
CSquareAirport::~CSquareAirport() { }

// Checks if the airport is owned.
// Player will buy the airport if they are not in debt.
// Or the player will pay a fee if the airport is already owned.
Player CSquareAirport::PlayerLanded(Player pPlayer)
{
	if (!mIsOwned)
	{
		if (!pPlayer->InDebt() && !pPlayer->HasMortgage())
		{
			if (pPlayer->GetType() == EPlayerType::CPU)
			{
				if (RandomRange(1, 100) > pPlayer->GetBuyRate())
				{
					pPlayer->SetMoney(-AIRPORT_PRICE);
					std::cout << "\n " << pPlayer->GetName() << " buys " << mName << " for " << POUND << AIRPORT_PRICE;

					mIsOwned = true;
					mpOwner = pPlayer.get();
				}
			}
			else if (pPlayer->GetType() == EPlayerType::Human)
			{
				std::cout << "\n\n Buy airport " << mName << " for " << POUND << AIRPORT_PRICE << "?";
				std::cout << "\n\n [1] Yes";
				std::cout << "\n\n [2] No \n";

				int input;
				std::cin >> input;

				if (input == 1)
				{
					pPlayer->SetMoney(-AIRPORT_PRICE);

					mIsOwned = true;
					mpOwner = pPlayer.get();
				}
			}
		}
	}
	else if (pPlayer.get() != mpOwner)
	{
		pPlayer->SetMoney(-AIRPORT_FEE);
		mpOwner->SetMoney(AIRPORT_FEE);
		std::cout << "\n " << pPlayer->GetName() << " pays " << POUND << AIRPORT_FEE << " of goods";
	}
	else if (pPlayer.get() == mpOwner)
	{
		std::cout << "\n " << pPlayer->GetName() << " owns " << mName;
	}

	return move(pPlayer);
}