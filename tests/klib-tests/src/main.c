#include <klibtest.h>

int main(const char *args) {
  test_memset();
  test_memcpy();
  test_memmove();
  test_strcpy();
  test_strncpy();
  test_strcat();
  test_strcmp();
  test_strncmp();
  test_strlen();
  test_memcmp();

  test_sprintf();
  return 0;
}
