#include <iostream>
#include "CharStack.h"
#include "IntegerQueue.h"

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
    setlocale(LC_ALL, "");
    //auto arr = Array<int>();
    //auto arr1 = Array<int>();

    //arr.SetSize(5, 5);
    //std::cout << arr.GetUpperBound() << " " << arr.IsEmpty() << std::endl;

    //for (int i = 0; i < 20; ++i) {
    //    arr.Add(i);
    //}
    //std::cout << arr.GetSize() << " " << arr.GetUpperBound() << " " << arr.IsEmpty() << std::endl;
    //for (int i = 19; i >= 0; i--) {
    //    arr1.Add(i);
    //}
    //std::cout << arr1.GetSize() << " " << arr1.GetUpperBound() << " " << arr1.IsEmpty() << std::endl;
    //
    //arr.Append(arr1);

    //std::cout << arr.GetSize() << " " << arr.GetUpperBound() << " " << arr.IsEmpty() << std::endl;

    //for (int i = 0; i < arr.GetSize(); i++) {
    //    std::cout << arr[i] << ((arr.GetUpperBound() != i) ? ", " : "");
    //}
    //std::cout << std::endl;

    //CharStack stack(5);

    //for (char c = 'a'; c <= 'z'; ++c) {
    //    stack.push(c);

    //}


    //while (!stack.isEmpty()) {
    //    std::cout << stack.pop() << " ";
    //}

    //std::cout << std::endl;

    //stack.shrinkToFit();

    //std::cout << stack.getCapacity() << " " << stack.getSize();
    //


    IntegerQueue queue(5);

    queue.Enqueue(10);
    queue.Enqueue(20);
    queue.Enqueue(30);

    std::cout << "Содержание очереди: " << std::endl;
    queue.Show();

    std::cout << "Извлечен: " << queue.Dequeue() << std::endl;
    std::cout << "Извлечен: " << queue.Dequeue() << std::endl;


    queue.Enqueue(40);
    queue.Enqueue(50);
    queue.Enqueue(60);


    std::cout << "Содержание очереди: " << std::endl;
    queue.Show();

    queue.Enqueue(70);
    queue.Enqueue(80);

    std::cout << "Содержание очереди: " << std::endl;
    queue.Show();
}