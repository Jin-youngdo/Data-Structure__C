// insert() 함수 : 배열의 원하는 인덱스에 값 삽입 
#include <stdio.h>
#include <string.h>
#define SIZE 10

int insert(int array[], int size, int loc, int value) {

	// 배열의 끝 숫자들을 +1 인덱스의 위치로 이동(loc index 제외) 
	for (int i = size; i >= loc; i--) 
		array[i + 1] = array[i];

	array[loc] = value;
	return size + 1;
}

int main(void) {
	int i, n, item;

	int list[SIZE+1] = { 1,2,3,4,5,6,7,8,9,10 };

	n = insert(list, SIZE-1, 5, 55);

	for (i = 0; i < n; i++)
		printf("%d ", list[i]);

	return 0;
}