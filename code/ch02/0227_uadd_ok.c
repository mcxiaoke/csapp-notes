#include "../utils.h"

int uadd_ok(unsigned x, unsigned y) {
  unsigned z = x + y;
  return (z < x || z < y) ? 0 : 1;
}

int main(int argc, char const *argv[]) {
  unsigned x = 0xfafbfcfd;
  unsigned y = 0x87654321;
  printf("uadd(%u,%u) ok? %d\n", x, y, uadd_ok(x, y));
  x = 0x1234;
  y = 0xabcd;
  printf("uadd(%u,%u) ok? %d\n", x, y, uadd_ok(x, y));
  show_bits(x);
  show_bits(~x);
  show_bits(0x100000000 - x);
  printf("x=%u,~x=%u,0x10000-x=%u\n", x, ~x, 0x10000 - x);
  return 0;
}
