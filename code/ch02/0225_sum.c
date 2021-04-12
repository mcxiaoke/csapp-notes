#include "../utils.h"

// segment fault if length = 0
// unsigned 0-1 = 4294967295
// but signed array index = -1
// a[-1], so crash
float sum_elements(float a[], unsigned length) {
  int i;
  float result = 0;
  // will crash, overflow
  //   for (i = 0; i < length - 1; i++) {
  // change to :
  for (i = 0; i < length; i++) {
    result += a[i];
  }
  return result;
}

void test_sum() {
  float a[] = {1, 3, 5, 7, 9};
  printf("sum=%f, ", sum_elements(a, 0));
  printf("sum=%f, ", sum_elements(a, 1));
  printf("sum=%f, ", sum_elements(a, 2));
  printf("sum=%f, ", sum_elements(a, 3));
  printf("sum=%f, ", sum_elements(a, 4));
  printf("sum=%f", sum_elements(a, 5));
}

int main(int argc, char const *argv[]) {
  //   unsigned x = 0;
  //   unsigned y = x - 1;
  //   printf("x=%u,y(u)=%u,y=%d\n", x, y, y);
  //   show_bits(x);
  //   show_bits(y);
  test_sum();
  return 0;
}
