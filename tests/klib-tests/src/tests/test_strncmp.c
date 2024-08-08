#include <klibtest.h>

void test_strncmp() {
  int r = 0;
  // 空串
  r = strncmp("", "", 100);
  assert(r == 0);

  // 相同字符串
  r = strncmp("hello", "hello", 100);
  assert(r == 0);

  // 我在本机上使用glib测试发现会报segmentation fault
  // 因此我在实现strncmp的时候故意没有对NULL进行处理
  // // null
  // r = strncmp(NULL, "hello", 100);
  // assert(r < 0);

  // r = strncmp(NULL, NULL, 0);
  // assert(r == 0);

  // 长度不等
  r = strncmp("hello", "helloa", 100);
  assert(r < 0);

  r = strncmp("hello", "helloa", 5);
  assert(r == 0);

  r = strncmp("hello", "Helloa", 100);
  assert(r > 0);
}

