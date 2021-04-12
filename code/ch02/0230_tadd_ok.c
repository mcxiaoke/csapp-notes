#include "../utils.h"

int tadd_ok(int x, int y) {
  int z = x + y;
  if (x > 0 && y > 0 && z <= 0) {
    return 0;
  }
  if (x < 0 && y < 0 && z >= 0) {
    return 0;
  }
  return 1;
}

int main(int argc, char const *argv[]) {
  int x = -1000000000;  // int max: 2147483647
  int y = -2077665544;
  printf("tadd(%d,%d=%d) ok? %d\n", x, y, x + y, tadd_ok(x, y));
  x = 1000000000;
  y = 2077665544;
  printf("tadd(%d,%d=%d) ok? %d\n", x, y, x + y, tadd_ok(x, y));
  x = 0;
  y = 2147483647;
  printf("tadd(%d,%d=%d) ok? %d\n", x, y, x + y, tadd_ok(x, y));
  return 0;
}
