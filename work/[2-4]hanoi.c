// �ϳ���ž ���� (���ȣ��) ��
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void hanoi_tower(int n, char from, char temp, char to) {

	if (n == 1) {
		printf("���� %d(��)�� %c���� %c�� �̵�\n", n, from, to);
		return;
	}
	else {
		// n-1 ������ A->B �� ��� C�� �̿��Ͽ� �ű��.
		hanoi_tower(n - 1, from, to, temp);
		printf("���� %d(��)�� %c���� %c�� �̵�\n", n, from, to);
		hanoi_tower(n - 1, temp, from, to);
	}
}

int main(void) {

	hanoi_tower(3, 'A', 'B', 'C');
	
	return 0;
}