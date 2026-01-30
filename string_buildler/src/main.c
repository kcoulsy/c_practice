
#include <stdio.h>
#include <stdlib.h>

int str_len(char letters[]) {
  int len = 0;
  int i = 0;
  while (letters[i] != '\0') {
    len++;
    i++;
  }
  return len;
}

char *make_str(char new_str[]) {
  int length = str_len(new_str);
  char *str = malloc(length + 1); // account for \0

  if (str == NULL) {
    printf("unable to allocate memory");
  }

  for (int i = 0; i < length; i++) {
    str[i] = new_str[i];
  }

  str[length] = '\0';

  return str;
}

void update_str(char *old_str, char new_str[]) {
  int length = str_len(new_str);

  old_str = realloc(old_str, length + 1); // account for \0

  for(int i = 0; i < length; i++) {
    old_str[i] = new_str[i];
  }
  old_str[length] = '\0';
}

void print_str(char *str) {
  int length = str_len(str);
  printf("%s (%d)\n", str, length);
}

int main(void) {
  char *a = make_str("Name");

  print_str(a);
  update_str(a, "New name");
  print_str(a);
  update_str(a, "Some");
  print_str(a);

  free(a);

  return 0;
}
