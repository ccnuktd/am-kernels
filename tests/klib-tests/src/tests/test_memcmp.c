#include <klibtest.h>

void test_memcmp() {
  int r = 0;
  // 空串
  r = memcmp("", "", 0);
  assert(r == 0);

  r = memcmp("", "", 10);
  assert(r == 0);

  // 相同字符串
  r = memcmp("hello", "hello", 5);
  assert(r == 0);

  // 我在本机上使用glib测试发现会报segmentation fault
  // 因此我在实现memcmp的时候故意没有对NULL进行处理
  // // null
  // r = memcmp(NULL, "hello");
  // assert(r < 0);

  // r = memcmp(NULL, NULL);
  // assert(r == 0);

  // 长度不等
  r = memcmp("hello", "hello\n", 6);
  assert(r < 0);

  r = memcmp("hello", "Helloa", 5);
  assert(r > 0);

  r = memcmp("hello", "Helloa", 0);
  assert(r == 0);
}

