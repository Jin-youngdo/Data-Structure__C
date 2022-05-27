// 2장 연습문제 21
#include <stdio.h>
#define WHITE 0
#define BLACK 1
#define WIDTH 10
#define HEIGHT 10

int screen[WIDTH][HEIGHT] = {
	{2, 2, 2, 2, 2, 2, 2, 2, 2, 2 },
	{2, 2, 2, 2, 2, 2, 2, 2, 2, 2 },
	{2, 2, 2, 2, 2, 2, 2, 2, 2, 2 },
	{2, 2, 2, 0, 0, 0, 0, 2, 2, 2 },
	{2, 2, 2, 0, 0, 0, 0, 2, 2, 2 },
	{2, 2, 2, 0, 0, 0, 0, 2, 2, 2 },
	{2, 2, 2, 0, 0, 0, 0, 2, 2, 2 },
	{2, 2, 2, 2, 2, 2, 2, 2, 2, 2 },
	{2, 2, 2, 2, 2, 2, 2, 2, 2, 2 },
	{2, 2, 2, 2, 2, 2, 2, 2, 2, 2 },
};

int read_pixel(int x, int y) {
	return screen[x][y];
}

void write_pixel(int x, int y, int color) {
	screen[x][y] = color;
}

void flood_fill(int x, int y) {
	if (read_pixel(x, y) == WHITE) {
		write_pixel(x, y, BLACK);
		if (x > 0)
			flood_fill(x - 1, y);
		if (x < (WIDTH - 1))
			flood_fill(x + 1, y);
		if (y > 0)
			flood_fill(x, y - 1);
		if (y < (HEIGHT - 1))
			flood_fill(x, y + 1);
	}
}

void result_print() {
	int i, j;

	for (i = 0; i < 10; i++) {
		for (j = 0; j < 10; j++)
			printf("%d ", screen[i][j]);
		printf("\n");
	}
}

int main() {
	
	printf("영역 채우기 대상 도형\n------------------------\n");
	result_print();

	flood_fill(4, 4);

	printf("안쪽을 채우는 순환 호출 함수 작동 \n------------------------\n");
	result_print();

	return 0;
}