#include "Templates.h"
#include <assert.h>

void testes()
{
	int* arr1 = CreateArrInc<int>(10000, 0, 100000);
	float* arr2 = CreateArrInc<float>(10000, 0, 100000);
	int* arr3 = CreateArrInc<int>(100000, 0, 100000);
	assert(FindSort<int>(arr1, 10000) == true);
	delete[] arr1;
	assert(FindSort<float>(arr2, 10000) == true);
	delete[] arr2;
	assert(FindSort<int>(arr3, 100000) == true);
	delete[] arr3;

}
