// 2차원 배열 예제
#include <stdio.h>
#define ROW 3
#define COL 5

int main(void) {
	int arr[ROW][COL];

	int byte_size, size;
	byte_size = sizeof(arr); // 15 * 4 = 60
	size = sizeof(arr) / sizeof(arr[0]); // 60 / 20 = 3

	printf("배열의 바이트 크기 : %d\n", byte_size);
	printf("sizeof(arr[0]) : %d\n", sizeof(arr[0]));
	printf("배열의 크기 : %d행\n", size);

	for (int i = 0; i < ROW; i++) {
		for (int j = 0; j < COL; j++) {
			arr[i][j] = 0;
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}

	return 0;
}