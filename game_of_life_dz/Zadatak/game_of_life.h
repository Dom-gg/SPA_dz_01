#pragma once
class game_of_life
{
private:
	static const unsigned int STUPACA = 40;
	static const unsigned int REDOVA = 20;
	char currentBoard[REDOVA][STUPACA];
	char nextBoard[REDOVA][STUPACA];
	void initBoards();
	void createRandomPattern();
	void displayBoard();
	void newBoard();
	void copyBoard();
	int cellPored(int redak, int stupac);
	int randomCell(int max, int min);
	void play();
	int exit();
public:
	game_of_life();
	void start();
};

