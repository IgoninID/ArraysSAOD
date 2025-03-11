#include "Templates.h"
#include <assert.h>

/// <summary>
/// тесты для проверки функции сортировки
/// </summary>
void tests_for_sort()
{
	//отсортированные массивы
	int arr1_s[] = { 1, 2, 3, 4, 5 };
	double arr2_s[] = { 1.1, 1.2, 1.3, 1.4, 2.5 };
	int arr3_s[] = { 500 };
	int* arr4_s = nullptr;
	assert(FindSort(arr1_s, 5) == true);
	assert(FindSort(arr2_s, 5) == true);
	assert(FindSort(arr3_s, 1) == true);
	assert(FindSort(arr4_s, 0) == true);

	//неотсортированные массивы
	int arr1_us[] = { 5, 6, 4, 1, 9 };
	double arr2_us[] = { 2.5, 1.4, 1.3, 1.2, 1.1 };
	int arr3_us[] = { 9, 9, 9, 5, 9 };
	double arr4_us[] = {-1.3, -3.7, 0.1, 6.9};
	assert(FindSort(arr1_us, 5) == false);
	assert(FindSort(arr2_us, 5) == false);
	assert(FindSort(arr3_us, 5) == false);
	assert(FindSort(arr4_us, 4) == false);
	SortMerge(arr1_us, 0, 4);
	//SortBub(arr1_us, 5);
	//SortQuick(arr1_us, 0, 4);
	//SortShell(arr1_us, 5);
	assert(FindSort(arr1_us, 5) == true);

	//массив с одинаковыми элементами
	int arr_w_sim_el[] = { 1, 1, 1, 1, 1 };
	assert(FindSort(arr_w_sim_el, 5) == true);

	//массив с одинаковыми соседними элементами
	int arr_w_dub_el[] = { 1, 1, 2, 2, 5 };
	assert(FindSort(arr_w_dub_el, 5) == true);

}

/// <summary>
/// тесты для проверки поиска
/// </summary>
void tests_for_search()
{
	int arr1[] = { 10, 20, 60, 200, 5000, 40000 };

	int arr2[] = { 100 };

	size_t n1 = 6;

	assert(FindElem(arr1, n1, 200)==4);

	assert(FindElem(arr1, n1, 40000) == 6);

	assert(FindElem(arr1, n1, 10) == 1);

	assert(FindElem(arr1, n1, 2) == 0);

	assert(FindElem(arr1, n1, 2000) == 0);

	assert(FindElem(arr2, 1, 100) == 1);

	assert(FindElem(arr2, 1, 200) == 0);

	assert(FindIter(arr1, n1, 200) == 4);
}

/// <summary>
/// тесты для проверки бинарного поиска
/// </summary>
void tests_for_byn_iter_search()
{
	int arr1_sort[] = { 5, 6, 9, 10, 100, 500, 5000, 80000 };
	size_t n1 = 8;
	int arr_w_1_el[] = { 5000 };

	assert(FindElemDub(arr1_sort, n1, 5) == 1);

	assert(FindElemDub(arr1_sort, n1, 80000) == 8);

	assert(FindElemDub(arr1_sort, n1, 10) == 4);

	assert(FindElemDub(arr1_sort, n1, 600) == 0);

	assert(FindElemDub(arr_w_1_el, 1, 80000) == 0);

	assert(FindElemDub(arr_w_1_el, 1, 5000) == 1);

	assert(FindIter(arr1_sort, n1, 5) == 1);

	assert(FindIter(arr1_sort, n1, 80000) == 8);

	assert(FindIter(arr1_sort, n1, 10) == 4);

	assert(FindIter(arr1_sort, n1, 600) == 0);

	assert(FindIter(arr_w_1_el, 1, 80000) == 0);

	assert(FindIter(arr_w_1_el, 1, 5000) == 1);
}