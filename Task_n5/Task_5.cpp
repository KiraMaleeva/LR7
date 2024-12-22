#include <iostream>
#include "../../Hat.h"
#include <string>
#include <cmath>
#include <algorithm>

std::string to3(long long a)
{
    std::string s;
    while (a != 0) // O(log a)
    {
        s = (char)('0' + a % 3) + s;
        a /= 3;
    }
    while (s.size() < 5)
        s = "0" + s;
    return s;
}

int main()
{
    hat(7);
    std::cout << "Патриций решил устроить праздник и для этого приготовил 240 бочек вина. Пользователь подсыпал яд в одну из бочек. Про яд известно, что человек, который его выпил, умирает в течение 24 часов. До праздника осталось два дня, то есть 48 часов. У патриция есть пять рабов, которыми он готов пожертвовать, чтобы узнать, в какой именно бочке яд. Найдите способ определения отравленной бочки с ядом.\n\n\n";

    while (true)
    {
        int n;
        std::string bch[240];
        short int live[5] = {2, 2, 2, 2, 2};
        for (int i = 1; i <= 240; i++)
            bch[i - 1] = to3(i); // O(log i) для каждого i

        std::cout << "Введите номер отравленной бочки: ";
        std::cin >> n;
        std::cout << "\nПервый день\n\n";

        for (int i = 0; i < 240; i++) // O(240), так как цикл фиксированный
        {
            if (i + 1 == n)
            {
                if (bch[i][0] == '0')
                    live[0] = 0;
                if (bch[i][1] == '0')
                    live[1] = 0;
                if (bch[i][2] == '0')
                    live[2] = 0;
                if (bch[i][3] == '0')
                    live[3] = 0;
                if (bch[i][4] == '0')
                    live[4] = 0;
            }
        }
        for (int i = 0; i < 5; i++)
        {
            std::cout << i + 1 << " раб: ";
            (live[i] == 0) ? std::cout << "мертв\n" : std::cout << "жив\n";
        }

        std::cout << "\nВторой день\n\n";
        for (int i = 0; i < 240; i++) // O(240), так как цикл фиксированный
        {
            if (i + 1 == n)
            {
                if (bch[i][0] == '1')
                    live[0] = 1;
                if (bch[i][1] == '1')
                    live[1] = 1;
                if (bch[i][2] == '1')
                    live[2] = 1;
                if (bch[i][3] == '1')
                    live[3] = 1;
                if (bch[i][4] == '1')
                    live[4] = 1;
            }
        }

        int res = 0, k = 0;
        for (int i = 4; i >= 0; --i)
        {
            if (live[i] == 2)
                k++;
            res += live[i] * pow(3, 4 - i);
        }

        std::cout << "Отравленная бочка: " << res << "\n\nВыживших рабов: " << k;

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