#include <stdio.h>
#include <stdlib.h>
#include "list.h"

Node *create_node(int value) {
  Node *n = malloc(sizeof(Node));
  n->value = value;
  n->next_node = NULL;

  return n;
}

Node *insert_at_head(Node *old_head, int value) {
  Node *new_head = create_node(value);
  new_head->next_node = old_head;
  return new_head;
}

void insert_at_tail(Node *head, int value) {
  Node *new_node = create_node(value);

  Node *current = head;
  while(current->next_node != NULL) {
    current = current->next_node;
  }

  current->next_node = new_node;
}

void print_list(Node *head) {
  Node *current = head;
  printf("[");
  while (current->next_node != NULL) {
    printf("%d, ", current->value);
    current = current->next_node;
  }
  printf("%d]", current->value);
}
