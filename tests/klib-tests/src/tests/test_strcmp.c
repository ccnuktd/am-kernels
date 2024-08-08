#include <klibtest.h>

void test_strcmp() {
  int r = 0;
  // 空串
  r = strcmp("", "");
  assert(r == 0);

  // 相同字符串
  r = strcmp("hello", "hello");
  assert(r == 0);

  // 我在本机上使用glib测试发现会报segmentation fault
  // 因此我在实现strcmp的时候故意没有对NULL进行处理
  // // null
  // r = strcmp(NULL, "hello");
  // assert(r < 0);

  // r = strcmp(NULL, NULL);
  // assert(r == 0);

  // 长度不等
  r = strcmp("hello", "helloa");
  assert(r < 0);

  r = strcmp("hello", "Helloa");
  assert(r > 0);
}

