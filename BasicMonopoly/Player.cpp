
/**************************************************************************************************

	Project: Basic Monopoly

	   File: Player.cpp

	 Author: Simon Rybicki

	   Date: 10/03/19

	Version: 1.1

	   Info: Implements a player object.

**************************************************************************************************/

#include "Player.hpp"

// Constructor.
// Sets the new player's ID, name, type and starting money.
CPlayer::CPlayer(std::string id, const std::string name, const EPlayerType type, 
	             const int startMoney, const int buyRate)
{
	mID = id;
	mName = name;
	mType = type;
	mMoney = startMoney;
	mBuyRate = buyRate;
	mPosition = 0;
	mMortgageStatus = false;
}

// Destructor.
CPlayer::~CPlayer() { }

// Gets the player ID.
const std::string CPlayer::GetID()
{
	return mID;
}

// Set the name of the player.
void CPlayer::SetName(const std::string name)
{
	mName = name;
}

// Gets the name of the player.
std::string CPlayer::GetName()
{
	return mName;
}

// Get the type of the player.
const EPlayerType CPlayer::GetType()
{
	return mType;
}

// Sets the money for the player.
void CPlayer::SetMoney(int amount)
{
	mMoney += amount;
}

// Gets the money the player has.
int CPlayer::GetMoney()
{
	return mMoney;
}

// Get the buying rate value.
int CPlayer::GetBuyRate()
{
	return mBuyRate;
}

// Checks to see if the player has a negative amount of money.
bool CPlayer::InDebt()
{
	if (mMoney < 0)
	{
		return true;
	}

	return false;
}

// Checks to see if the player has a mortgage.
bool CPlayer::HasMortgage()
{
	return mMortgageStatus;
}

// Sets the player mortgage status.
void CPlayer::SetMortgageStatus(bool status)
{
	mMortgageStatus = status;
}

// Sets the position of the player on the board.
void CPlayer::SetPosition(int position)
{
	mPosition = position;
}

// Gets the position of the player on the board.
int CPlayer::GetPosition()
{
	return mPosition;
}

// Adds the property to the owned list, deducts the cost from the player's money, 
// increaces the property group count.
void CPlayer::BuyProperty(CSquareProperty* pProperty, int propertyCost, EPropertyGroup propertyGroup)
{
	mMoney -= propertyCost;
	mpOwnedProperties.push_back(pProperty);
	mProperties[propertyGroup] += 1;
}

// Gets the number of properties of a group.
int CPlayer::GetPropertyCount(EPropertyGroup propertyGroup)
{
	return mProperties[propertyGroup];
}

// Gets a list of properties that are owned by the player and not mortgaged.
Properties CPlayer::GetOwnedProperties()
{
	return mpOwnedProperties;
}

// Set a list of properties that are owned by the player and not mortgaged.
void CPlayer::SetOwnedProperties(Properties pOwnedProperties)
{
	mpOwnedProperties = pOwnedProperties;
}

// Gets a list of properties that are mortgaged.
Properties CPlayer::GetMortgagedProperties()
{
	return mpMortgagedProperties;
}

// Sets a list of properties that are mortgaged.
void CPlayer::SetMortgagedProperties(Properties pMortgagedProperties)
{
	mpMortgagedProperties = pMortgagedProperties;
}