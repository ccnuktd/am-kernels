#include <klibtest.h>

#define N 32
static char src[N];
static char dst[20 * N];

static void reset() {
  int i;
  for (i = 0; i < N; i ++) {
    src[i] = i + 1;
    dst[i] = i - 1;
    // 字符串考虑
    if (i == N - 1) src[i] = dst[i] = '\0';
  }
}

// 需要考虑\0截断
static void cmp_eq(int off, int pos) {
  int i;
  for (i = off; i < N; i ++) {
    assert(src[i] == dst[pos + i - off]);
    if (src[i] == '\0') break;
  }
}

int get_pos() {
  for (int i = 0; i < 20 * N; i ++) if (dst[i] == '\0') return i;
  return -1;
}

void test_strcat() {
  int pos = 0;

  reset();

  for (int off = 0; off < 4; off ++) {
    pos = get_pos();
    strcat(dst, src + off);
    cmp_eq(off, pos);
  }

  // 考虑\0放在src中间的情况
  src[N / 2] = '\0';
  for (int off = 0; off < N; off ++) {
    pos = get_pos();
    strcat(dst, src + off);
    cmp_eq(off, pos);
  }
}

