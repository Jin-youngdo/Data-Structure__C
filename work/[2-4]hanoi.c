// 하노이탑 문제 (재귀호출) ★
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void hanoi_tower(int n, char from, char temp, char to) {

	if (n == 1) {
		printf("원반 %d(을)를 %c에서 %c로 이동\n", n, from, to);
		return;
	}
	else {
		// n-1 원반을 A->B 로 기둥 C를 이용하여 옮긴다.
		hanoi_tower(n - 1, from, to, temp);
		printf("원반 %d(을)를 %c에서 %c로 이동\n", n, from, to);
		hanoi_tower(n - 1, temp, from, to);
	}
}

int main(void) {

	hanoi_tower(3, 'A', 'B', 'C');
	
	return 0;
}