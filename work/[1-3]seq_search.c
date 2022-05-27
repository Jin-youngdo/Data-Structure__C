// 과제 3: 순차탐색
#include <stdio.h>

int seq_search(int list[], int size, int key) {

	int i;

	for (i = 0; i < size; i++) {
		if (list[i] == key)
			return i; // 키 인덱스 반환
	}
	return -1;
}

int main(void) {

	int x[10] = { 5, 9, 10, 17, 21, 29, 33, 37, 38, 43 };
	int size = sizeof(x) / sizeof(x[0]);
	
	int key_index = seq_search(x, size, 21);

	printf("key index : %d => list[%d]", x[key_index], key_index);

	return 0;
}