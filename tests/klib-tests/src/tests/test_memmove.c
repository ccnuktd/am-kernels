#include <klibtest.h>

#define N 32
static uint8_t arr[2 * N];
static uint8_t cmp[N];
static uint8_t *src = arr + (N / 2);
static uint8_t *dst = arr + N;

static void reset() {
  int i;
  for (i = 0; i < 2 * N; i ++) {
    arr[i] = i;
  }
}

// 检查cmp[l,r)和dst[l + off, r + off)区间中的值是否相等
static void cmp_eq(int l, int r, int off) {
  int i;
  for (i = l; i < r; i ++) {
    assert(cmp[i] == dst[i + off]);
  }
}

// 考虑区间重叠
void test_memmove() {
  reset();

  for (int i = 0; i <= N; i ++) {
    for (int j = 0; i + j <= N; j ++) {
      memcpy(cmp, src, i);
      memmove(dst + j, src, i);
      cmp_eq(0, i, j);
    }
  }
}

