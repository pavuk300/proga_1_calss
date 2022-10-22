#include <iostream>
#include <math.h>
#include <cmath>
#include <fstream>
#include <string>
#include <stdlib.h>

int sortup(const void* a, const void* b)
{
	return (*(int*)a - *(int*)b);
}

float func(float s, float m, float n, float r) 
{
	return (s * r * pow(1 + r, n)) / (12 * (pow(1 + r, n) - 1));
}

int main()
{
	setlocale(LC_ALL, "Russian");
	std::cout << "Заем.\n";                         //1
	float s, p, n, r, m;
	std::cout << "s, p, n через пробел: ";
	std::cin >> s >> p >> n;
	r = (float)p / 100;
	if (n == 0 and r == 0)
		std::cout << s << "\n";
	else if (n == 0)
		std::cout << s * (r + 1) << "\n";
	else if (r == 0)
		std::cout << (float)s / (n * 12) << "\n";
	else
	{
		m = (float)(s * r * pow(1 + r, n)) / (12 * (pow(1 + r, n) - 1));
		std::cout << m << "\n";
	}

	std::cout << "Ссуда.\n";                        //2
	std::cout << "s, m, n через пробел: ";
	std::cin >> s >> m >> n;
	float left = -1, right = 100;
	if (s <= 0 or n <= 0 or m <= 0) {
		std::cout << "-_-" << "\n";
	}
	else if (12 * m == s / n) {
		std::cout << "0" << "\n";
		//return 0;
	}
	else
	{
		float mid;
		for (int i = 0; i < 100; ++i) 
		{
			mid = (left + right) / 2;
			if (func(s, m, n, mid) > (m + 0.000001)) 
				right = mid;
			if (func(s, m, n, mid) < (m - 0.000001)) 
				left = mid;
			if (func(s, m, n, mid) < (m + 0.000001) and func(s, m, n, mid) > (m - 0.000001)) {
				r = mid;
				break;
			}
		}
	}
	std::cout << r * 100 << "\n";

	std::ifstream F("C:/C++/3/inp.txt");            //3
	std::string line;
	std::cout << "Строки из файла.\n";
	while (std::getline(F, line))
		std::cout << line << "\n";
	F.close();

	F.open("C:/C++/3/inp.txt");
	std::cout << "Цифры из файла.\n";                 //4
	while (std::getline(F, line))
	{
		for (int i = 0; i < line.size(); i++)
		{
			if (isdigit((int)line[i]))
				std::cout << line[i];
		}
		if (!F.eof())
			std::cout << "\n";
	}
	F.close();

	std::cout << "Алфавитный порядок\n";            //5
	std::string str;
	std::cin >> str;
	if (str.size() == 30)
	{
		int mas[30];
		for (int i = 0; i < 30; i++)
		{
			mas[i] = (int)str[i];
		}
		qsort(mas, 30, sizeof(int), sortup);
		for (int i = 0; i < 30; i++)
		{
			std::cout << (char)mas[i];
		}
	}
	else
		std::cout << "-_-";
}