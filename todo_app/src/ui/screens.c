#include "../utils/console.h"
#include "screens.h"
#include <stdio.h>

ViewState screen_menu() {
  clear_term();
  printf("Welcome to your todo list!\n\n");
  printf("1. View Todos\n");
  printf("2. Add Todo\n");
  printf("3. Remove \n");
  printf("4. Exit \n");
  printf("\n");

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
