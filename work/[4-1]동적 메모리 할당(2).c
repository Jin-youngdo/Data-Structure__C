// ���� �޸� �Ҵ� (����ü)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	char name[10];
	int age;
	double gpa;
} student;

int main(void) {

	student* s;

	s = (student*)malloc(sizeof(student));

	if (s == NULL) {
		fprintf(stderr, "�޸𸮰� �����ؼ� �Ҵ��� �� �����ϴ�.\n");
		exit(1);
	}

	strcpy_s(s->name, 10, "Park");
	// ����ü �����ͷ� ���� ������ ���� -> ���
	s->age = 20;
	s->gpa = 4.2;
	printf("s->name = %s\n", s->name);
	printf("s->age = %d\n", s->age);
	printf("s->gpa = %.2lf\n", s->gpa);

	free(s);
	return 0;
}