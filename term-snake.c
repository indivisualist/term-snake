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

// read from keyboard and act accordingly
void getInput(int *runGame) {

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
			printf("exiting game!");
			*runGame = 0;
			break;
		default:
			printf("wsad, q to exit");
	}
	//putchar(keyPress);
}

// make interesting stuff with the level
void updateLevel(char level[ROWS][COLS]) {
	// do stuff
}

// draw the updated level
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
		getInput(&runGame);
		updateLevel(level);
		drawLevel(level);
	}

	return EXIT_SUCCESS;

}
