#include <stdlib.h>
#include <stdio.h>

void clear_term() {
  system("cls");
}

void print_menu() {
  clear_term();
  printf("Welcome to your todo list!\n\n");
  printf("1. View Todos\n");
  printf("2. Add Todo\n");
  printf("3. Remove \n");
  printf("\n");
}

void print_todos() {
  clear_term();
  printf("Your TODOs:\n\n");

  // print todos when we have them

  printf("Type anything to go back");
}
