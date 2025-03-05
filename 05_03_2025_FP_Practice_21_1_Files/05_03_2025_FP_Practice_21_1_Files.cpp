#include <iostream>
#include <string>
#include <fstream>

using namespace std;

#define MAX_WORD 100

bool isLongWord(const char* word) {
    return strlen(word) >= 7;
}

bool isLongWord(const string& word) {
    return word.length() >= 7;
}

void task1(const char* inputFile, const char* outputFile) {
    FILE* in, * out;
    
    if (fopen_s(&in, inputFile, "r") != 0 || fopen_s(&out, outputFile, "w") != 0) {
        perror("Ошибка открытия файла");
        return;
    }

    char word[MAX_WORD];

    while (!feof(in)) {
        fgets(word, MAX_WORD - 1, in);
        if (isLongWord(word)) {
            fprintf_s(out, "%s", word);
        }
    }

    fclose(in);
    fclose(out);
}

void task1WithStream(const string& inputFile, const string& outputFile) {
    ifstream inFile(inputFile);
    ofstream outFile(outputFile, ios::app);

    if (!inFile || !outFile) {
        cerr << "Ошибка открытия файла!" << endl;
        return;
    }

    string word;

    while (getline(inFile, word)) {
        if (isLongWord(word)) {
            outFile << word << endl;
        }
    }

    outFile.close();
    inFile.close();
}


int main()
{
    setlocale(LC_ALL, "");
    //task1("input.txt", "output1.txt");
    task1WithStream("input.txt", "output1.txt");
}

