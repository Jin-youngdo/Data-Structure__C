// delete_array() : ������ ��ġ�� �ε����� �迭���� ����
#include <stdio.h>
#define SIZE 10

int delete_array(int array[], int n, int loc) {

	// ������ �ε��� ��ġ�� �ε��� +1�� ������ �ٲ��ֱ�
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