
typedef struct Node {
  int value;
  struct Node *next_node;
} Node;

Node *create_node(int value);
void insert_at_head(Node **old_head, int value);
void insert_at_tail(Node **head, int value);
void insert_at_position(Node **head, int value, int position);
void print_list(Node *head);

extern const int DELETE_SUCCESS;
extern const int DELETE_NOT_FOUND;

int delete_first_by_value(Node **head, int value);
int delete_all_by_value(Node **head, int value);
int delete_by_position(Node **head, int position);
int delete_list(Node **head);
