// �ݺ��� ��� �Ǻ���ġ���� ���
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int fibo(int n) {

	int n1 = 0;
	int n2 = 1;
	int n3 = 0;

	printf("%d %d ", n1, n2);

	for (int i = 2; i <= n; i++) {
		n3 = n1 + n2;
		n1 = n2;
		n2 = n3;
		printf("%d ", n3);
	}
	
	return n3;
}

int main(void) {

	int num;

	printf("�Ǻ���ġ �� �Է� : ");
	scanf("%d", &num);

	int result = fibo(num);

	return 0;
}