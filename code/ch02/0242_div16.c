#include "../utils.h"

// https://github.com/Vonng/CSAPP/blob/master/ch2/s2-3.md

int div16(int x) {
  // p73,p74
  int bias = (x >> 31) & 0xF;
  return (x + bias) >> 4;
  // return x < 0 ? (x + (1 << 4) - 1) >> 4 : x >> 4;
}

int main(int argc, char const *argv[]) {
  /* code */
  int x = 4099;
  printf("A: %d / 16 = %d\n", x, x / 16);
  printf("B: %d / 16 = %d\n", x, div16(x));
  x = 32;
  printf("A: %d / 16 = %d\n", x, x / 16);
  printf("B: %d / 16 = %d\n", x, div16(x));
  x = -1234;
  printf("A: %d / 16 = %d\n", x, x / 16);
  printf("B: %d / 16 = %d\n", x, div16(x));
  return 0;
}
