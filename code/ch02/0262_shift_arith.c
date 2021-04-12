#include "../utils.h"

int int_shift_are_arthimetic() {
  int x = -1;
  show_bits(-1);
  show_bits(-1 >> 1);
  show_bits(-1 ^ (-1 >> 1));
  show_bits(!(-1 ^ (-1 >> 1)));
  // sign bit, first bit is 1 for -1
  // -1 =           1111 1111 1111 1111 1111 1111 1111 1111
  // -1>>1 =        1111 1111 1111 1111 1111 1111 1111 1111
  // -1^(-1>>1)=    0000 0000 0000 0000 0000 0000 0000 0000
  // !(-1^(-1>>1))= 0000 0000 0000 0000 0000 0000 0000 0001
  return !(x ^ (x >> 1));
}

int main(int argc, char const *argv[]) {
  printf("int_shift_are_arthimetic = %s\n",
         int_shift_are_arthimetic() ? "true" : "false");
  return 0;
}
