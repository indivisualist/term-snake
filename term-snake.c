#include <stdio.h>
#include <stdlib.h>

#define SNAKE_HEAD 'O'
#define SNAKE_BODY '#'
#define ROWS 40
#define COLS 20

int main() {

	// set up data
	char level[ROWS][COLS];
	int snakeLength;
	
	int i;
	int j;
	for (i=0; i<COLS; i++) {
		for (j=0; j<ROWS; j++) {
			// init "empty level" with spaces
			level[j][i] = ' ';
		}
	}

	// calculate snake starting point
	int xPos = ROWS / 2;
	int yPos = COLS / 2;
	// position snake head
	level[xPos][yPos] = SNAKE_HEAD;

	int currentRow;
	int currentCol;
	for (currentCol=0; currentCol<COLS; currentCol++) {
		for (currentRow=0; currentRow<ROWS; currentRow++) {
			// draw current level
			printf("%c", level[currentRow][currentCol]);
		}
		printf("\n");
	}

	return EXIT_SUCCESS;

}
