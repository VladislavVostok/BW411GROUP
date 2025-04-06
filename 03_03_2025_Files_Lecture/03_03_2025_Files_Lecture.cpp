#include <iostream>
#include <string>
#define _CRT_SECURE_NO_WARNINGS

using namespace std;

struct Item {
    char title[20];
    unsigned int qty;
    float price;
};


int main()
{

    setlocale(LC_ALL, "");
    //FILE* myFile;

    //fopen_s(&myFile, "mydata.txt", "a");

    //fclose(myFile);


    //fopen_s(&myFile, "mydata.txt", "r");

    //if (myFile == NULL)
    //    cout << "Файл не существует!";
    //else {
    //    cout << "Файл в памяти!";
    //}

    //fclose(myFile);




    wstring str = L"product";
    const int n = 100;
    int arr[n];
    FILE* out;
    const char* path = "D:\\examples\\outfile.txt";
    for (int i = 0; i < n; i++)
    {
        arr[i] = i + 5;
    }
    if ((fopen_s(&out, path, "w")) != NULL)
        cout << "The file could not be created";
    else
    {
        for (int i = 0; i < n; i++)
        {
            fprintf(out, "%.6d ", arr[i]);
            fprintf(out, "\n");
        }
        if (fclose(out) == EOF)
            cout << "The file is not closed";
        else
            cout << "The file is closed";
    }

    int a;

    if (fopen_s(&out, path, "r") != NULL)
        cout << "The file cannot be opened";
    else
    {
        while (!feof(out)) {
            fscanf_s(out, "%d", &a);
            cout << a << " ";
        }
    }



    int i = 0;
    FILE* in;
    Item myshop[10];
    const char* path1 = "D:\\examples\\data.txt";
    if (fopen_s(&in, path1, "r") != NULL)
        cout << "The file cannot be opened";
    else
    {
        while (!feof(in)) {
            fscanf_s(in, "%s", myshop[i].title,
                sizeof(myshop[i].title));
            fscanf_s(in, "%u", &myshop[i].qty,
                sizeof(myshop[i].qty));
            fscanf_s(in, "%f", &myshop[i].price,
                sizeof(myshop[i].price));
            cout << myshop[i].title << " "
                << myshop[i].qty << " "
                << myshop[i].price << "\n";;
            i++;
        }
    }
    fflush(in);

    
    int c;
    int len = 0;
    char buf[128];
    FILE* in1;
    if (fopen_s(&in1, path1, "r") != NULL)
        cout << "The file cannot be opened";
    else
    {
        while (!feof(in1)) {
            fgets(buf, 127, in1);
            len = strlen(buf);
            if (buf[len - 1] == '\n')
            {
                buf[len - 1] = '\0';
            }
            puts(buf);
        }
    }
    return 0;

}
