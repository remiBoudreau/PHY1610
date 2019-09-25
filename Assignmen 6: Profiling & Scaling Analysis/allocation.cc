#include "allocation.h"
// memory allocation routine
int** alloc_array_int(int sizex, int sizey) {
    int** result;
    result = new int*[sizex];
    result[0] = new int[sizex*sizey];
    for (int i=1;i<sizex;++i)
        result[i] = &(result[0][i*sizey]);
    return result;
}
void dealloc_array_int(int** result) {
    delete[] result[0];
    delete[] result;
}
float** alloc_array_float(int sizex, int sizey) {
    float** result;
    result = new float*[sizex];
    result[0] = new float[sizex*sizey];
    for (int i=1;i<sizex;++i)
        result[i] = &(result[0][i*sizey]);
    return result;
}
void dealloc_array_float(float** result) {
    delete[] result[0];
    delete[] result;
}
