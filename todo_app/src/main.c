#include "print.h"
#include <stdio.h>

typedef enum ViewState {
  Menu,
  List,
  Add,
  Remove,
  Exit
} ViewState;

void clear_input_buffer() {
  // Clear the input buffer - remove leftover newline
  int c;
  while ((c = getchar()) != '\n' && c != EOF);
}

ViewState screen_menu() {
  print_menu();
  int input;
  scanf_s("%d", &input);
  clear_input_buffer();
  ViewState next_screen = Menu;
  switch(input) {
    case 1:
      next_screen = List;
      break;
    case 2:
      next_screen = Add;
      break;
    case 3:
      next_screen = Remove;
      break;
    case 4:
      next_screen = Exit;
      break;
  }

  return next_screen;
}

ViewState screen_todos() {
  print_todos();
  getchar(); // block terminal

  return Menu;
}

ViewState screen_add() {
  clear_term();
  printf("Enter your todo:\n\n");

  char todo_text[256];
  fgets(todo_text, sizeof(todo_text), stdin);

  return Menu;
}

ViewState screen_remove() {
  clear_term();
  printf("Enter the id of the todo to remove:\n\n");
  int id;
  scanf_s("%d", &id);

  return Menu;
}

void render(ViewState *state) {
  switch(*state) {
    case List:
      *state = screen_todos();
      break;
    case Add:
      *state = screen_add();;
      break;
    case Remove:
      *state = screen_remove();
      break;
    case Menu:
      *state = screen_menu();
      break;
    default:
      break;
  }

  if (*state != Exit) {
    render(state);
  }
}

int main(void) {
  ViewState state = Menu;

  render(&state);
  return 0;
}
