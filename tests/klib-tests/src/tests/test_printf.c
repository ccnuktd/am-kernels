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

	// %05s
	// char a[4] = "asd";
	// ret = printf("%05s\n", a);
	// assert(ret == 6);

	// char b[8] = "asdasdf\n";
	// ret = printf("%05s", b);
	// assert(ret == strlen(b));

	// //%2s
	// char c[4] = "asd";
	// ret = printf("%5s\n", c);
	// assert(ret == 6);

	// char d[8] = "asdasdf\n";
	// ret = printf("%5s", d);
	// assert(ret == strlen(d));

	//%x
	int e = -1;
	printf("e:%x\n", e);
}