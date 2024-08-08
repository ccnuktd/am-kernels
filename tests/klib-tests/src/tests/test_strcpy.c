#include <klibtest.h>

#define N 32
static char src[N];
static char dst[N];

static void reset() {
  int i;
  for (i = 0; i < N; i ++) {
    src[i] = i + 1;
    dst[i] = i - 1;
    // 字符串考虑
    if (i == N - 1) src[i] = '\0';
  }
}

// 检查src[l,r)和dst[l + off, r + off)区间中的值是否相等
// 需要考虑\0截断
static void cmp_eq(int off) {
  int i;
  for (i = off; i < N; i ++) {
    assert(src[i] == dst[i - off]);
    if (src[i] == '\0') break;
  }
}

void test_strcpy() {
  reset();
  for (int off = 0; off < N; off ++) {
    strcpy(dst, src + off);
    cmp_eq(off);
  }

  // 考虑\0放在src中间的情况
  src[N / 2] = '\0';
  for (int off = 0; off < N; off ++) {
    strcpy(dst, src + off);
    cmp_eq(off);
  }
}

