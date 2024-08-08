#include <klibtest.h>

void test_strlen() {
  int r = 0;
  // 字符串
  r = strlen("hello world!");
  assert(r == 12);

  // null和空串
  r = strlen("");
  assert(r == 0);

  // 我在本机上使用glib测试发现会报segmentation fault
  // 因此我在实现strncmp的时候故意没有对NULL进行处理
  // r = strlen(NULL);
  // assert(r == 0);

  // 有\0在中间
  r = strlen("hello\0world!");
  assert(r == 5);

  // 非ascii码
  r = strlen("\t\n\r");
  assert(r == 3);
}

