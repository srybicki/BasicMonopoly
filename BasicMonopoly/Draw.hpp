
/**************************************************************************************************

	Project: Basic Monopoly

	   File: Draw.hpp

	 Author: Simon Rybicki

	   Date: 30/03/19

	Version: 1.0

	   Info: Defines a draw manager class.

**************************************************************************************************/

#ifndef _DRAW_H
#define _DRAW_H

#include <iostream>
#include <string>
#include <Windows.h>

const char S_CELL = 219;
const char V_LINE = 179;
const char H_LINE = 95;
const char DICE_TL = 201;
const char DICE_TR = 187;
const char DICE_BR = 188;
const char DICE_BL = 200;
const char DICE_V = 186;
const char DICE_H = 205;

const std::string PADDING_LEFT = "  ";
const std::string PADDING_TOP = "\n";
const std::string DICE_PADDING_1 = "              ";
const std::string DICE_PADDING_2 = "                           ";
const std::string DICE_PADDING_3 = "                                        ";
const std::string DICE_PADDING_4 = "                                                     ";
const std::string DICE_PADDING_5 = "                                                                  ";
const std::string DICE_PADDING_6 = "                                                                               ";

const int BOARD_POSITIONS[26] = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26 };

class CDraw
{

public:

	// Constructor.
	// Setup drawing in the console window.
	CDraw();

	// Destructor.
	~CDraw();

	// Clears all printed characters and moves the cursor position back to start.
	void ClearScreen();

	// Draws the Monopoly board.
	void DisplayBoard(
		const int& player1Pos, const int& player2Pos, 
		const int& player3Pos, const int& player4Pos,
		const std::string player1ID, const std::string player2ID, 
		const std::string player3ID, const std::string player4ID);

	// Draws the dice.
	void DisplayDice(const int& dicePos, const int& diceFace);

	// Clean up.
	void Reset();

private:

	HANDLE mHstdin;

	HANDLE mHstdout;

	CONSOLE_SCREEN_BUFFER_INFO mCsbi;

	// Draw calls for each row in the monopoly board.
	void DrawRow1(const int& player1Pos, const int& player2Pos, const int& player3Pos, const int& player4Pos,
		const std::string player1ID, const std::string player2ID, const std::string player3ID, const std::string player4ID);
	void DrawRow2(const int& player1Pos, const int& player2Pos, const int& player3Pos, const int& player4Pos,
		const std::string player1ID, const std::string player2ID, const std::string player3ID, const std::string player4ID);
	void DrawRow3(const int& player1Pos, const int& player2Pos, const int& player3Pos, const int& player4Pos,
		const std::string player1ID, const std::string player2ID, const std::string player3ID, const std::string player4ID);
	void DrawRow4(const int& player1Pos, const int& player2Pos, const int& player3Pos, const int& player4Pos,
		const std::string player1ID, const std::string player2ID, const std::string player3ID, const std::string player4ID);
	void DrawRow5( const int& player1Pos, const int& player2Pos, const int& player3Pos, const int& player4Pos,
		const std::string player1ID, const std::string player2ID, const std::string player3ID, const std::string player4ID);
	void DrawRow6(const int& player1Pos, const int& player2Pos, const int& player3Pos, const int& player4Pos,
		const std::string player1ID, const std::string player2ID, const std::string player3ID, const std::string player4ID);
	void DrawRow7(const int& player1Pos, const int& player2Pos, const int& player3Pos, const int& player4Pos,
		const std::string player1ID, const std::string player2ID, const std::string player3ID, const std::string player4ID);

	// Draw calls for all 6 sides of a dice.
	void DrawFace1(const std::string& padding);
	void DrawFace2(const std::string& padding);
	void DrawFace3(const std::string& padding);
	void DrawFace4(const std::string& padding);
	void DrawFace5(const std::string& padding);
	void DrawFace6(const std::string& padding);

};

#endif  // _DRAW_H