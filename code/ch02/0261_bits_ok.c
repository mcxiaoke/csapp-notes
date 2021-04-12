#include "../utils.h"

int check_bits(int x) {
  // A: !~x
  // B: !x
  // C: !~(x | ~0xff)
  // D: !((x >> ((sizeof(int)-1) << 3)) & 0xff)
  int m_shift = (sizeof(int) - 1) << 3;
  int msb = (x >> m_shift) & 0xff;
  int lsb = x & 0xff;
  int all_bits_is_1 = !(~x);
  int all_bits_is_0 = !x;
  // 0xffffff00 = ~0xff
  // y = x | 0xffffff00 : set all bits to 1 but keep lsb
  // z = ~(y) : set all bits to 0 except lsb, not lsb
  // r = ~z is 1 only if z = 0 (means ~lsb=0, means lsb=all 1)
  // 0xffffff00 = ~0x000000ff
  int lsb_mask = ~0xff;
  int all_lsb_is_1 = !(~(x | lsb_mask));
  //@@ int all_lsb_is_1 = !(~(x | 0xffffff00));
  // y = x | 0x00ffffff : set all bits to 1 but keep msb
  // z = ~(y) : set all bits to 0 except msb, ~msb
  // r = !z is 1 only if z = 0 (means ~msb=0, means msb=all 1)
  // as:8 = 2 << 3
  // as:3 = sizeof(int) - 1
  // as:0xff000000 = 0xff << 3*8
  // as:0x00ffffff = ~0xff000000
  // so:0x00ffffff = ~(0xff << ((sizeof(int)-1)<<3))
  int msb_mask = ~(0xff << ((sizeof(int) - 1) << 3));
  int all_msb_is_1 = !(~(x | msb_mask));
  //@@ int all_msb_is_1 = !(~(x | 0x00ffffff));
  printf("\n");
  show_bits(x);
  printf("all_1=%d \tall_0=%d \tmsb_1=%d \tlsb_1=%d\n", all_bits_is_1,
         all_bits_is_0, all_msb_is_1, all_lsb_is_1);
  return all_bits_is_1 || all_bits_is_0 || all_msb_is_1 || all_lsb_is_1;
}

int main(int argc, char const *argv[]) {
  int x = 0xffffffff;  // all_1=1 	all_0=0 	msb_1=1 	lsb_1=1
  printf("check_bits(0x%x)=%d\n", x, check_bits(x));
  x = 0x0;  // all_1=0 	all_0=1 	msb_1=0 	lsb_1=0
  printf("check_bits(0x%x)=%d\n", x, check_bits(x));
  x = 0xff;  // all_1=0 	all_0=0 	msb_1=0 	lsb_1=1
  printf("check_bits(0x%x)=%d\n", x, check_bits(x));
  x = 0xff000000;  // all_1=0 	all_0=0 	msb_1=1 	lsb_1=0
  printf("check_bits(0x%x)=%d\n", x, check_bits(x));
  x = 0x1;  // all_1=0 	all_0=0 	msb_1=0 	lsb_1=0
  printf("check_bits(0x%x)=%d\n", x, check_bits(x));
  x = 0xf0000000;  // all_1=0 	all_0=0 	msb_1=0 	lsb_1=0
  printf("check_bits(0x%x)=%d\n", x, check_bits(x));
  x = 0x12345;  // all_1=0 	all_0=0 	msb_1=0 	lsb_1=0
  printf("check_bits(0x%x)=%d\n", x, check_bits(x));
  x = 0xfabc;  // all_1=0 	all_0=0 	msb_1=0 	lsb_1=0
  printf("check_bits(0x%x)=%d\n", x, check_bits(x));
  x = 0x1050a0f0;
  printf("check_bits(0x%x)=%d\n", x, check_bits(x));
  x = 0x25ff;  // all_1=0 	all_0=0 	msb_1=0 	lsb_1=1
  printf("check_bits(0x%x)=%d\n", x, check_bits(x));
  x = 0xff123456;  // all_1=0 	all_0=0 	msb_1=1 	lsb_1=0
  printf("check_bits(0x%x)=%d\n", x, check_bits(x));
  x = 0xffabcdff;  // all_1=0 	all_0=0 	msb_1=1 	lsb_1=1
  printf("check_bits(0x%x)=%d\n", x, check_bits(x));
  return 0;
}
