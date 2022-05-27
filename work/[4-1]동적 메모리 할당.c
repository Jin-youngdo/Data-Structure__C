// 동적 메모리 할당
#include <stdio.h>
#include <stdlib.h>
#define SIZE 6

int main(void) {

	int* p;
	int i;

	p = (int)malloc(SIZE * sizeof(int)); // 동적메모리 블록의 시작 주소 반환

	if (p == NULL) {
		fprintf(stderr, "메모리가 부족해서 할당할 수 없습니다.\n");
		exit(1);
	}

	printf("p[SIZE] = { ");
	for (i = 0; i < SIZE; i++) {
		p[i] = i;
		printf("%d ", p[i]);
	}
	printf("}\n"); // 0 1 2 3 4 5  

	printf("sizeof(p) = %d\n", sizeof(p));  // 4
	printf("sizeof(*p) = %d\n", sizeof(*p)); // 4

	free(p);

	return 0;

}