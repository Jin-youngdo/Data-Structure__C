// �������� 12��
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	int i;
	char str[20];
} TEST;

int main(void) {

	TEST* p = NULL;

	p = (TEST*)malloc(sizeof(TEST)); // ���� �޸� �Ҵ�
	if (p == NULL) {
		printf("memory error");
		return;
	}

	p->i = 100;
	strcpy(p->str, "just testing");
	printf("%d\n", p->i);
	printf("%s\n", p->str);

	free(p);

	return 0;
}