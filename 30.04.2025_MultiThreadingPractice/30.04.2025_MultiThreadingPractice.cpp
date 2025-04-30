#include <iostream>
#include <fstream>
#include <thread>
#include <chrono>
#include <random>
#include <string>

#include <shared_mutex>
#include <condition_variable>
using namespace std;

// Глобальные переменные
mutex file_mutex;        // Разделяемая блокировка (множественное чтение / эксклюзивная запись).
condition_variable file_ready;  // Условная переменная для ожидания данных.
bool data_available = false;    // Флаг наличия новых данных.




// Функция писатель
void writer(const string& filename) {
    ofstream file(filename, ios::app);

    if (!file.is_open()) {
        cerr << "Ошибка открытия файла!" << endl;
        return;
    }

    //Генератор случайных чисел

    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dist(1, 100);

    for (int i = 0; i < 5; ++i) {
        this_thread::sleep_for(chrono::seconds(1));
        int num = dist(gen);

        // Блокировка на запись (эксклюзивная)
        {
            unique_lock<mutex> lock(file_mutex);
            file << num << endl;
            cout << "Писатель записал: " << num << endl;
            data_available = true;
        }

    }
    file_ready.notify_all();
}


void reader(const string& filename, int reader_id) {
    ifstream file(filename);

    if (!file.is_open()) {
        cerr << "Ошибка открытия файла!" << endl;
        return;
    }

    //Бесконечный цикл чтения

    while (true) {

        unique_lock<mutex> lock(file_mutex);
        file_ready.wait(lock, [] { return data_available; });

        string line;
        while (getline(file, line)) {}    // Пропускаем все строки до последней

        if (!line.empty()) {
            cout << "Читатель " << reader_id << " прочитал: " << line << endl;
        }

        file.clear();
        file.seekg(0, ios::end);


    }
}


int main()
{
    setlocale(LC_ALL, "");
    const string filename = "data.txt";
    ofstream clear_file(filename, ios::trunc);
    clear_file.close();

    thread writer_t(writer, filename);
    thread rider1(reader, filename, 1);
    thread rider2(reader, filename, 2);



    writer_t.join();

    //rider1.detach();
    //rider2.detach();
    
    rider1.join();
    rider2.join();
    
    
    return 0;

}
