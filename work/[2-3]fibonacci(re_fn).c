// ���ȣ���� �̿��� �Ǻ���ġ ����
// �ð����⵵�� ���� ������ �ݺ��� > ���ȣ��
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int fibo(int n) {

	if (n == 0) return 0;
	if (n == 1) return 1;

	return (fibo(n - 1) + fibo(n - 2));
}

int main(void) {

	int num, result;

	printf("�Ǻ���ġ �� �Է� : ");
	scanf("%d", &num);
	
	for (int i = 0; i < num; i++) {
		printf("%d ", fibo(i));
	}

	return 0;
}

