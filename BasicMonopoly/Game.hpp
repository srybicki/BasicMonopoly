
/**************************************************************************************************

	Project: Basic Monopoly

	   File: Game.hpp

	 Author: Simon Rybicki

	   Date: 15/03/19

	Version: 1.1

	   Info: Defines a monopoly game manager class.

**************************************************************************************************/

#ifndef _GAME_H
#define _GAME_H

#include "Square.hpp"
#include "Data.hpp"
#include "Draw.hpp"

#include <vector>
#include <memory>

const std::string MONOPOLY_FILE = "Monopoly.txt";           // File name of the monopoly data.
const int MIN_ROUNDS = 20;                                  // Minimum number of rounds to be played before the game ends.
const int START_MONEY = 1500;                               // Amount of money a player will have at the start.
const int PASS_GO_MONEY = 200;                              // Amount of money player gets after passing go.
const int DELAY = 1500;                                     // Wait 1.5 seconds between player turns.

// Define a dice type.
struct SDice
{
	int mPos;
	int mFace;
};

class CGame
{

public:

	// Constructor.
	// Sets the players and maximum rounds to play.
	// Param:
	// Returns:
	CGame();

	// Destructor.
	// Param:
	// Returns:
	~CGame();

	// Plays a game of monopoly for a number of rounds or a player loses.
	// Param:
	// Returns:
	void Play();

private:

	// List of players.
	Players mpPlayers;

	// List of monopoly board sqaures.
	Squares mpSquares;

	// Draw graphics manager.
	CDraw* mpDraw;

	// Game dice.
	SDice mDice;

	// Maximum position on the monopoly board.
	int mMaxPosition;

	// Maximum number of rounds to play.
	int mMaxRound;

	// Flag to see if squares and seed data has been loaded.
	bool mDataLoaded;

	// Sets a new game of Monopoly.
	// Param: Quit flag.
	// Return:
	void Setup(bool& quit);

	// Displays the final stats and the winner.
	// Param:
	// Return:
	void End();

	// Displays the Monopoly board without any players.
	// Param:
	// Return:
	void DisplayBoardEmpty();

	// Displays the Monopoly board with players.
	// Param:
	// Return:
	void DisplayBoardPlayers();

	// Displays the current round number.
	// Param: Current round number.
	// Return:
	void DisplayRound(int& roundNum);

	// Set a random position and facing value for the dice.
	// Param: 
	// Return:
	void RollDice();

	// Updates the player position.
	Player UpdatePlayerPosition(Player pCurrentPlayer, int moveSteps);

	// Checks if the player has passed GO.
	// Performs an action based on the square landed on.
	// Checks if the player needs to mortgage a property.
	// Displays the player's remaining money.
	// Checks if the player needs to repay a mortgage.
	// Param: Current player (pointer), Number of steps to move.
	// Return: Current player (pointer).
	Player UpdatePlayerStatus(Player pCurrentPlayer, const bool& passedGo);

	// Player make an attept to mortgate one or more properties, until they are out of debt 
	// or run out of properties to mortgage. If successful the mortgaged property status will change 
	// and the player will be paid the value of the property. The property will be taken off mortgaged list.
	// Param: Current player (pointer).
	// Return: Current player (pointer).
	Player MortgageProperty(Player pCurrentPlayer);

	// Player make an attept to replay the lowest valued property mortgage.
	// If successful the mortgaged property status will change and the property will be taken off mortgaged list.
	// Param: Current player (pointer).
	// Return: Current player (pointer).
	Player RepayMortgage(Player pCurrentPlayer);

	// Checks if the game has reached the maximum round.
	// Param: Current round number.
	// Return: True if final round complete.
	bool HasGameFinished(int& roundNum);

	// Checks if the player is in debt and has a mortgage.
	// Param: Current player (pointer).
	// Return: True if the player has lost.
	bool HasPlayerLost(CPlayer* pCurrentPlayer);
};

// Define a game smart pointer.
using Game = std::unique_ptr<CGame>;

#endif  // _GAME_H