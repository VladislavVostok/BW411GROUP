#include <iostream>
#include <thread>
#include <vector>
//
//void worker() {
//    std::cout << "Поток с ID: " << std::this_thread::get_id() << " работает\n";
//    std::this_thread::sleep_for(std::chrono::milliseconds(100));
//    std::cout << "Поток с ID: " << std::this_thread::get_id() << " Завершил работу \n";
//}
//
//int main() {
//
//    setlocale(LC_ALL, "");
//    const int num_threads = 20;
//    std::vector<std::thread> threads;
//
//    // Создаем и запускаем потоки
//    for (int i = 0; i < num_threads; ++i) {
//        threads.emplace_back(worker);
//    }
//
//    // Выводим ID главного потока
//    std::cout << "Главный поток ID: " << std::this_thread::get_id() << "\n";
//
//    // Выводим ID созданных потоков
//    for (auto& t : threads) {
//        std::cout << "Созданный поток ID: " << t.get_id() << "\n";
//        t.join();
//    }
//
//    // ID несуществующего потока
//    std::thread t;
//    std::cout << "ID неинициализированного потока: " << t.get_id() << "\n";
//
//    return 0;
//}


#include <iostream>
#include <thread>
#include <vector>

//void task(int id) {
//    std::cout << "Задача " << id << " выполняется на ядре "
//        << std::this_thread::get_id() << "\n";
//    // Имитация работы
//    std::this_thread::sleep_for(std::chrono::milliseconds(100));
//}
//
//int main() {
//
//    setlocale(LC_ALL, "");
//    // Получаем количество поддерживаемых аппаратных потоков
//    unsigned int n = std::thread::hardware_concurrency();
//
//    std::cout << "Доступно аппаратных ядер: " << n << "\n";
//
//    // Создаем оптимальное количество потоков
//    std::vector<std::thread> threads;
//    for (unsigned int i = 0; i < n; ++i) {
//        threads.emplace_back(task, i + 1);
//    }
//
//    for (auto& t : threads) {
//        t.join();
//    }
//
//    // Пример, когда hardware_concurrency() не может определить количество
//    if (n == 0) {
//        std::cout << "Не удалось определить количество ядер. Используем 2 потока.\n";
//        std::thread t1(task, 1);
//        std::thread t2(task, 2);
//        t1.join();
//        t2.join();
//    }
//
//    return 0;
//}


#include <iostream>
#include <thread>
#include <mutex>
#include <vector>

//std::mutex mtx; // Мьютекс для синхронизации доступа
//int shared_data = 0;
//
//void increment(int n) {
//    for (int i = 0; i < n; ++i) {
//        // Блокируем мьютекс перед доступом к общим данным
//        std::cout << std::this_thread::get_id() << std::endl;
//        std::lock_guard<std::mutex> lock(mtx);
//        ++shared_data;
//        //Мьютекс автоматически освобождается при выходе из области видимости
//    }
//}
//
//int main() {
//    setlocale(LC_ALL, "");
//    std::thread t1(increment, 100000);
//    std::thread t2(increment, 100000);
//
//    t1.join();
//    t2.join();
//
//    std::cout << "Результат: " << shared_data << std::endl;
//    // Без мьютекса результат мог бы быть меньше 200000
//    return 0;
//}

//#include <iostream>
//#include <thread>
//#include <mutex>
//
//std::mutex mtx; // Создаем мьютекс
//int shared_data = 0;
//
//void flexible_increment() {
//    for (int i = 0; i < 100000; ++i) {
//        std::unique_lock<std::mutex> lock(mtx, std::defer_lock); // Не блокируем сразу
//        // Можно выполнить другие операции...
//        lock.lock(); // Блокируем явно
//        ++shared_data;
//        // Можно разблокировать раньше конца области видимости
//        lock.unlock();
//    }
//}
//
//
//std::recursive_mutex rec_mtx;
//
//void recursive_function(int level) {
//    std::lock_guard<std::recursive_mutex> lock(rec_mtx);
//    std::cout << "Уровень: " << level << "Thread ID" << std::this_thread::get_id() << std::endl;
//    std::this_thread::sleep_for(std::chrono::milliseconds(500));
//    if (level > 0) {
//        recursive_function(level - 1);
//    }
//}
//
//
//std::timed_mutex timed_mtx;
//
//void timed_thread() {
//    auto now = std::chrono::steady_clock::now();
//    std::cout << "Thread ID" << std::this_thread::get_id() << std::endl;
//    if (timed_mtx.try_lock_until(now + std::chrono::milliseconds(100))) {
//        std::cout << "Поток получил блокировку\n";
//        std::this_thread::sleep_for(std::chrono::milliseconds(50));
//        timed_mtx.unlock();
//    }
//    else {
//        std::cout << "Поток не получил блокировку за отведенное время\n";
//    }
//}
//
//void increment() {
//    for (int i = 0; i < 100000; ++i) {
//        mtx.lock();   // Блокируем мьютекс
//        ++shared_data; // Критическая секция
//        mtx.unlock(); // Разблокируем мьютекс
//    }
//}
//
//int main() {
//    setlocale(LC_ALL, "");
//    std::thread t1(timed_thread);
//    std::thread t2(timed_thread);
//
//    t1.join();
//    t2.join();
//
//    std::cout << "Результат: " << shared_data << std::endl;
//    return 0;
//}

#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <queue>

#include <atomic>

std::mutex mtx;
std::condition_variable cv;
std::queue<int> data_queue;

bool finished = false;


// Поток-производитель
void producer() {
    for (int i = 0; i < 1000; ++i) {
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
        
            data_queue.push(i);


        cv.notify_one(); // Уведомляем один ожидающий поток
    
    }
    {
        std::lock_guard<std::mutex> lock(mtx);
        finished = true;
    }
    cv.notify_all(); // Уведомляем все ожидающие потоки
}

// Поток-потребитель
void consumer(int n) {
    while (true) {
       

        if (finished && data_queue.empty()) break;

        while (!data_queue.empty()) {
            int val = data_queue.front();
            data_queue.pop();
            std::cout << "Потреблено " << n <<": " << val << std::endl;
        }
    }
}

int main() {
    setlocale(LC_ALL, "");
    
    std::atomic<int> bits(255);

    bits.fetch_and(240);   // Атомарное AND
    
    
    std::thread t1(producer);
    std::thread t2(consumer, 777);
    std::thread t3(consumer, 555);

    t1.join();
    t2.join();
    t3.join();

    return 0;
}