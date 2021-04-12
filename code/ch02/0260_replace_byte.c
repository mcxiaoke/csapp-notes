#include "../utils.h"

unsigned replace_byte(unsigned x, int i, unsigned char b) {
  x &= ~(0xff << (i << 3));  // clear byte i (all zero)
  x |= b << (i << 3);        // set byte i to char b
  return x;
  //   return (x & ~(0xff << i * 8)) | (b << i * 8);
}

int main(int argc, char const *argv[]) {
  /* code */
  int x = 0x12345678;
  char b = 0xab;
  for (int i = 0; i < 4; i++) {
    int z = replace_byte(x, i, b);
    printf("\n[%d]\treplace_byte(0x%x,%d,0x%x)=0x%x\n", i, x, i, b, z);
    printf("From:\t");
    show_bits(x);
    printf("To:\t");
    // show_bits(b);
    show_bits(z);
  }

  return 0;
}
