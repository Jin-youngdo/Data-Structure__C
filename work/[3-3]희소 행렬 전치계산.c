// 희소 행렬의 전치 계산 
#include <stdio.h>
#include <stdlib.h>
#define MAX_TERMS 100

typedef struct {
	int row;
	int col;
	int value;
} ELEMENT;

typedef struct SparseMatrix {
	ELEMENT data[MAX_TERMS];
	int rows;  // 행의 개수
	int cols;  // 열의 개수
	int terms; // 항의 개수
} SparseMatrix;

SparseMatrix matrix_transpose2(SparseMatrix a) {

	SparseMatrix b;
	int c, i, bindex; // 행렬 b에서 현재 저장 위치
	b.rows = a.rows;
	b.cols = a.cols;
	b.terms = a.terms;

	if (a.terms > 0) {
		bindex = 0;
		for (c = 0; c < a.cols; c++) {
			for (i = 0; i < a.terms; i++) {
				if (a.data[i].col == c) {
					b.data[bindex].row = a.data[i].col;
					b.data[bindex].col = a.data[i].row;
					b.data[bindex].value = a.data[i].value;
					bindex++;
				}
			}
		}
	}
	return b;
}

void matrix_print(SparseMatrix a) {
	int i;
	printf("=========================\n");

	for (i = 0; i < a.terms; i++)
		printf("(%d, %d, %d) \n", a.data[i].row, a.data[i].col, a.data[i].value);

	printf("=========================\n");
}

int main(void) {

	SparseMatrix m = {
		{{0, 3, 7},
		{1, 0, 9},
		{1, 5, 8},
		{3, 0, 6},
		{3, 1, 5},
		{4, 5, 1},
		{5, 2, 2}},
		6,
		6,
		7
	};
	SparseMatrix result;

	matrix_print(m);
	printf("\n------- transpose -------\n\n");
	result = matrix_transpose2(m);
	matrix_print(result);

	return 0;
}