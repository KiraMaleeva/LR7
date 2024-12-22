#include <iostream>
#include "../../Hat.h"
#include <string>
#include <algorithm>
#include <cmath>

char base[] = "0123456789ABCDEFGHIGKLMNOPQRSTUVWXYZ";

// перевод в заданую си
std::string si(int a, int n, int k)
{
    std::string res = "";
    int N = std::abs(a);

    while (N > 0) // O(log N)
    {
        res = base[N % n] + res;
        N /= n;
    }

    while (res.size() < k - 1) // O(k)
    {
        res = "0" + res;
    }

    res = ((a >= 0) ? '0' : base[n - 1]) + res;
    return res;
}

std::string obr(std::string res, int n)
{
    for (size_t i = 1; i < res.size(); i++) // O(n), где n - размер строки res
    {
        if (isdigit(res[i]))
        {
            res[i] = base[(n - 1) - (res[i] - '0')];
        }
        else
        {
            res[i] = base[(n - 1) - (res[i] - 'A' + 10)];
        }
    }
    return res;
}

std::string dop(int a, int n, int k)
{
    if (a >= 0)
    {
        return si(a, n, k);
    }
    else
    {
        std::string res = obr(si(a, n, k), n);
        for (int i = res.size() - 1; i >= 0; i--) // O(n), где n - размер строки res
        {
            if (res[i] == base[n - 1])
            {
                res[i] = '0';
            }
            else
            {
                if (isdigit(res[i]))
                {
                    res[i] = res[i] + 1;
                }
                else
                {
                    res[i] = base[(res[i] - 'A' + 10) + 1];
                }
                break;
            }
        }
        return res;
    }
}

std::string pr(std::string res, int n)
{
    if (res[0] == '0')
    {
        return res;
    }
    else
    {
        for (size_t i = 1; i < res.size(); i++) // O(n), где n - размер строки res
        {
            if (isdigit(res[i]))
            {
                res[i] = base[(n - 1) - (res[i] - '0')];
            }
            else
            {
                res[i] = base[(n - 1) - (res[i] - 'A' + 10)];
            }
        }
        int carry = 1;
        for (int i = res.size() - 1; i >= 0; i--) // O(n), где n - размер строки res
        {
            int d;
            if (isdigit(res[i]))
            {
                d = res[i] - '0';
            }
            else
            {
                d = res[i] - 'A' + 10;
            }
            int sum = d + carry;
            carry = sum / n;
            res[i] = base[sum % n];
        }
        res[0] = base[n - 1];
        return res;
    }
}

std::string calc(long long a, long long b, std::string res1, std::string res2, int n)
{
    int carry = 0;
    std::string res = "";
    for (int i = res1.size() - 1; i >= 0; i--) // O(n), где n - размер строки res1
    {
        int d1 = isdigit(res1[i]) ? res1[i] - '0' : res1[i] - 'A' + 10;
        int d2 = isdigit(res2[i]) ? res2[i] - '0' : res2[i] - 'A' + 10;
        int sum = d1 + d2 + carry;
        carry = sum / n;
        res = base[sum % n] + res;
    }

    if (a * b < 0)
    {
        if (res[0] != '0')
        {
            res = pr(res, n);
            res[0] = '-';
        }
    }
    else if (a > 0 && b > 0)
    {
        if (carry != 0)
        {
            res = base[carry] + res;
        }
    }
    else
    {
        res = pr(res, n);
        res[0] = '-';
    }
    return res;
}

int main()
{

    hat(7);
    std::cout << "Найдите сумму двоичных чисел, заданных в естественной форме. Сложение выполните в обратном коде. Ответ выразите в прямом коде.\n\n\n";

    while (true)
    {
        long long n, a, b;
        std::cout << "Введите систему исчисления: ";
        std::cin >> n;
        std::cout << "Введите первое число: ";
        a = cinll();
        std::cout << "Введите второе число: ";
        b = cinll();

        int max = std::max(std::abs(a), std::abs(b));
        int k = static_cast<int>(std::log(max) / std::log(n)) + 2;

        std::cout << "\n"
                  << "Сумма: "
                  << calc(a, b, dop(a, n, k), dop(b, n, k), n);

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