#ifndef __MCX_UTILS_HEADER__
#define __MCX_UTILS_HEADER__

#include <inttypes.h>
#include <limits.h> /* for CHAR_BIT */
#include <stdio.h>
#include <string.h>

#ifndef CHAR_BIT
#define CHAR_BIT 8
#endif

// https://stackoverflow.com/questions/47981

// from http://c-faq.com/misc/bitsets.html
#define BITMASK(b) (1 << ((b) % CHAR_BIT))
#define BITSLOT(b) ((b) / CHAR_BIT)
#define BITSET(a, b) ((a)[BITSLOT(b)] |= BITMASK(b))
#define BITCLEAR(a, b) ((a)[BITSLOT(b)] &= ~BITMASK(b))
#define BITTEST(a, b) ((a)[BITSLOT(b)] & BITMASK(b))
#define BITNSLOTS(nb) ((nb + CHAR_BIT - 1) / CHAR_BIT)

#define BYTE_TO_BIN "%c%c%c%c%c%c%c%c%c"
#define BIN_FMT(byte)                                            \
  (byte & 0x80 ? '1' : '0'), (byte & 0x40 ? '1' : '0'),          \
      (byte & 0x20 ? '1' : '0'), (byte & 0x10 ? '1' : '0'), ' ', \
      (byte & 0x08 ? '1' : '0'), (byte & 0x04 ? '1' : '0'),      \
      (byte & 0x02 ? '1' : '0'), (byte & 0x01 ? '1' : '0')

void show_endian() {
  int x = 0x1234;
  char* p = (char*)&x;
  if (p[0] == 0x34 && p[1] == 0x12) {
    printf("Byte Order: Little Endian!\n");
  } else {
    printf("Byte Order: Big Endian!\n");
  }
}

void show_address(void* start, size_t len) {
  // 这里是按计算机存储地址从低位到高位打印
  printf("Addressdd: ");
  for (size_t i = 0; i < len; i++) {
    printf("%p ", start + i);
  }
  printf(" (%ldb)\n", len);
}

/**
 *
 * 0x01234567
 * 地址低到高
 * LOW --> HIGH
 * 67 45 23 01 (little endian)
 * 01 23 45 67 (big endian)
 *
 * */
void show_byte_binary(unsigned char* start, size_t len) {
  // 这里是按计算机存储地址从低位到高位打印
  // low bit to high bit (little endian)
  //   printf("Binary:  ");
  for (size_t i = 0; i < len; i++) {
    // int x = start[i];
    printf(BYTE_TO_BIN " ", BIN_FMT(start[i]));
  }
  printf(" (%ldb)\n", len);
}

void show_binary(int* pval) {
  unsigned char* start = (unsigned char*)pval;
  size_t len = sizeof(int);
  //   show_address(start, len);
  show_byte_binary(start, len);
}

void show_bits(int val) {
  // 这里是按实际值从高位到低位打印
  // high bit to low bit (littble endian)
  //   printf("Int ORG: dec:%d hex:0x%x addr:%p\n", val, val, pval);
  //   printf("Int HEX: %4x %4x %4x %4x %4x %4x %4x %4x\n", val >> 28 & 0x0f,
  //          val >> 24 & 0x0f, val >> 20 & 0x0f, val >> 16 & 0x0f, val >> 12 &
  //          0x0f, val >> 8 & 0x0f, val >> 4 & 0x0f, val & 0x0f);
  printf(
      "BIN: " BYTE_TO_BIN " " BYTE_TO_BIN " " BYTE_TO_BIN " " BYTE_TO_BIN "\n",
      BIN_FMT(val >> 24), BIN_FMT(val >> 16), BIN_FMT(val >> 8), BIN_FMT(val));
}

#endif /* __MCX_UTILS_HEADER__ */
