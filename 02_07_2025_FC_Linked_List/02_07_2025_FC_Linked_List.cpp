#include <iostream>
#include "LinkedList.h"

int main()
{

    LinkedList<int> list;

    list.AddToTail(10);
    list.AddToTail(20);
    list.AddToTail(30);
    list.Show();


    list.InsertAt(1, 15);
    list.Show();

    list.DeleteAt(2);
    list.Show();

    int pos = list.Find(15);
    cout << "Элемент 15 находится по индексу [" << pos << "];" << endl;

    int replacements = list.Replace(10, 100);

    cout << "Замене подверглось " << replacements << " объектов;" << endl;

    list.Reverse();
    list.Show();

    return 0;
}
