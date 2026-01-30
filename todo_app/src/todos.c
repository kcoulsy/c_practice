#include "todos.h"
#include <stdlib.h>

void add_todo(TodoList *todo_list, Todo todo) {
  int current_count = *todo_list->count;
  int new_count = current_count + 1;

  todo_list->list = realloc(todo_list->list, (new_count) * sizeof(Todo));
  todo_list->list[current_count] = todo;
  *todo_list->count = new_count;
}

void remove_todo(TodoList *todo_list, int id) {
  int found_index = -1;

  for (int i = 0; i < *todo_list->count; i++) {
    if (todo_list->list[i].id == id) {
      found_index = i;
      break;
    }
  }

  if (found_index == -1) {
    return;
  }

  // shift everything back 1
  for (int i = found_index; i < *todo_list->count - 1; i++) {
    todo_list->list[i] = todo_list->list[i + 1];
    todo_list->list[i].id = i + 1;
  }

  *todo_list->count = *todo_list->count - 1;
  todo_list->list = realloc(todo_list->list, (*todo_list->count) * sizeof(Todo));
}
