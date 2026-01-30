#include "print.h"
#include <stdio.h>

typedef enum ViewState {
  Menu,
  List,
  Add,
  Remove,
  Exit
} ViewState;


ViewState screen_menu() {
  print_menu();
  int input;
  scanf_s("%d", &input);
  ViewState next_screen = Menu;
  if (input == 1) {
    next_screen = List;
  }
  if (input == 2) {
    next_screen = Add;
  }
  if (input == 3) {
    next_screen = Remove;
  }

  return next_screen;
}

ViewState screen_todos() {
  print_todos();
  int tmp;;
  scanf_s("%d", tmp); // block terminal
  return Menu;
}


void render(ViewState *state) {
  switch(*state) {
    case List:
      *state = screen_todos();
    case Menu:
    default:
      *state = screen_menu();
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
