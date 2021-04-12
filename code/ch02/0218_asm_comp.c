#include "../utils.h"

int main(int argc, char const *argv[]) {
  /* code */
  //   show_bits(0x02e0);
  //   show_bits(0xa8);
  //   show_bits(0x28);
  //   show_bits(0xd0);
  //   show_bits(0x78);
  //   show_bits(0x88);
  //   show_bits(0x01f8);
  //   show_bits(0x08);
  //   show_bits(0xc0);
  //   show_bits(0xb8d4);
  short v = -12345;
  unsigned short uv = v;
  int x = v;
  unsigned ux = uv;
  show_bits_auto(v);
  show_bits_auto(uv);
  show_bits_auto(0xffff + 1);
  // 无符号数short = 有符号数short + 2**16
  show_bits_auto(v + 0x10000);
  show_bits_auto(x);
  show_bits_auto(ux);
  printf("\nv=%d,uv=%u\nx=%d,ux=%u\n", v, uv, x, ux);
  show_bytes((bp)&v, sizeof(short));
  show_bytes((bp)&uv, sizeof(unsigned short));
  show_bytes((bp)&x, sizeof(int));
  show_bytes((bp)&ux, sizeof(unsigned int));

  unsigned u = __UINT32_MAX__;
  int tu = (int)u;
  printf("u=%u, tu=%d\n", u, tu);
  show_bits_auto(-5);
  return 0;
}
