// 1���� �迭 ����
#include <stdio.h>

int main(void) {

	int arr[5];
	int byte_size, size;

	byte_size = sizeof(arr); // int �ڷ����� ũ�� 4byte * 5 = 20
	printf("�迭�� ����Ʈ ũ�� : %d\n", byte_size);

	size = sizeof(arr) / sizeof(arr[0]); // (4*5)20 / 4 = 5
	printf("�迭�� ũ�� : %d\n", size);

	for (int i = 0; i < size; i++) {
		arr[i] = 0;
		printf("%d ", arr[i]);
	}
	return 0;
}