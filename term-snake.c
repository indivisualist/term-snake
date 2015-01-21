#include <stdio.h>
#include <stdlib.h>

#define SNAKE_HEAD 'O'
#define SNAKE_BODY '#'
#define ROWS 40
#define COLS 20

void initLevel(char level[ROWS][COLS]) {

	// init level with spaces
	int currentRow;
	int currentCol;
	for (currentCol=0; currentCol<COLS; currentCol++) {
		for (currentRow=0; currentRow<ROWS; currentRow++) {
			level[currentRow][currentCol] = ' ';
		}
	}

	// calculate snake starting point
	int xPos = ROWS / 2;
	int yPos = COLS / 2;

	// position snake head
	level[xPos][yPos] = SNAKE_HEAD;

}

void getInput() {
	// do stuff
}

void updateLevel(char level[ROWS][COLS]) {
	// do stuff
}

void drawLevel(char level[ROWS][COLS]) {

	int currentRow;
	int currentCol;
	for (currentCol=0; currentCol<COLS; currentCol++) {
		for (currentRow=0; currentRow<ROWS; currentRow++) {
			printf("%c", level[currentRow][currentCol]);
		}
		printf("\n");
	}

}

int main() {

	char level[ROWS][COLS];
	int snakeLength = 0;
	int runGame = 1;

	initLevel(level);

	// game loop
	while (runGame) {
		getInput();
		updateLevel(level);
		drawLevel(level);
		runGame = 0; //DEBUG
	}

	return EXIT_SUCCESS;

}
