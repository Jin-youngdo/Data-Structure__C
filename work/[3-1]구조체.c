#include <stdio.h>

typedef struct studentTag {
	char name[10];
	int age;
	double gpa;
} STUDENT;

int main(void) {

	printf("studentTag ����ü�� ũ�� = %d\n", sizeof(STUDENT));
	STUDENT a = { "kim", 20, 4.3 };
	printf("a ����ü�� ũ�� : %d\n", sizeof(a));
	printf("�л� a�� �̸� : %s\n", a.name);
	printf("�л� a�� ���� : %d\n", a.age);
	printf("�л� a�� ���� : %.2f\n", a.gpa);
	return 0;
}