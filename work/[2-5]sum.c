// ¿Á±Õ «’ (¿Á±Õ »£√‚)
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int sum(int n) {

	if (n == 0 || n == 1)
		return 0;
	else
		return (n + sum(n - 1));
}

int main(void) {

	int num = 5;
	printf("sum(%d) : %d\n", num, sum(num));

	return 0;
}