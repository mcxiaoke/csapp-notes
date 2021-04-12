#include "../utils.h"

void test_complement() {
  short x = 12345;
  short mx = -x;
  show_hex_auto(x);
  show_bits_auto(x);
  show_hex_auto(mx);
  show_bits_auto(mx);
}

int main(int argc, char const *argv[]) {
  // printf("CHAR_BIT=%08x, ", CHAR_BIT);
  // printf("CHAR_MAX=%08x, ", CHAR_MAX);
  // printf("INT_MIN=%08x, ", INT_MIN);
  // printf("INT_MAX=%08x, ", INT_MAX);
  // printf("UINT_MAX=%08x\n", UINT_MAX);
  // test_complement();
  show_hex_auto(0);
  show_bits_auto(0);

  show_hex_auto(0xff);
  show_bits_auto(0xff);
  show_hex_auto(0xffffffff);
  show_bits_auto(0xffffffff);

  show_hex_auto(0xffff);
  show_bits_auto(0xffff);
  show_hex_auto(0xffffff00);
  show_bits_auto(0xffffff00);

  show_hex_auto(0xffffff);
  show_bits_auto(0xffffff);
  show_hex_auto(0xffff0000);
  show_bits_auto(0xffff0000);

  show_hex_auto(0x7fffffff);
  show_bits_auto(0x7fffffff);
  show_hex_auto(0xff000000);
  show_bits_auto(0xff000000);

  show_hex_auto(0x80000000);
  show_bits_auto(0x80000000);

  return 0;
}
