
/**************************************************************************************************

	Project: Basic Monopoly

	   File: Game.cpp

	 Author: Simon Rybicki

	   Date: 15/03/19

	Version: 1.1

	   Info: Implements the monopoly game manager class.

**************************************************************************************************/

#include "Game.hpp"

// Constructor.
// Sets the players and maximum rounds to play.
CGame::CGame()
{
	// Setup the players for the game.
	Player pPlayer1(new CPlayer("P1", PLAYER_NAMES_1[RandomRange(0, 4)], EPlayerType::Human, START_MONEY));
	Player pPlayer2(new CPlayer("P2", PLAYER_NAMES_2[RandomRange(0, 4)], EPlayerType::CPU, START_MONEY, 25));
	Player pPlayer3(new CPlayer("P3", PLAYER_NAMES_3[RandomRange(0, 4)], EPlayerType::CPU, START_MONEY, 50));
	Player pPlayer4(new CPlayer("P4", PLAYER_NAMES_4[RandomRange(0, 4)], EPlayerType::CPU, START_MONEY, 75));
	mpPlayers.push_back(move(pPlayer1));
	mpPlayers.push_back(move(pPlayer2));
	mpPlayers.push_back(move(pPlayer3));
	mpPlayers.push_back(move(pPlayer4));

	// Load the board data from a TXT file.
	Data pDataManager(new CData);
	mDataLoaded = pDataManager->LoadMonopolyData(MONOPOLY_FILE, mpSquares);

	// Check if data has been loaded.
	if (mDataLoaded)
	{
		SeedRandom();
		mMaxPosition = (static_cast<int>(mpSquares.size()) - 1);
		mpDraw = new CDraw();
	}
}

// Destructor.
CGame::~CGame() 
{ 
	delete mpDraw;
	mpDraw = nullptr;
}

// Plays a game of monopoly for a number of rounds or a player loses.
void CGame::Play()
{
	if (mDataLoaded)
	{
		bool quit = false;
		Setup(quit);

		if (quit)
		{
			return;
		}
		
		int roundNum = 1;

		// Main game loop.
		do {

			for (auto& pPlayer : mpPlayers)
			{
				mpDraw->ClearScreen();

				if (pPlayer->GetType() == EPlayerType::Human)
				{
					DisplayBoardPlayers();
					mpDraw->DisplayDice(mDice.mPos, mDice.mFace);
					DisplayRound(roundNum);

					std::cout << "\n";
					for (auto& pPlayer : mpPlayers)
					{
						std::cout << "\n " << pPlayer->GetID() << "  " << pPlayer->GetName() << "  " << POUND << pPlayer->GetMoney();
					}
					std::cout << "\n\n [1] Roll dice \n";

					int input;
					std::cin >> input;

					mpDraw->ClearScreen();
				}

				if ( !HasPlayerLost(pPlayer.get()) )
				{
					RollDice();

					const int oldPos = pPlayer->GetPosition();
					pPlayer = UpdatePlayerPosition(std::move(pPlayer), mDice.mFace);

					DisplayBoardPlayers();
					mpDraw->DisplayDice(mDice.mPos, mDice.mFace);
					DisplayRound(roundNum);
					std::cout << "\n\n " << pPlayer->GetName() << " rolls " << mDice.mFace;

					bool passedGo = (oldPos > pPlayer->GetPosition() ? true : false);
					pPlayer = UpdatePlayerStatus(std::move(pPlayer), passedGo);
				}
				else  // Player has lost.
				{
					DisplayBoardPlayers();
					mpDraw->DisplayDice(mDice.mPos, mDice.mFace);
					DisplayRound(roundNum);
					std::cout << "\n\n " << pPlayer->GetName() << " is BUST";
				}

				Sleep(DELAY);
			}

			roundNum++;

		} while (!HasGameFinished(roundNum));

		End();

		mpDraw->Reset();
	}
	else  // Issue with data.
	{
		std::cout << "\n Error: Unable to load Monopoly board data.";
	}
}

// Sets a new game of Monopoly.
void CGame::Setup(bool& quit)
{
	DisplayBoardEmpty();

	// Display starting message and options.
	std::cout << "\n +------------------+";
	std::cout << "\n    BASIC MONOPOLY   ";
	std::cout << "\n +------------------+";
	std::cout << "\n\n  Welcome to Monopoly.";
	std::cout << "\n\n  [1] New Game";
	std::cout << "\n\n  [2] Quit \n";

	int input;
	std::cin >> input;

	// Check if quit was selected.
	if (input == 2)
	{
		mpDraw->Reset();
		quit = true;
		return;
	}

	mpDraw->ClearScreen();
	DisplayBoardEmpty();

	std::cout << "\n +------------------+";
	std::cout << "\n    BASIC MONOPOLY   ";
	std::cout << "\n +------------------+";
	std::cout << "\n\n  Enter your player name.";
	std::cout << "\n\n  Player 1: ";

	// Get player name.
	std::string name;
	std::cin >> name;

	// Check if name is too long;
	if (name.length() > 10)
	{
		name = name.substr(0, 10);
	}

	// Update the player name.
	mpPlayers[0]->SetName(name);

	mpDraw->ClearScreen();
	DisplayBoardEmpty();

	// Calculate normal and long play rounds.
	const int normalRounds = (MIN_ROUNDS * 2);
	const int longRounds = (MIN_ROUNDS * 3);

	// Display game mode options.
	std::cout << "\n +------------------+";
	std::cout << "\n    BASIC MONOPOLY   ";
	std::cout << "\n +------------------+";
	std::cout << "\n\n  Select a play mode.";
	std::cout << "\n\n  [1] Short  (" << MIN_ROUNDS << " rounds)";
	std::cout << "\n\n  [2] Normal (" << normalRounds << " rounds)";
	std::cout << "\n\n  [3] Long   (" << longRounds << " rounds) \n";

	input;
	std::cin >> input;

	// Check round number selected.
	if (input == 2)
	{
		mMaxRound = normalRounds;
	}
	else if (input == 3)
	{
		mMaxRound = longRounds;
	}
	else  // 1 and default.
	{
		mMaxRound = MIN_ROUNDS;
	}
}

// Displays the final stats and the winner.
void CGame::End()
{
	mpDraw->ClearScreen();
	DisplayBoardEmpty();

	// Display game results.
	std::cout << "\n +------------------+";
	std::cout << "\n      GAME OVER     ";
	std::cout << "\n +------------------+";
	std::cout << "\n\n  Final results: \n";

	for (auto& pPlayer : mpPlayers)
	{
		std::cout << "\n  " << pPlayer->GetID() << "  " << pPlayer->GetName() << "  " << POUND << pPlayer->GetMoney();
	}

	// Find the winner based on the most amount of money.
	int winnerMoney = 0;
	std::string winnerName;
	for (auto& pPlayer : mpPlayers)
	{
		if (pPlayer->GetMoney() > winnerMoney)
		{
			winnerMoney = pPlayer->GetMoney();
			winnerName = pPlayer->GetName();
		}
	}

	// Check if there is a draw.
	int matches = 0;
	for (auto& pPlayer : mpPlayers)
	{
		if (winnerMoney == pPlayer->GetMoney())
		{
			matches += 1;
		}
	}

	// Check if there is no draw.
	if (matches == 1)
	{
		std::cout << "\n\n Winner: " << winnerName;
	}
	else  // Draw.
	{
		std::cout << "\n\n Draw between top players.";
	}

	std::cout << "\n\n ------------------";
	std::cout << "\n\n  [1] Quit\n";

	int input = 0;

	// Check if quit was selected.
	while (input != 1)
	{
		std::cin >> input;
	}
}

// Displays the Monopoly board without any players.
void CGame::DisplayBoardEmpty()
{
	mpDraw->DisplayBoard(0, 0, 0, 0, "", "", "", "");
}

// Displays the Monopoly board with players.
void CGame::DisplayBoardPlayers()
{
	mpDraw->DisplayBoard(
		(mpPlayers[0]->GetPosition() + 1),
		(mpPlayers[1]->GetPosition() + 1),
		(mpPlayers[2]->GetPosition() + 1),
		(mpPlayers[3]->GetPosition() + 1),
		mpPlayers[0]->GetID(),
		mpPlayers[1]->GetID(),
		mpPlayers[2]->GetID(),
		mpPlayers[3]->GetID());
}

// Displays the current round number.
void CGame::DisplayRound(int& roundNum)
{
	std::cout << "\n\n ------------------------------";
	std::cout << "\n           ROUND " << roundNum;
}

// Returns a random number based on a dice (1 to 6).
void CGame::RollDice()
{
	mDice.mPos = RandomDice();
	mDice.mFace = RandomDice();
}

// Updates the player position.
Player CGame::UpdatePlayerPosition(Player pCurrentPlayer, int moveSteps)
{
	int newPosition = (pCurrentPlayer->GetPosition() + moveSteps);

	if (newPosition > mMaxPosition)
	{
		newPosition = ((newPosition - mMaxPosition) - 1);
	}

	pCurrentPlayer->SetPosition(newPosition);

	return move(pCurrentPlayer);
}

// Checks if the player has passed GO.
// Performs an action based on the square landed on.
// Checks if the player needs to mortgage a property.
// Displays the player's remaining money.
// Checks if the player needs to repay a mortgage.
Player CGame::UpdatePlayerStatus(Player pCurrentPlayer, const bool& passedGo)
{
	const int position = pCurrentPlayer->GetPosition();

	std::cout << "\n " << pCurrentPlayer->GetName() << " lands on " << mpSquares[position]->GetName();

	if (passedGo)
	{
		pCurrentPlayer->SetMoney(PASS_GO_MONEY);
		std::cout << "\n " << pCurrentPlayer->GetName() << " passes GO and collects " << POUND << PASS_GO_MONEY;
	}

	pCurrentPlayer = mpSquares[position]->PlayerLanded(move(pCurrentPlayer));
	
	if (pCurrentPlayer->HasMortgage())
	{
		pCurrentPlayer = RepayMortgage(move(pCurrentPlayer));
	}

	std::cout << "\n " << pCurrentPlayer->GetName() << " has " << POUND << pCurrentPlayer->GetMoney();

	if (pCurrentPlayer->InDebt())
	{
		pCurrentPlayer = MortgageProperty(move(pCurrentPlayer));
	}

	return move(pCurrentPlayer);
}

// Player makes an attept to mortgate one or more properties, until they are out of debt,
// or run out of properties to mortgage. If successful, the mortgaged property status will 
// change and the player will be paid the value of the property. The property will be taken 
// off the mortgaged list.
Player CGame::MortgageProperty(Player pCurrentPlayer)
{
	pCurrentPlayer->SetMortgageStatus(true);

	Properties pPlayerOwnedProperties = pCurrentPlayer->GetOwnedProperties();
	Properties pPlayerMortgagedProperties = pCurrentPlayer->GetMortgagedProperties();

	int propertyCount = static_cast<int>(pPlayerOwnedProperties.size());

	while (pCurrentPlayer->InDebt() && propertyCount != 0)
	{
		CSquareProperty* pCheapestProperty = pPlayerOwnedProperties[0];
		int propertyIndex = 0;

		for (int i = 1; i < propertyCount; ++i)
		{
			if (!pPlayerOwnedProperties[i]->IsMortgaged() &&
				pPlayerOwnedProperties[i]->GetCost() < pCheapestProperty->GetCost())
			{
				pCheapestProperty = pPlayerOwnedProperties[i];
				propertyIndex = i;
			}
		}

		pCurrentPlayer->SetMoney(pCheapestProperty->GetCost());

		pCheapestProperty->SetMortgagedStatus(true);
		pPlayerMortgagedProperties.push_back(pCheapestProperty);
		pPlayerOwnedProperties.erase(pPlayerOwnedProperties.begin() + propertyIndex);
		pCurrentPlayer->SetOwnedProperties(pPlayerOwnedProperties);
		pCurrentPlayer->SetMortgagedProperties(pPlayerMortgagedProperties);

		propertyCount -= 1;
	}

	return move(pCurrentPlayer);
}

// Player make an attept to replay the lowest valued property mortgage.
// If successful the mortgaged property status will change and the property will be taken off mortgaged list.
Player CGame::RepayMortgage(Player pCurrentPlayer)
{
	Properties pPlayerOwnedProperties = pCurrentPlayer->GetOwnedProperties();
	Properties pPlayerMortgagedProperties = pCurrentPlayer->GetMortgagedProperties();

	CSquareProperty* pMortgagedProperty = pPlayerMortgagedProperties[0];
	int mortgageCount = static_cast<int>(pPlayerMortgagedProperties.size());
	int propertyIndex = 0;

	for (int i = 1; i < mortgageCount; ++i)
	{
		if (pPlayerMortgagedProperties[i]->GetCost() < pMortgagedProperty->GetCost())
		{
			pMortgagedProperty = pPlayerMortgagedProperties[i];
			propertyIndex = i;
		}
	}

	if (pCurrentPlayer->GetMoney() >= pMortgagedProperty->GetCost())
	{
		pCurrentPlayer->SetMoney(-pMortgagedProperty->GetCost());

		pMortgagedProperty->SetMortgagedStatus(false);
		pPlayerOwnedProperties.push_back(pMortgagedProperty);
		pPlayerMortgagedProperties.erase(pPlayerMortgagedProperties.begin() + propertyIndex);
		pCurrentPlayer->SetOwnedProperties(pPlayerOwnedProperties);
		pCurrentPlayer->SetMortgagedProperties(pPlayerMortgagedProperties);

		if ((mortgageCount - 1) == 0)
		{
			pCurrentPlayer->SetMortgageStatus(false);
		}
	}

	return move(pCurrentPlayer);
}

// Checks if the game has reached the maximum round.
bool CGame::HasGameFinished(int& roundNum)
{
	if (roundNum > mMaxRound)
	{
		return true;
	}

	return false;
}

// Checks if the player is in debt and has a mortgage.
bool CGame::HasPlayerLost(CPlayer* pCurrentPlayer)
{
	if (pCurrentPlayer->InDebt() && pCurrentPlayer->HasMortgage())
	{
		return true;
	}

	return false;
}