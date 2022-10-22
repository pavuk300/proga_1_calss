#include <iostream>
#include <fstream>
#include <string>
#define _USE_MATH_DEFINES
#include <math.h>
#include <map>
#include <Windows.h>


bool sign(float x) //sign
{
	if (x == 0)
		return true;
	if (x < 0)
		return false;
	else
		return true;
}

float tri(float a, float b, float ang) //треугольник
{
	return sin(ang * M_PI / 180) * a * b / 2;
}


float sq(float a, float b) //прямоугольник
{
	return a * b;
}


float roun(float r) //окружность
{
	return M_PI * r * r;
}


float row_column(float* column, float* row) //перемножение столбца и строки
{
	float out = 0;
	for (int i = 0; i < 4; i++)
	{
		out += column[i] * row[i];
	}
	return out;
}


std::string calculate_ss(std::string nums, int n, int n2) //перевод nums из n - ой системы в n2 - ую
{
	int index = nums.length() - 1; //Позиция цифры
	int corr = 55, s(0); //корректировка по ascii
	for (int i = 0; i < nums.length(); i++) //перевод из n в 10
	{
		std::string let(1, nums[i]); //Символ из числа
		if (isdigit((int)(char)nums[i])) //Если цифра то корректировку не делаем, если буква, то делаем
		{
			s += std::stoi(let) * pow(n, index);
			if (std::stoi(let) >= n) //-_-
				return "-_-";
		}
		else
		{
			s += ((int)let[0] - corr) * pow(n, index);
			if (((int)let[0] - corr) >= n) //-_-
				return "-_-";
		}
		--index; //уменьшаем индекс
	}
	if (n2 != 10)
	{
		std::string stro(""); //перевод из 10 в n2
		int deb;
		while (s > 0)
		{
			deb = s % n2;
			if (deb > 9)
				stro += (char)(deb + corr);
			else
				stro += std::to_string(deb);
			s /= n2;
		}
		std::reverse(stro.begin(), stro.end());
		return stro;
	}
	return std::to_string(s);
}

//----------------- Вспомогательные функции -----------------\\

void print_matrix(float(*mas)[3]) //Вывод матрицы на печать
{
	for (int i = 0; i < 2; ++i)
	{
		std::cout << "| ";
		for (int j = 0; j < 3; ++j)
		{
			if (j != 2)
				std::cout << mas[i][j] << "\t";
			else
				std::cout << mas[i][j];
		}
		std::cout << " |\n";
	}
}


bool startwith(std::string s, std::string st) //Если строка s начинается с st, то true иначе false
{
	if (st.length() > s.length())
		return false;
	for (int i = 0; i < st.length(); ++i)
		if (s[i] != st[i])
			return false;
	return true;
}


std::string cutstring(std::string str, int n) //Вырезание подстроки, начинающаяся с элемента с индексом n
{
	std::string out = "";
	for (int(i) = n; i < str.length(); ++i)
		out += str[i];
	return out;

}

//----------------------------------------------------------\\

std::map<int, std::string> p;

void prepare_dic() //создание словаря с римскими обозначениями
{
	p[-3000] = "MMM";
	p[-2000] = "MM";
	p[-1000] = "M";
	p[-900] = "CM";
	p[-500] = "D";
	p[-400] = "CD";
	p[-300] = "CCC";
	p[-200] = "CC";
	p[-100] = "C";
	p[-90] = "XC";
	p[-50] = "L";
	p[-40] = "XL";
	p[-30] = "XXX";
	p[-20] = "XX";
	p[-10] = "X";
	p[-9] = "IX";
	p[-8] = "VIII";
	p[-7] = "VII";
	p[-6] = "VI";
	p[-5] = "V";
	p[-4] = "IV";
	p[-3] = "III";
	p[-2] = "II";
	p[-1] = "I";
}

int from_roman(std::string r) //основная функция
{
	std::string s = "", prevVal = "", currVal = "", tmpVal = "";
	std::map<int, std::string>::iterator it = p.begin(); //иттератор словаря
	int val, summ = 0;
	std::string key;
	for (int i = 0; it != p.end(); it++, i++)
	{
		key = it->second;
		//if (key != "I" or key != "V" or key != "X" or key != "L" or key != "C" or key != "D" or key != "M")
			//return -1;
		val = -(it->first);
		while (startwith(r, key))
		{
			r = cutstring(r, (int)key.length());
			summ += val;
		}
	}
	return summ;
}

int main()
{
	setlocale(LC_ALL, "Russian");
	/*std::cout << "Создание файла.\n";							//1d
	std::ofstream Fw("text.txt");
	std::string in;
	std::cout << "Введите 10 числел:\n";
	for (int i = 0; i < 10; i++)
	{
		std::cin >> in;
		Fw << in << "\n";
	}
	Fw.close();
	std::ifstream Fr("text.txt");
	std::string line;
	float a, s = 0;
	while (std::getline(Fr, line))
	{
		a = std::stof(line);
		s += a;
	}
	Fr.close();
	std::cout << "Сумма чисел из файла: " <<(float)s << "\n";

	//---------------------------------------------------------------------------------------------------------------------//

	std::cout << "Sign\nВведите x: ";							//2d
	float x;
	std::cin >> x;
	if (sign(x))
		std::cout << "Положительное.\n";
	else
		std::cout << "Отрицательное.\n";*/

	//---------------------------------------------------------------------------------------------------------------------//

	float a, b, ang, r;											//3d
	std::cout << "Введите две стороны и угол между ними: ";
	std::cin >> a >> b >> ang;
	if (a > 0 and b > 0 and ang > 0 and ang < 180)
		std::cout << "S = " << tri(a, b, ang) << "\n";
	else
		std::cout << "-_-\n";

	std::cout << "Введите две стороны прямоуголькоика: ";
	std::cin >> a >> b;
	if (a > 0 and b > 0)
		std::cout << "S = " << sq(a, b) << "\n";
	else
		std::cout << "-_-\n";

	std::cout << "Введите радиус окружности: ";
	std::cin >> r;
	if (r > 0)
		std::cout << "S = " << roun(r) << "\n";
	else
		std::cout << "-_-\n";

	//---------------------------------------------------------------------------------------------------------------------//

	/*std::string ss1 = "********------------------";				//4d
	std::string ss2 = "--------------------------";
	for (int i = 1; i <= 13; ++i)
	{
		if (i <= 6)
			std::cout << ss1 << "\n";
		else
			std::cout << ss2 << "\n";
	}*/

	//---------------------------------------------------------------------------------------------------------------------//

	std::cout << "Синусоида\n";
	HWND hwnd = GetConsoleWindow();
	HDC dc = GetDC(hwnd);

	int x = 0;
	for (float i = 0; i < M_PI * 10; i += 0.05, ++x)
		SetPixel(dc, x, 250 + 25 * sin(i), RGB(255, 255, 255));

	//---------------------------------------------------------------------------------------------------------------------//

	/*std::cout << "Конвертер римских чисел.\n";					//6d
	std::cout << "Введите римское число.\n";
	prepare_dic(); //создание словаря
	std::string rim;
	std::cin >> rim;
	std::cout << rim << " = " << from_roman(rim) << "\n";*/

	//---------------------------------------------------------------------------------------------------------------------//

	/*std::cout << "Генератор чисел.\n";							//7d
	int n, m, b1;
	std::cout << "Введите i, m, b: ";
	std::cin >> n >> m >> b1;
	if (n > 0)
	{
		int* mas;
		mas = new int[n];
		mas[0] = 0;
		std::cout << mas[0] << "\n";
		for (int i = 1; i < n; ++i)
		{
			mas[i] = m * mas[i - 1] + b;
			std::cout << mas[i] << "\n";
		}
	}
	else
		std::cout << "-_-\n";

	//---------------------------------------------------------------------------------------------------------------------//

	std::cout << "Перемножение матриц.\n";						//8d
	float mas1[3][4] = { {5, 2, 0, 10}, {3, 5, 2, 5}, {20, 0, 0, 0} }, mas2[2][4] = { {1.2, 2.8, 5, 2}, {0.5, 0.4, 1, 1.5} }, masS[2][3]; //Таблицы
	for (int i = 0; i < 2; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			masS[i][j] = row_column(mas2[i], mas1[j]); //Умножение
		}
	}
	print_matrix(masS); //Вывод матрицы C
	float max1(0), min1(100000), max2(0), min2(100000), s1(0), s2(0);
	int maxo1, maxo2, mino1, mino2;
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (!i) //Вырученные бабки
			{
				if (max1 < masS[i][j]) //Максимум
				{
					max1 = masS[i][j];
					maxo1 = j + 1;
				}
				if (min1 > masS[i][j]) //Минимум
				{
					min1 = masS[i][j];
					mino1 = j + 1;
				}
				s1 += masS[i][j];      //Сумма
			}
			else  //Комиссионные бабки
			{
				if (max2 < masS[i][j]) //максимум
				{
					max2 = masS[i][j];
					maxo2 = j + 1;
				}
				if (min2 > masS[i][j]) //Минимум
				{
					min2 = masS[i][j];
					mino2 = j + 1;
				}
				s2 += masS[i][j];	   //Сумма
			}
		}
	}
	std::cout << "1) Больше всего денег выручил " << maxo1 << " продавец. Меньше всего " << mino1 << " продавец.\n";
	std::cout << "2) Больше комиссионных получил " << maxo2 << " продавец. Меньше всего " << mino2 << " продавец.\n";
	std::cout << "3) Общая сумма вырученных денег равна: " << s1 << "\n";
	std::cout << "4) Сумма комиссионных равна: " << s2 << "\n";
	std::cout << "5) Общая сумма прошедшая через руки продавцов равна: " << s1 + s2 << "\n";
	
	//---------------------------------------------------------------------------------------------------------------------//
																//9d
	std::cout << "Введите число, его сиситему счисления и в какую нужно перевести: ";
	std::string nums;
	int n1, n2;
	std::cin >> nums >> n1 >> n2;
	std::cout << calculate_ss(nums, n1, n2);*/
}