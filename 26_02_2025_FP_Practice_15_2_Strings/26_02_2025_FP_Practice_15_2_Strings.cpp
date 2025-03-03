#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <regex>

using namespace std;
/*
Задание 1. Дана строка символов. Заменить в ней все  пробелы на табуляции.
*/

string replaceSpaceWithTabs(const string& input) {
    string result = input;
    
    size_t pos = result.find(' ');

    while (pos != string::npos) {
        result.replace(pos, 1, "\t");
        pos = result.find(' ', pos + 1);
    }

    return result;
}


/*
Задание 2.Дана строка символов. Определить количество  букв, цифр и 
остальных символов, присутствующих в  строке.
*/

void countCharacters(const string& input, int& letters, int& digits, int& others) {
    letters = digits = others = 0;

    for (int i = 0; i < input.size(); i++) {

        if (isalpha(input[i])) {
            
        }
    }

    for (char c : input) {
        if (isalpha(c)) {
            letters++;
        }
        else if (isdigit(c)) {
            digits++;
        }
        else {
            others++;
        }
    }

}

/*
Задание 3. Подсчитать количество слов во введенном  предложении.
*/

int countWorld(const string& input) {
    const string separators{  }; // Разделители слов
    vector<string> words; // Вектор для хранения слов

    size_t start{ input.find_first_not_of(separators, 0) };
    while (start != string::npos) {
        size_t end = input.find_first_of(separators, start + 1); // Находим, где заканчивается слово
    
        if (end == string::npos) // Если не найден ни один из символов-разделителей
            end = input.length(); // Устанавливаем переменную end на конец текста
    
        words.push_back(input.substr(start, end - start));
        start = input.find_first_not_of(separators, end + 1); // Находим начальный индекс следующего слова
    }

    return words.size();
}


/*
    Задание 4. Дана строка символов. Необходимо проверить  
    является ли эта строка палиндромом.
*/


bool isPalindrome(const string& input) {
    string cleaned;
    stringstream object;

    for (char c : input) {
        string st{};
        if (!isspace(c)) {
            cleaned.push_back(tolower(c));
        }
    }

    string reversed = cleaned;

    reverse(reversed.begin(), reversed.end());

    return reversed == cleaned;

}

int main()
{

    //int arr[]{ 10,20,30,40,50,60,70,80,90,110 };

    //for (int i : arr) {
    //    cout << i;
    //}

    //vector<string> verarr {"Hello", "World", "How", "are"};

    //for (string item : verarr) {
    //    for (char c : item) {
    //        cout << c << endl;
    //    }
    //}

    // Задание 1.
    string input = "Hello World! How are you!";
    string output = replaceSpaceWithTabs(input);
    cout << input << endl << output << endl;

    // Задание 2.
    int letters, digits, others;
    countCharacters(input, letters, digits, others);
    cout << "Количество букв: " << letters << endl 
         << "Количество чисел: " << digits << endl 
         << "Количество символов: " << others;

    // Задание 4.

    string inp = "HelleH";
    if (isPalindrome(inp)) {
        cout << "Строка является палидромом." << endl;
    }
    else{
        cout << "Не очень ;)" << endl;
    }



    string text = "Contact us at email@example.com or support@domain.com for more information.";

    // Регулярное выражение для поиска email-адресов
    regex email_regex(R"(([a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\.[a-zA-Z]{2,}))");

    // Итератор для поиска всех совпадений в тексте
    auto words_begin = sregex_iterator(text.begin(), text.end(), email_regex);
    auto words_end = sregex_iterator();

    // Вывод всех найденных email-адресов
    for (sregex_iterator i = words_begin; i != words_end; ++i) {
        smatch match = *i;
        string match_str = match.str();
        cout << "Found email: " << match_str << '\n';
    }


}


