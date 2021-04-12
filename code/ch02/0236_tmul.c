#include "../utils.h"

int tmul_ok_0235(int x, int y) {
  int p = x * y;
  return !x || (p / x == y);
}

int tmul_ok(int32_t x, int32_t y) {
  int64_t x2 = x;
  int64_t y2 = y;
  int64_t z = x * y;
  int64_t z2 = x2 * y2;
  int64_t m = INT32_MAX;
  int64_t n = INT32_MIN;
  printf("MUL: %d*%d=%d,z=%lld,z2=%lld,m=%lld,n=%lld\n", x, y, x * y, z, z2, m,
         n);
  return z2 == z;
}

int main(int argc, char const *argv[]) {
  /* code */
  int x = 1000;
  int y = 87654321;
  printf("tmul_ok(%d * %d) = %d ok? %d\n", x, y, x * y, tmul_ok(x, y));
  x = 87654321;
  y = -1000;
  printf("tmul_ok(%d * %d) = %d ok? %d\n", x, y, x * y, tmul_ok(x, y));
  x = 8765;
  y = 1000;
  printf("tmul_ok(%d * %d) = %d ok? %d\n", x, y, x * y, tmul_ok(x, y));
  show_bits(1754975080);
  show_bits(2147483647);
  show_bits(-2147483648);
  return 0;
}
