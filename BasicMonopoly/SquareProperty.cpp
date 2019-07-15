
/**************************************************************************************************

	Project: Basic Monopoly

	   File: SquareProperty.cpp

	 Author: Simon Rybicki

	   Date: 04/03/19

	Version: 1.0

	   Info: Implements the Property square on the monopoly board.

**************************************************************************************************/

#include "SquareProperty.hpp"

// Constructor. 
// Sets the type of square and name of the square.
// Sets the cost, rent, group type of the property.
// Marks the property as not owned and no player owner.
CSquareProperty::CSquareProperty(ESquareType squareType, std::string sqaureName, int squareCost,
	                             int squareRent, EPropertyGroup propertyGroup)
{
	mType = squareType;
	mName = sqaureName;
	mCost = squareCost;
	mRent = squareRent;
	mGroup = propertyGroup;
	mIsOwned = false;
	mpOwner = nullptr;
	mIsMortgaged = false;
}

// Destructor.
CSquareProperty::~CSquareProperty() { }

// Checks if the property is owned.
// Player will buy the property if they are not in debt.
// Or the player will pay a fee if the property is already owned and is not mortgaged.
Player CSquareProperty::PlayerLanded(Player pPlayer)
{
	if (!mIsOwned)
	{
		if (!pPlayer->InDebt() && !pPlayer->HasMortgage())
		{
			if (pPlayer->GetType() == EPlayerType::CPU)
			{
				if (RandomRange(1, 100) > pPlayer->GetBuyRate())
				{
					pPlayer->BuyProperty(this, mCost, mGroup);
					std::cout << "\n " << pPlayer->GetName() << " buys " << mName << " for " << POUND << mCost;

					mIsOwned = true;
					mpOwner = pPlayer.get();
				}
				else
				{
					std::cout << "\n " << pPlayer->GetName() << " ignores " << mName << " for " << POUND << mCost;
				}
			}
			else if (pPlayer->GetType() == EPlayerType::Human)
			{
				std::cout << "\n\n Buy property " << mName << " for " << POUND << mCost << "?";
				std::cout << "\n\n [1] Yes";
				std::cout << "\n\n [2] No \n";

				int input;
				std::cin >> input;

				if (input == 1)
				{
					pPlayer->BuyProperty(this, mCost, mGroup);

					mIsOwned = true;
					mpOwner = pPlayer.get();
				}
			}
		}
	}
	else if (pPlayer.get() != mpOwner && !mIsMortgaged)
	{
		int rentPay = mRent;

		if (mpOwner->GetPropertyCount(mGroup) == GROUP_PROPERTY_TOTALS[mGroup])
		{
			rentPay *= DOUBLE_RENT;
		}

		pPlayer->SetMoney(-rentPay);
		mpOwner->SetMoney(rentPay);
		std::cout << "\n " << pPlayer->GetName() << " pays " << POUND << rentPay;
	}
	else if (pPlayer.get() == mpOwner)
	{
		std::cout << "\n " << pPlayer->GetName() << " owns " << mName;
	}

	return move(pPlayer);
}

// Gets the cost of the property.
int CSquareProperty::GetCost()
{
	return mCost;
}

// Checks if the property is mortgaged.
bool CSquareProperty::IsMortgaged()
{
	return mIsMortgaged;
}

// Sets the mortgage status of the property.
void CSquareProperty::SetMortgagedStatus(bool status)
{
	mIsMortgaged = status;
}