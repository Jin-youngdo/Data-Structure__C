// p.75 Quiz 1 - 4

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
	int x_coord;
	int y_coord;
}Coord;

double get_distance(Coord p1, Coord p2) {

	double dx = p1.x_coord - p2.x_coord;
	double dy = p1.y_coord - p2.y_coord;
	
	double distance = sqrt((dx * dx) + (dy * dy));

	return distance;
};

int main(void) {

	Coord p1 = { 1, 2 };
	Coord p2 = { 9, 8 };

	double distance = get_distance(p1, p2);

	printf("p1와 p2 점 사이의 거리 : %.2f\n", distance);

	return 0;
}