#include "../model/todos.h"

typedef enum ViewState {
  Menu,
  List,
  Add,
  Remove,
  Exit
} ViewState;

ViewState screen_menu();
ViewState screen_todos(const TodoList todo_list);  // const - read only!
ViewState screen_add(TodoList todo_list);
ViewState screen_remove(TodoList todo_list);
