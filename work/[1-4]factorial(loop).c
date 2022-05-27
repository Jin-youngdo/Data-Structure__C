// 팩토리얼 함수(반복문)
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
	
	printf("몇 팩토리얼(숫자입력)? ");
	scanf("%d", &num);

	int fact = factorial(num);

	printf("%d! = %d", num, fact);
	return 0;
}