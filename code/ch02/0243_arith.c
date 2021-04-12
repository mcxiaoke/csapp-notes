#include "../utils.h"

#define M 15 /* Mystery number 1 */
#define N 8  /* Mystery number 2 */
int arith(int x, int y) {
  int result = 0;
  result = x * M + y / N;
  return result;
}

/* Translation of assembly code for arith */
int optarith(int x, int y) {
  int t = x;
  x <<= 5;
  x -= t; /*  x = x*32 -x，使用了形式 B的优化：`(x<<(n+1))-(x<<m)`，
 这里 n=4, m=0, 从而 M = [1111] = 15 */
  if (y < 0) y += 7; /* y + (1<<3)-1 */
  y >>= 3; /* Arithmetic shift，从而 N 为 2 的 3 次方，即为 8。*/
  return x + y;
}

int main(int argc, char const *argv[]) {
  /* code */
  return 0;
}
