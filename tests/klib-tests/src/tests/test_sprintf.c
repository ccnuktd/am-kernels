#include <klibtest.h>
#include <limits.h>

static int data[9] = {0, INT_MAX / 17, INT_MAX, INT_MIN, INT_MIN + 1,
              UINT_MAX / 17, UINT_MAX, -1, INT_MAX};

static char str[500];
static char str_cmp[500] = {"0\t126322567\t2147483647\t-2147483648\t-2147483647\t252645135\t-1\t-1\t-2147483648\t\0"};

void test_sprintf() {
	// %d测试
	data[8] += 1;
  	int pos = 0;
	for (int i = 0; i < 9; i ++) {
		pos += sprintf(str + pos, "%d\t", data[i]);
	}

	int r = strncmp(str, str_cmp, 100);
	assert(r == 0);
	
	// %s测试
	sprintf(str, "hello\0world");
	assert(strcmp(str, "hello") == 0);

	sprintf(str, "hello world");
	assert(strcmp(str, "hello world") == 0);

	sprintf(str, "");
	assert(strcmp(str, "") == 0);

	sprintf(str, "\r");
	assert(strcmp(str, "\r") == 0);

}