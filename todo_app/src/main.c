#include "ui/screens.h"
#include <stdlib.h>

void render(ViewState *state, TodoList todo_list) {
  switch(*state) {
    case List:
      *state = screen_todos(todo_list);
      break;
    case Add:
      *state = screen_add(todo_list);
      break;
    case Remove:
      *state = screen_remove(todo_list);
      break;
    case Menu:
      *state = screen_menu();
      break;
    default:
      break;
  }

  if (*state != Exit) {
    render(state, todo_list);
  }
}

int main(void) {
  ViewState state = Menu;
  int *count = malloc(sizeof(int));
  *count = 0;
  int initial_capacity = 10;
  Todo *todos = malloc(initial_capacity * sizeof(Todo));
  TodoList todo_list = {
    .count= count,
    .list = todos
  };

  render(&state, todo_list);
  return 0;
}
