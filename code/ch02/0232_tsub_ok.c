#include "../utils.h"

int tsub_ok(int x, int y) {
  int z = x - y;
  if (x < y && z >= 0) {
    return 0;
  }
  if (x > y && z <= 0) {
    return 0;
  }
  return 1;
}

int main(int argc, char const *argv[]) {
  int x = -1000000000;  // int max: 2147483647
  int y = 2077665544;
  printf("tsub(%d,%d=%d) ok? %d\n", x, y, x + y, tsub_ok(x, y));
  x = 1000000000;
  y = -2077665544;
  printf("tsub(%d,%d=%d) ok? %d\n", x, y, x + y, tsub_ok(x, y));
  x = -10;
  y = -2147483647;
  printf("tsub(%d,%d=%d) ok? %d\n", x, y, x + y, tsub_ok(x, y));
  return 0;
}
