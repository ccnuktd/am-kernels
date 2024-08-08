#include <klibtest.h>

#define N 32
static char src[N];
static char dst[N];

static void reset() {
  int i;
  for (i = 0; i < N; i ++) {
    src[i] = i + 1;
    dst[i] = i - 1;
    if (i == N - 1) src[i] = '\0';
  }
}

// 检查src[l,r)和dst[l + off, r + off)区间中的值是否相等
static void cmp_eq(int l, int r, int off) {
  int i;
  for (i = l; i < r; i ++) {
    assert(src[i] == dst[i + off]);
    if (src[i] == '\0') break;
  }
}

void test_strncpy() {
  reset();

  for (int i = 0; i <= N; i ++) {
    for (int j = 0; i + j <= N; j ++) {
      strncpy(dst + j, src, i);
      cmp_eq(0, i, j);
    }
  }

  src[N / 2] = '\0';
  for (int i = 0; i <= N; i ++) {
    for (int j = 0; i + j <= N; j ++) {
      strncpy(dst + j, src, i);
      cmp_eq(0, i, j);
    }
  }
}

