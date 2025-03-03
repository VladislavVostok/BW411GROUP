#include <iostream>
#include <string>

using namespace std;

int main()
{

    string message1{ "Hello!" };
    string message2 = "Hello!";
    string message3("Hello!");

    std::cout << message1 << endl;
    std::cout << message2 << endl;
    std::cout << message3 << endl;

    string message4(10, '*');

    std::cout << message4 << endl;


    string hello1{ "hello world" };
    string message_hello{ hello1 }; // message = "hello world"

    string message5{ "hello world", 4 }; // берем первые 4 символа - message1 = "hell"

    string message6{ "hello world", 6, 5 }; // 5 символов начиная с 6 символа - message2 = "world"

    cout << message6.capacity()<< " " << message6.size() << " " << message6.length();

    
    string message;

    if (message.empty())
        cout << "String is empty" << std::endl;
    else
        cout << "String is not empty" << std::endl;

    std::string hello{ "hello" };
    std::string world{ "world" };

    cout << hello + " " + world + "!" << std::endl;

    string message{ "hello "s + "world"s + "!"s };

    wstring text1{ L"Name: \t\"Tom\"\nAge:\t38" };
    string text2{ R"(Name:    "Tom"
        Age:    38)" };


    string dig{ "123" };
    int n{ stoi(dig) }; // n == 123


    cout << string::npos;

}