// ����2: ���α׷��� ����ð� �����ϱ� 
#include <stdio.h>
#include <stdlib.h>
#include <time.h> // clock_t �ڷ���, clock() �Լ� 

int main(void) {

	clock_t start, end;
	
	start = clock(); // ���� ����
	
	// ����ð��� �����ϱ� ���� �ǹ̾��� �ݺ���
	for (int i = 0; i < 199999990; i++) {};

	end = clock();  // ���� ���� 

	double duration = (double)(end - start) / CLOCKS_PER_SEC;

	printf("����ð��� %f���Դϴ�.\n", duration);

	return 0;
}