#include <klibtest.h>
#include <limits.h>


void test_printf() {
	// %d测试
	int ret = printf("1+1=%d\n", 1 + 1);
	printf("total char: %d\n", ret);
	assert(ret == 6);

	ret = printf("hello world!\n");
	printf("total char: %d\n", ret);
	assert(ret == 13);
}