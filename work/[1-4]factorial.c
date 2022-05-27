// 과제 4: 순환 팩토리얼 [재귀함수]
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int factorial(int n) {

	// 함수 반복(호출)수 확인
	printf("factorial(%d)\n", n); 
	// 재귀 함수의 경우 중단 지점을 반드시 설정해야함.
	if (n == 1 || n== 0)
		return(1);
	else
		return(n * factorial(n - 1));
}

int main(void) {

	int num, fact;

	printf("몇 팩토리얼(숫자입력)? ");
	scanf("%d", &num);

	fact = factorial(num);
	printf("\n%d! = %d", num, fact);

	return 0;
}