#include <inttypes.h>
#include <stdio.h>
#include <string.h>

#include "../utils.h"

typedef unsigned char* bp;

void show_single_char(const char* s) {
  for (size_t i = 0; i < strlen(s); i++) {
    printf("%2c ", s[i]);
  }
  printf(" (%ldb)\n", strlen(s));
}

void show_bytes(bp start, size_t len) {
  for (size_t i = 0; i < len; i++) {
    printf("%.2x ", start[i]);
  }
  printf(" (%ldb)\n", len);
}

void show_int(int x) {
  printf("As Integer:\t");
  show_bytes((bp)&x, sizeof(int));
}

void show_float(float x) {
  printf("As Float:\t");
  show_bytes((bp)&x, sizeof(float));
}

void show_pointer(void* x) {
  printf("As Pointer:\t");
  show_bytes((bp)&x, sizeof(void*));
}

void show_original(int* pval) {
  int val = *pval;
  // 这里是按实际值从高位到低位打印
  // high bit to low bit (littble endian)
  printf("Int ORG: dec:%d hex:0x%x addr:%p\n", val, val, pval);
  printf("Int HEX: %4x %4x %4x %4x %4x %4x %4x %4x\n", val >> 28 & 0x0f,
         val >> 24 & 0x0f, val >> 20 & 0x0f, val >> 16 & 0x0f, val >> 12 & 0x0f,
         val >> 8 & 0x0f, val >> 4 & 0x0f, val & 0x0f);
  printf("Int BIN: " BYTE_TO_BIN " " BYTE_TO_BIN " " BYTE_TO_BIN " " BYTE_TO_BIN
         "\n",
         BIN_FMT(val >> 24), BIN_FMT(val >> 16), BIN_FMT(val >> 8),
         BIN_FMT(val));
}

void test_show_bytes(int val) {
  int ival = val;
  float fval = (float)ival;
  int* pval = &ival;
  show_original(&val);
  show_binary(&val);
  show_int(ival);
  show_float(fval);
  show_pointer(pval);
}

void test_show_bytes2() {
  int val = 0x87654321;
  bp p = (bp)&val;
  show_bytes(p, 1);
  show_bytes(p, 2);
  show_bytes(p, 3);
  show_bytes(p, 4);

  const char* s = "123456";
  show_single_char(s);
  show_bytes((bp)s, strlen(s));
  s = "abcdef";
  show_single_char(s);
  show_bytes((bp)s, strlen(s));
}

int main(int argc, const char* argv[]) {
  test_show_bytes(0x123456);
  show_endian();
}
