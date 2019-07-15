
/**************************************************************************************************

	Project: Basic Monopoly

	   File: BasicMonopoly.cpp

	 Author: Simon Rybicki

	   Date: 10/03/19

	Version: 1.0

	   Info: Entry point of the program.
			 Creates a new game of Monopoly and plays.

**************************************************************************************************/

#include "Game.hpp"

int main()
{
	// Setup a new game of Monopoly and play.
	Game monopolyGame(new CGame);
	monopolyGame->Play();

	// Pause program.
	std::cout << "\n";
	getchar();  

	return EXIT_SUCCESS;
}