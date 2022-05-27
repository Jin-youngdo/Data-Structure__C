// delete_array() : 제거할 위치의 인덱스를 배열에서 제거
#include <stdio.h>
#define SIZE 10

int delete_array(int array[], int n, int loc) {

	// 제거할 인덱스 위치를 인덱스 +1의 값으로 바꿔주기
	for (int i = loc; i < n; i++)
		array[i] = array[i + 1];

	return n-1;
}

int main(void) {

	int array[SIZE] = { 1,2,3,4,5,6,7,8,9,10 };
	int size = sizeof(array) / sizeof(array[0]);

	printf("items: %d\n", size);
	for (int i = 0; i < size; i++)
		printf("%d ", array[i]);
	printf("\n");

	size = delete_array(array, size, 6);
	printf("\n------ delete arr[6] ------\n");

	printf("\nitems: %d\n", size);
	for(int i = 0; i < size; i++)
		printf("%d ", array[i]);

	return 0;
}