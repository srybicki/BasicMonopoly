
/**************************************************************************************************

	Project: Basic Monopoly

	   File: Draw.cpp

	 Author: Simon Rybicki

	   Date: 30/03/19

	Version: 1.0

	   Info: Implements a draw manager class.

**************************************************************************************************/

#include "Draw.hpp"

// Constructor.
// Setup drawing in the console window.
CDraw::CDraw() 
{
	mHstdin = GetStdHandle(STD_INPUT_HANDLE);
	mHstdout = GetStdHandle(STD_OUTPUT_HANDLE);

	// Remember original console settings.
	GetConsoleScreenBufferInfo(mHstdout, &mCsbi);
}

// Destructor.
CDraw::~CDraw() { }

// Clears all printed characters and moves the cursor position back to start.
void CDraw::ClearScreen()
{
	DWORD count;
	DWORD cellCount;
	COORD homeCoords = { 0, 0 };

	mHstdout = GetStdHandle(STD_OUTPUT_HANDLE);
	if (mHstdout == INVALID_HANDLE_VALUE)
	{
		return;
	}

	// Get the number of cells in the current buffer.
	if (!GetConsoleScreenBufferInfo(mHstdout, &mCsbi))
	{
		return;
	}
	cellCount = mCsbi.dwSize.X *mCsbi.dwSize.Y;

	// Fill the entire buffer with spaces.
	if (!FillConsoleOutputCharacter(
		mHstdout,
		(TCHAR) ' ',
		cellCount,
		homeCoords,
		&count
	)) return;

	// Fill the entire buffer with the current colors and attributes.
	if (!FillConsoleOutputAttribute(
		mHstdout,
		mCsbi.wAttributes,
		cellCount,
		homeCoords,
		&count
	)) return;

	// Move the cursor home.
	SetConsoleCursorPosition(mHstdout, homeCoords);
}

// Draws the Monopoly board.
void CDraw::DisplayBoard(
	const int& player1Pos, const int& player2Pos, const int& player3Pos, const int& player4Pos,
	const std::string player1ID, const std::string player2ID, const std::string player3ID, const std::string player4ID)
{
	/*
	COLOR LIST:
	1 Dark Blue
	2 Dark Green
	3 Dark Cyan
	4 Dark Red
	5 Dark Magenta
	6 Dark Yellow
	7 Dark White
	8 Grey
	9 Blue
	10 Green
	11 Cyan
	12 Red
	13 Magenta
	14 Yellow
	15 White (default)
	*/

	std::cout << PADDING_TOP;
	DrawRow1(player1Pos, player2Pos, player3Pos, player4Pos, player1ID, player2ID, player3ID, player4ID);
	std::cout << PADDING_TOP;
	DrawRow2(player1Pos, player2Pos, player3Pos, player4Pos, player1ID, player2ID, player3ID, player4ID);
	std::cout << PADDING_TOP;
	DrawRow3(player1Pos, player2Pos, player3Pos, player4Pos, player1ID, player2ID, player3ID, player4ID);
	std::cout << PADDING_TOP;
	DrawRow4(player1Pos, player2Pos, player3Pos, player4Pos, player1ID, player2ID, player3ID, player4ID);
	std::cout << PADDING_TOP;
	DrawRow5(player1Pos, player2Pos, player3Pos, player4Pos, player1ID, player2ID, player3ID, player4ID);
	std::cout << PADDING_TOP;
	DrawRow6(player1Pos, player2Pos, player3Pos, player4Pos, player1ID, player2ID, player3ID, player4ID);
	std::cout << PADDING_TOP;
	DrawRow7(player1Pos, player2Pos, player3Pos, player4Pos, player1ID, player2ID, player3ID, player4ID);
	std::cout << PADDING_TOP;
}

void CDraw::DrawRow1(
	const int& player1Pos, const int& player2Pos, const int& player3Pos, const int& player4Pos,
	const std::string player1ID, const std::string player2ID, const std::string player3ID, const std::string player4ID)
{
	SetConsoleTextAttribute(mHstdout, 15);
	std::cout << PADDING_LEFT; (player1Pos == BOARD_POSITIONS[6] ? std::cout << player1ID : std::cout << S_CELL << S_CELL) << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL; (player2Pos == BOARD_POSITIONS[6] ? std::cout << player2ID : std::cout << S_CELL << S_CELL);
	SetConsoleTextAttribute(mHstdout, 4);
	std::cout << PADDING_LEFT; (player1Pos == BOARD_POSITIONS[7] ? std::cout << player1ID : std::cout << S_CELL << S_CELL) << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL; (player2Pos == BOARD_POSITIONS[7] ? std::cout << player2ID : std::cout << S_CELL << S_CELL);
	std::cout << PADDING_LEFT; (player1Pos == BOARD_POSITIONS[8] ? std::cout << player1ID : std::cout << S_CELL << S_CELL) << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL; (player2Pos == BOARD_POSITIONS[8] ? std::cout << player2ID : std::cout << S_CELL << S_CELL);
	SetConsoleTextAttribute(mHstdout, 15);
	std::cout << PADDING_LEFT; (player1Pos == BOARD_POSITIONS[9] ? std::cout << player1ID : std::cout << S_CELL << S_CELL) << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL; (player2Pos == BOARD_POSITIONS[9] ? std::cout << player2ID : std::cout << S_CELL << S_CELL);
	SetConsoleTextAttribute(mHstdout, 6);
	std::cout << PADDING_LEFT; (player1Pos == BOARD_POSITIONS[10] ? std::cout << player1ID : std::cout << S_CELL << S_CELL) << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL; (player2Pos == BOARD_POSITIONS[10] ? std::cout << player2ID : std::cout << S_CELL << S_CELL);
	std::cout << PADDING_LEFT; (player1Pos == BOARD_POSITIONS[11] ? std::cout << player1ID : std::cout << S_CELL << S_CELL) << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL; (player2Pos == BOARD_POSITIONS[11] ? std::cout << player2ID : std::cout << S_CELL << S_CELL);
	std::cout << PADDING_LEFT; (player1Pos == BOARD_POSITIONS[12] ? std::cout << player1ID : std::cout << S_CELL << S_CELL) << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL; (player2Pos == BOARD_POSITIONS[12] ? std::cout << player2ID : std::cout << S_CELL << S_CELL);
	SetConsoleTextAttribute(mHstdout, 15);
	std::cout << PADDING_LEFT; (player1Pos == BOARD_POSITIONS[13] ? std::cout << player1ID : std::cout << S_CELL << S_CELL) << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL; (player2Pos == BOARD_POSITIONS[13] ? std::cout << player2ID : std::cout << S_CELL << S_CELL);

	std::cout << PADDING_TOP;

	SetConsoleTextAttribute(mHstdout, 15);
	std::cout << PADDING_LEFT << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL;
	SetConsoleTextAttribute(mHstdout, 4);
	std::cout << PADDING_LEFT << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL;
	std::cout << PADDING_LEFT << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL;
	SetConsoleTextAttribute(mHstdout, 15);
	std::cout << PADDING_LEFT << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL;
	SetConsoleTextAttribute(mHstdout, 6);
	std::cout << PADDING_LEFT << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL;
	std::cout << PADDING_LEFT << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL;
	std::cout << PADDING_LEFT << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL;
	SetConsoleTextAttribute(mHstdout, 15);
	std::cout << PADDING_LEFT << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL;

	std::cout << PADDING_TOP;

	SetConsoleTextAttribute(mHstdout, 15);
	std::cout << PADDING_LEFT << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL;
	SetConsoleTextAttribute(mHstdout, 4);
	std::cout << PADDING_LEFT << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL;
	std::cout << PADDING_LEFT << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL;
	SetConsoleTextAttribute(mHstdout, 15);
	std::cout << PADDING_LEFT << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL;
	SetConsoleTextAttribute(mHstdout, 6);
	std::cout << PADDING_LEFT << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL;
	std::cout << PADDING_LEFT << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL;
	std::cout << PADDING_LEFT << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL;
	SetConsoleTextAttribute(mHstdout, 15);
	std::cout << PADDING_LEFT << S_CELL << "   Free  " << S_CELL;

	std::cout << PADDING_TOP;

	SetConsoleTextAttribute(mHstdout, 15);
	std::cout << PADDING_LEFT << S_CELL << S_CELL << S_CELL << " Jail " << S_CELL << S_CELL;
	SetConsoleTextAttribute(mHstdout, 4);
	std::cout << PADDING_LEFT << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL;
	std::cout << PADDING_LEFT << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL;
	SetConsoleTextAttribute(mHstdout, 15);
	std::cout << PADDING_LEFT << S_CELL << " Airport " << S_CELL;
	SetConsoleTextAttribute(mHstdout, 6);
	std::cout << PADDING_LEFT << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL;
	std::cout << PADDING_LEFT << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL;
	std::cout << PADDING_LEFT << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL;
	SetConsoleTextAttribute(mHstdout, 15);
	std::cout << PADDING_LEFT << S_CELL << " Parking " << S_CELL;

	std::cout << PADDING_TOP;

	SetConsoleTextAttribute(mHstdout, 15);
	std::cout << PADDING_LEFT << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL;
	SetConsoleTextAttribute(mHstdout, 4);
	std::cout << PADDING_LEFT << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL;
	std::cout << PADDING_LEFT << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL;
	SetConsoleTextAttribute(mHstdout, 15);
	std::cout << PADDING_LEFT << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL;
	SetConsoleTextAttribute(mHstdout, 6);
	std::cout << PADDING_LEFT << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL;
	std::cout << PADDING_LEFT << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL;
	std::cout << PADDING_LEFT << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL;
	SetConsoleTextAttribute(mHstdout, 15);
	std::cout << PADDING_LEFT << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL;

	std::cout << PADDING_TOP;

	SetConsoleTextAttribute(mHstdout, 15);
	std::cout << PADDING_LEFT << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL;
	SetConsoleTextAttribute(mHstdout, 4);
	std::cout << PADDING_LEFT << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL;
	std::cout << PADDING_LEFT << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL;
	SetConsoleTextAttribute(mHstdout, 15);
	std::cout << PADDING_LEFT << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL;
	SetConsoleTextAttribute(mHstdout, 6);
	std::cout << PADDING_LEFT << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL;
	std::cout << PADDING_LEFT << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL;
	std::cout << PADDING_LEFT << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL;
	SetConsoleTextAttribute(mHstdout, 15);
	std::cout << PADDING_LEFT << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL;

	std::cout << PADDING_TOP;

	SetConsoleTextAttribute(mHstdout, 15);
	std::cout << PADDING_LEFT; (player3Pos == BOARD_POSITIONS[6] ? std::cout << player3ID : std::cout << S_CELL << S_CELL) << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL; (player4Pos == BOARD_POSITIONS[6] ? std::cout << player4ID : std::cout << S_CELL << S_CELL);
	SetConsoleTextAttribute(mHstdout, 4);
	std::cout << PADDING_LEFT; (player3Pos == BOARD_POSITIONS[7] ? std::cout << player3ID : std::cout << S_CELL << S_CELL) << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL; (player4Pos == BOARD_POSITIONS[7] ? std::cout << player4ID : std::cout << S_CELL << S_CELL);
	std::cout << PADDING_LEFT; (player3Pos == BOARD_POSITIONS[8] ? std::cout << player3ID : std::cout << S_CELL << S_CELL) << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL; (player4Pos == BOARD_POSITIONS[8] ? std::cout << player4ID : std::cout << S_CELL << S_CELL);
	SetConsoleTextAttribute(mHstdout, 15);
	std::cout << PADDING_LEFT; (player3Pos == BOARD_POSITIONS[9] ? std::cout << player3ID : std::cout << S_CELL << S_CELL) << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL; (player4Pos == BOARD_POSITIONS[9] ? std::cout << player4ID : std::cout << S_CELL << S_CELL);
	SetConsoleTextAttribute(mHstdout, 6);
	std::cout << PADDING_LEFT; (player3Pos == BOARD_POSITIONS[10] ? std::cout << player3ID : std::cout << S_CELL << S_CELL) << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL; (player4Pos == BOARD_POSITIONS[10] ? std::cout << player4ID : std::cout << S_CELL << S_CELL);
	std::cout << PADDING_LEFT; (player3Pos == BOARD_POSITIONS[11] ? std::cout << player3ID : std::cout << S_CELL << S_CELL) << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL; (player4Pos == BOARD_POSITIONS[11] ? std::cout << player4ID : std::cout << S_CELL << S_CELL);
	std::cout << PADDING_LEFT; (player3Pos == BOARD_POSITIONS[12] ? std::cout << player3ID : std::cout << S_CELL << S_CELL) << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL; (player4Pos == BOARD_POSITIONS[12] ? std::cout << player4ID : std::cout << S_CELL << S_CELL);
	SetConsoleTextAttribute(mHstdout, 15);
	std::cout << PADDING_LEFT; (player3Pos == BOARD_POSITIONS[13] ? std::cout << player3ID : std::cout << S_CELL << S_CELL) << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL; (player4Pos == BOARD_POSITIONS[13] ? std::cout << player4ID : std::cout << S_CELL << S_CELL);

	std::cout << PADDING_TOP;
}

void CDraw::DrawRow2(
	const int& player1Pos, const int& player2Pos, const int& player3Pos, const int& player4Pos,
	const std::string player1ID, const std::string player2ID, const std::string player3ID, const std::string player4ID)
{
	SetConsoleTextAttribute(mHstdout, 8);
	std::cout << PADDING_LEFT; (player1Pos == BOARD_POSITIONS[5] ? std::cout << player1ID : std::cout << S_CELL << S_CELL) << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL; (player2Pos == BOARD_POSITIONS[5] ? std::cout << player2ID : std::cout << S_CELL << S_CELL);
	std::cout << "             ";
	std::cout << "             ";
	std::cout << "             ";
	std::cout << "             ";
	std::cout << "             ";
	std::cout << "             ";
	SetConsoleTextAttribute(mHstdout, 14);
	std::cout << PADDING_LEFT; (player1Pos == BOARD_POSITIONS[14] ? std::cout << player1ID : std::cout << S_CELL << S_CELL) << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL; (player2Pos == BOARD_POSITIONS[14] ? std::cout << player2ID : std::cout << S_CELL << S_CELL);

	std::cout << PADDING_TOP;

	SetConsoleTextAttribute(mHstdout, 8);
	std::cout << PADDING_LEFT << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL;
	std::cout << "             ";
	std::cout << "             ";
	std::cout << "             ";
	std::cout << "             ";
	std::cout << "             ";
	std::cout << "             ";
	SetConsoleTextAttribute(mHstdout, 14);
	std::cout << PADDING_LEFT << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL;

	std::cout << PADDING_TOP;

	SetConsoleTextAttribute(mHstdout, 8);
	std::cout << PADDING_LEFT << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL;
	std::cout << "             ";
	std::cout << "             ";
	std::cout << "             ";
	std::cout << "             ";
	std::cout << "             ";
	std::cout << "             ";
	SetConsoleTextAttribute(mHstdout, 14);
	std::cout << PADDING_LEFT << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL;

	std::cout << PADDING_TOP;

	SetConsoleTextAttribute(mHstdout, 8);
	std::cout << PADDING_LEFT << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL;
	std::cout << "             ";
	std::cout << "             ";
	std::cout << "             ";
	std::cout << "             ";
	std::cout << "             ";
	std::cout << "             ";
	SetConsoleTextAttribute(mHstdout, 14);
	std::cout << PADDING_LEFT << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL;

	std::cout << PADDING_TOP;

	SetConsoleTextAttribute(mHstdout, 8);
	std::cout << PADDING_LEFT << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL;
	std::cout << "             ";
	std::cout << "             ";
	std::cout << "             ";
	std::cout << "             ";
	std::cout << "             ";
	std::cout << "             ";
	SetConsoleTextAttribute(mHstdout, 14);
	std::cout << PADDING_LEFT << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL;

	std::cout << PADDING_TOP;

	SetConsoleTextAttribute(mHstdout, 8);
	std::cout << PADDING_LEFT << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL;
	std::cout << "             ";
	std::cout << "             ";
	std::cout << "             ";
	std::cout << "             ";
	std::cout << "             ";
	std::cout << "             ";
	SetConsoleTextAttribute(mHstdout, 14);
	std::cout << PADDING_LEFT << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL;

	std::cout << PADDING_TOP;

	SetConsoleTextAttribute(mHstdout, 8);
	std::cout << PADDING_LEFT; (player3Pos == BOARD_POSITIONS[5] ? std::cout << player3ID : std::cout << S_CELL << S_CELL) << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL; (player4Pos == BOARD_POSITIONS[5] ? std::cout << player4ID : std::cout << S_CELL << S_CELL);
	std::cout << "             ";
	std::cout << "             ";
	std::cout << "             ";
	std::cout << "             ";
	std::cout << "             ";
	std::cout << "             ";
	SetConsoleTextAttribute(mHstdout, 14);
	std::cout << PADDING_LEFT; (player3Pos == BOARD_POSITIONS[14] ? std::cout << player3ID : std::cout << S_CELL << S_CELL) << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL; (player4Pos == BOARD_POSITIONS[14] ? std::cout << player4ID : std::cout << S_CELL << S_CELL);

	std::cout << PADDING_TOP;
}

void CDraw::DrawRow3(
	const int& player1Pos, const int& player2Pos, const int& player3Pos, const int& player4Pos,
	const std::string player1ID, const std::string player2ID, const std::string player3ID, const std::string player4ID)
{
	SetConsoleTextAttribute(mHstdout, 8);
	std::cout << PADDING_LEFT; (player1Pos == BOARD_POSITIONS[4] ? std::cout << player1ID : std::cout << S_CELL << S_CELL) << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL; (player2Pos == BOARD_POSITIONS[4] ? std::cout << player2ID : std::cout << S_CELL << S_CELL);
	std::cout << "             ";
	std::cout << "             ";
	std::cout << "             ";
	std::cout << "             ";
	std::cout << "             ";
	std::cout << "             ";
	SetConsoleTextAttribute(mHstdout, 14);
	std::cout << PADDING_LEFT; (player1Pos == BOARD_POSITIONS[15] ? std::cout << player1ID : std::cout << S_CELL << S_CELL) << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL; (player2Pos == BOARD_POSITIONS[15] ? std::cout << player2ID : std::cout << S_CELL << S_CELL);

	std::cout << PADDING_TOP;

	SetConsoleTextAttribute(mHstdout, 8);
	std::cout << PADDING_LEFT << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL;
	std::cout << "             ";
	std::cout << "             ";
	std::cout << "             ";
	std::cout << "             ";
	std::cout << "             ";
	std::cout << "             ";
	SetConsoleTextAttribute(mHstdout, 14);
	std::cout << PADDING_LEFT << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL;

	std::cout << PADDING_TOP;

	SetConsoleTextAttribute(mHstdout, 8);
	std::cout << PADDING_LEFT << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL;
	std::cout << "             ";
	std::cout << "             ";
	std::cout << "             ";
	std::cout << "             ";
	std::cout << "             ";
	std::cout << "             ";
	SetConsoleTextAttribute(mHstdout, 14);
	std::cout << PADDING_LEFT << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL;

	std::cout << PADDING_TOP;

	SetConsoleTextAttribute(mHstdout, 8);
	std::cout << PADDING_LEFT << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL;
	std::cout << "             ";
	std::cout << "             ";
	std::cout << "             ";
	std::cout << "             ";
	std::cout << "             ";
	std::cout << "             ";
	SetConsoleTextAttribute(mHstdout, 14);
	std::cout << PADDING_LEFT << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL;

	std::cout << PADDING_TOP;

	SetConsoleTextAttribute(mHstdout, 8);
	std::cout << PADDING_LEFT << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL;
	std::cout << "             ";
	std::cout << "             ";
	std::cout << "             ";
	std::cout << "             ";
	std::cout << "             ";
	std::cout << "             ";
	SetConsoleTextAttribute(mHstdout, 14);
	std::cout << PADDING_LEFT << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL;

	std::cout << PADDING_TOP;

	SetConsoleTextAttribute(mHstdout, 8);
	std::cout << PADDING_LEFT << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL;
	std::cout << "             ";
	std::cout << "             ";
	std::cout << "             ";
	std::cout << "             ";
	std::cout << "             ";
	std::cout << "             ";
	SetConsoleTextAttribute(mHstdout, 14);
	std::cout << PADDING_LEFT << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL;

	std::cout << PADDING_TOP;

	SetConsoleTextAttribute(mHstdout, 8);
	std::cout << PADDING_LEFT; (player3Pos == BOARD_POSITIONS[4] ? std::cout << player3ID : std::cout << S_CELL << S_CELL) << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL; (player4Pos == BOARD_POSITIONS[4] ? std::cout << player4ID : std::cout << S_CELL << S_CELL);
	std::cout << "             ";
	std::cout << "             ";
	std::cout << "             ";
	std::cout << "             ";
	std::cout << "             ";
	std::cout << "             ";
	SetConsoleTextAttribute(mHstdout, 14);
	std::cout << PADDING_LEFT; (player3Pos == BOARD_POSITIONS[15] ? std::cout << player3ID : std::cout << S_CELL << S_CELL) << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL; (player4Pos == BOARD_POSITIONS[15] ? std::cout << player4ID : std::cout << S_CELL << S_CELL);

	std::cout << PADDING_TOP;
}

void CDraw::DrawRow4(
	const int& player1Pos, const int& player2Pos, const int& player3Pos, const int& player4Pos,
	const std::string player1ID, const std::string player2ID, const std::string player3ID, const std::string player4ID)
{
	SetConsoleTextAttribute(mHstdout, 15);
	std::cout << PADDING_LEFT; (player1Pos == BOARD_POSITIONS[3] ? std::cout << player1ID : std::cout << S_CELL << S_CELL) << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL; (player2Pos == BOARD_POSITIONS[3] ? std::cout << player2ID : std::cout << S_CELL << S_CELL);
	std::cout << "             ";
	std::cout << "             ";
	std::cout << "             ";
	std::cout << "             ";
	std::cout << "             ";
	std::cout << "             ";
	std::cout << PADDING_LEFT; (player1Pos == BOARD_POSITIONS[16] ? std::cout << player1ID : std::cout << S_CELL << S_CELL) << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL; (player2Pos == BOARD_POSITIONS[16] ? std::cout << player2ID : std::cout << S_CELL << S_CELL);

	std::cout << PADDING_TOP;

	SetConsoleTextAttribute(mHstdout, 15);
	std::cout << PADDING_LEFT << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL;
	std::cout << "     OOO    O";
	std::cout << "OO  OOOOOO  O";
	std::cout << "OO    OO  OOO";
	std::cout << "OOO  OOOOOO  ";
	std::cout << " OOOOOO  OO  ";
	std::cout << " OO    OO    ";
	std::cout << PADDING_LEFT << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL;

	std::cout << PADDING_TOP;

	SetConsoleTextAttribute(mHstdout, 15);
	std::cout << PADDING_LEFT << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL;
	std::cout << "     OOOO  OO";
	std::cout << "OO OO    OO O";
	std::cout << "OOO   OO OO  ";
	std::cout << "  OO OO   OO ";
	std::cout << "OO    OO OO  ";
	std::cout << "  OO  OO     ";
	std::cout << PADDING_LEFT << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL;

	std::cout << PADDING_TOP;

	SetConsoleTextAttribute(mHstdout, 15);
	std::cout << PADDING_LEFT << S_CELL << S_CELL << " Bonus " << S_CELL << S_CELL;
	std::cout << "     OO OOOO ";
	std::cout << "OO OO    OO O";
	std::cout << "O OO  OO OO  ";
	std::cout << "  OO OOOOOO  ";
	std::cout << "OO    OO OO  ";
	std::cout << "   OOOO      ";
	std::cout << PADDING_LEFT << S_CELL << " Penalty " << S_CELL;

	std::cout << PADDING_TOP;

	SetConsoleTextAttribute(mHstdout, 15);
	std::cout << PADDING_LEFT << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL;
	std::cout << "     OO  OO  ";
	std::cout << "OO OO    OO O";
	std::cout << "O  OO OO OO  ";
	std::cout << "  OO OO      ";
	std::cout << "OO    OO OO  ";
	std::cout << "    OO       ";
	std::cout << PADDING_LEFT << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL;

	std::cout << PADDING_TOP;

	SetConsoleTextAttribute(mHstdout, 15);
	std::cout << PADDING_LEFT << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL;
	std::cout << "     OO      ";
	std::cout << "OO  OOOOOO  O";
	std::cout << "O   OOOO  OOO";
	std::cout << "OOO  OO      ";
	std::cout << " OOOOOO  OOOO";
	std::cout << "OOO OO       ";
	std::cout << PADDING_LEFT << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL;

	std::cout << PADDING_TOP;

	SetConsoleTextAttribute(mHstdout, 15);
	std::cout << PADDING_LEFT; (player3Pos == BOARD_POSITIONS[3] ? std::cout << player3ID : std::cout << S_CELL << S_CELL) << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL; (player4Pos == BOARD_POSITIONS[3] ? std::cout << player4ID : std::cout << S_CELL << S_CELL);
	std::cout << "             ";
	std::cout << "             ";
	std::cout << "             ";
	std::cout << "             ";
	std::cout << "             ";
	std::cout << "             ";
	std::cout << PADDING_LEFT; (player3Pos == BOARD_POSITIONS[16] ? std::cout << player3ID : std::cout << S_CELL << S_CELL) << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL; (player4Pos == BOARD_POSITIONS[16] ? std::cout << player4ID : std::cout << S_CELL << S_CELL);

	std::cout << PADDING_TOP;
}

void CDraw::DrawRow5(
	const int& player1Pos, const int& player2Pos, const int& player3Pos, const int& player4Pos,
	const std::string player1ID, const std::string player2ID, const std::string player3ID, const std::string player4ID)
{
	SetConsoleTextAttribute(mHstdout, 12);
	std::cout << PADDING_LEFT; (player1Pos == BOARD_POSITIONS[2] ? std::cout << player1ID : std::cout << S_CELL << S_CELL) << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL; (player2Pos == BOARD_POSITIONS[2] ? std::cout << player2ID : std::cout << S_CELL << S_CELL);
	std::cout << "             ";
	std::cout << "             ";
	std::cout << "             ";
	std::cout << "             ";
	std::cout << "             ";
	std::cout << "             ";
	SetConsoleTextAttribute(mHstdout, 10);
	std::cout << PADDING_LEFT; (player1Pos == BOARD_POSITIONS[17] ? std::cout << player1ID : std::cout << S_CELL << S_CELL) << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL; (player2Pos == BOARD_POSITIONS[17] ? std::cout << player2ID : std::cout << S_CELL << S_CELL);

	std::cout << PADDING_TOP;

	SetConsoleTextAttribute(mHstdout, 12);
	std::cout << PADDING_LEFT << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL;
	std::cout << "             ";
	std::cout << "             ";
	std::cout << "             ";
	std::cout << "             ";
	std::cout << "             ";
	std::cout << "             ";
	SetConsoleTextAttribute(mHstdout, 10);
	std::cout << PADDING_LEFT << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL;

	std::cout << PADDING_TOP;

	SetConsoleTextAttribute(mHstdout, 12);
	std::cout << PADDING_LEFT << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL;
	std::cout << "             ";
	std::cout << "             ";
	std::cout << "             ";
	std::cout << "             ";
	std::cout << "             ";
	std::cout << "             ";
	SetConsoleTextAttribute(mHstdout, 10);
	std::cout << PADDING_LEFT << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL;

	std::cout << PADDING_TOP;

	SetConsoleTextAttribute(mHstdout, 12);
	std::cout << PADDING_LEFT << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL;
	std::cout << "             ";
	std::cout << "             ";
	std::cout << "             ";
	std::cout << "             ";
	std::cout << "             ";
	std::cout << "             ";
	SetConsoleTextAttribute(mHstdout, 10);
	std::cout << PADDING_LEFT << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL;

	std::cout << PADDING_TOP;

	SetConsoleTextAttribute(mHstdout, 12);
	std::cout << PADDING_LEFT << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL;
	std::cout << "             ";
	std::cout << "             ";
	std::cout << "             ";
	std::cout << "             ";
	std::cout << "             ";
	std::cout << "             ";
	SetConsoleTextAttribute(mHstdout, 10);
	std::cout << PADDING_LEFT << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL;

	std::cout << PADDING_TOP;

	SetConsoleTextAttribute(mHstdout, 12);
	std::cout << PADDING_LEFT << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL;
	std::cout << "             ";
	std::cout << "             ";
	std::cout << "             ";
	std::cout << "             ";
	std::cout << "             ";
	std::cout << "             ";
	SetConsoleTextAttribute(mHstdout, 10);
	std::cout << PADDING_LEFT << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL;

	std::cout << PADDING_TOP;

	SetConsoleTextAttribute(mHstdout, 12);
	std::cout << PADDING_LEFT; (player3Pos == BOARD_POSITIONS[2] ? std::cout << player3ID : std::cout << S_CELL << S_CELL) << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL; (player4Pos == BOARD_POSITIONS[2] ? std::cout << player4ID : std::cout << S_CELL << S_CELL);
	std::cout << "             ";
	std::cout << "             ";
	std::cout << "             ";
	std::cout << "             ";
	std::cout << "             ";
	std::cout << "             ";
	SetConsoleTextAttribute(mHstdout, 10);
	std::cout << PADDING_LEFT; (player3Pos == BOARD_POSITIONS[17] ? std::cout << player3ID : std::cout << S_CELL << S_CELL) << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL; (player4Pos == BOARD_POSITIONS[17] ? std::cout << player4ID : std::cout << S_CELL << S_CELL);

	std::cout << PADDING_TOP;
}

void CDraw::DrawRow6(
	const int& player1Pos, const int& player2Pos, const int& player3Pos, const int& player4Pos,
	const std::string player1ID, const std::string player2ID, const std::string player3ID, const std::string player4ID)
{
	SetConsoleTextAttribute(mHstdout, 12);
	std::cout << PADDING_LEFT; (player1Pos == BOARD_POSITIONS[1] ? std::cout << player1ID : std::cout << S_CELL << S_CELL) << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL; (player2Pos == BOARD_POSITIONS[1] ? std::cout << player2ID : std::cout << S_CELL << S_CELL);
	std::cout << "             ";
	std::cout << "             ";
	std::cout << "             ";
	std::cout << "             ";
	std::cout << "             ";
	std::cout << "             ";
	SetConsoleTextAttribute(mHstdout, 10);
	std::cout << PADDING_LEFT; (player1Pos == BOARD_POSITIONS[18] ? std::cout << player1ID : std::cout << S_CELL << S_CELL) << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL; (player2Pos == BOARD_POSITIONS[18] ? std::cout << player2ID : std::cout << S_CELL << S_CELL);

	std::cout << PADDING_TOP;

	SetConsoleTextAttribute(mHstdout, 12);
	std::cout << PADDING_LEFT << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL;
	std::cout << "             ";
	std::cout << "             ";
	std::cout << "             ";
	std::cout << "             ";
	std::cout << "             ";
	std::cout << "             ";
	SetConsoleTextAttribute(mHstdout, 10);
	std::cout << PADDING_LEFT << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL;

	std::cout << PADDING_TOP;

	SetConsoleTextAttribute(mHstdout, 12);
	std::cout << PADDING_LEFT << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL;
	std::cout << "             ";
	std::cout << "             ";
	std::cout << "             ";
	std::cout << "             ";
	std::cout << "             ";
	std::cout << "             ";
	SetConsoleTextAttribute(mHstdout, 10);
	std::cout << PADDING_LEFT << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL;

	std::cout << PADDING_TOP;

	SetConsoleTextAttribute(mHstdout, 12);
	std::cout << PADDING_LEFT << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL;
	std::cout << "             ";
	std::cout << "             ";
	std::cout << "             ";
	std::cout << "             ";
	std::cout << "             ";
	std::cout << "             ";
	SetConsoleTextAttribute(mHstdout, 10);
	std::cout << PADDING_LEFT << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL;

	std::cout << PADDING_TOP;

	SetConsoleTextAttribute(mHstdout, 12);
	std::cout << PADDING_LEFT << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL;
	std::cout << "             ";
	std::cout << "             ";
	std::cout << "             ";
	std::cout << "             ";
	std::cout << "             ";
	std::cout << "             ";
	SetConsoleTextAttribute(mHstdout, 10);
	std::cout << PADDING_LEFT << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL;

	std::cout << PADDING_TOP;

	SetConsoleTextAttribute(mHstdout, 12);
	std::cout << PADDING_LEFT << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL;
	std::cout << "             ";
	std::cout << "             ";
	std::cout << "             ";
	std::cout << "             ";
	std::cout << "             ";
	std::cout << "             ";
	SetConsoleTextAttribute(mHstdout, 10);
	std::cout << PADDING_LEFT << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL;

	std::cout << PADDING_TOP;

	SetConsoleTextAttribute(mHstdout, 12);
	std::cout << PADDING_LEFT; (player3Pos == BOARD_POSITIONS[1] ? std::cout << player3ID : std::cout << S_CELL << S_CELL) << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL; (player4Pos == BOARD_POSITIONS[1] ? std::cout << player4ID : std::cout << S_CELL << S_CELL);
	std::cout << "             ";
	std::cout << "             ";
	std::cout << "             ";
	std::cout << "             ";
	std::cout << "             ";
	std::cout << "             ";
	SetConsoleTextAttribute(mHstdout, 10);
	std::cout << PADDING_LEFT; (player3Pos == BOARD_POSITIONS[18] ? std::cout << player3ID : std::cout << S_CELL << S_CELL) << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL; (player4Pos == BOARD_POSITIONS[18] ? std::cout << player4ID : std::cout << S_CELL << S_CELL);

	std::cout << PADDING_TOP;
}

void CDraw::DrawRow7(
	const int& player1Pos, const int& player2Pos, const int& player3Pos, const int& player4Pos,
	const std::string player1ID, const std::string player2ID, const std::string player3ID, const std::string player4ID)
{
	SetConsoleTextAttribute(mHstdout, 15);
	std::cout << PADDING_LEFT; (player1Pos == BOARD_POSITIONS[0] ? std::cout << player1ID : std::cout << S_CELL << S_CELL) << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL; (player2Pos == BOARD_POSITIONS[0] ? std::cout << player2ID : std::cout << S_CELL << S_CELL);
	SetConsoleTextAttribute(mHstdout, 13);
	std::cout << PADDING_LEFT; (player1Pos == BOARD_POSITIONS[25] ? std::cout << player1ID : std::cout << S_CELL << S_CELL) << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL; (player2Pos == BOARD_POSITIONS[25] ? std::cout << player2ID : std::cout << S_CELL << S_CELL);
	std::cout << PADDING_LEFT; (player1Pos == BOARD_POSITIONS[24] ? std::cout << player1ID : std::cout << S_CELL << S_CELL) << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL; (player2Pos == BOARD_POSITIONS[24] ? std::cout << player2ID : std::cout << S_CELL << S_CELL);
	SetConsoleTextAttribute(mHstdout, 15);
	std::cout << PADDING_LEFT; (player1Pos == BOARD_POSITIONS[23] ? std::cout << player1ID : std::cout << S_CELL << S_CELL) << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL; (player2Pos == BOARD_POSITIONS[23] ? std::cout << player2ID : std::cout << S_CELL << S_CELL);
	SetConsoleTextAttribute(mHstdout, 11);
	std::cout << PADDING_LEFT; (player1Pos == BOARD_POSITIONS[22] ? std::cout << player1ID : std::cout << S_CELL << S_CELL) << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL; (player2Pos == BOARD_POSITIONS[22] ? std::cout << player2ID : std::cout << S_CELL << S_CELL);
	std::cout << PADDING_LEFT; (player1Pos == BOARD_POSITIONS[21] ? std::cout << player1ID : std::cout << S_CELL << S_CELL) << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL; (player2Pos == BOARD_POSITIONS[21] ? std::cout << player2ID : std::cout << S_CELL << S_CELL);
	std::cout << PADDING_LEFT; (player1Pos == BOARD_POSITIONS[20] ? std::cout << player1ID : std::cout << S_CELL << S_CELL) << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL; (player2Pos == BOARD_POSITIONS[20] ? std::cout << player2ID : std::cout << S_CELL << S_CELL);
	SetConsoleTextAttribute(mHstdout, 15);
	std::cout << PADDING_LEFT; (player1Pos == BOARD_POSITIONS[19] ? std::cout << player1ID : std::cout << S_CELL << S_CELL) << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL; (player2Pos == BOARD_POSITIONS[19] ? std::cout << player2ID : std::cout << S_CELL << S_CELL);

	std::cout << PADDING_TOP;

	SetConsoleTextAttribute(mHstdout, 15);
	std::cout << PADDING_LEFT << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL;
	SetConsoleTextAttribute(mHstdout, 13);
	std::cout << PADDING_LEFT << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL;
	std::cout << PADDING_LEFT << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL;
	SetConsoleTextAttribute(mHstdout, 15);
	std::cout << PADDING_LEFT << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL;
	SetConsoleTextAttribute(mHstdout, 11);
	std::cout << PADDING_LEFT << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL;
	std::cout << PADDING_LEFT << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL;
	std::cout << PADDING_LEFT << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL;
	SetConsoleTextAttribute(mHstdout, 15);
	std::cout << PADDING_LEFT << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL;

	std::cout << PADDING_TOP;

	SetConsoleTextAttribute(mHstdout, 15);
	std::cout << PADDING_LEFT << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL;
	SetConsoleTextAttribute(mHstdout, 13);
	std::cout << PADDING_LEFT << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL;
	std::cout << PADDING_LEFT << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL;
	SetConsoleTextAttribute(mHstdout, 15);
	std::cout << PADDING_LEFT << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL;
	SetConsoleTextAttribute(mHstdout, 11);
	std::cout << PADDING_LEFT << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL;
	std::cout << PADDING_LEFT << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL;
	std::cout << PADDING_LEFT << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL;
	SetConsoleTextAttribute(mHstdout, 15);
	std::cout << PADDING_LEFT << S_CELL << S_CELL << " Go to " << S_CELL << S_CELL;

	std::cout << PADDING_TOP;

	SetConsoleTextAttribute(mHstdout, 15);
	std::cout << PADDING_LEFT << S_CELL << S_CELL << S_CELL << S_CELL << " GO " << S_CELL << S_CELL << S_CELL;
	SetConsoleTextAttribute(mHstdout, 13);
	std::cout << PADDING_LEFT << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL;
	std::cout << PADDING_LEFT << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL;
	SetConsoleTextAttribute(mHstdout, 15);
	std::cout << PADDING_LEFT << S_CELL << " Airport " << S_CELL;
	SetConsoleTextAttribute(mHstdout, 11);
	std::cout << PADDING_LEFT << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL;
	std::cout << PADDING_LEFT << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL;
	std::cout << PADDING_LEFT << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL;
	SetConsoleTextAttribute(mHstdout, 15);
	std::cout << PADDING_LEFT << S_CELL << S_CELL << "  Jail " << S_CELL << S_CELL;

	std::cout << PADDING_TOP;

	SetConsoleTextAttribute(mHstdout, 15);
	std::cout << PADDING_LEFT << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL;
	SetConsoleTextAttribute(mHstdout, 13);
	std::cout << PADDING_LEFT << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL;
	std::cout << PADDING_LEFT << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL;
	SetConsoleTextAttribute(mHstdout, 15);
	std::cout << PADDING_LEFT << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL;
	SetConsoleTextAttribute(mHstdout, 11);
	std::cout << PADDING_LEFT << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL;
	std::cout << PADDING_LEFT << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL;
	std::cout << PADDING_LEFT << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL;
	SetConsoleTextAttribute(mHstdout, 15);
	std::cout << PADDING_LEFT << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL;

	std::cout << PADDING_TOP;

	SetConsoleTextAttribute(mHstdout, 15);
	std::cout << PADDING_LEFT << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL;
	SetConsoleTextAttribute(mHstdout, 13);
	std::cout << PADDING_LEFT << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL;
	std::cout << PADDING_LEFT << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL;
	SetConsoleTextAttribute(mHstdout, 15);
	std::cout << PADDING_LEFT << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL;
	SetConsoleTextAttribute(mHstdout, 11);
	std::cout << PADDING_LEFT << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL;
	std::cout << PADDING_LEFT << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL;
	std::cout << PADDING_LEFT << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL;
	SetConsoleTextAttribute(mHstdout, 15);
	std::cout << PADDING_LEFT << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL;

	std::cout << PADDING_TOP;

	SetConsoleTextAttribute(mHstdout, 15);
	std::cout << PADDING_LEFT; (player3Pos == BOARD_POSITIONS[0] ? std::cout << player3ID : std::cout << S_CELL << S_CELL) << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL; (player4Pos == BOARD_POSITIONS[0] ? std::cout << player4ID : std::cout << S_CELL << S_CELL);
	SetConsoleTextAttribute(mHstdout, 13);
	std::cout << PADDING_LEFT; (player3Pos == BOARD_POSITIONS[25] ? std::cout << player3ID : std::cout << S_CELL << S_CELL) << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL; (player4Pos == BOARD_POSITIONS[25] ? std::cout << player4ID : std::cout << S_CELL << S_CELL);
	std::cout << PADDING_LEFT; (player3Pos == BOARD_POSITIONS[24] ? std::cout << player3ID : std::cout << S_CELL << S_CELL) << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL; (player4Pos == BOARD_POSITIONS[24] ? std::cout << player4ID : std::cout << S_CELL << S_CELL);
	SetConsoleTextAttribute(mHstdout, 15);
	std::cout << PADDING_LEFT; (player3Pos == BOARD_POSITIONS[23] ? std::cout << player3ID : std::cout << S_CELL << S_CELL) << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL; (player4Pos == BOARD_POSITIONS[23] ? std::cout << player4ID : std::cout << S_CELL << S_CELL);
	SetConsoleTextAttribute(mHstdout, 11);
	std::cout << PADDING_LEFT; (player3Pos == BOARD_POSITIONS[22] ? std::cout << player3ID : std::cout << S_CELL << S_CELL) << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL; (player4Pos == BOARD_POSITIONS[22] ? std::cout << player4ID : std::cout << S_CELL << S_CELL);
	std::cout << PADDING_LEFT; (player3Pos == BOARD_POSITIONS[21] ? std::cout << player3ID : std::cout << S_CELL << S_CELL) << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL; (player4Pos == BOARD_POSITIONS[21] ? std::cout << player4ID : std::cout << S_CELL << S_CELL);
	std::cout << PADDING_LEFT; (player3Pos == BOARD_POSITIONS[20] ? std::cout << player3ID : std::cout << S_CELL << S_CELL) << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL; (player4Pos == BOARD_POSITIONS[20] ? std::cout << player4ID : std::cout << S_CELL << S_CELL);
	SetConsoleTextAttribute(mHstdout, 15);
	std::cout << PADDING_LEFT; (player3Pos == BOARD_POSITIONS[19] ? std::cout << player3ID : std::cout << S_CELL << S_CELL) << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL << S_CELL; (player4Pos == BOARD_POSITIONS[19] ? std::cout << player4ID : std::cout << S_CELL << S_CELL);

	std::cout << PADDING_TOP;
}

// Draws the dice.
void CDraw::DisplayDice(const int& dicePos, const int& diceFace)
{
	SetConsoleTextAttribute(mHstdout, 15);

	std::string padding;

	// Check dice floor roll position.
	switch (dicePos)
	{
	case 1: padding = DICE_PADDING_1; break;
	case 2: padding = DICE_PADDING_2; break;
	case 3: padding = DICE_PADDING_3; break;
	case 4: padding = DICE_PADDING_4; break;
	case 5: padding = DICE_PADDING_5; break;
	case 6: padding = DICE_PADDING_6; break;
	default:
		padding = DICE_PADDING_1;
		break;
	}

	// Check dice upward face value.
	switch (diceFace)
	{
	case 1: DrawFace1(padding); break;
	case 2: DrawFace2(padding); break;
	case 3: DrawFace3(padding); break;
	case 4: DrawFace4(padding); break;
	case 5: DrawFace5(padding); break;
	case 6: DrawFace6(padding); break;
	default:
		DrawFace1(padding);
		break;
	}
}

void CDraw::DrawFace1(const std::string& padding)
{
	std::cout << PADDING_LEFT << padding << DICE_TL << DICE_H << DICE_H << DICE_H << DICE_H << DICE_H << DICE_H << DICE_H << DICE_TR << "\n";
	std::cout << PADDING_LEFT << padding << DICE_V << "       " << DICE_V << "\n";
	std::cout << PADDING_LEFT << padding << DICE_V << "   o   " << DICE_V << "\n";
	std::cout << PADDING_LEFT << padding << DICE_V << "       " << DICE_V << "\n";
	std::cout << PADDING_LEFT << padding << DICE_BL << DICE_H << DICE_H << DICE_H << DICE_H << DICE_H << DICE_H << DICE_H << DICE_BR << "\n";
}

void CDraw::DrawFace2(const std::string& padding)
{
	std::cout << PADDING_LEFT << padding << DICE_TL << DICE_H << DICE_H << DICE_H << DICE_H << DICE_H << DICE_H << DICE_H << DICE_TR << "\n";
	std::cout << PADDING_LEFT << padding << DICE_V << " o     " << DICE_V << "\n";
	std::cout << PADDING_LEFT << padding << DICE_V << "       " << DICE_V << "\n";
	std::cout << PADDING_LEFT << padding << DICE_V << "     o " << DICE_V << "\n";
	std::cout << PADDING_LEFT << padding << DICE_BL << DICE_H << DICE_H << DICE_H << DICE_H << DICE_H << DICE_H << DICE_H << DICE_BR << "\n";
}

void CDraw::DrawFace3(const std::string& padding)
{
	std::cout << PADDING_LEFT << padding << DICE_TL << DICE_H << DICE_H << DICE_H << DICE_H << DICE_H << DICE_H << DICE_H << DICE_TR << "\n";
	std::cout << PADDING_LEFT << padding << DICE_V << " o     " << DICE_V << "\n";
	std::cout << PADDING_LEFT << padding << DICE_V << "   o   " << DICE_V << "\n";
	std::cout << PADDING_LEFT << padding << DICE_V << "     o " << DICE_V << "\n";
	std::cout << PADDING_LEFT << padding << DICE_BL << DICE_H << DICE_H << DICE_H << DICE_H << DICE_H << DICE_H << DICE_H << DICE_BR << "\n";
}

void CDraw::DrawFace4(const std::string& padding)
{
	std::cout << PADDING_LEFT << padding << DICE_TL << DICE_H << DICE_H << DICE_H << DICE_H << DICE_H << DICE_H << DICE_H << DICE_TR << "\n";
	std::cout << PADDING_LEFT << padding << DICE_V << " o   o " << DICE_V << "\n";
	std::cout << PADDING_LEFT << padding << DICE_V << "       " << DICE_V << "\n";
	std::cout << PADDING_LEFT << padding << DICE_V << " o   o " << DICE_V << "\n";
	std::cout << PADDING_LEFT << padding << DICE_BL << DICE_H << DICE_H << DICE_H << DICE_H << DICE_H << DICE_H << DICE_H << DICE_BR << "\n";
}

void CDraw::DrawFace5(const std::string& padding)
{
	std::cout << PADDING_LEFT << padding << DICE_TL << DICE_H << DICE_H << DICE_H << DICE_H << DICE_H << DICE_H << DICE_H << DICE_TR << "\n";
	std::cout << PADDING_LEFT << padding << DICE_V << " o   o " << DICE_V << "\n";
	std::cout << PADDING_LEFT << padding << DICE_V << "   o   " << DICE_V << "\n";
	std::cout << PADDING_LEFT << padding << DICE_V << " o   o " << DICE_V << "\n";
	std::cout << PADDING_LEFT << padding << DICE_BL << DICE_H << DICE_H << DICE_H << DICE_H << DICE_H << DICE_H << DICE_H << DICE_BR << "\n";
}

void CDraw::DrawFace6(const std::string& padding)
{
	std::cout << PADDING_LEFT << padding << DICE_TL << DICE_H << DICE_H << DICE_H << DICE_H << DICE_H << DICE_H << DICE_H << DICE_TR << "\n";
	std::cout << PADDING_LEFT << padding << DICE_V << " o   o " << DICE_V << "\n";
	std::cout << PADDING_LEFT << padding << DICE_V << " o   o " << DICE_V << "\n";
	std::cout << PADDING_LEFT << padding << DICE_V << " o   o " << DICE_V << "\n";
	std::cout << PADDING_LEFT << padding << DICE_BL << DICE_H << DICE_H << DICE_H << DICE_H << DICE_H << DICE_H << DICE_H << DICE_BR << "\n";
}

// Clean up.
void CDraw::Reset()
{
	FlushConsoleInputBuffer(mHstdin);

	// Reset console setting back to original.
	SetConsoleTextAttribute(mHstdout, mCsbi.wAttributes);
}