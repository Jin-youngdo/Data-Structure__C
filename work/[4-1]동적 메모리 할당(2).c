// 동적 메모리 할당 (구조체)
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
		fprintf(stderr, "메모리가 부족해서 할당할 수 없습니다.\n");
		exit(1);
	}

	strcpy_s(s->name, 10, "Park");
	// 구조체 포인터로 값을 전달할 떄는 -> 사용
	s->age = 20;
	s->gpa = 4.2;
	printf("s->name = %s\n", s->name);
	printf("s->age = %d\n", s->age);
	printf("s->gpa = %.2lf\n", s->gpa);

	free(s);
	return 0;
}