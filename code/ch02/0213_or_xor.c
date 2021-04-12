#include "../utils.h"

// set: set bit m of x to 1
// bis(0,0) = 0, bis(1,0) = 1
// bis(0,1) = 1, bis(1,1) = 1
// only same two = 0
int bis(int x, int m) {
  // 0xf9 = 1111 1001 x
  // 0x15 = 0001 0101 m
  // ret  = 1111 1101
  return x | m;
}

// clear: set bit m of x to 0
// bic(0,0) = 0, bic(1,0) = 1
// bic(0,1) = 0, bic(1,1) = 0
// only (1, 0) second zero = 1
int bic(int x, int m) {
  // ~ NOT, & AND, | OR, ^ XOR
  //   int r = x;
  //   r &= ~ m;
  // 0xf9  = 1111 1001 x
  // 0x15  = 0001 0101 m
  // ~0x15 = 1110 1010 ~m
  // ret   = 1110 1000 x&(~m)
  return x & (~m);
}

// https://recursive.in/2015/07/28/bis-bic-or-xor/
// https://cs.stackexchange.com/questions/134756

// ~x
int bool_not(int x) { return bic(0xFFFFFFFF, x); }

// x | y
int bool_or(int x, int y) { return bis(x, y); }

// x ^ y = (x & ~y) | (~x & y)
int bool_xor(int x, int y) { return bis(bic(x, y), bic(y, x)); }

int bool_and(int x, int y) { return 0; }

void test_bit_ops() {
  int x = 0x4321;
  printf("BIT SET 6:\n");
  show_bits(1UL << 6);
  show_bits(x);
  show_bits(bis(x, 6));
  printf("BIT CLEAR 8:\n");
  show_bits(1UL << 8);
  show_bits(x);
  show_bits(bic(x, 8));
}

void test_bool_or() {
  int x = 0x4321;
  int y = 0x8765;
  show_bits(x);
  show_bits(y);
  show_bits(bis(x, y));
}

void test_bool_xor() {
  int x = 0x4321;
  int y = 0x8765;
  show_bits(x);
  show_bits(y);
  // keep
  show_bits(bic(x, y));
  show_bits(bic(y, x));
  show_bits(bis(bic(x, y), bic(y, x)));
}

int main(int argc, char const *argv[]) {
  //   show_bits(0xf9);
  //   show_bits(0x15);
  //   show_bits(bis(0xf9, 0x15));
  //   show_bits(bic(0xf9, 0x15));
  //   show_bits(bool_not(0x15));
  test_bool_xor();
  return 0;
}
