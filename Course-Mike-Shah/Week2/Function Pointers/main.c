#include "array.h"
#include <stdio.h>

int main() {
	array_t* array = make_array(10);

	for (int i = 0; i < 10; i++) {
		array->pfnSet(array->self, i, i);
	}

	for (int i = 0; i < 10; i++) {
		printf("%d\n", array->pfnGet(array->self, i));
	}

	return 0;
}
