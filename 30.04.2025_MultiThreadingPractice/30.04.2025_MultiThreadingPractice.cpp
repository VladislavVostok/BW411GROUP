//#include <iostream>
//#include <fstream>
//#include <thread>
//#include <chrono>
//#include <random>
//#include <string>
//
//#include <shared_mutex>
//#include <condition_variable>
//
//
using namespace std;
//
//// Глобальные переменные
//mutex file_mutex;        // Разделяемая блокировка (множественное чтение / эксклюзивная запись).
//condition_variable file_ready;  // Условная переменная для ожидания данных.
//bool data_available = false;    // Флаг наличия новых данных.
//bool done = true;
//
//
//
//// Функция писатель
//void writer(const string& filename) {
//    ofstream file(filename, ios::app);
//
//    if (!file.is_open()) {
//        cerr << "Ошибка открытия файла!" << endl;
//        return;
//    }
//
//    //Генератор случайных чисел
//
//    random_device rd;
//    mt19937 gen(rd());
//    uniform_int_distribution<> dist(1, 100);
//
//    for (int i = 0; i < 5; ++i) {
//        this_thread::sleep_for(chrono::seconds(1));
//        int num = dist(gen);
//
//        // Блокировка на запись (эксклюзивная)
//        {
//            unique_lock<mutex> lock(file_mutex);
//            file << num << endl;
//            cout << "Писатель записал: " << num << endl;
//            data_available = true;
//        }
//
//    }
//    file_ready.notify_all();
//}
//
//
//void reader(const string& filename, int reader_id) {
//    ifstream file(filename);
//
//    if (!file.is_open()) {
//        cerr << "Ошибка открытия файла!" << endl;
//        return;
//    }
//
//    //Бесконечный цикл чтения
//
//    while (true) {
//
//        unique_lock<mutex> lock(file_mutex);
//        file_ready.wait(lock, [] { return data_available || done; });
//
//        string line;
//        while (getline(file, line)) {}    // Пропускаем все строки до последней
//
//        if (!line.empty()) {
//            cout << "Читатель " << reader_id << " прочитал: " << line << endl;
//        }
//
//        file.clear();
//        file.seekg(0, ios::end);
//
//
//    }
//}
//
//
//int main()
//{
//    setlocale(LC_ALL, "");
//    const string filename = "data.txt";
//    ofstream clear_file(filename, ios::trunc);
//    clear_file.close();
//
//    thread writer_t(writer, filename);
//    thread rider1(reader, filename, 1);
//    thread rider2(reader, filename, 2);
//
//
//
//    writer_t.join();
//
//    //rider1.detach();
//    //rider2.detach();
//    
//    rider1.join();
//    rider2.join();
//    
//    
//    return 0;
//
//}

//
//#include <future>
//#include <iostream>
//#include <thread>

//
//int main(int argc, char* argv[]) {
//    int count = 10;
//
//    auto future1 = std::async(std::launch::async, [&count] {
//        for (int i = 0; i < count; ++i) {
//            std::cout << 1;
//            std::this_thread::sleep_for(std::chrono::milliseconds(1));
//        }
//        });
//    auto future2 = std::async(std::launch::async, [&count] {
//        for (int i = 0; i < count; ++i) {
//            std::cout << 2;
//            std::this_thread::sleep_for(std::chrono::milliseconds(1));
//        }
//        });
//
//    return 0;
//}
#include <future>
#include <iostream>
#include <thread>

//promise<int> prom;
//shared_future<int> shared_fut = prom.get_future().share();
//
//
//void main() {
//    setlocale(LC_ALL, "");
//    auto reader = [](std::shared_future<int> f) {
//        std::cout << "Поток " << std::this_thread::get_id()
//            << " получил " << f.get() << std::endl;
//        };
//
//
//
//    std::thread t1(reader, shared_fut);
//    std::thread t2(reader, shared_fut);
//
//    this_thread::sleep_for(std::chrono::seconds(10));
//
//    prom.set_value(42);  // Записываем значение
//
//    t1.join(); t2.join();
//
//}


//#include <iostream>
//#include <thread>
//
//thread_local int thread_specific_var = 0; // Уникальна для каждого потока
//
//void thread_function(int id) {
//    thread_specific_var = id;
//    cout << "Поток " << id << ": " << thread_specific_var << std::endl;
//}
//
//int main() {
//    setlocale(LC_ALL, "");
//    thread t1(thread_function, 1);
//    thread t2(thread_function, 2);
//
//    t1.join();
//    t2.join();
//
//    // В основном потоке переменная осталась 0
//    cout << "Основной поток: " << thread_specific_var << std::endl;
//    return 0;
//}


#include <iostream>
#include <vector>
#include <queue>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <functional>
#include <future>

// Класс пула потоков
class ThreadPool {
public:
    // Конструктор создает указанное количество потоков
    ThreadPool(size_t threads) : stop(false) {
        for (size_t i = 0; i < threads; ++i) {
            // Создаем рабочие потоки
            workers.emplace_back([this] {
                // Бесконечный цикл выполнения задач
                while (true) {
                    std::function<void()> task;  // Объект для хранения задачи

                    {
                        // Блокируем мьютекс для доступа к очереди задач
                        std::unique_lock<std::mutex> lock(this->queue_mutex);

                        // Ожидаем, пока появится задача или будет сигнал остановки
                        this->condition.wait(lock,
                            [this] { return this->stop || !this->tasks.empty(); });

                        // Если остановка и очередь пуста - завершаем поток
                        if (this->stop && this->tasks.empty())
                            return;

                        // Берем задачу из очереди
                        task = std::move(this->tasks.front());
                        this->tasks.pop();
                    }

                    // Выполняем задачу (мьютекс уже разблокирован)
                    task();
                }
            });
        }
    }

    // Метод для добавления задачи в пул
    template<class F, class... Args>
    auto enqueue(F&& f, Args&&... args)
        -> std::future<typename std::result_of<F(Args...)>::type> {
        // Определяем тип возвращаемого значения функции
        using return_type = typename std::result_of<F(Args...)>::type;

        // Создаем packaged_task для функции, чтобы можно было получить future
        auto task = std::make_shared<std::packaged_task<return_type()>>(
            // Связываем функцию с аргументами
            std::bind(std::forward<F>(f), std::forward<Args>(args)...)
        );

        // Получаем future для результата задачи
        std::future<return_type> res = task->get_future();

        {
            // Блокируем мьютекс для добавления задачи в очередь
            std::unique_lock<std::mutex> lock(queue_mutex);

            // Проверяем, не остановлен ли пул
            if (stop)
                throw std::runtime_error("enqueue on stopped ThreadPool");

            // Добавляем задачу в очередь (лямбда, которая выполняет packaged_task)
            tasks.emplace([task]() { (*task)(); });
        }

        // Уведомляем один из ожидающих потоков о новой задаче
        condition.notify_one();

        // Возвращаем future, через который можно получить результат
        return res;
    }

    // Деструктор останавливает все потоки
    ~ThreadPool() {
        {
            // Блокируем мьютекс для установки флага остановки
            std::unique_lock<std::mutex> lock(queue_mutex);
            stop = true;
        }

        // Уведомляем все потоки о необходимости завершиться
        condition.notify_all();

        // Дожидаемся завершения всех рабочих потоков
        for (std::thread& worker : workers)
            worker.join();
    }

private:
    std::vector<std::thread> workers;  // Вектор рабочих потоков
    std::queue<std::function<void()>> tasks;  // Очередь задач

    std::mutex queue_mutex;  // Мьютекс для синхронизации доступа к очереди
    std::condition_variable condition;  // Условная переменная для ожидания задач
    bool stop;  // Флаг остановки пула
};

int main() {
    // Создаем пул из 4 потоков
    ThreadPool pool(4);
    std::vector<std::future<int>> results;  // Вектор для хранения результатов

    // Добавляем 8 задач в пул
    for (int i = 0; i < 90; ++i) {
        results.emplace_back(
            pool.enqueue([i] {
                std::cout << "Задача " << i << " выполняется\n";
                std::this_thread::sleep_for(std::chrono::seconds(1));
                return i * i;
                })
        );
    }

    // Ожидаем результаты всех задач
    for (auto&& result : results)
        std::cout << "Результат: " << result.get() << std::endl;

    return 0;
}