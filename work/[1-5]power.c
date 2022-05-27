// �ŵ����� ��� (���)
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

double power(double x, int n) {

	if (n == 0)
		return 1;
	else if ((n % 2) == 0)		// n�� ¦���� ���
		return power(x * x, n / 2);
	else						// n�� Ȧ���� ���
		return x * power(x * x, (n - 1) / 2);
}

int main(void) {

	int i, n;
	double x, result;

	printf("���� ���(2�� 5�� : 2.0 5 �Է�)? ");
	scanf("%lf %d", &x, &n);
	
	result = power(x, n);

	printf("%.2f�� %d�� = %.2f\n", x, n, result);

	return 0;
}