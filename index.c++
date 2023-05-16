#include <iostream>
#include <conio.h>
#include <windows.h>

const int BOARD_WIDTH = 40;
const int BOARD_HEIGHT = 20;
const char FROG = '@';
const char CAR = '#';
const char LOG = '=';
const char SAFE_ZONE = '_';

enum Direction { UP, DOWN, LEFT, RIGHT };

struct Position {
    int x;
    int y;
};

class FroggerGame {
private:
    char board[BOARD_HEIGHT][BOARD_WIDTH];
    Position frog;
    int score;

public:
    FroggerGame() {
        frog.x = BOARD_WIDTH / 2;
        frog.y = BOARD_HEIGHT - 1;
        score = 0;
        initializeBoard();
    }

    void initializeBoard() {
        for (int i = 0; i < BOARD_HEIGHT; i++) {
            for (int j = 0; j < BOARD_WIDTH; j++) {
                if (i == 0 || i == BOARD_HEIGHT - 1) {
                    board[i][j] = '=';
                } else {
                    board[i][j] = ' ';
                }
            }
        }
        board[frog.y][frog.x] = FROG;
    }

    void drawBoard() {
        system("cls");
        for (int i = 0; i < BOARD_HEIGHT; i++) {
            for (int j = 0; j < BOARD_WIDTH; j++) {
                std::cout << board[i][j];
            }
            std::cout << std::endl;
        }
        std::cout << "Score: " << score << std::endl;
    }

    void updateFrog(Direction direction) {
        board[frog.y][frog.x] = ' ';

        switch (direction) {
            case UP:
                frog.y--;
                break;
            case DOWN:
                frog.y++;
                break;
            case LEFT:
                frog.x--;
                break;
            case RIGHT:
                frog.x++;
                break;
        }

        if (frog.y == 0) {
            score++;
            frog.y = BOARD_HEIGHT - 1;
        }

        board[frog.y][frog.x] = FROG;
    }

    void runGame() {
        while (true) {
            drawBoard();

            if (kbhit()) {
                char key = getch();
                Direction direction = LEFT;

                switch (key) {
                    case 'w':
                        direction = UP;
                        break;
                    case 's':
                        direction = DOWN;
                        break;
                    case 'a':
                        direction = LEFT;
                        break;
                    case 'd':
                        direction = RIGHT;
                        break;
                }

                updateFrog(direction);
            }
        }
    }
};

int main() {
    FroggerGame game;
    game.runGame();

    return 0;
}
