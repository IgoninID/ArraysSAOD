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
    tests_for_isort();
    //size_t ns = 50000;
    //double time_sort = 0;
    //for (int i = 0; i < 100; i++)
    //{
    //    long long* arr = CreateArr<long long>(ns, 0, 1000000000);
    //    time_sort += TimeFunc([&]() {SortShell(arr, ns);});
    //    delete[] arr;
    //}
    //std::cout << time_sort / 100.0;
    
    size_t n = 2500000000;
    long long* arr = CreateArrInc<long long>(n, 0, 20000);
    random_device rd; // инициализация случайных чисел
    mt19937 gen(rd()); // генератор случайных чисел
    uniform_int_distribution<> distr(0, 2000000000000000); // равномерное целочисленное распределение случайных чисел
    double times = 0; // счетчик времени
    for (int i = 0; i < 500000; i++)
    {
       long long find_val = distr(gen); // выбираем случайный элемент в качестве искомого
        times = times + TimeFunc([&]() {size_t i = Bin_search_rec<long long>(arr, 0, n-1, find_val);});
                                        //size_t i = FindElem(arr, n, find_val);}); // находим время затраченное на поиск элемента в массиве, суммируем
    }
    std::cout << times;
    delete[] arr;


    //cout << FindElem<int>(arr, 100000000, find_val) << "\n";
    //cout << FindElemDub<int>(arr, 100000000, find_val);
    //TotalTime<int>(arr, n, 0, 300000000);
    //string s = "arr1.txt";
    //SavetoF<int>(arr, 100000000, s);
    return 0;
}
