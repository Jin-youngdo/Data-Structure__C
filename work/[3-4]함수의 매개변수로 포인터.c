// 포인터를 함수의 매개변수로 사용 (참조에 의한 호출)
#include <stdio.h>

void swap(int* a, int* b) {
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

int main(void) {

	int a = 1, b = 2;

	printf("swap을 호출하기 전 a=%d, b=%d\n", a, b);
	swap(&a, &b);

	printf("swap을 호출하기 후 a=%d, b=%d\n", a, b);

	return 0;
}