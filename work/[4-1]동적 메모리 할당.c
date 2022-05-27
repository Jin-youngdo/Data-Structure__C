// ���� �޸� �Ҵ�
#include <stdio.h>
#include <stdlib.h>
#define SIZE 6

int main(void) {

	int* p;
	int i;

	p = (int)malloc(SIZE * sizeof(int)); // �����޸� ����� ���� �ּ� ��ȯ

	if (p == NULL) {
		fprintf(stderr, "�޸𸮰� �����ؼ� �Ҵ��� �� �����ϴ�.\n");
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