#include <iostream>
#include "Templates.h"

using namespace std;

int main()
{
    tests_for_findsort();
    tests_for_search();
    tests_for_byn_iter_search();
    tests_for_bsort();
    tests_for_msort();
    tests_for_qsort();
    tests_for_ssort();
    //int* arr = CreateArrInc<int>(100000000, 0, 10000);
    //for (int i = 0; i < 100; i++)
    //{
    //    cout << arr[i] << "\n";
    //}
    //random_device rd;
    //mt19937 gen(rd());
    //uniform_int_distribution<> distr(0, 100000000-1);
    //int find_val = arr[distr(gen)];
    //cout << FindElem<int>(arr, 100000000, find_val) << "\n";
    //cout << FindElemDub<int>(arr, 100000000, find_val);
    //TotalTime<int>(arr, n, 0, n - 1);
    //string s = "arr1.txt";
    //SavetoF<int>(arr, 100000000, s);
    //elete[] arr;

}
