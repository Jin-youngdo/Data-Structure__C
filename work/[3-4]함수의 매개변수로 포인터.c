// �����͸� �Լ��� �Ű������� ��� (������ ���� ȣ��)
#include <stdio.h>

void swap(int* a, int* b) {
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

int main(void) {

	int a = 1, b = 2;

	printf("swap�� ȣ���ϱ� �� a=%d, b=%d\n", a, b);
	swap(&a, &b);

	printf("swap�� ȣ���ϱ� �� a=%d, b=%d\n", a, b);

	return 0;
}