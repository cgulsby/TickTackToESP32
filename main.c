#include <stdio.h>

char board[3][3];

void print_board();

int main() {

  print_board();

  return 0;
}

void print_board() {

  printf("+-----------+\n");
  printf("| %c  | %c  | %c  |\n", board[0][0], board[0][1], board[0][2]);
  printf("|---|---|---|\n");
  printf("| %c  | %c  | %c  |\n", board[1][0], board[1][1], board[1][2]);
  printf("|---|---|---|\n");
  printf("| %c  | %c  | %c  |\n", board[2][0], board[2][1], board[2][2]);
  printf("+-----------+\n");
}
