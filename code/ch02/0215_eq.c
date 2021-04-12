#include <inttypes.h>
#include <stdio.h>

/*

and     or
1 1 1   1 1 1
1 0 0   1 0 1
0 1 0   0 1 1
0 0 0   0 0 0


*/

int is_same(int x, int y) { return (x & y) && (x | y); }

int main(int argc, char const *argv[]) {
  printf("%02x == %02x ? %s\n", 12, 34, is_same(12, 34) ? "true" : "false");
  printf("%02x == %02x ? %s\n", 90, 90, is_same(90, 90) ? "true" : "false");
  return 0;
}
