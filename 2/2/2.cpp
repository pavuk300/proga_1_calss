#include <iostream>
#define _USE_MATH_DEFINES
#include <math.h>


int main()
{
    setlocale(LC_ALL, "Russian");
    std::cout << "Вычислисть объем и полную поверхность усе ченного конуса.\n"; //1
    std::cout << "Объем(введите r, R, h через пробел R > r): ";
    float r, R, h, l;
    std::cin >> r >> R >> h;
    if (R > r and R > 0 and r > 0 and h > 0)
    {
        l = (float)sqrt(h * h + pow(R - r, 2));
        std::cout << "V = " << (float)1 / 3 * M_PI * (R * R + R * r + r * r) << "\n";
        std::cout << "S = " << (float)M_PI * (R * R + (R + r) * l + r * r) << "\n";
    }
    else
        std::cout << "-_-\n";

    std::cout << "Задача разветвление.\n"; //2e
    float a, x;
    std::cout << "Ведите x и a через пробел: ";
    std::cin >> x >> a;
    if (x != 0)
    {
        if (abs(x) < 1)
            if (a != 0)
                std::cout << "w = " << (float)a * log(abs(x)) << "\n";
            else
                std::cout << 0 << "\n";
        else
            if (x * x < a)
                std::cout << "w = " << (float)sqrt(a - x * x) << "\n";
            else
                std::cout << "w не определено.";
    }
    else
        std::cout << "Не существует";


    float y, b; //3e
    std::cout << "Для произвольных x, y, b рассчитать функцию.\n";
    std::cout << "x, y, b(через пробел): ";
    std::cin >> x >> y >> b;
    if (b < y or b <= x)
        std::cout << "z не определено.\n";
    else
        std::cout << "z = " << (float)log(b - y) * sqrt(b - x) << "\n";

    int n; //4e
    std::cout << "Распечатать 10 последовательных натуральных чисел начиная с N.\n";
    std::cout << "Введите N: ";
    std::cin >> n;
    for (int i = n; i < n + 10; ++i)
        std::cout << i << " ";
    std::cout << "\n";

    std::cout << "Табулирование функции.\n"; //5e
    for (x = -4; x <= 4; x += 0.5)
    {
        if (x != 1)
            std::cout << "y(" << x << ") = " << (float)(x * x - 2 * x + 2) / (x - 1) << "\n";
        else
            std::cout << "При x = 1 значение не определенно.\n";
    }

}