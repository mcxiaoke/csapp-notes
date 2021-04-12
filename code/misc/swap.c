#include <stdio.h>

void swap_int(int* x, int* y) {
  int temp = *x;
  *x = *y;
  *y = temp;
}

int main(int argc, char const* argv[]) { return 0; }

// int main(int argc, char const* argv[]) {
//   int x = 2, y = 8;
//   printf("x=%d,y=%d\n", x, y);
//   swap_int(&x, &y);
//   printf("x=%d,y=%d\n", x, y);
//   return 0;
// }
