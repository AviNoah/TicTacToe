#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;


static int board[3][3];
bool isXTurn = 1;

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
	int i, j;
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			int a = board[i][j];
			char c = *"?"; // Default to empty cell

			if (a == 1)
				// if X
				c = *"X";
			else if (a == 2)
				// if O
				c = *"O";

			std::cout << c;
		}
		std::cout << std::endl;
	}
}

bool checkBoardFor(char pSymb)
{
	// Receives a player symbol.
	// Will return whether or not a player won.
	int i, b;

	// Convert player symbol to our int representation
	b = 1; // for x;
	if (pSymb == *"O") b = 2;

	// Check all rows and columns.
	for (i = 0; i < 3; i++)
	{
		if (board[i][0] == board[i][1] && board[i][0] == board[i][2] && board[i][0] == b)
			return true; // Checks if row matches
		if (board[0][i] == board[1][i] && board[0][i] == board[2][i] && board[0][i] == b)
			return true; // Checks if column matches
	}

	// Check diagonals
	if (board[0][0] == board[1][1] && board[0][0] == board[2][2] && board[0][0] == b)
		return true;
	if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[1][1] == b)
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
			if (board[i][j] == 0) return true;
	return false;
}

bool checkIfACellIsFree(int i, int j)
{
	// Checks and returns if selected cell is a free cell on the board.
	if (i > 3 || i < 0) return false;
	if (j > 3 || j < 0) return false;
	return (board[i][j] == 0);
}

void requestInputAs(char pSymb)
{
	// Request input from the selected player
	printf("%c's turn\n", pSymb);
	int row, col;
	printf("Rows and columns are numbered from left to right in (1-3) (1-3) format\n");
	printf("Enter row:\n");
	scanf_s("%d", &row);
	printf("Enter col:\n");
	scanf_s("%d", &col);
	while (!checkIfACellIsFree(row-1, col-1))
	{
		printf("That cell is already taken.\n");
		printf("Enter row:\n");
		scanf_s("%d", &row);
		printf("Enter col:\n");
		scanf_s("%d", &col);
	}
	int b = 1; // for x;
	if (pSymb == *"O") b = 2;
	board[row-1][col-1] = b;
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
			
		}
		else
		{
			// From here on it is not X's turn.
			requestInputAs(*"O");
		}
		isXTurn = 1 - isXTurn; // Flip turn.
		printBoard();
	}
	if (checkBoardFor(*"X"))
	{
		printf("%s has won!", "X");
		return 0;
	}
	if (checkBoardFor(*"O"))
	{
		printf("%s has won!", "O");
		return 0;
	}
	printf("It is a tie");
	return 0;
}
		