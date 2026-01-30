#include <stdlib.h>
#include <stdio.h>

void clear_term() {
  system("cls");
}

void clear_input_buffer() {
  // Clear the input buffer - remove leftover newline
  int c;
  while ((c = getchar()) != '\n' && c != EOF);
}
