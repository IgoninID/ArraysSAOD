#include "Templates.h"
#include <assert.h>

/// <summary>
/// тесты для проверки функции сортировки
/// </summary>
void tests_for_findsort()
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

	//массив с одинаковыми элементами
	int arr_w_sim_el[] = { 1, 1, 1, 1, 1 };
	assert(FindSort(arr_w_sim_el, 5) == true);

	//массив с одинаковыми соседними элементами
	int arr_w_dub_el[] = { 1, 1, 2, 2, 5 };
	assert(FindSort(arr_w_dub_el, 5) == true);

}

/// <summary>
/// тесты для проверки последовательного поиска
/// </summary>
void tests_for_search()
{
	int arr1[] = { 10, 20, 60, 200, 5000, 40 };

	int arr2[] = { 100 };

	size_t n1 = 6;

	assert(FindElem(arr1, n1, 200)==4);

	assert(FindElem(arr1, n1, 40) == 6);

	assert(FindElem(arr1, n1, 10) == 1);

	assert(FindElem(arr1, n1, 2) == 0);

	assert(FindElem(arr1, n1, 2000) == 0);

	assert(FindElem(arr2, 1, 100) == 1);

	assert(FindElem(arr2, 1, 200) == 0);

	assert(FindElem(arr1, n1, 200) == 4);
}

/// <summary>
/// тесты для проверки бинарного и итерационного поиска
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

	assert(FindInter(arr1_sort, n1, 5) == 1);

	assert(FindInter(arr1_sort, n1, 80000) == 8);

	assert(FindInter(arr1_sort, n1, 10) == 4);

	assert(FindInter(arr1_sort, n1, 600) == 0);

	assert(FindInter(arr_w_1_el, 1, 80000) == 0);

	assert(FindInter(arr_w_1_el, 1, 5000) == 1);
}

/// <summary>
/// тесты для проверки сортировки пузырьком
/// </summary>
void tests_for_bsort()
{
	int arr1[] = { 5, 10, 2, 5, 2, 6, 4, 8, 10, 1000, 40 };
	assert(FindSort(arr1, 11) == false);
	int arr2[] = { 5, 5, 5, 5, 5, 1, 1, 1, 1 };
	assert(FindSort(arr2, 9) == false);
	int arr3[] = { 100, 20, 10, 9, 8, 6, 4, 2 };
	assert(FindSort(arr3, 8) == false);
	int arr4[] = { 1, 2, 3, 4, 5, 6, 1, 2, 3, 4, 5, 6 };
	assert(FindSort(arr4, 12) == false);
	int arr_w_1[] = { 400 };
	int arr_w_2[] = { 400, 300 };
	assert(FindSort(arr_w_2, 2) == false);
	SortBub(arr_w_1, 1);
	assert(FindSort(arr_w_1, 1) == true);
	SortBub(arr_w_2, 2);
	assert(FindSort(arr_w_2, 2) == true);
	SortBub(arr1, 11);
	assert(FindSort(arr1, 11) == true);
	SortBub(arr2, 9);
	assert(FindSort(arr2, 9) == true);
	SortBub(arr3, 8);
	assert(FindSort(arr3, 8) == true);
	SortBub(arr4, 12);
	assert(FindSort(arr4, 12) == true);

}

/// <summary>
/// тесты для проверки Quicksort
/// </summary>
void tests_for_qsort()
{
	int arr1[] = { 5, 10, 2, 5, 2, 6, 4, 8, 10, 1000, 40 };
	assert(FindSort(arr1, 11) == false);
	int arr2[] = { 5, 5, 5, 5, 5, 1, 1, 1, 1 };
	assert(FindSort(arr2, 9) == false);
	int arr3[] = { 100, 20, 10, 9, 8, 6, 4, 2 };
	assert(FindSort(arr3, 8) == false);
	int arr4[] = { 1, 2, 3, 4, 5, 6, 1, 2, 3, 4, 5, 6 };
	assert(FindSort(arr4, 12) == false);
	int arr_w_1[] = { 400 };
	int arr_w_2[] = { 400, 300 };
	assert(FindSort(arr_w_2, 2) == false);
	SortQuick(arr_w_1, 0, 0);
	assert(FindSort(arr_w_1, 1) == true);
	SortQuick(arr_w_2, 0, 1);
	assert(FindSort(arr_w_2, 2) == true);
	SortQuick(arr1, 0, 10);
	assert(FindSort(arr1, 11) == true);
	SortQuick(arr2, 0, 8);
	assert(FindSort(arr2, 9) == true);
	SortQuick(arr3, 0, 7);
	assert(FindSort(arr3, 8) == true);
	SortQuick(arr4, 0, 11);
	assert(FindSort(arr4, 12) == true);
}

/// <summary>
/// тесты для проверки сортировки Шелла
/// </summary>
void tests_for_ssort()
{
	int arr1[] = { 5, 10, 2, 5, 2, 6, 4, 8, 10, 1000, 40 };
	assert(FindSort(arr1, 11) == false);
	int arr2[] = { 5, 5, 5, 5, 5, 1, 1, 1, 1 };
	assert(FindSort(arr2, 9) == false);
	int arr3[] = { 100, 20, 10, 9, 8, 6, 4, 2 };
	assert(FindSort(arr3, 8) == false);
	int arr4[] = { 1, 2, 3, 4, 5, 6, 1, 2, 3, 4, 5, 6 };
	assert(FindSort(arr4, 12) == false);
	int arr_w_1[] = { 400 };
	int arr_w_2[] = { 400, 300 };
	assert(FindSort(arr_w_2, 2) == false);
	SortShell(arr_w_1, 1);
	assert(FindSort(arr_w_1, 1) == true);
	SortShell(arr_w_2, 2);
	assert(FindSort(arr_w_2, 2) == true);
	SortShell(arr1, 11);
	assert(FindSort(arr1, 11) == true);
	SortShell(arr2, 9);
	assert(FindSort(arr2, 9) == true);
	SortShell(arr3, 8);
	assert(FindSort(arr3, 8) == true);
	SortShell(arr4, 12);
	assert(FindSort(arr4, 12) == true);
}

/// <summary>
/// тесты для проверки сортировки слиянием
/// </summary>
void tests_for_msort()
{
	int arr1[] = { 5, 10, 2, 0, 7, 6, 4, 8, 1, 40 };
	assert(FindSort(arr1, 10) == false);
	int arr2[] = { 5, 5, 5, 5, 5, 1, 1, 1, 1 };
	assert(FindSort(arr2, 9) == false);
	int arr3[] = { 100, 20, 10, 9, 8, 6, 4, 2 };
	assert(FindSort(arr3, 8) == false);
	int arr4[] = { 1, 2, 3, 4, 5, 6, 1, 2, 3, 4, 5, 6 };
	assert(FindSort(arr4, 12) == false);
	int arr_w_1[] = { 400 };
	int arr_w_2[] = { 400, 300 };
	assert(FindSort(arr_w_2, 2) == false);
	SortMerge(arr_w_1, 0, 0);
	assert(FindSort(arr_w_1, 1) == true);
	SortMerge(arr_w_2, 0, 1);
	assert(FindSort(arr_w_2, 2) == true);
	SortMerge(arr1, 0, 9);
	assert(FindSort(arr1, 10) == true);
	SortMerge(arr2, 0, 8);
	assert(FindSort(arr2, 9) == true);
	SortMerge(arr3, 0, 7);
	assert(FindSort(arr3, 8) == true);
	SortMerge(arr4, 0, 11);
	assert(FindSort(arr4, 12) == true);
}

/// <summary>
/// тесты для проверки сортировки вставками
/// </summary>
void tests_for_isort()
{
	int arr1[] = { 5, 10, 2, 5, 2, 6, 4, 8, 10, 1000, 40 };
	assert(FindSort(arr1, 11) == false);
	int arr2[] = { 5, 5, 5, 5, 5, 1, 1, 1, 1 };
	assert(FindSort(arr2, 9) == false);
	int arr3[] = { 100, 20, 10, 9, 8, 6, 4, 2 };
	assert(FindSort(arr3, 8) == false);
	int arr4[] = { 1, 2, 3, 4, 5, 6, 1, 2, 3, 4, 5, 6 };
	assert(FindSort(arr4, 12) == false);
	int arr_w_1[] = { 400 };
	int arr_w_2[] = { 400, 300 };
	assert(FindSort(arr_w_2, 2) == false);
	SortInsert(arr_w_1, 1);
	assert(FindSort(arr_w_1, 1) == true);
	SortInsert(arr_w_2, 2);
	assert(FindSort(arr_w_2, 2) == true);
	SortInsert(arr1, 11);
	assert(FindSort(arr1, 11) == true);
	SortInsert(arr2, 9);
	assert(FindSort(arr2, 9) == true);
	SortInsert(arr3, 8);
	assert(FindSort(arr3, 8) == true);
	SortInsert(arr4, 12);
	assert(FindSort(arr4, 12) == true);
}