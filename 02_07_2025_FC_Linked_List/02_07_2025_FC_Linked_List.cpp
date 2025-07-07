#include <iostream>
//#include "LinkedList.h"
#include "DoublyLinkedList.h"

int main()
{

    //LinkedList<int> list;

    //list.AddToTail(10);
    //list.AddToTail(20);
    //list.AddToTail(30);
    //list.Show();


    //list.InsertAt(1, 15);
    //list.Show();

    //list.DeleteAt(2);
    //list.Show();

    //int pos = list.Find(15);
    //cout << "Элемент 15 находится по индексу [" << pos << "];" << endl;

    //int replacements = list.Replace(10, 100);

    //cout << "Замене подверглось " << replacements << " объектов;" << endl;

    //list.Reverse();
    //list.Show();


    DoublyLinkedList<int> list;
    list.AddToHead(1);
    list.AddToTail(2);
    list.AddToTail(3);
    list.AddToHead(0);
    list.Show();

    list.DeleteFromHead();
    list.DeleteFromTail();
    list.Show();

    list.InsertAt(1, 5);
    list.InsertAt(0, -1);
    list.InsertAt(4, 10);


    list.Show();

    list.DeleteAt(2);
    list.Show();

    int pos = list.Find(2);
    cout << pos << endl;

    int replacements = list.Replace(1, 100);
    cout << replacements << endl;
    list.Show();

    list.Reverse();
    list.Show();

    list.DeleteAll();
    list.Show();
    



    return 0;
}
