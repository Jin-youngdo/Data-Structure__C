// �Ǻ���ġ ���� ���
#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS

// �Ǻ���ġ ������ ���(�ݺ���)
int fibo_loop(int num) {

	int n1 = 0;
	int n2 = 1;
	int n3;

	for (int i = 2; i <= num; i++) {
		n3 = n1 + n2;
		n1 = n2;
		n2 = n3;
	}
	return n3;
}

// �Ǻ���ġ ������ ���(��� ȣ��)
int fibo_rec(int num) {

	if (num == 0)
		return 0;
	if (num == 1)
		return 1;

	return fibo_rec(num - 1) + fibo_rec(num - 2);
}

int main(void) {

	int num, result;

	printf("�Ǻ���ġ ������ ũ�� ���� : ");
	scanf("%d", &num);
	result = fibo_loop(num);
	printf("�ݺ����� ����� �Ǻ���ġ ������ �� : %d\n", result);
	result = fibo_rec(num);
	printf("���ȣ���� ����� �Ǻ���ġ ������ �� : %d\n", result);

	return 0;
}