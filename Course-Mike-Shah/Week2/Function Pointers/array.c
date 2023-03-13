#include "array.h"

int Get_array_t(array_t *self, size_t index) {
	return self->data[index];
}

void Set_array_t(array_t* self, size_t index, int value) {
	self->data[index] = value;
}


array_t* make_array(size_t capacity) {
	array_t* newArray = (array_t*)malloc(sizeof(array_t));
	newArray->self = newArray;
	newArray->data = (int*)malloc(sizeof(int)*capacity);
	newArray->size = capacity;

	newArray->pfnGet = Get_array_t;
	newArray->pfnSet = Set_array_t;

	return newArray;
}

void delete_array(array_t *self){
	free(self->data);
	free(self);
}
