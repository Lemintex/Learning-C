#include <stdio.h>
#include "aaronvector.h"

int main() {
	vector_h first;
	first.x = 2;
	first.y = 3;

	vector_h second;
	second.x = 5;
	second.y = -5;

	add(&first, &second);
	printf("first.x = %f\n", first.x);
	printf("first.y = %f\n", first.y);
	printf("second.x = %f\n", second.x);
	printf("second.y = %f\n", second.y);

	return 0;
}
