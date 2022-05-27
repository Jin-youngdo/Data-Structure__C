// 배열을 함수의 매개변수로 받는 예제
#include <stdio.h>
#define SIZE 6
#define _CRT_SECURE_NO_WARNINGS

void get_int(int arr[]) {

	printf("6개의 정수를 입력하시오 : ");

	for (int i = 0; i < SIZE; i++)
		scanf("%d", &arr[i]);
}

int arr_sum(int arr[]) {

	int sum=0;

	for (int i = 0; i < SIZE; i++)
		// sum += *(arr + i)
		sum += arr[i];

	return sum;
}

int main(void) {

	int arr[SIZE];
	
	get_int(arr);
	printf("arr의 합 : %d\n", arr_sum(arr));
	return 0;
}