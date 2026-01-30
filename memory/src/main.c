#include <stdlib.h>
#include <stdio.h>

void some_func() {
  int x = 10;
  // x will dissappear when the function ends
}

struct Point {
  int x;
  int y;
}; // <- semi required for structs

struct Student {
  char name[64];
  int grade;
};

void add_student(struct Student *students, struct Student new_student, int *num_students) {
  students = realloc(students, *num_students + 1);
  students[*num_students] = new_student;
  *num_students = *num_students + 1;
}


int main(void) {
  int *p = malloc(sizeof(int)); // creates heap memory

  if (p == NULL) {
    printf("Memory allocation failed\n");;
    return 1;
  }

  *p = 42;
  printf("%d\n", *p);

  free(p);

  // Rules for malloc/calloc
  // 1. always check if it returns NULL
  // 2. always free() to avoid memory leaks
  // 3. pointer arithmetic works like arrays

  // Dynamically allocating
  int n;
  printf("Enter size: ");
  scanf_s("%d", &n);

  int *arr = malloc(n * sizeof(int)); // continuous n blocks of memory of size of int
  // *arr is pointing to that first block, just like an array pointer does
  for (int i = 0; i < n; i++) {
    arr[i] = i * 10;
    // same thing as *(arr + i) = i * 10
  }

  for (int i = 0; i < n; i++) {
    printf("%d ", arr[i]);
  }

  free(arr);

  printf("\n calloc: \n");

  // calloc - allocates and zeros memory
  int *arr2 = calloc(5, sizeof(int));

  for (int i = 0; i < 5; i++) {
    printf("%d ", arr2[i]);
  }
  // 0 0 0 0 0

  // realloc
  arr2 = realloc(arr2, 10 * sizeof(int));

  printf("\n realloc \n");

  for (int i = 0; i < 10; i++) {
    printf("%d ", arr2[i]);
  }
  // note: these new values are not zeros, it has old garbage in it
  // 0 0 0 0 0 0 520093982 8536 -1041694384 337

  free(arr2);

  // structs
  struct Point p1 = { .x = 10, .y = 5};
  printf("\n p1 \n %d %d\n", p1.x, p1.y);


  // pointers to struct
  struct Point *pp = &p1;
  printf("%d\n", (*pp).x);
  printf("%d\n", pp->x);  // arrow operator: equivalent to (*pp).x

  struct Student student = {
    .name = "Kristian",
    .grade = 10
  };

  printf("\nStudent: %s %d", student.name, student.grade);

  int *num_students = malloc(sizeof(int));

  if (num_students == NULL) {
    printf("failed to allocate memory");
    return 1;
  }

  *num_students = 0;

  struct Student *students = malloc(*num_students * sizeof(struct Student));

  // for (int i = 0; i < num_students; i++) {
  //   struct Student s = { .name="temp", .grade=i };
  //   students[i] = s;
  // }

  struct Student s1 = { .name = "Mike", .grade = 5};
  add_student(students, s1, num_students);
  struct Student s2 = { .name = "Kevin", .grade = 6};
  add_student(students, s2, num_students);
  struct Student s3 = { .name = "Ross", .grade = 2};
  add_student(students, s3, num_students);

  add_student(students, (struct Student){ .name = "Bob", .grade = 3 }, num_students);

  for (int i = 0; i < *num_students; i++) {
    printf("\n%d. %s %d", i, students[i].name, students[i].grade);
  }

  free(students);
  free(num_students);

  return 0;
}
