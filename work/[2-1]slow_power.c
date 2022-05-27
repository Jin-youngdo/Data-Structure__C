// �ݺ����� �ŵ����� 
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

double slow_power(double x, int n) {
	
	double result = 1.0;

	for (int i = 0; i < n; i++) {
		result = result * x;
	}

	return result;
}

int main(void) {

	int n;
	double x;

	printf("���� ���(2^5: 2.0 5 �Է�)? ");
	scanf("%lf %d", &x, &n);

	double result = slow_power(x, n);

	printf("%.2lf�� %d�� = %.4lf\n", x, n, result);
	return 0;
}