// 재귀호출을 이용한 피보나치 수열
// 시간복잡도가 높기 때문에 반복문 > 재귀호출
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int fibo(int n) {

	if (n == 0) return 0;
	if (n == 1) return 1;

	return (fibo(n - 1) + fibo(n - 2));
}

int main(void) {

	int num, result;

	printf("피보나치 수 입력 : ");
	scanf("%d", &num);
	
	for (int i = 0; i < num; i++) {
		printf("%d ", fibo(i));
	}

	return 0;
}

