#include "list.h"

// Note this is not a complete linked list, doesn't include getting or removing
// values etc. Just basic to practice some structs and references

int main(void) {

  Node *head = create_node(5);
  insert_at_head(&head, 10);
  insert_at_tail(&head, 20);
  insert_at_tail(&head, 3);
  insert_at_tail(&head, 3);
  insert_at_tail(&head, 2);
  delete_all_by_value(&head, 3);

  print_list(head);

  return 0;
}
