#include <iostream>
#include "Array.h"

//template <typename T>
//double average(T arr[], int size) {
//    if (size == 0) return 0.0;
//
//    T sum = arr[0];
//
//    for (int i = 1; i < size; i++) {
//        sum += arr[i];
//    }
//
//    return static_cast<double>(sum) / size;
//}

int main()
{

    auto arr = Array<int>();
    auto arr1 = Array<int>();

    arr.SetSize(5, 5);
    std::cout << arr.GetUpperBound() << " " << arr.IsEmpty() << std::endl;

    for (int i = 0; i < 20; ++i) {
        arr.Add(i);
    }
    std::cout << arr.GetSize() << " " << arr.GetUpperBound() << " " << arr.IsEmpty() << std::endl;
    for (int i = 19; i >= 0; i--) {
        arr1.Add(i);
    }
    std::cout << arr1.GetSize() << " " << arr1.GetUpperBound() << " " << arr1.IsEmpty() << std::endl;
    
    arr.Append(arr1);

    std::cout << arr.GetSize() << " " << arr.GetUpperBound() << " " << arr.IsEmpty() << std::endl;

    for (int i = 0; i < arr.GetSize(); i++) {
        std::cout << arr[i] << ((arr.GetUpperBound() != i) ? ", " : "");
    }
    std::cout << std::endl;

}