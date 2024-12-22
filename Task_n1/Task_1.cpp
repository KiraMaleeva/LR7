#include <iostream>
#include "../../Hat.h"
#include <string>

std::string calc(std::string a)
{
    if (a[0] == '0')
        return a;
    if (a[a.size() - 1] == '1')
        a[a.size() - 1] = '0';
    else
    {
        a[a.size() - 1] = '1';
        for (int i = a.size() - 2; i > 0; i--) // O(n), где n - размер строки a
            if (a[i] == '0')
            {
                a[i] = '1';
            }
            else
            {
                a[i] = '0';
                break;
            }
    }
    return a;
}

int main()
{
    hat(7);
    std::cout << "Перевести числа из дополнительного кода в обратный.\n\n\n";

    while (true)
    {
        std::string a;
        std::cout << "Введите число в дополнительном коде: ";
        std::cin >> a;

        std::cout << "\n"
                  << "В обратном: "
                  << calc(a); // O(n), вызов функции с алгоритмической сложностью O(n)

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
                std::cout << "Необходимо ввести число 1 или 2, другие числа или буквы не допускаются!\n";
        }
    }

    return 0;
}
