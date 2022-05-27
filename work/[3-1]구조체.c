#include <stdio.h>

typedef struct studentTag {
	char name[10];
	int age;
	double gpa;
} STUDENT;

int main(void) {

	printf("studentTag 구조체의 크기 = %d\n", sizeof(STUDENT));
	STUDENT a = { "kim", 20, 4.3 };
	printf("a 구조체의 크기 : %d\n", sizeof(a));
	printf("학생 a의 이름 : %s\n", a.name);
	printf("학생 a의 나이 : %d\n", a.age);
	printf("학생 a의 평점 : %.2f\n", a.gpa);
	return 0;
}