
/**************************************************************************************************

	Project: Basic Monopoly

	   File: Player.hpp

	 Author: Simon Rybicki

	   Date: 10/03/19

	Version: 1.0

	   Info: Defines a player object.

**************************************************************************************************/

#ifndef _PLAYER_H
#define _PLAYER_H

#include "Utility.hpp"
#include "Property.hpp"

#include <string>

// List of player type names.
const std::string PLAYER_NAMES_1[5] =
{
	"Alex",
	"Ben",
	"John",
	"Lucy",
	"Amy"
};

const std::string PLAYER_NAMES_2[5] =
{
	"Claire",
	"James",
	"Fred",
	"Jim",
	"Ryan"
};

const std::string PLAYER_NAMES_3[5] =
{
	"Brian",
	"Sarah",
	"Jack",
	"Racheal",
	"Amber"
};

const std::string PLAYER_NAMES_4[5] =
{
	"Anne",
	"Rose",
	"Max",
	"Henry",
	"Tony"
};

// Define the type of player.
enum EPlayerType
{
	Human, CPU
};

class CPlayer
{

public:

	// Constructor. 
	// Sets the new player's ID, name, type, starting money and buying rate.
	// Param: ID, Name, Type, Money.
	// Return:
	CPlayer(const std::string id, const std::string name, const EPlayerType type, 
		    const int startMoney, const int buyRate = 100);

	// Destructor.
	// Param:
	// Return:
	~CPlayer();

	// Gets the player ID.
	// Param:
	// Return: Player ID.
	const std::string GetID();

	// Set the name of the player.
	// Param: Name.
	// Return:
	void SetName(const std::string name);

	// Gets the name of the player.
	// Param:
	// Return: Player name.
	std::string GetName();

	// Get the type of the player.
	// Param:
	// Return: Player type.
	const EPlayerType GetType();
	
	// Sets the money for the player.
	// Param: Amount of money to give or take from the player's current money.
	// Return:
	void SetMoney(int amount);
	
	// Gets the money the player has.
	// Param:
	// Return: Player money.
	int GetMoney();

	// Get the buying rate value.
	// Param:
	// Return: Buy rate.
	int GetBuyRate();

	// Checks to see if the player has a negative amount of money.
	// Param:
	// Return: True if the player money is negative.
	bool InDebt();
	
	// Sets the position of the player on the board.
	// Param: New postion on the board.
	// Return:
	void SetPosition(int position);
	
	// Gets the position of the player on the board.
	// Param:
	// Return: Player position on the board.
	int GetPosition();

	// Gets the number of properties of a group.
	// Param: Type of property group.
	// Return: Number of properties owned for the group.
	int GetPropertyCount(EPropertyGroup propertyGroup);

	// Checks to see if the player has a mortgage.
	// Param:
	// Return: True if the player has a mortgage.
	bool HasMortgage();
	
	// Sets the player mortgage status.
	// Param: Mortgage status.
	// Return:
	void SetMortgageStatus(bool status);

	// Adds the property to the owned list, deducts the cost from the player's money, 
	// increaces the property group count.
	// Param: Property (pointer), Property cost, Property group type.
	// Return:
	void BuyProperty(CSquareProperty* pProperty, int propertyCost, EPropertyGroup propertyGroup);

	// Gets a list of properties that are owned by the player and not mortgaged.
	// Param:
	// Return: List of properties.
	Properties GetOwnedProperties();
	
	// Set a list of properties that are owned by the player and not mortgaged.
	// Param: Property list.
	// Return:
	void SetOwnedProperties(Properties pOwnedProperties);

	// Gets a list of properties that are mortgaged.
	// Param:
	// Return: List of mortgaged properties.
	Properties GetMortgagedProperties();

	// Sets a list of properties that are mortgaged.
	// Param: Property list.
	// Return:
	void SetMortgagedProperties(Properties pMortgagedProperties);

private:

	// ID of player.
	std::string mID;

	// Name of the player.
	std::string mName;

	// Type of player.
	EPlayerType mType;

	// Amount of money the player has.
	int mMoney;

	// Rate of buying a property (CPU only).
	int mBuyRate;
	
	// Position of the player on the monopoly board.
	int mPosition;

	// Count of properties the player owns in each group.
	int mProperties[MAX_GROUPS] = {0};

	// Flag for the player mortgage status.
	bool mMortgageStatus;

	// List of player owned properties that are not mortgaged.
	Properties mpOwnedProperties;
	
	// List of player properties that are mortgaged.
	Properties mpMortgagedProperties;
};

// Define a player smart pointer.
using Player = std::unique_ptr<CPlayer>;

// Define a list of player smart pointers.
using Players = std::vector<std::unique_ptr<CPlayer>>;

#endif  // _PLAYER_H