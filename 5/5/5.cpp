#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <random>
#include <climits>

using std::cin;
using std::cout;

long int inp()
{
	std::string s;
	std::getline(std::cin, s);
	char* p;
	if (!s.size())
	{
		std::cout << "Введите число в правильном формате: ";
		return inp();
	}
	for (unsigned long long int i = 0; i < s.size(); i++)
	{
		if (!isdigit(s[i]) and s[i])
		{
			std::cout << "Введите число в правильном формате: ";
			return inp();
		}
	}
	if (std::strtol(s.c_str(), &p, 10) == INT_MAX)
		cout << "Введеное чиссло слишком большое, поэтому программа выполнится для максимального числа " << INT_MAX << "\n";
	return std::strtol(s.c_str(), &p, 10);
}

long long int fac(long long int n)
{
	unsigned long long int s = 1;
	while (n)
	{
		s *= n;
		n--;
	}
	return s;
}

int random_num(int x0, int x1)
{
	return x0 + (rand() % static_cast<int>(x1 - x0 + 1));
}

std::string random_word()
{
	int len = 1 + (rand() % 100);
	std::string s = "";
	for (int i = 0; i < len; i++)
		s += std::string(1, (char)random_num(97, 122));
	return s;
}

bool* resh(int n) //Решето Эратосфена
{
	bool *mas = new bool[n + 1];
	for (unsigned long long int i = 0; i <= n; ++i)
		mas[i] = true;
	for (unsigned long long int i = 2; i <= n; ++i)
		if (mas[i])
			for (unsigned long long int j = i * i; j <= n; j += i)
				mas[j] = false;
	return mas;
}

void Evk() //1
{
	std::cout << "Алгоритм Евклида\n";
	int a, b;
	std::cout << "Введите a: ";
	a = inp();
	std::cout << "Введите b: ";
	b = inp();
	int a1 = a, b1 = b;
	if (a >= 0 and b >= 0 or ((a == 0 and b != a) or (b == 0 and a != b)))
	{
		while (a != 0 and b != 0) //деление
		{
			if (a > b)
				a = a % b;
			else
				b = b % a;
		}
		std::cout << a + b << "\n";

		while (a1 != 0 and b1 != 0) //вычитание
		{
			if (a1 > b1)
				a1 = a1 - b1;
			else
				b1 = b1 - a1;
		}
		std::cout << a1 + b1 << "\n";
	}
	else
		std::cout << "-_-\n";

}

void resh_out() //2
{
	std::cout << "Решето Эратосфена.\nВведите число до которого нужно найти простые: ";
	unsigned long long int n = inp();
	if (n >= 0)
	{
		try
		{
			bool* mas = resh(n);
			for (unsigned long long int i = 0; i <= n; ++i)
				if (mas[i] == 1)
				{
					std::cout << i << " - простое\n";
				}
				else
					std::cout << i << " - составное\n";
		}
		catch (const std::exception&)
		{
			cout << "Слишком большое число\n";
		}
	}
	else
		std::cout << "-_-";
}

void find_max_min_word(std::string in) //3
{
	std::ifstream Fo(in);
	std::string s, sMax, sMin;
	int maxim = 0, mini = 999999999;
	while (!Fo.eof())
	{
		Fo >> s;
		if (s.size() > maxim)
		{
			maxim = s.size();
			sMax = s;
		}
		if (s.size() < mini)
		{
			mini = s.size();
			sMin = s;
		}
	}
	Fo.close();
	std::string mas[] = { sMax, sMin };
	std::cout << "Самое длинное слово в файле " << in << ": " << sMax << "\n";
}

void four() //4
{
	std::cout << "Задание ряды.\n";
	std::cout << "Введите n: ";
	long int n = inp();
	bool out = true;
	if (n >= 1)
	{
		long double s = 0, ss = 0; int j;
		for (long int i = 1; i <= n; i++)
		{
			s = 0;
			for (j = 1; j <= i; j++)
				s += (long double)pow(-1, j % 2 + 1) * 1 / j;
			ss += (long double)fac(i) / s;
			if (ss < 0)
			{
				cout << "Число слишком большое.\n";
				out = false;
				break;
			}
		}
		if (out)
			std::cout << std::fixed << ss << "\n";
	}
	else
		cout << "n больше нуля\n";
}

void files(std::string in) //5
{
	std::cout << "Задание файлы. Добовление произвольного слова в файл и сортировка слов файле\n";
	std::ifstream Fo(in);
	std::ofstream Fi("out1.txt");
	std::string s;
	std::vector<std::string> mas;
	while (!Fo.eof())
	{
		Fo >> s;
		mas.push_back(s);
	}
	mas.push_back(random_word());
	std::string *arr = new std::string[mas.size()];
	std::copy(mas.begin(), mas.end(), arr);
	std::sort(arr, arr + mas.size());
	for (int i = 0; i < mas.size(); i++)
	{
		Fi << arr[i] << " ";
		std::cout << arr[i] << "\n";
	}
	Fo.close();
	Fi.close();
}

int main()
{
	cout << INT_MAX << "\n";
	setlocale(LC_ALL, "Russian");
	std::cout << "Введите номер задания(0 - 5) (0 - выход): ";
	int a = inp();
	if (a == 1)
		Evk();
	if (a == 2)
		resh_out();
	if (a == 3)
		find_max_min_word("in.txt");
	if (a == 4)
		four();
	if (a == 5)		
		files("in1.txt");
	if (a > 5 or a < 0)
		std::cout << "Такого задания нет" << "\n";
	if (a)
	{
		system("pause");
		system("cls");
		main();
	}
}