// ���� 4: ��ȯ ���丮�� [����Լ�]
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int factorial(int n) {

	// �Լ� �ݺ�(ȣ��)�� Ȯ��
	printf("factorial(%d)\n", n); 
	// ��� �Լ��� ��� �ߴ� ������ �ݵ�� �����ؾ���.
	if (n == 1 || n== 0)
		return(1);
	else
		return(n * factorial(n - 1));
}

int main(void) {

	int num, fact;

	printf("�� ���丮��(�����Է�)? ");
	scanf("%d", &num);

	fact = factorial(num);
	printf("\n%d! = %d", num, fact);

	return 0;
}