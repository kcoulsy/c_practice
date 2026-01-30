#include <stdio.h>

void change(int x) {
  x = 100;
}

void change_ptr(int *x) { // declare it's a pointer in the definition
  // dereference and assign to 100
  *x = 100;
}

void swap(int *a, int *b) {
  int tmp = *a;
  *a = *b;
  *b = tmp;
}

int sum_array(int arr[], int size) {
  int value = 0;
  for (int i = 0; i < size; i++) {
    value += *(arr + i);
  }

  return value;
}

void make_all_zero(int arr[], int size) {
  for (int i = 0; i < size; i++) {
    *(arr + i) = 0;
  }
}

int main(void) {
  int x = 10;
  int *p = &x;

  // x is an int
  // &x is the "memory address of x"
  // p is "pointer to x"
  //
  // & = address of
  // * = dereference (go to what it points to)
  // * in declaration = pointer to
  //
  // p stores an address
  // *p accesses the value at that address

  // Visualization
  //      address   value
  // (x)  0x1000    10
  // (p)  0x2000    0x1000 <- pointing to the other address in memory
  //
  // *p is saying "go to 0x1000 and read the value"

  // Changing values
  *p = 20;
  // this would set the value of 0x1000 to 20

  // without using pointers
  int a = 10;
  change(a); // you'd think a would now be 100
  printf("%d\n", a); // but this prints 10
  // when we passed a into change it made a COPY

  change_ptr(&a); // pass the reference & memory address
  printf("%d\n", a); // now it prints 100


  // pointers and arrays
  int arr[3] = { 1, 2, 3 };
  // important to know that arr == &arr[0]

  int *arr_ptr = arr;

  printf("%d\n", *arr_ptr); // prints 1
  printf("%d\n", *(arr_ptr+1)); // prints 2

  // these are the same
  // arr[i] == *(arr+i)
  // this is why arrays decay to pointers and why bounds matter

  // looking at the memory
  // int arr[3] = { 10, 20, 30 }
  // address    value
  // 0x1000     10
  // 0x1004     20
  // 0x1008     30
  // arr IS NOT a pointer variable
  // arr IS a block of memory
  // but in most expressions arr decays into a pointer (automatically converts, c jargon)
  // basically int * pointing to the first element
  //
  // int *p = arr  (now p contains 0x1000)
  //
  // when you do p+1 c does NOT add 1 byte, it does:
  // p + (1 * sizeof(int))
  // 0x1000 + 4 = 0x1004
  //
  // arr[3] - internally c would write this as *(arr + 3)
  //
  // Two Different Things:
  // 1. Where the pointer lives
  // 2. What the pointer points to
  //
  // so back to this example
  // int arr[3] = { 10, 20, 30 }
  // int *p = arr;
  //
  //          address    value
  // arr[0]   0x1000     10
  // arr[1]   0x1004     20
  // arr[2]   0x1008     30
  // p        0x2000     0x1000
  //
  // *p would say read value at 0x1000, the first value of the arrays block of memory
  // *(p+2) would say read value at 0x1000 + (2 * sizeof(int)) == 0x1008
  //
  // need to make sure not to confuse the address of p with it having a value of another address
  //
  // pointer arithmetic uses: the VALUE stored in the pointer, NOT the address of the pointer itself.
  //
  // ELI5 version
  // p = a piece of paper with an address written on it
  // p lives in your pocket (0x2000)
  // p has "go to 0x1000" written on it
  // p + 1 would mean
  // look at the note, read 0x1000, add one element to that, "go to 0x1004"
  // but the note is still in your pocket at 0x2000!
  //
  // so since pointer arithmetic uses the value
  // int arr[3] = { 10, 20, 30 }
  // int *p = arr;
  // p++ would move to the next int -it's effectively p = p+1 so it's moving the value
  // p would still have 0x2000 address but now with a value of 0x1004


  // NULL pointers
  // int *p = NULL
  // (points to nothing, no address)
  // dereferencing this will crash so always check
  //
  //  if (p != NULL) {
  //    *p = 10
  //  }

  // common pointer bugs:
  //
  // uninitialized pointers
  // int *p;
  // *p = 10; // crash
  //
  // dereferencing NULL
  // int *p = NULL;
  // *p = 10; // crash
  //
  // out of bounds access
  // int arr[3];
  // arr[5] = 10; // memory corruption
  //
  // returning address of dead variables
  // int* bad(void) {
  //  int x = 10;
  //  return &x; // dead memory
  // }


  // pointer RULES to memorize
  // 1. Initialize pointers
  // 2. Never dereference unless valid
  // 3. Pass sizes with arrays
  // 4. Avoid clever pointer math
  // 5. One level of indirection at a time (avoid more than one level like **p or ***p)

  // Practice
  int first = 10;
  int second = 20;
  printf("Before: First: %d, Second %d \n", first, second);
  swap(&first, &second);
  printf("After: First: %d, Second %d \n", first, second);

  int nums[5] = { 1, 2, 3, 4, 5 };
  int sum = sum_array(nums, 5);
  printf("%d\n", sum);

  int before_nums[3] = { 1, 2, 3 };
  printf("%d, %d, %d\n", before_nums[0], before_nums[1], before_nums[2]);
  make_all_zero(before_nums, 3);
  printf("%d, %d, %d\n", before_nums[0], before_nums[1], before_nums[2]);

  // %p prints hexadecimal,
  // (void *) is casting it
  printf("%p\n", (void*)&x);


  // chars
  char str[] = "hello";
  // Address    Value
  // 0x2000     'h'
  // 0x2001     'e'
  // 0x2002     'l'
  // 0x2003     'l'
  // 0x2004     'o'
  // 0x2005     '\0'
  char *cp = str;
  // cp is 0x3000 pointing to 0x2000
  cp++;
  // cp make the value of cp 0x2001 (size of char is 1 so 0x2000 + (i * sizeof(char));

  // case 1: ar
  int ar[5] = { 1, 2, 3, 4, 5 };
  int *pr = ar;
  // ar     0x1000
  // pr     0x1000
  // pr + 1 0x1004
  //
  // case 2: &ar
  int (*q)[5] = &ar;
  // &ar = address of the whole array
  //
  // q      0x1000
  // q + 1  0x1000 + sizeof(arr) = 0x1000 + 20 = 0x1014
  //
  // 0x1000 ar[0]
  // 0x1004 ar[1]
  // 0x1008 ar[2]
  // 0x100C ar[3]
  // 0x1010 ar[4]
  // 0x1014 <- puts it here
  //
  // this matters because functions that accept arrays see int*  not &arr
  // multidimentional arrays also rely on this
  //
  int matrix[2][3];
  int (*ptr)[3] = matrix;

  // ptr+3 moves 3 ints (next row)




  return 0;
}
