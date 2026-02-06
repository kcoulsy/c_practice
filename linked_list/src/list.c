#include "list.h"
#include <stdio.h>
#include <stdlib.h>

const int DELETE_SUCCESS = 1;
const int DELETE_NOT_FOUND = 0;

Node *create_node(int value) {
  Node *n = malloc(sizeof(Node));
  n->value = value;
  n->next_node = NULL;

  return n;
}

void insert_at_head(Node **head, int value) {
  Node *new_node = create_node(value);

  if (new_node == NULL) {
    return;
  }

  // linking old node to new head - must go first
  new_node->next_node = *head;
  // setting head to be the new node
  *head = new_node;
}

void insert_at_tail(Node **head, int value) {
  Node *new_node = create_node(value);

  if (new_node == NULL) {
    return;
  }

  if (*head == NULL) {
    return;
  }

  Node *current = *head;
  while (current->next_node != NULL) {
    current = current->next_node;
  }

  current->next_node = new_node;
}

void insert_at_position(Node **head, int value, int position) {
  if (position <= 0) {
    insert_at_head(head, value);
    return;
  }

  Node *new_node = create_node(value);

  if (new_node == NULL) {
    return;
  }

  if (*head == NULL) {
    *head = new_node;
    new_node->next_node = NULL;
    return;
  }

  int count = 0;

  Node *current = *head;
  Node *prev = NULL;
  while (count < position && current != NULL) {
    prev = current;
    current = current->next_node;
    count++;
  }

  if (prev != NULL) {
    prev->next_node = new_node;
  }

  new_node->next_node = current;
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

int delete_first_by_value(Node **head, int value) {
  if (*head == NULL) {
    return DELETE_NOT_FOUND;
  }

  if ((*head)->value == value) {
    Node *old = *head;
    *head = (*head)->next_node;
    free(old);
    return DELETE_SUCCESS;
  }

  Node *current = *head;

  while ((*current).next_node != NULL && (*current).next_node->value != value) {
    current = current->next_node;
  }

  if (current->next_node == NULL) {
    return DELETE_NOT_FOUND;
  }

  Node *temp = current->next_node;

  current->next_node = temp->next_node;
  free(temp);

  return DELETE_SUCCESS;
}

int delete_by_position(Node **head, int position) {
  if (*head == NULL || position < 0) {
    return DELETE_NOT_FOUND;
  }

  if (position == 0) {
    Node *old = *head;
    *head = (*head)->next_node;
    free(old);
    return DELETE_SUCCESS;
  }

  Node *current = *head;

  for (int i = 0; i < position - 1 && current != NULL; i++) {
    current = current->next_node;
  }

  if (current == NULL || current->next_node == NULL) {
    return DELETE_NOT_FOUND;
  }

  Node *temp = current->next_node;
  current->next_node = temp->next_node;
  free(temp);

  return DELETE_SUCCESS;
}

int delete_all_by_value(Node **head, int value) {
  if (*head == NULL) {
    return DELETE_NOT_FOUND;
  }

  int deleted_count = 0;
  Node *current = *head;
  Node *prev = NULL;

  // could be multiple at the head so handle that
  while (current != NULL && current->value == value) {
    Node *temp = current;
    current = temp->next_node;
    free(temp);
    deleted_count++;
  }

  // now the current value is the first non deleted so update head
  *head = current;

  while (current != NULL) {
    if (current->value == value) {
      Node *temp = current;
      prev->next_node = current->next_node;
      current = current->next_node;
      free(temp);
      deleted_count++;
    } else {
      prev = current;
      current = current->next_node;
    }
  }

  return (deleted_count > 0) ? DELETE_SUCCESS : DELETE_NOT_FOUND;
}
