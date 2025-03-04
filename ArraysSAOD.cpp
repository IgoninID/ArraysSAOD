﻿#include <iostream>
#include "Templates.h"

using namespace std;

int main()
{
    tests_for_sort();
    tests_for_search();
    tests_for_bynsearch();
    size_t n = 100000;
    int* arr = CreateArrInc<int>(n, 0, 1000000);
    //for (int i = 0; i < 100; i++)
    //{
    //    cout << arr[i] << "\n";
    //}
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> distr(0, n-1);
    int find_val = arr[distr(gen)];
    cout << FindElem<int>(arr, n, find_val) << "\n";
    cout << FindElemDub<int>(arr, n, find_val);
    //TotalTime<int>(arr, n, 0, n - 1);
    //string s = "arr1.txt";
    //SavetoF<int>(arr, 100000000, s);
    delete[] arr;

}
