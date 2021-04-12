#include "../utils.h"

/* $begin xdr_vulnerability */
/*
 * Illustration of code vulnerability similar to that found in
 * Sun's XDR library.
 */
void *copy_elements(void *ele_src[], int ele_cnt, size_t ele_size) {
  /*
   * Allocate buffer for ele_cnt objects, each of ele_size bytes
   * and copy from locations designated by ele_src
   */
  void *result = malloc(ele_cnt * ele_size);  // line:data:overflow
  if (result == NULL)                         /* malloc failed */
    return NULL;
  void *next = result;
  int i;
  for (i = 0; i < ele_cnt; i++) {  // line:data:copyloop
    /* Copy object i to destination */
    memcpy(next, ele_src[i], ele_size);
    /* Move pointer to next memory region */
    next += ele_size;
  }
  return result;
}
/* $end xdr_vulnerability */

void *better_copy_elements(void *ele_src[], int ele_cnt, size_t ele_size) {
  /*
   * Allocate buffer for ele_cnt objects, each of ele_size bytes
   * and copy from locations designated by ele_src
   */
  if (ele_cnt <= 0 || ele_size == 0) {
    return NULL;
  }
  if (SIZE_MAX / ele_size < ele_cnt) {
    return NULL;
  }

  void *result = malloc(ele_cnt * ele_size);  // line:data:overflow
  if (result == NULL)                         /* malloc failed */
    return NULL;
  void *next = result;
  int i;
  for (i = 0; i < ele_cnt; i++) {  // line:data:copyloop
    /* Copy object i to destination */
    memcpy(next, ele_src[i], ele_size);
    /* Move pointer to next memory region */
    next += ele_size;
  }
  return result;
}

int main(int argc, char const *argv[]) {
  /* code */
  return 0;
}
