#pragma once
#include <iostream>
#include <fstream>
#include <random> // ���������� ��� ������ �� ���������� �������
#include <chrono> // ���������� ��� ������ �� ��������
#include <functional> // ���������� ��� ������ � �������������� �����
#include <string>

using namespace std;
using namespace chrono;

/// <summary>
/// �������� ������� �� ���������� ������� �� start �� end
/// </summary>
/// <typeparam name="TypeData - ��� ��������� �������"></typeparam>
/// <param name="n - ������ �������"></param>
/// <param name="start - ��������� �������� ��������� �����"></param>
/// <param name="end - �������� �������� ��������� �����"></param>
/// <returns>
/// ������ ����������� ���������� �������
/// </returns>
template <typename TypeData >
TypeData* CreateArr(size_t n, TypeData start, TypeData end)
{
	random_device rd; // ������������� ��������� �����
	mt19937 gen(rd()); // ��������� ��������� �����
	//TODO: ��������� �������������
	if ((typeid(TypeData) == typeid(int))||(typeid(TypeData) == typeid(long))||(typeid(TypeData) == typeid(short))||(typeid(TypeData) == typeid(unsigned))|| (typeid(TypeData) == typeid(long long))) // �������� �� ������������� ���
	{
		uniform_int_distribution<> distr(start, end); // ����������� ������������� ������������� ��������� �����
		TypeData* arr = new TypeData[n]; // ��������� ������ ��� ������ ������� n
		for (size_t i = 0; i < n; i++)
		{
			arr[i] = distr(gen); // ���������� ������� ���������� �������
		}
		return arr; // ���������� ������
	}
	else
	{
		uniform_real_distribution<> distr(start, end); // ����������� ������������ ������������� ��������� �����
		TypeData* arr = new TypeData[n]; // ��������� ������ ��� ������ ������� n
		for (size_t i = 0; i < n; i++)
		{
			arr[i] = distr(gen); // ���������� ������� ���������� �������
		}
		return arr; // ���������� ������
	}
}

/// <summary>
/// ���������� ������� ������������ �� ���������� �������
/// </summary>
/// <typeparam name="TypeData - ��� ��������� �������"></typeparam>
/// <param name="arr - ������"></param>
/// <param name="n - ������ �������"></param>
/// <param name="val - ������� �������"></param>
/// <param name="testFunc - ����������� �������"></param>
/// <returns>
/// ���������� ���������� ����������� �� ���������� �������
/// </returns>
template <typename TypeData>
int TimeFunc(TypeData* arr, size_t n, TypeData val, function<size_t(TypeData*, size_t, TypeData)> testFunc)
{
	auto t1 = steady_clock::now(); // ��������� �����
	size_t i = testFunc(arr, n, val); // ����������� �������
	auto t2 = steady_clock::now(); // �������� �����
	auto delta = duration_cast<milliseconds>(t2 - t1); // ���������� ������������ �� ������� ������� � ������������
	cout << delta.count() << "\n"; // ����� � ������� ���������� ����������
	return delta.count(); // ���������� ���������� ����������
}

/// <summary>
/// �������� ����� �������� � �������
/// BigO time (best - 1; average - log(n); worst - log(n))
/// BigO space (1)
/// </summary>
/// <typeparam name="TypeData - ��� ��������� �������"></typeparam>
/// <param name="arr - ������"></param>
/// <param name="n - ������ �������"></param>
/// <param name="find_val - ������� �������"></param>
/// <returns>
/// ����� �������� � �������(������ + 1), ���� ���, �� ������ 0
/// </returns>
template <typename TypeData>
size_t FindElemDub(TypeData* arr, size_t n, TypeData find_val)
{
	size_t left = 0; // ����� ������� �������
	size_t right = n; // ������ ������� �������
	size_t mid; // �������� 
	while (left < right)
	{
		mid = left + (right - left) / 2; // ������� �������� �������
		if (arr[mid] > find_val)
		{
			right = mid;
		}
		else
		{
			left = mid + 1;
		}
	}
	right--; // ��������� �� 1 ������ �������
	if (arr[right] == find_val) // �������� �� �������� �������
		return right + 1; // ������� ������ + 1
	else
	return 0; // ���������� 0 ���� ������� �� ������
}

/// <summary>
/// ���������� �������� � ������� ���������������� �����
/// BigO time (worst - n; average - n; best - 1)
/// </summary>
/// <typeparam name="TypeData - ��� ��������� �������"></typeparam>
/// <param name="arr - ������"></param>
/// <param name="n - ������ �������"></param>
/// <param name="elem - ������� �������"></param>
/// <returns>
/// ����� �������� � �������(������ + 1), ���� ���, �� ������ 0
/// </returns>
template <typename TypeData>
size_t FindElem(TypeData* arr,size_t n,TypeData elem)
{
	for (size_t i = 0; i < n; i++) // �������� �� ����� �������
	{
		if (elem == arr[i]) // ���� ������� ������� ����� ��������
		{
			return i+1; // ���������� ������ + 1
		}
	}
	return 0; // ���� �� ������ ���������� 0
}

/// <summary>
/// �������� ������� � ��������� ������������� ����������
/// </summary>
/// <typeparam name="TypeData - ��� ��������� �������"></typeparam>
/// <param name="n - ������ �������"></param>
/// <param name="start - ��������� �������� ��������� �����"></param>
/// <param name="end - �������� �������� ��������� �����"></param>
/// <returns>
/// ������ � ��������� ������������� ����������
/// </returns>
template <typename TypeData >
TypeData* CreateArrInc(size_t n, TypeData start, TypeData end)
{
	random_device rd; // ������������� ��������� �����
	mt19937 gen(rd()); // ��������� ��������� �����
	//TODO: ��������� �������������
	if ((typeid(TypeData) == typeid(int)) || (typeid(TypeData) == typeid(long)) || (typeid(TypeData) == typeid(short)) || (typeid(TypeData) == typeid(unsigned)) || (typeid(TypeData) == typeid(long long))) // �������� �� ������������� ���
	{
		uniform_int_distribution<> distr(start, end); // ����������� ������������� ������������� ��������� �����
		TypeData* arr = new TypeData[n]; // ��������� ������ ��� ������ ������� n
		arr[0] = distr(gen); // ��������� ��������� �������
		for (size_t i = 1; i < n; i++)
		{
				arr[i] = arr[i - 1] + (distr(gen) / 100); // ��������� ������� = ���������� + ��������� �����/100
		}
		return arr; // ���������� ������
	}
	else
	{
		uniform_real_distribution<> distr(start, end); // ����������� ������������ ������������� ��������� �����
		TypeData* arr = new TypeData[n]; // ��������� ������ ��� ������ ������� n
		arr[0] = distr(gen); // ��������� ��������� �������
		for (size_t i = 1; i < n; i++)
		{
				arr[i] = arr[i - 1] + (distr(gen) / 100); // ��������� ������� = ���������� + ��������� �����/100
		}
		return arr; // ���������� ������
	}
}

/// <summary>
/// �������� ���������� �� ����������� �������
/// </summary>
/// <typeparam name="TypeData - ��� ��������� �������"></typeparam>
/// <param name="arr - ������"></param>
/// <param name="n - ������ �������"></param>
/// <returns>
/// 1 - ���� ������ ������������, 0 - ���� ���
/// </returns>
template <typename TypeData>
bool FindSort(TypeData* arr, size_t n)
{
	for (size_t i = 1; i < n; i++) // �������� �� ����� �������
	{
		if (arr[i] < arr[i - 1]) // ���������� ������� ������� � ����������
		{
			return false; // ���� ������� ������ ����������� �� ������ ��������������
		}
	}
	return true; // ���� ������� �� �����������, �� ������ ������������
}

/// <summary>
/// ���������� �������� ���������� ������� �� 100 ���������� ����� �������
/// </summary>
/// <typeparam name="TypeData - ��� ��������� �������"></typeparam>
/// <param name="arr - ������"></param>
/// <param name="n - ������ �������"></param>
/// <param name="start - ��������� �������� ��������� ����� ��� ������� �������� �������"></param>
/// <param name="end - �������� �������� ��������� ����� ��� ������� �������� �������"></param>
template <typename TypeData>
void TotalTime(TypeData* arr, size_t n, int start, int end)
{
	random_device rd; // ������������� ��������� �����
	mt19937 gen(rd()); // ��������� ��������� �����
	uniform_int_distribution<> distr(start, end); // ����������� ������������� ������������� ��������� �����
	int times = 0; // ������� �������
	for (int i = 0; i < 100;i++) 
	{
		TypeData find_val = distr(gen); // �������� ��������� ������� � �������� ��������
		times += TimeFunc<TypeData>(arr, n, find_val, FindElem<TypeData>); // ������� ����� ����������� �� ����� �������� � �������, ���������
	}
	cout << times/100.0; // ������� ������� �����
}

/// <summary>
/// ���������� ������� � ��������� ����
/// </summary>
/// <typeparam name="TypeData - ��� ��������� �������"></typeparam>
/// <param name="arr - ������"></param>
/// <param name="n - ������ �������"></param>
/// <param name="fname - ��� �����"></param>
/// <returns>
/// 1 - ���� �� ��������, 0 - ������� ��������� ���� ������
/// </returns>
template <typename TypeData>
int SavetoF(TypeData* arr, size_t n, const string& fname)
{
	ofstream Savef; // ���������� ������ ��� ������
	Savef.open(fname); // ��������� ���� ��� ������
	if (Savef.is_open()) // �������� �� ��������
	{
		for (size_t i = 0; i < n; i++)
		{
			Savef << arr[i] << " , "; // ������ ������� � ����
		}
	}
	else // ���� ���� �� ��������
	{
		return 1; // ���������� 1
	}
	Savef.close(); // ��������� ����
	return 0; // ���������� 0
}

/// <summary>
/// ����� ��� �������� ������� ����������
/// </summary>
void tests_for_findsort();

/// <summary>
/// ����� ��� �������� ������
/// </summary>
void tests_for_search();

/// <summary>
/// ����� ��� �������� ��������� ������
/// </summary>
void tests_for_byn_iter_search();

/// <summary>
/// ������ ����������������� ������
/// BigO time (average - log2(log2(n)); worst - n)
/// BigO space (1)
/// </summary>
/// <typeparam name="TypeData - ��� ��������� �������"></typeparam>
/// <param name="arr - ������"></param>
/// <param name="n - ������ �������"></param>
/// <param name="Elem - ������� �������"></param>
/// <returns>
/// ����� �������� � �������(������ + 1), ���� ���, �� ������ 0
/// </returns>
template <typename TypeData>
size_t FindInter(TypeData* arr, size_t n, TypeData Elem)
{
	size_t left = 0;
	size_t right = n - 1;
	while ((left <= right) && (Elem >= arr[left]) && (Elem <= arr[right]))
	{
		// ��������� ����� �� �������
		if (left == right)
		{
			// ��������� ������ �� ������� �������
			if (arr[left] == Elem)
			{
				return left + 1;
			}
			// ���� ��� �� ���������� 0
			return 0;
		}
		// ��������� ������ �������� ������ �� ��� �������� 
		size_t pos = left + (((double)(right - left) / (arr[right] - arr[left])) * (Elem - arr[left]));
		// ��������� ���� ������� ������� �� ����������� �������
		if (arr[pos] == Elem)
		{
			return pos + 1;
		}
		// ���� ������� ������� ������ ��� ������� �� ����������� �������, ����� ����� �� ������ �������� �������
		if (arr[pos] < Elem)
		{
			left = pos + 1;
		}
		// ���� ������� ������� ������ ��� ������� �� ����������� �������, ����� ����� �� ����� �������� �������
		else
		{
			right = pos - 1;
		}
	}
	// ���� ������� �� ������ �� ���������� 0
	return 0;
}

/// <summary>
/// ������ ���������� ��������� �� �����������
/// BigO time (best - n; average - n^2; worst - n^2)
/// BigO space (1)
/// </summary>
/// <typeparam name="TypeData - ��� ��������� �������"></typeparam>
/// <param name="arr - ������"></param>
/// <param name="n - ������ �������"></param>
template <typename TypeData>
void SortBub(TypeData* arr, size_t n)
{
	// ������� ���� � ����������� ��������� ���������� ����������
	for (size_t i = 0; i < n-1; i++)
	{
		// ��������� i �������� ��� �� ���������� �����
		for (size_t j = 0; j < n - i-1;j++)
		{
			//���������� �������� ��������
			if (arr[j] > arr[j + 1])
			{
				// ������ ������� ���� ������� ������������
				swap(arr[j], arr[j + 1]);
				//TypeData temp = arr[j];
				//arr[j] = arr[j + 1];
				//arr[j + 1] = temp;
			}
		}
	}
}

/// <summary>
/// ������� ���������, ������� ������������� ������ ����� �������, ��� 
/// ��� ������� �������� ��������� ����� �� �������� pivot, � ��� 
/// ����� ������� �������� ����������� ������ �� �������� pivot.
/// </summary>
/// <typeparam name="TypeData - ��� ��������� �������"></typeparam>
/// <param name="arr - ������"></param>
/// <param name="left - ����� �������"></param>
/// <param name="right - ������ �������"></param>
/// <param name="pivot - ������ �������"></param>
/// <returns></returns>
template <typename TypeData>
size_t Partit(TypeData* arr, size_t left, size_t right, TypeData pivot)
{
	size_t Pindex = left;
	for (size_t i = left; i <= right;i++)
	{
		// ���� ������� ������� ������ ��� ������ �������
		if (arr[i] <= pivot)
		{
			// ������ ������� ������� [Pindex] � ������� ���������
			swap(arr[Pindex], arr[i]);
			Pindex++;
		}
	}
	Pindex--;
	return Pindex;
}

/// <summary>
/// ������ ���������� QuickSort �� �����������
/// BigO time (best - n*log(n); average - n*log(n); worst - n^2)
/// BigO space (log(n))
/// </summary>
/// <typeparam name="TypeData - ��� ��������� �������"></typeparam>
/// <param name="arr - ������"></param>
/// <param name="left - ����� ������� �������"></param>
/// <param name="right - ������ ������� �������"></param>
template <typename TypeData>
void SortQuick(TypeData* arr, size_t left, size_t right)
{
	// �� ��������� ������ �� ��� ���������� ������ 
	// ����� �������� � ���������� �������� �� �� �����������.
	if (left < right)
	{ 
		// todo ���� ������� ������ �������
		TypeData pivot = arr[right];
		// �������� ������� � �������� ����������� ������ ������� ��������
		size_t Pindex = Partit(arr, left, right, pivot);
		SortQuick(arr, left, Pindex - 1);
		SortQuick(arr, Pindex + 1, right);
	}
}

/// <summary>
/// ������ ���������� ����� �� �����������
/// ���������� ���������� �� �������� �����, ����� ����������� � 2 ����, �� 0
/// BigO time (best - n*log(n); average - (n*log(n))^2; worst - (n*log(n))^2)
/// BigO space (1)
/// </summary>
/// <typeparam name="TypeData - ��� ��������� �������"></typeparam>
/// <param name="arr - ������"></param>
/// <param name="n - ������ �������"></param>
template <typename TypeData>
void SortShell(TypeData* arr, size_t n)
{
	// ��������� � �������� ����������, ����� ��������� ���
	for (size_t gap = n / 2; gap > 0; gap /= 2)
	{
		// ��������� ���������� ������� � ������������ ��� ����� ������� ����������.
		// ������ �������� � ������������ a[0 ..gap - 1] ��� ��������� � ���������� ������� � ������������, 
		// ���������� ��������� ��� ���� �������, ���� ���� ������ �� ����� ������������ � ������������.
		for (size_t i = gap; i < n;i += 1)
		{
			// ���������� a[i] � ���������, ������� ���� ������������� �� �����������, 
			// ��������� a[i] � temp � �������� ��������� � ������� i
			TypeData temp = arr[i];
			// �������� ����� ��������������� �� ���������� �������� ����� �� ��� ���, 
			// ���� �� ����� ������� ���������� �������������� ��� a[i]
			size_t j;
			for (j = i;j >= gap && arr[j - gap] > temp;j -= gap)
			{
				arr[j] = arr[j - gap];
			}
			// �������� temp(�������� a[i]) � ������ �����
			arr[j] = temp;
		}
	}
}

/// <summary>
/// ������ ������� ���� ����������� �� ������� arr[] �� �����������
/// ������ ��������� arr[left..mid]
/// ������ ��������� arr[mid+1..right]
/// </summary>
/// <typeparam name="TypeData - ��� ��������� �������"></typeparam>
/// <param name="arr - ������"></param>
/// <param name="left - ����� ������� �������"></param>
/// <param name="mid - �������� �������"></param>
/// <param name="right - ������ ������� �������"></param>
template <typename TypeData>
void Merge(TypeData* arr, size_t left, size_t mid, size_t right)
{
	size_t n1 = mid - left + 1;
	size_t n2 = right - mid;

	//������� ����������
	TypeData* L = new TypeData(n1);
	TypeData* R = new TypeData(n2);
	for (size_t i = 0; i < n1;i++)
	{
		// todo �������� �� memcpy ��� copy
		L[i] = arr[left + i];
	}
	for (size_t j = 0; j < n2;j++)
	{
		R[j] = arr[mid + 1 + j];
	}

	size_t i = 0;
	size_t j = 0;
	size_t k = left;
	//������ ������� ����������� ������� � arr[left..right]
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
	// todo �������� �� memcpy ��� copy
	//�������� ���������� �������� ���������� L, ���� ����� ��������
	while (i < n1)
	{
		arr[k] = L[i];
		i++;
		k++;
	}
	// todo �������� �� memcpy ��� copy
	//�������� ���������� �������� ���������� R, ���� ����� ��������
	while (j < n2)
	{
		arr[k] = R[j];
		j++;
		k++;
	}
}

/// <summary>
/// ������ ���������� �������� �� �����������
/// BigO time (best - n*log(n); average - n*log(n); worst - n*log(n))
/// BigO space (n)
/// </summary>
/// <typeparam name="TypeData - ��� ��������� �������"></typeparam>
/// <param name="arr - ������"></param>
/// <param name="left - ����� ������� �������"></param>
/// <param name="right - ������ ������� �������"></param>
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

/// <summary>
/// ���������� ��������� �� �����������
/// BigO time (best - n; average - n^2; worst - n^2)
/// BigO space (1)
/// </summary>
/// <typeparam name="TypeData"></typeparam>
/// <param name="arr"></param>
/// <param name="n"></param>
template <typename TypeData>
void SortInsert(TypeData* arr, size_t n)
{
	for (size_t i = 1; i < n; i++)
	{
		TypeData key = arr[i];
		size_t j = i - 1;
		// ������� �������� arr[0..i-1],
		// ������� ������ ��������� ��������
		// �� ���� ������� ���� �� ������� �������
		while (j >= 0 && arr[j] > key)
		{
			arr[j + 1] = arr[j];
			j = j - 1;
		}
		arr[j + 1] = key;
	}
}

/// <summary>
/// ����� ��� �������� ���������� ���������
/// </summary>
void tests_for_bsort();

/// <summary>
/// ����� ��� �������� Quicksort
/// </summary>
void tests_for_qsort();

/// <summary>
/// ����� ��� �������� ���������� �����
/// </summary>
void tests_for_ssort();

/// <summary>
/// ����� ��� �������� ���������� ��������
/// </summary>
void tests_for_msort();

/// <summary>
/// ����� ��� �������� ���������� ���������
/// </summary>
void tests_for_isort();