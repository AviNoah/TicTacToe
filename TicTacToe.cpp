#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;


static int board[3][3];
bool isXTurn = true;

void initializeBoard()
{
	int i, j;
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			board[i][j] = 0;
		}
	}
}



void printBoard()
{
	system("CLS"); // Clear terminal screen.
	printf("ss");
	int i, j;
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			int a = board[i][j];
			char c[] = "?"; // Default to empty cell

			if (a == 1)
				// if X
				c[0] = *"X";
			else if (a == 2)
				// if O
				c[0] = *"O";

			std::cout << c[0];
		}
		std::cout << std::endl;
	}
}

bool checkBoardFor(char pSymb)
{
	// Receives a player symbol.
	// Will return whether or not a player won.
	int i;
	// Check all rows and columns.
	for (i = 0; i < 3; i++)
	{
		if (board[i][0] == board[i][1] && board[i][0] == board[i][2] && board[i][0] == pSymb)
			return true; // Checks if row matches
		if (board[0][i] == board[1][i] && board[0][i] == board[2][i] && board[0][i] == pSymb)
			return true; // Checks if column matches
	}

	// Check diagonals
	if (board[0][0] == board[1][1] && board[0][0] == board[2][2] && board[i][0] == pSymb)
		return true;
	if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[1][1] == pSymb)
		return true;

	// No winning moves detected, didn't win yet.
	return false;
}

bool checkIfCellIsFree()
{
	// Checks and returns if there is a free cell on the board.
	int i, j;
	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
			if (board[i][j] == *"?") return true;
	return false;
}

bool checkIfACellIsFree(int i, int j)
{
	// Checks and returns if selected cell is a free cell on the board.
	return (board[i][j] == *"?");
}

void requestInputAs(char pSymb)
{
	// Request input from the selected player
	int row, col;
	printf("Enter row:\n");
	scanf("%d", row);
	printf("Enter col:\n");
	scanf("%d", col);
	while (!checkIfACellIsFree(row, col))
	{
		printf("That cell is already taken.");
		printf("Enter row:\n");
		scanf("%d", row);
		printf("Enter col:\n");
		scanf("%d", col);
	}

	board[row][col] = pSymb;
}
int main()
{
	initializeBoard();
	printBoard();

	// While neither X or O won yet.
	while (!checkBoardFor(*"X") && !checkBoardFor(*"O") && checkIfCellIsFree())
	{
		// Check if it is X's turn.
		if (isXTurn) {
			requestInputAs(*"X");
			continue;
		}

		// From here on it is not X's turn.
		requestInputAs(*"O");
	}
	return 0;
}
		