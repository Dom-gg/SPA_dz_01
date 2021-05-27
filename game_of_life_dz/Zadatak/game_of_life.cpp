#include "game_of_life.h"
#include <iostream>

using namespace std;

game_of_life::game_of_life()
{
	srand(time(0));
	this->initBoards();
}

void game_of_life::start()
{
	int choice = 0;
	cout << "Game of Life" << endl;

	do
	{
		do
		{
			cout <<  endl
				<< "1) Play a game" << endl
				<< "2) Exit \n" << endl;
			cout << "Choose an option (1/2): ";
			cin >> choice;
		} while (choice > 2 || choice < 1);

		switch (choice)
		{
		case 1:
			this->play();
			break;
		case 2:
			this->exit();
			break;

		default:
			break;
		}
	} while (choice != 2);
}

void game_of_life::initBoards()
{
	this->currentBoard[0][0] = '-';
	this->nextBoard[0][0] = '-';
}

void game_of_life::createRandomPattern()
{
	for (int i = 0; i < this->REDOVA; ++i)
	{
		for (int ix = 0; ix < this->STUPACA; ++ix)
		{
			this->currentBoard[i][ix] = '-';
		}
	}

	for (int i = 0; i < this->REDOVA; i += 2)
	{
		for (int ix = 0; ix < this->STUPACA; ix++)
		{
			if (this->randomCell(4, 1) == 4) {
				this->currentBoard[i][ix] = '*';
			}
		}
	}
}

void game_of_life::displayBoard()
{
	for (int i = 0; i < this->REDOVA; i++)
	{
		cout << "|";
		for (int ix = 0; ix < this->STUPACA; ix++)
		{
			if (this->currentBoard[i][ix] != '*')
				this->currentBoard[i][ix] = ' ';

			cout << this->currentBoard[i][ix];

		}
		cout << "|" << endl;
	}
}

void game_of_life::newBoard()
{
	int neighbors;

	for (int i = 0; i < this->REDOVA; i++)
	{
		for (int ix = 0; ix < this->STUPACA; ix++)
		{
			neighbors = this->cellPored(i, ix);
			if (neighbors < 2)
				this->nextBoard[i][ix] = '-';
			else if (neighbors > 3)
				this->nextBoard[i][ix] = '-';
			else if (neighbors == 3)
				this->nextBoard[i][ix] = '*';
			else if (this->currentBoard[i][ix] == '*' && neighbors == 2)
				this->nextBoard[i][ix] = '*';
			else
				nextBoard[i][ix] = '-';
		}

	}
}

void game_of_life::copyBoard()
{
	for (int i = 0; i < this->REDOVA; i++)
	{
		for (int ix = 0; ix < this->STUPACA; ix++)
		{
			this->currentBoard[i][ix] = this->nextBoard[i][ix];
		}
	}
}

int game_of_life::cellPored(int redak, int stupac)
{
	int neighbor = 0;

	if (this->currentBoard[redak - 1][stupac - 1] == '*')
		++neighbor;
	if (this->currentBoard[redak][stupac - 1] == '*')
		++neighbor;
	if (this->currentBoard[redak - 1][stupac] == '*')
		++neighbor;
	if (this->currentBoard[redak - 1][stupac + 1] == '*')
		++neighbor;
	if (this->currentBoard[redak + 1][stupac - 1] == '*')
		++neighbor;
	if (this->currentBoard[redak + 1][stupac] == '*')
		++neighbor;
	if (this->currentBoard[redak][stupac + 1] == '*')
		++neighbor;
	if (this->currentBoard[redak + 1][stupac + 1] == '*')
		++neighbor;

	return neighbor;
}

int game_of_life::randomCell(int max, int min)
{
	return rand() % (max - min + 1) + min;
}


void game_of_life::play()
{
	char next = 0;
	this->createRandomPattern();

	do {

		this->displayBoard();
		this->newBoard();
		this->copyBoard();
		cout << "New game? (Y/N): ";
		cin >> next;
	} while (next == 'Y');
}
int game_of_life::exit()
{
	cout << "Good game!" << endl;

	return 0;
}
