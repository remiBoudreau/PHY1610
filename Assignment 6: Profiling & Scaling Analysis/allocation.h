#ifndef ALLOCATIONH
#define ALLOCATIONH
// memory allocation routines
int** alloc_array_int(int sizex, int sizey);
void dealloc_array_int(int** result);
float** alloc_array_float(int sizex, int sizey);
void dealloc_array_float(float** result);
#endif
