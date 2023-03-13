#ifndef _ARRAY_H_
#define  _ARRAY_H_

#include <stdlib.h>
#include <time.h>

typedef struct array {
	struct array* self;

	int* data;
	size_t size;
	
	void (*pfnSet)(struct array*, size_t, int);
	int (*pfnGet)(struct array*, size_t);
}array_t;

int Get_array_t(array_t* self, size_t index);

void Set_array_t(array_t* self, size_t index, int value);

array_t* make_array(size_t capacity);

void delete_array(array_t* self);

#endif
