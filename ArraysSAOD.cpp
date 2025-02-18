#include <iostream>
#include "Templates.h"

using namespace std;

int main()
{
    int* arr = CreateArrInc<int>(100000000, 0, 10000);
    //for (int i = 0; i < 100; i++)
    //{
    //    cout << arr[i] << "\n";
    //}
    TotalTime<int>(arr, 100000000, 0, 100000000 - 1);
    string s = "arr1.txt";
    //SavetoF<int>(arr, 100000000, s);

}
