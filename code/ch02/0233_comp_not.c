#include "../utils.h"

int main(int argc, char const *argv[]) {
  int x = 0x123456;
  // -x == ~x+1
  show_bits(x);
  show_bits(-x);
  show_bits(~x + 1);
  return 0;
}
