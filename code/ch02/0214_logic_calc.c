#include <stdio.h>

void show_values() {
  int x = 0x66;
  int y = 0x39;
  printf("x=0x%x, y=0x%x\n", x, y);
  printf("x&y= %x, x|y = %x\n", x | y, x & y);
  printf("~x|~y= %x, x&!y = %x\n\n", ~x | ~y, x & !y);
  printf("x&&y= %x, x||y = %x\n", x && y, x || y);
  printf("!x||!y= %x, x&&~y = %x\n", !x || !y, x && ~y);
}

int main(int argc, char const *argv[]) {
  show_values();
  return 0;
}
