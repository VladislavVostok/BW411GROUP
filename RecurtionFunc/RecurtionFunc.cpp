#include <iostream>
#include <chrono>


long int factorial(long int n) {
    if (n == 0) {
        return 0;
    }
    else if (n == 1) {
        return 1;
    }
    else {
        return n * factorial(n - 1);
    }
}

long int factorial2(long int N)
{
    long int F = 1;
    // цикл осуществляет подсчет факториала
    for (int i = 2; i <= N; i++)
        F *= i;
    return F;
}

int main()
{
    unsigned long int res;
    auto start_time = std::chrono::steady_clock::now();

     res = factorial(10);

    auto end_time = std::chrono::steady_clock::now();
    auto elapsed_ns = std::chrono::duration_cast<std::chrono::nanoseconds>(end_time - start_time);
    std::cout << elapsed_ns.count() << " ns\n";

    start_time = std::chrono::steady_clock::now();

    res = factorial(10);

    end_time = std::chrono::steady_clock::now();
    elapsed_ns = std::chrono::duration_cast<std::chrono::nanoseconds>(end_time - start_time);

    std::cout << elapsed_ns.count() << " ns\n";
    return 0;
}
