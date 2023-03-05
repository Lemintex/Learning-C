#ifndef AARONVECTOR_H
#define AARONVECTOR_H

typedef struct vector {
	float x;
	float y;
} vector_h;

void add(vector_h* out, vector_h* in);

#endif
