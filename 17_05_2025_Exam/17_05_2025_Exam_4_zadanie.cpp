#include <iostream>
#include <string>
#include <fstream>
#include <ctime>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <cctype>
#include <climits>

using namespace std;

const int MAX_SIZE = 50;

struct Stack {
    int data[MAX_SIZE];
    int top = -1;
};

void push(Stack& s, int value) {
    if (s.top >= MAX_SIZE - 1) {
        cout << "Стек переполнен!" << endl;
        return;
    }

    s.data[++s.top] = value;
}

int pop(Stack& s) {
    if (s.top < 0) {
        cout << "Стек пуст!" << endl;
        return INT_MIN;
    }

    int temp = s.data[s.top];
    s.data[s.top] = INT_MAX;
    s.top--;
    return temp;
}

int peek(const Stack& s) {
    if (s.top < 0) {
        cout << "Стек пуст!" << endl;
        return INT_MIN;

    }

    return s.data[s.top];
}

bool isEmpty(const Stack& s) {
    return s.top == -1;
}

void printStack(const Stack& s) {
    if (isEmpty(s)) {
        cout << "Стек пуст!" << endl;
        return;
    }
    cout << "Стек: " << endl;
    for (int i = 0; i <= s.top; ++i) {
        cout << s.data[i] << " -> ";
    }
    cout << endl;
}

int main()
{
    setlocale(LC_ALL, "");
    Stack s;
    push(s, 10);
    push(s, 20);
    push(s, 30);
    push(s, 40);
    push(s, 50);
    push(s, 60);
    push(s, 70);

    printStack(s);

    pop(s);

    printStack(s);
    pop(s);
    printStack(s);
    cout << peek(s) << endl;


}
