#include <stdio.h>
#include <stdlib.h>
#include <termios.h>
#include <unistd.h>

#define SNAKE_HEAD 'O'
#define SNAKE_BODY '#'
#define ROWS 40
#define COLS 20

// reads from keypress, doesn't echo
// see http://stackoverflow.com/a/23035044
int getch(void) {
	struct termios oldattr, newattr;
	int ch;
	tcgetattr(STDIN_FILENO, &oldattr);
	newattr = oldattr;
	newattr.c_lflag &= ~(ICANON | ECHO);
	tcsetattr(STDIN_FILENO, TCSANOW, &newattr);
	ch = getchar();
	tcsetattr(STDIN_FILENO, TCSANOW, &oldattr);
	return ch;
}

// set up the level
void initLevel(char level[ROWS][COLS], int snakePos[1][2]) {

	// init level with spaces
	int currentRow;
	int currentCol;
	for (currentCol=0; currentCol<COLS; currentCol++) {
		for (currentRow=0; currentRow<ROWS; currentRow++) {
			level[currentRow][currentCol] = ' ';
		}
	}

	// calculate snake starting point
	snakePos[0][0] = ROWS / 2;
	snakePos[0][1] = COLS / 2;

}

// read from keyboard and update the game
void updateLevel(char level[ROWS][COLS], int *runGame) {

	char keyPress = getch();
	switch (keyPress) {
		case 'w':
			printf("up");
			break;
		case 's':
			printf("down");
			break;
		case 'a':
			printf("left");
			break;
		case 'd':
			printf("right");
			break;
		case 'q':
			printf("exiting game");
			*runGame = 0;
			break;
		default:
			printf("wsad, q to exit");
	}
	//putchar(keyPress);
}

// draw the updated level
void drawLevel(char level[ROWS][COLS], int snakePos[1][2]) {

	int currentRow;
	int currentCol;
	for (currentCol=0; currentCol<COLS; currentCol++) {
		for (currentRow=0; currentRow<ROWS; currentRow++) {
			
			if (snakePos[0][0] == currentRow && snakePos[0][1] == currentCol) {
				// current snake head position
				printf("%c", SNAKE_HEAD);
			}
			else {
				// draw the level
				printf("%c", level[currentRow][currentCol]);
			}
			
		}
		// new line after row
		printf("\n");
	}

}

int main() {

	char level[ROWS][COLS];
	int snakePos[1][2] = { 0, 0 };
	int snakeLength = 0;
	int runGame = 1;

	initLevel(level, snakePos);

	// game loop
	while (runGame) {
		updateLevel(level, &runGame);
		drawLevel(level, snakePos);
	}

	return EXIT_SUCCESS;

}
