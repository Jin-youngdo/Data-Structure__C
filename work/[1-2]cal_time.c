// 과제2: 프로그램의 수행시간 측정하기 
#include <stdio.h>
#include <stdlib.h>
#include <time.h> // clock_t 자료형, clock() 함수 

int main(void) {

	clock_t start, end;
	
	start = clock(); // 측정 시작
	
	// 수행시간을 도출하기 위한 의미없는 반복문
	for (int i = 0; i < 199999990; i++) {};

	end = clock();  // 측정 종료 

	double duration = (double)(end - start) / CLOCKS_PER_SEC;

	printf("수행시간은 %f초입니다.\n", duration);

	return 0;
}