#include <iostream>
#include <math.h>


void solve(float b, float c)
{
    if (b != 0)
        std::cout << "x = " << (float)-c / b << "\n";
    else
        std::cout << "Бесконечно много решений\n";
}


int main()
{
    setlocale(LC_ALL, "Russian");
    std::cout << "Уравнение bx + c = 0.\n";
    std::cout << "Введите b и c через пробел: ";
    float a, b, c, D;
    std::cin >> b >> c;
    solve(b, c);

    std::cout << "Уравнение ax^2 + bx + c = 0.\n";
    std::cout << "Введите a, b и c через пробел: ";
    std::cin >> a >> b >> c;
    if (a == 0)
        solve(b, c);
    else
    {
        D = (float)b * b - 4 * a * c;
        if (D > 0)
        {
            D = (float)sqrt(D);
            std::cout << "x1 = " << (float)(-b - D) / 2 * a << "x2 = " << (float)(-b + D) / 2 * a << "\n";
        }
        else if (D == 0)
            std::cout << "x = " << (float)(-b) / 2 << "\n";
        else if (D < 0)
            std::cout << "Решений нет.\n";
    }

    std::cout << "Лампа со шторкой.\n";
    bool b1, b2, b3;
    std::cout << "Раздвинуты ли шторы(0 или 1)?: ";
    std::cin >> b1;
    std::cout << "На улице день(0 или 1)?: ";
    std::cin >> b2;
    std::cout << "Включена ли лампа(0 или 1)?: ";
    std::cin >> b3;
    if (b3 or (b2 and b1))
        std::cout << "Светло\n";
    else
        std::cout << "Темно\n";
    return 0;
}