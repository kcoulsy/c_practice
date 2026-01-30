#include "print.h"
#include "todos.h"
#include <stdio.h>
#include <stdlib.h>

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

ViewState screen_todos(TodoList todo_list) {
  clear_term();
  printf("Your TODOs:\n\n");

  for (int i = 0; i < *todo_list.count; i++) {
    printf("%d: %s", todo_list.list[i].id, todo_list.list[i].str);
  }

  printf("\nPress enter...\n");
  getchar(); // block terminal

  return Menu;
}

ViewState screen_add(TodoList todo_list) {
  clear_term();
  printf("Enter your todo:\n\n");

  Todo new_todo;
  new_todo.id = *todo_list.count + 1;
  fgets(new_todo.str, sizeof(new_todo.str), stdin);
  add_todo(&todo_list, new_todo);

  return Menu;
}

ViewState screen_remove(TodoList todo_list) {
  clear_term();
  printf("Enter the id of the todo to remove:\n\n");
  int id;
  scanf_s("%d", &id);
  clear_input_buffer();

  remove_todo(&todo_list, id);

  return Menu;
}

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
