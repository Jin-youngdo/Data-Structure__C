// 과제1: 가장 큰 값 구하기
#include <stdio.h>

int get_max_score(int scores[], int size) {

	int i, largest;
	largest = scores[0];

	for (i = 0; i < size; i++) {
		if (scores[i] > largest)
			largest = scores[i];
	}
	return largest;
}

int main(void) {

	int scores[10] = { 10, 20, 30, 40, 5, 70, 15, 25, 35, 61 };
	int size = sizeof(scores) / sizeof(scores[0]);
	int largest = get_max_score(scores, size);

	printf("The largest score is : %d", largest);

	return 0;
}