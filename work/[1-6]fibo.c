// 피보나치 수열 계산
#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS

// 피보나치 수열의 계산(반복문)
int fibo_loop(int num) {

	int n1 = 0;
	int n2 = 1;
	int n3;

	for (int i = 2; i <= num; i++) {
		n3 = n1 + n2;
		n1 = n2;
		n2 = n3;
	}
	return n3;
}

// 피보나치 수열의 계산(재귀 호출)
int fibo_rec(int num) {

	if (num == 0)
		return 0;
	if (num == 1)
		return 1;

	return fibo_rec(num - 1) + fibo_rec(num - 2);
}

int main(void) {

	int num, result;

	printf("피보나치 수열의 크기 지정 : ");
	scanf("%d", &num);
	result = fibo_loop(num);
	printf("반복문을 사용한 피보나치 수열의 끝 : %d\n", result);
	result = fibo_rec(num);
	printf("재귀호출을 사용한 피보나치 수열의 끝 : %d\n", result);

	return 0;
}