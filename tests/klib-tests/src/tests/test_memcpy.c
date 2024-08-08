#include <klibtest.h>

#define N 32
static uint8_t src[N];
static uint8_t dst[N + 1];

static void reset() {
  int i;
  for (i = 0; i < N; i ++) {
    src[i] = i + 1;
    dst[i] = i - 1;
  }
}

// 检查src[l,r)和dst[l + off, r + off)区间中的值是否相等
static void cmp_eq(int l, int r, int off) {
  int i;
  for (i = l; i < r; i ++) {
    assert(src[i] == dst[i + off]);
  }
}

void test_memcpy() {
  reset();

  for (int i = 0; i <= N; i ++) {
    for (int j = 0; i + j <= N; j ++) {
      memcpy(dst + j, src, i);
      cmp_eq(0, i, j);
    }
  }
}

