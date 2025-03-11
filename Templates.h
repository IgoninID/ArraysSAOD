#pragma once
#include <iostream>
#include <fstream>
#include <random> // библиотека для работы со случайными числами
#include <chrono> // библиотека для работы со временем
#include <functional> // библиотека для работы с функциональным типом
#include <string>

using namespace std;
using namespace chrono;

/// <summary>
/// Создание массива со случайными числами от start до end
/// </summary>
/// <typeparam name="TypeData - тип элементов массива"></typeparam>
/// <param name="n - размер массива"></param>
/// <param name="start - начальное значение случайных чисел"></param>
/// <param name="end - конечное значение случайных чисел"></param>
/// <returns>
/// массив заполненный случайными числами
/// </returns>
template <typename TypeData >
TypeData* CreateArr(size_t n, TypeData start, TypeData end)
{
	random_device rd; // инициализация случайных чисел
	mt19937 gen(rd()); // генератор случайных чисел
	//TODO: остальные целочисленные
	if ((typeid(TypeData) == typeid(int))||(typeid(TypeData) == typeid(long))||(typeid(TypeData) == typeid(short))||(typeid(TypeData) == typeid(unsigned))|| (typeid(TypeData) == typeid(long long))) // проверка на целочисленный тип
	{
		uniform_int_distribution<> distr(start, end); // равномерное целочисленное распределение случайных чисел
		TypeData* arr = new TypeData[n]; // выделение памяти под массив размера n
		for (size_t i = 0; i < n; i++)
		{
			arr[i] = distr(gen); // заполнение массива случайными числами
		}
		return arr; // возвращаем массив
	}
	else
	{
		uniform_real_distribution<> distr(start, end); // равномерное вещественное распределение случайных чисел
		TypeData* arr = new TypeData[n]; // выделение памяти под массив размера n
		for (size_t i = 0; i < n; i++)
		{
			arr[i] = distr(gen); // заполнение массива случайными числами
		}
		return arr; // возвращаем массив
	}
}

/// <summary>
/// Вычисление времени затраченного на выполнение функции
/// </summary>
/// <typeparam name="TypeData - тип элементов массива"></typeparam>
/// <param name="arr - массив"></param>
/// <param name="n - размер массива"></param>
/// <param name="val - искомый элемент"></param>
/// <param name="testFunc - тестируемая функция"></param>
/// <returns>
/// количество милисекунд затраченное на выполнение функции
/// </returns>
template <typename TypeData>
int TimeFunc(TypeData* arr, size_t n, TypeData val, function<size_t(TypeData*, size_t, TypeData)> testFunc)
{
	auto t1 = steady_clock::now(); // начальное время
	size_t i = testFunc(arr, n, val); // тестируемая функция
	auto t2 = steady_clock::now(); // конечное время
	auto delta = duration_cast<milliseconds>(t2 - t1); // вычисление затраченного на функцию времени в милисекундах
	cout << delta.count() << "\n"; // вывод в консоль количества милисекунд
	return delta.count(); // возвращаем количество милисекунд
}

/// <summary>
/// Бинарный поиск элемента в массиве
/// </summary>
/// <typeparam name="TypeData - тип элементов массива"></typeparam>
/// <param name="arr - массив"></param>
/// <param name="n - размер массива"></param>
/// <param name="find_val - искомый элемент"></param>
/// <returns>
/// место элемента в массиве(индекс + 1), если нет, то вернет 0
/// </returns>
template <typename TypeData>
size_t FindElemDub(TypeData* arr, size_t n, TypeData find_val)
{
	size_t left = 0; // левая граница массива
	size_t right = n; // правая граница массива
	size_t mid; // середина 
	while (left < right)
	{
		mid = left + (right - left) / 2; // находим середину массива
		if (arr[mid] == find_val)
		{
			right = mid;
		}
		else
		{
			left = mid + 1;
		}
	}
	right--; // уменьшаем на 1 правую границу
	if (arr[right] == find_val) // проверка на искомоый элемент
		return right + 1; // выводим индекс + 1
	else
	return 0; // возвращаем 0 если элемент не найден
}

/// <summary>
/// Нахождение элемента в массиве
/// </summary>
/// <typeparam name="TypeData - тип элементов массива"></typeparam>
/// <param name="arr - массив"></param>
/// <param name="n - размер массива"></param>
/// <param name="elem - искомый элемент"></param>
/// <returns>
/// место элемента в массиве(индекс + 1), если нет, то вернет 0
/// </returns>
template <typename TypeData>
size_t FindElem(TypeData* arr,size_t n,TypeData elem)
{
	for (size_t i = 0; i < n; i++) // проходим по всему массиву
	{
		if (elem == arr[i]) // если элемент массива равен искомому
		{
			return i+1; // возвращаем индекс + 1
		}
	}
	return 0; // если не найден возвращаем 0
}

/// <summary>
/// создание массива с монотонно возрастающими элементами
/// </summary>
/// <typeparam name="TypeData - тип элементов массива"></typeparam>
/// <param name="n - размер массива"></param>
/// <param name="start - начальное значение случайных чисел"></param>
/// <param name="end - конечное значение случайных чисел"></param>
/// <returns>
/// массив с монотонно возрастающими элементами
/// </returns>
template <typename TypeData >
TypeData* CreateArrInc(size_t n, TypeData start, TypeData end)
{
	random_device rd; // инициализация случайных чисел
	mt19937 gen(rd()); // генератор случайных чисел
	//TODO: остальные целочисленные
	if ((typeid(TypeData) == typeid(int)) || (typeid(TypeData) == typeid(long)) || (typeid(TypeData) == typeid(short)) || (typeid(TypeData) == typeid(unsigned)) || (typeid(TypeData) == typeid(long long))) // проверка на целочисленный тип
	{
		uniform_int_distribution<> distr(start, end); // равномерное целочисленное распределение случайных чисел
		TypeData* arr = new TypeData[n]; // выделение памяти под массив размера n
		arr[0] = distr(gen); // случайный начальный элемент
		for (size_t i = 1; i < n; i++)
		{
				arr[i] = arr[i - 1] + (distr(gen) / 100); // следующий элемент = предыдущий + случайное число/100
		}
		return arr; // возвращаем массив
	}
	else
	{
		uniform_real_distribution<> distr(start, end); // равномерное вещественное распределение случайных чисел
		TypeData* arr = new TypeData[n]; // выделение памяти под массив размера n
		arr[0] = distr(gen); // случайный начальный элемент
		for (size_t i = 1; i < n; i++)
		{
				arr[i] = arr[i - 1] + (distr(gen) / 100); // следующий элемент = предыдущий + случайное число/100
		}
		return arr; // возвращаем массив
	}
}

/// <summary>
/// проверка сортировки по возрастанию массива
/// </summary>
/// <typeparam name="TypeData - тип элементов массива"></typeparam>
/// <param name="arr - массив"></param>
/// <param name="n - размер массива"></param>
/// <returns>
/// 1 - если массив отсортирован, 0 - если нет
/// </returns>
template <typename TypeData>
bool FindSort(TypeData* arr, size_t n)
{
	for (size_t i = 1; i < n; i++) // проходим по всему массиву
	{
		if (arr[i] < arr[i - 1]) // сравниваем текущий элемент с предыдущим
		{
			return false; // если текущий меньше предыдущего то массив неотсортирован
		}
	}
	return true; // если условие не выполнилось, то массив отсортирован
}

/// <summary>
/// вычисление среднего количества времени на 100 выполнений одной функции
/// </summary>
/// <typeparam name="TypeData - тип элементов массива"></typeparam>
/// <param name="arr - массив"></param>
/// <param name="n - размер массива"></param>
/// <param name="start - начальное значение случайных чисел для индекса элемента массива"></param>
/// <param name="end - конечное значение случайных чисел для индекса элемента массива"></param>
template <typename TypeData>
void TotalTime(TypeData* arr, size_t n, int start, int end)
{
	random_device rd; // инициализация случайных чисел
	mt19937 gen(rd()); // генератор случайных чисел
	uniform_int_distribution<> distr(start, end); // равномерное целочисленное распределение случайных чисел
	int times = 0; // счетчик времени
	for (int i = 0; i < 100;i++) 
	{
		TypeData find_val = arr[distr(gen)]; // выбираем случайный элемент из массива в качестве искомого
		times += TimeFunc<TypeData>(arr, n, find_val, FindElem<TypeData>); // находим время затраченное на поиск элемента в массиве, суммируем
	}
	cout << times/100.0; // находим среднее время
}

/// <summary>
/// сохранение массива в текстовый файл
/// </summary>
/// <typeparam name="TypeData - тип элементов массива"></typeparam>
/// <param name="arr - массив"></param>
/// <param name="n - размер массива"></param>
/// <param name="fname - имя файла"></param>
/// <returns>
/// 1 - файл не открылся, 0 - функция выполнила свою работу
/// </returns>
template <typename TypeData>
int SavetoF(TypeData* arr, size_t n, string fname)
{
	ofstream Savef; // переменная потока для записи
	Savef.open(fname); // открываем файл для записи
	if (Savef.is_open()) // проверка на открытие
	{
		for (size_t i = 0; i < n; i++)
		{
			Savef << arr[i] << " , "; // запись массива в файл
		}
	}
	else // если файл не открылся
	{
		return 1; // возвращаем 1
	}
	Savef.close(); // закрываем файл
	return 0; // возвращаем 0
}

/// <summary>
/// тесты для проверки функции сортировки
/// </summary>
void tests_for_sort();

/// <summary>
/// тесты для проверки поиска
/// </summary>
void tests_for_search();

/// <summary>
/// тесты для проверки бинарного поиска
/// </summary>
void tests_for_byn_iter_search();

template <typename TypeData>
size_t FindIter(TypeData* arr, size_t n, TypeData Elem)
{
	size_t left = 0;
	size_t right = n - 1;
	while ((left <= right) && (Elem >= arr[left]) && (Elem <= arr[right]))
	{
		if (left == right)
		{
			if (arr[left] == Elem)
			{
				return left + 1;
			}
			return 0;
		}
		size_t pos = left + (((double)(right - left) / (arr[right] - arr[left])) * (Elem - arr[left]));
		if (arr[pos] == Elem)
		{
			return pos + 1;
		}
		if (arr[pos] < Elem)
		{
			left = pos + 1;
		}
		else
		{
			right = pos - 1;
		}
	}
	return 0;
}

template <typename TypeData>
void SortBub(TypeData* arr, size_t n)
{
	for (size_t i = 0; i < n-1; i++)
	{
		for (size_t j = 0; j < n - i-1;j++)
		{
			if (arr[j] > arr[j + 1])
			{
				swap(arr[j], arr[j + 1]);
				//TypeData temp = arr[j];
				//arr[j] = arr[j + 1];
				//arr[j + 1] = temp;
			}
		}
	}
}

template <typename TypeData>
size_t Partit(TypeData* arr, size_t left, size_t right, TypeData pivot)
{
	size_t Pindex = left;
	for (size_t i = left; i <= right;i++)
	{
		if (arr[i] <= pivot)
		{
			swap(arr[Pindex], arr[i]);
			Pindex++;
		}
	}
	Pindex--;
	return Pindex;
}

template <typename TypeData>
void SortQuick(TypeData* arr, size_t left, size_t right)
{
	if (left < right)
	{
		TypeData pivot = arr[right];
		size_t Pindex = Partit(arr, left, right, pivot);
		SortQuick(arr, left, Pindex - 1);
		SortQuick(arr, Pindex + 1, right);
	}
}

template <typename TypeData>
void SortShell(TypeData* arr, size_t n)
{
	for (size_t gap = n / 2; gap > 0; gap /= 2)
	{
		for (size_t i = gap; i < n;i += 1)
		{
			TypeData temp = arr[i];
			size_t j;
			for (j = i;j >= gap && arr[j - gap] > temp;j -= gap)
			{
				arr[j] = arr[j - gap];
			}
			arr[j] = temp;
		}
	}
}

template <typename TypeData>
void Merge(TypeData* arr, size_t left, size_t mid, size_t right)
{
	size_t n1 = mid - left + 1;
	size_t n2 = right - mid;
	TypeData* L = new TypeData(n1);
	TypeData* R = new TypeData(n2);
	for (size_t i = 0; i < n1;i++)
	{
		L[i] = arr[left + i];
	}
	for (size_t j = 0; j < n2;j++)
	{
		R[j] = arr[mid + 1 + j];
	}
	size_t i = 0;
	size_t j = 0;
	size_t k = left;
	while ((i < n1) && (j < n2))
	{
		if (L[i] <= R[j])
		{
			arr[k] = L[i];
			i++;
		}
		else
		{
			arr[k] = R[j];
			j++;
		}
		k++;
	}
	while (i < n1)
	{
		arr[k] = L[i];
		i++;
		k++;
	}
	while (j < n2)
	{
		arr[k] = R[j];
		j++;
		k++;
	}
}

template <typename TypeData>
void SortMerge(TypeData* arr, size_t left, size_t right)
{
	if (left >= right)
		return;
	size_t mid = left + (right - left) / 2;
	SortMerge(arr, left, mid);
	SortMerge(arr, mid+1, right);
	Merge(arr, left, mid, right);
}