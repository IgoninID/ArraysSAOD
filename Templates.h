#pragma once
#include <iostream>
#include <fstream>
#include <random> //
#include <chrono> //
#include <functional> //
#include <string> //
#include <cassert>

using namespace std;
using namespace chrono;

/// <summary>
/// —оздание массива со случайными числами от start до end
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
	random_device rd;
	mt19937 gen(rd());
	//TODO: остальные целочисленные
	if ((typeid(TypeData) == typeid(int))||(typeid(TypeData) == typeid(long))||(typeid(TypeData) == typeid(short))||(typeid(TypeData) == typeid(unsigned))|| (typeid(TypeData) == typeid(long long)))
	{
		uniform_int_distribution<> distr(start, end);
		TypeData* arr = new TypeData[n];
		for (size_t i = 0; i < n; i++)
		{
			arr[i] = distr(gen);
		}
		return arr;
	}
	else
	{
		uniform_real_distribution<> distr(start, end);
		TypeData* arr = new TypeData[n];
		for (size_t i = 0; i < n; i++)
		{
			arr[i] = distr(gen);
		}
		return arr;
	}
}

/// <summary>
/// ¬ычисление времени затраченного на выполнение функции
/// </summary>
/// <typeparam name="TypeData - тип"></typeparam>
/// <param name="testFunc - выполн€ема€ функци€"></param>
/// <returns>
/// количество милисекунд затраченное на выполнение функции
/// </returns>
template <typename TypeData>
int TimeFunc(TypeData testFunc)
{
	auto t1 = steady_clock::now();
	testFunc();
	auto t2 = steady_clock::now();
	auto delta = duration_cast<milliseconds>(t2 - t1);
	cout << delta.count() << "\n";
	return delta.count();
}

/// <summary>
/// Ќахождение элемента в массиве
/// </summary>
/// <typeparam name="TypeData - тип элементов массива"></typeparam>
/// <param name="arr - массив"></param>
/// <param name="n - размер массива"></param>
/// <param name="elem - искомый элемент"></param>
/// <returns>
/// нашел ли элемент в массиве
/// </returns>
template <typename TypeData>
bool FindElem(TypeData* arr,size_t n,TypeData elem)
{
	for (size_t i = 0; i < n; i++)
	{
		if (elem == arr[i])
		{
			return 1;
		}
	}
	return 0;
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
	random_device rd;
	mt19937 gen(rd());
	//TODO: остальные целочисленные
	if ((typeid(TypeData) == typeid(int)) || (typeid(TypeData) == typeid(long)) || (typeid(TypeData) == typeid(short)) || (typeid(TypeData) == typeid(unsigned)) || (typeid(TypeData) == typeid(long long)))
	{
		uniform_int_distribution<> distr(start, end);
		TypeData* arr = new TypeData[n];
		arr[0] = distr(gen);
		for (size_t i = 1; i < n; i++)
		{
				arr[i] = arr[i - 1] + (distr(gen) / 100);
		}
		return arr;
	}
	else
	{
		uniform_real_distribution<> distr(start, end);
		TypeData* arr = new TypeData[n];
		arr[0] = distr(gen);
		for (size_t i = 1; i < n; i++)
		{
				arr[i] = arr[i - 1] + (distr(gen) / 100);
		}
		return arr;
	}
}

/// <summary>
/// проверка сортировки по возрастанию массива
/// </summary>
/// <typeparam name="TypeData - тип элементов массива"></typeparam>
/// <param name="arr - массив"></param>
/// <param name="n - размер массива"></param>
/// <returns></returns>
template <typename TypeData>
bool FindSort(TypeData* arr, size_t n)
{
	for (size_t i = 1; i < n; i++)
	{
		if (arr[i] < arr[i - 1])
		{
			return false;
		}
	}
	return true;
}

/// <summary>
/// вычисление среднего количества времени на 100 выполнений одной функции
/// </summary>
/// <typeparam name="TypeData - тип элементов массива"></typeparam>
/// <param name="arr - массив"></param>
/// <param name="n - размер массива"></param>
/// <param name="start - начальное значение случайных чисел дл€ индекса элемента массива"></param>
/// <param name="end - конечное значение случайных чисел дл€ индекса элемента массива"></param>
template <typename TypeData>
void TotalTime(TypeData* arr, size_t n, int start, int end)
{
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<> distr(start, end);
	int times = 0;
	for (int i = 0; i < 100;i++)
	{
		TypeData find_val = arr[distr(gen)];
		times += TimeFunc([&]() {bool ind = FindElem<TypeData>(arr, n, find_val);});
	}
	cout << times/100.0;
}

/// <summary>
/// сохранение массива в текстовый файл
/// </summary>
/// <typeparam name="TypeData - тип элементов массива"></typeparam>
/// <param name="arr - массив"></param>
/// <param name="n - размер массива"></param>
/// <param name="fname - им€ файла"></param>
template <typename TypeData>
void SavetoF(TypeData* arr, size_t n, string fname)
{
	ofstream Savef;
	Savef.open(fname);
	if (Savef.is_open())
	{
		for (size_t i = 0; i < n; i++)
		{
			Savef << arr[i] << " , ";
		}
	}
	Savef.close();
}

//todo тесты




