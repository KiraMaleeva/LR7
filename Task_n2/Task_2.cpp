#include <iostream>
#include "../../Hat.h"
#include <string>
#include <algorithm>

std::string si(int a)
{
    std::string res = "";
    unsigned int N = std::abs(a);

    while (N > 0) // O(log N)
    {
        res = (N % 2 ? '1' : '0') + res;
        N /= 2;
    }

    res = ((a >= 0) ? '0' : '1') + res;
    return res;
}

std::string obr(std::string res)
{
    for (size_t i = 0; i < res.size(); i++) // O(n), где n - размер строки res
    {
        res[i] = (res[i] == '0') ? '1' : '0';
    }
    return res;
}

std::string sum(std::string res1, std::string res2)
{
    if (res1.size() < res2.size())
    {
        res1.insert(0, res2.size() - res1.size(), '0'); // O(n), где n - разница в размерах res1 и res2
    }
    else if (res2.size() < res1.size())
    {
        res2.insert(0, res1.size() - res2.size(), '0'); // O(n), где n - разница в размерах res2 и res1
    }
    std::string res(res1.size(), '0');
    int carry = 0;
    for (int i = res1.size() - 1; i >= 0; i--) // O(n), где n - размер строки res1
    {
        int bit1 = res1[i] - '0';
        int bit2 = res2[i] - '0';
        int sum = bit1 + bit2 + carry;
        res[i] = (sum % 2) + '0';
        carry = sum / 2;
    }
    if (carry)
    {
        res.insert(res.begin(), '1'); // O(n), где n - размер строки res
    }
    return res;
}

// Главная функция
int main()
{
    std::cout << "Найдите сумму двоичных чисел, заданных в естественной форме. Сложение выполните в обратном коде. Ответ выразите в прямом коде.\n\n\n";

    while (true)
    {
        long long a, b;
        std::cout << "Введите первое число: ";
        std::cin >> a;
        std::cout << "Введите второе число: ";
        std::cin >> b;

        std::cout << "\nСумма: " << obr(sum(obr(si(a)), obr(si(b)))); // O(n), вызовы функций с алгоритмической сложностью O(n)

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
