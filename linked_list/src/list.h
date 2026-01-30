
typedef struct Node {
  int value;
  struct Node *next_node;
} Node;

Node *create_node(int value);
Node *insert_at_head(Node *old_head, int value);
void insert_at_tail(Node *head, int value);
void print_list(Node *head);
