#ifndef __MCX_UTILS_HEADER__
#define __MCX_UTILS_HEADER__

#include <inttypes.h>
#include <limits.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
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

typedef unsigned char* bp;

void show_bytes(bp start, size_t len) {
  for (size_t i = 0; i < len; i++) {
    printf("%.2x ", start[i]);
  }
  printf(" (%ldb)\n", len);
}

void show_endian() {
  printf("Int Size: %ld, Pointer Size: %ld\n", sizeof(int), sizeof(void*));
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

void show_bits_by_byte(int val, int size) {
  // 这里是按实际值从高位到低位打印
  // high bit to low bit (littble endian)
  for (size_t i = size; i > 0; i--) {
    printf(BYTE_TO_BIN " ", BIN_FMT(val >> (i - 1) * 8));
  }
  printf("(0x%08x = %d)\n", val, val);
}

void show_bits_auto(int val) {
  int x = abs(val - 1);
  // 这里是按实际值从高位到低位打印
  // high bit to low bit (littble endian)
  if (x < 0xff) {
    show_bits_by_byte(val, 1);
  } else if (x < 0xffff) {
    show_bits_by_byte(val, 2);
  } else if (x < 0xffffff) {
    show_bits_by_byte(val, 3);
  } else {
    show_bits_by_byte(val, 4);
  }
}

void show_bits(int val) {
  // 这里是按实际值从高位到低位打印
  // high bit to low bit (littble endian)
  //   printf("Int ORG: dec:%d hex:0x%x addr:%p\n", val, val, pval);
  show_bits_by_byte(val, sizeof(int));
}

void show_hex_by_byte(int val, int size) {
  for (size_t i = size; i > 0; i--) {
    printf("%-4x %-4x ", val >> ((i - 1) * 8 + 4) & 0x0f,
           val >> (i - 1) * 8 & 0x0f);
  }
  printf("(0x%08x = %d)\n", val, val);
}

void show_hex_auto(int val) {
  int x = abs(val - 1);
  if (x < 0xff) {
    show_hex_by_byte(val, 1);
  } else if (x < 0xffff) {
    show_hex_by_byte(val, 2);
  } else if (x < 0xffffff) {
    show_hex_by_byte(val, 3);
  } else {
    show_hex_by_byte(val, 4);
  }
}

void show_hex(int val) { show_hex_by_byte(val, sizeof(int)); }

void show_bits_p(const char* prefix, int val) {
  printf("%s\t", prefix);
  show_bits(val);
}

#endif /* __MCX_UTILS_HEADER__ */
