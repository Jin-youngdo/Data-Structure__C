// �迭�� �Լ��� �Ű������� �޴� ����
#include <stdio.h>
#define SIZE 6
#define _CRT_SECURE_NO_WARNINGS

void get_int(int arr[]) {

	printf("6���� ������ �Է��Ͻÿ� : ");

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
	printf("arr�� �� : %d\n", arr_sum(arr));
	return 0;
}