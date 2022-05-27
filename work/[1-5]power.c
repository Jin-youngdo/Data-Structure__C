// °ÅµìÁ¦°ö °è»ê (Àç±Í)
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

double power(double x, int n) {

	if (n == 0)
		return 1;
	else if ((n % 2) == 0)		// nÀÌ Â¦¼öÀÎ °æ¿ì
		return power(x * x, n / 2);
	else						// nÀÌ È¦¼öÀÎ °æ¿ì
		return x * power(x * x, (n - 1) / 2);
}

int main(void) {

	int i, n;
	double x, result;

	printf("¸îÀÇ ¸î½Â(2ÀÇ 5½Â : 2.0 5 ÀÔ·Â)? ");
	scanf("%lf %d", &x, &n);
	
	result = power(x, n);

	printf("%.2fÀÇ %d½Â = %.2f\n", x, n, result);

	return 0;
}