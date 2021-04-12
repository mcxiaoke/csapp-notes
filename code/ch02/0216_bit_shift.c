#include <stdio.h>

#include "../utils.h"

// https://en.wikipedia.org/wiki/Bitwise_operations_in_C

int logicalRightShift(int x, int n) { return (unsigned)x >> n; }
int arithmeticRightShift(int x, int n) {
  if (x < 0 && n > 0)
    return x >> n | ~(~0U >> n);
  else
    return x >> n;
}

void show_shift(int x) {
  show_bits_p("Ori:", x);
  show_bits_p("<<3:", x << 3);
  show_bits_p(">>2l:", logicalRightShift(x, 2));
  show_bits_p(">>2a:", arithmeticRightShift(x, 2));
  printf("\n");
}

int main(int argc, char const *argv[]) {
  show_shift(0xc3);
  show_shift(0x75);
  show_shift(0x87);
  show_shift(0x66);
  show_shift(-0x876543);
  show_shift(-0xa9);
  // show_bits_by_byte(0xc3, 1);
  // show_bits_by_byte(0xc3, 2);
  // show_bits_by_byte(0xc3, 3);
  // show_bits_by_byte(0xc3, 4);
  // show_hex(0xc3);
  // show_bits(0xc3);
  // show_bits_auto(0xc3);
  // show_bits_auto(0x1234);
  // show_bits_auto(0x234567);
  // show_bits_auto(0x87654321);
  return 0;
}