#include "aaronvector.h"

void add(vector_h* out, vector_h* in) {
	out->x += in->x;
	out->y += in->y;
}
