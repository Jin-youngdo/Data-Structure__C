// 1차원 배열 예제
#include <stdio.h>

int main(void) {

	int arr[5];
	int byte_size, size;

	byte_size = sizeof(arr); // int 자료형의 크기 4byte * 5 = 20
	printf("배열의 바이트 크기 : %d\n", byte_size);

	size = sizeof(arr) / sizeof(arr[0]); // (4*5)20 / 4 = 5
	printf("배열의 크기 : %d\n", size);

	for (int i = 0; i < size; i++) {
		arr[i] = 0;
		printf("%d ", arr[i]);
	}
	return 0;
}