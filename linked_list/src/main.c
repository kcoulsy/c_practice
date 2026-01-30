#include "list.h"

// Note this is not a complete linked list, doesn't include getting or removing values etc.
// Just basic to practice some structs and references

int main(void) {

  Node *head = create_node(5);
  Node *new_head = insert_at_head(head, 10);
  insert_at_tail(new_head, 20);
  insert_at_tail(new_head, 3);
  insert_at_tail(new_head, 2);

  print_list(new_head);

  return 0;
}
