// 2장 연습문제 14
#include <stdio.h>

double sum(int n) {

	if (n == 1) return 1;
	else return (1.0 / n) + sum(n - 1);

}

int main(void) {

	double result = sum(5);
	printf("%.2lf", result);

	return 0;
}