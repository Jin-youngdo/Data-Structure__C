// ���丮�� �Լ�(�ݺ���)
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int factorial(int n) {

	int fact = 1;

	for (int i = 1; i <= n; i++) {
		fact *= i;
	}
	return fact;
}

int main(void) {

	int num;
	
	printf("�� ���丮��(�����Է�)? ");
	scanf("%d", &num);

	int fact = factorial(num);

	printf("%d! = %d", num, fact);
	return 0;
}