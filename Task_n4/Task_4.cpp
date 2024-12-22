#include <iostream>
#include "../../Hat.h"
#include <string>
#include <algorithm>

long long pl(long long a, long long b)
{
    while (b) // O(log b), где b - размер второго числа
    {
        long long c = a & b;
        a = a ^ b;
        b = c << 1;
    }
    return a;
}

long long mp(long long a, long long b)
{
    long long res = 0;
    while (b != 0) // O(log b), где b - размер второго числа
    {
        if (b & 1)
        {
            res = pl(res, a); // O(log a), так как pl выполняется внутри mp
        }
        a <<= 1;
        b >>= 1;
    }
    return res;
}

long long dv(long long a, long long b)
{
    long long c = 0;

    while (a >= b) // O(log a), где a - размер первого числа
    {
        long long i = 0, d = b;
        while (a >= (d << 1)) // O(log a), так как d удваивается на каждом шаге
        {
            i = pl(i, 1); // O(log i), так как выполняется внутри внешнего while
            d <<= 1;
        }
        c |= 1 << i;
        a = pl(a, (-1) * d); // O(log d)
    }
    return c;
}

long long mod(long long a, long long b)
{
    return pl(a, (-1) * mp(dv(a, b), b)); // O(log a + log b), так как вызывает другие функции
}

int main()
{
    hat(7);
    std::cout << "Необходимо разработать программу, которая проверяет, делится ли введенное пользователем число на 3, 79, 151\n\n\n";

    while (true)
    {
        long long n;

        std::cout << "Введите число: "; 
        n = cinll();
        std::cout << pl(13, 6);

        if (!mod(n, 3)) // O(log n)
        {
            std::cout << "Делится на 3\n";
        } else {
            std::cout << "Не делится на 3\n";
        }
        if (!mod(n, 79)) // O(log n)
        {
            std::cout << "Делится на 79\n";
        }else {
            std::cout << "Не делится на 79\n";
        }
        if (!mod(n, 151)) // O(log n)
        {
            std::cout << "Делится на 151\n";
        }else {
            std::cout << "Не делится на 151\n";
        }

        std::cout
            << "\n\n"
            << "Введите 1, чтобы вновь посчитать значения;\n"
            << "Введите 2, чтобы выйти из программы: " << '\n';

        while (true)
        {
            int a;
            a = cinll();

            std::cout << '\n';

            if (a == 1)
            {
                break;
            }
            if (a == 2)
                exit(0);
            else
                std::cout << "Необходимо ввести число 1 или 2, другие числа или буквы не допускаются!\n"
                          << '\n';
        }
    }

    return 0;
}