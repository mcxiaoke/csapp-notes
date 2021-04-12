#include <stdio.h>

void print_array(int a[], int cnt) {
  for (size_t i = 0; i < cnt; i++) {
    printf("%d ", a[i]);
  }
  printf("\n");
}

void bit_swap(int *x, int *y) {
  *y = *x ^ *y;
  *x = *x ^ *y;
  *y = *x ^ *y;
}

void reverse_array(int a[], int cnt) {
  int first, last;
  for (first = 0, last = cnt - 1; first < last; first++, last--) {
    bit_swap(&a[first], &a[last]);
  }
}

void test_xor() {
  int array1[] = {1, 2, 3, 4, 5, 6, 7};
  int array2[] = {1, 3, 5, 7, 9};
  int cnt1 = sizeof(array1) / sizeof(array1[0]);
  int cnt2 = sizeof(array2) / sizeof(array2[0]);
  print_array(array1, cnt1);
  reverse_array(array1, cnt1);
  print_array(array1, cnt1);
  print_array(array2, cnt2);
  reverse_array(array2, cnt2);
  print_array(array2, cnt2);
}

int main(int argc, char const *argv[]) {
  test_xor();
  return 0;
}
