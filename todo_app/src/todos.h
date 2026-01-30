
typedef struct Todo {
  int id;
  char str[256];
} Todo;

typedef struct TodoList {
  int *count;
  Todo *list;
} TodoList;

void add_todo(TodoList *list, Todo todo);
void remove_todo(TodoList *list, int id);
