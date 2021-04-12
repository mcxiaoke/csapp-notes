#include "../utils.h"

int fun1(unsigned word) { return (int)((word << 24) >> 24); }
int fun2(unsigned word) { return ((int)word << 24) >> 24; }

void test_fun() {
  int x1 = 0x00000076;
  int x2 = 0x87654321;
  int x3 = 0x000000c9;
  int x4 = 0xedcba987;
  printf("\n");
  show_bits(x1);
  show_bits(fun1(x1));
  show_bits(fun2(x1));
  printf("\n");
  show_bits(x2);
  show_bits(fun1(x2));
  show_bits(fun2(x2));
  printf("\n");
  show_bits(x3);
  show_bits(fun1(x3));
  show_bits(fun2(x3));
  printf("\n");
  show_bits(x4);
  show_bits(fun1(x4));
  show_bits(fun2(x4));
}

void test_trucate() {
  int x = 53191;
  short sx = (short)x;
  int y = sx;
  show_bits(x);
  show_bits(sx);
  show_bits(y);
}

int main(int argc, char const *argv[]) {
  test_trucate();
  return 0;
}
