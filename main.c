#include <stdio.h>

char board[3][3];
const char PLAYER_ONE = 'X';
const char PLAYER_TWO = 'Y';

void print_board();
void reset_board();
int check_free_spaces();
void player_one_move();
void player_two_move();
void check_winner();
void print_winner(char);

int main() {

  // Title Screen
  printf("\n\n");
  printf("+------------------------------------------+\n");
  printf("|       Tic          Tac        ToESP32    |\n");
  printf("+------------------------------------------+\n");
  printf("\n");
  printf("+------------------------------------------+\n");
  printf("| Instructions:                            |\n");
  printf("|------------------------------------------|\n");
  printf("| Player 1 (You!) is X                     |\n");
  printf("| Player 2 (Not You!) is O                 |\n");
  printf("| Select Row, Column for your move         |\n");
  printf("+------------------------------------------+\n");
  printf("\n\n");

  reset_board();

  // get player one move
  player_one_move();
  // get player two move
  player_two_move();
  // is there a winner?
  check_winner();
  // No
  // yes

  return 0;
}

void print_board() {
  printf("    1   2   3\n");
  printf("  +-----------+\n");
  printf("1 | %c | %c | %c |\n", board[0][0], board[0][1], board[0][2]);
  printf("  |---|---|---|\n");
  printf("2 | %c | %c | %c |\n", board[1][0], board[1][1], board[1][2]);
  printf("  |---|---|---|\n");
  printf("3 | %c | %c | %c |\n", board[2][0], board[2][1], board[2][2]);
  printf("  +-----------+\n");
}

void reset_board() {
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      board[i][j] = ' ';
    }
  }
}

int check_free_spaces() {
  int free_spaces = 9;

  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      if (board[i][j] != ' ') {
        free_spaces--;
      }
    }
  }

  return free_spaces;
}

void player_one_move() {
  int x;
  int y;

  do {
    printf("\n\n");
    printf("Enter row: ");
    scanf(" %d", &x);
    x--;
    printf("\nEnter column: ");
    scanf(" %d", &y);
    y--;
    if (board[x][y] != ' ') {
      printf("Invalid move, try again\n\n");
    } else {
      board[x][y] = PLAYER_ONE;
    }

  } while (board[x][y] != ' ');
}

void player_two_move() {
  int x;
  int y;

  do {
    printf("\n\n");
    printf("Enter row: ");
    scanf(" %d", &x);
    x--;
    printf("\nEnter column: ");
    scanf(" %d", &y);
    y--;
    if (board[x][y] != ' ') {
      printf("Invalid move, try again\n\n");
    } else {
      board[x][y] = PLAYER_TWO;
    }

  } while (board[x][y] != ' ');
}

void check_winner() {
  // check rows
  for (int i = 0; i < 3; i++) {
    if (board[i][0] == board[i][1] == board[i][2]) {
      // return winner
    }
  }
  // check columns
  for (int i = 0; i < 3; i++) {
    if (board[0][i] == board[1][i] == board[2][i]) {
      // return winner
    }
  }
  // check diagonals
  if (board[0][0] == board[1][1] == board[2][2]) {
    // return winner
  }
  if (board[0][2] == board[1][1] == board[2][0]) {
    // return winner
  }
  // return no winner
}

void print_winner(char winner) {
  if (winner == PLAYER_ONE) {
    printf("\n\n");
    printf("Player 1 is the winner!!\n");
    printf("Thanks for playing!\n");
  } else if (winner == PLAYER_TWO) {
    printf("\n\n");
    printf("Player 2 is the winner!!\n");
    printf("Thanks for playing!\n");
  } else {
    printf("\n\n");
    printf("It's a draw!!\n");
    printf("Thanks for playing!\n");
  }
}
