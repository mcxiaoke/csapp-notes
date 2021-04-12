#include "../utils.h"

int strlonger(char* s, char* t) {
  // buggly if s.len < t.len
  // size_t is unsigned
  // unsigned small - big is very big
  //   return strlen(s) - strlen(t) > 0;
  // correct
  return strlen(s) > strlen(t);
}

int main(int argc, char const* argv[]) {
  size_t x = 0;
  size_t y = x - 12;
  int z = (int)y;
  show_bits(y);
  show_bits(z);
  char* s = "OK";
  char* t = "Hello, World!";
  printf("x=%lu,y=%lu,z=%d\n", x, y, z);
  printf("s=%lu,t=%lu,s-t=%lu\n", strlen(s), strlen(t), strlen(s) - strlen(t));
  printf("[%s] is longer than [%s] ? %u\n", s, t, strlonger(s, t));
  return 0;
}
