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
	int snakeLength;

	initLevel(level);
	drawLevel(level);

	return EXIT_SUCCESS;

}
