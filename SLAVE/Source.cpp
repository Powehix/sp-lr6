#include<iostream>
#include<windows.h>
#include<time.h>

using namespace std;

int main(int argc, char **argv)
{
	//10 вариант

	setlocale(LC_ALL, "Russian");

	cout << "SLAVE запущен!\n\n";

	//количество входных параметров соответствует условиям задания
	if (argc >= 3)
	{
		//количество входных аргументов равно трем, если SLAVE не получает PID приложения MASTER (запущен независимо от него)
		if (argc == 3)
		{
			cout << "SLAVE запущен независимо от MASTER.\n";
		}

		//количество входных аргументов равно четырем, если SLAVE получает PID приложения MASTER (запущен при помощи MASTER)
		if (argc == 4)
		{
			cout << "SLAVE запущен при помощи MASTER.\n";
			cout << "PID: " << argv[3] << endl;
		}

		//преобразование полученных переменных в числа
		cout << "Преобразование полученных переменных в числа...\n";
		const int m = atoi(argv[1]);
		const int n = atoi(argv[2]);

		//инициализация двумерного массива вещественных чисел
		cout << "Инициализация двумерного массива вещественных чисел...\n";
		float **arr = new float*[m];   //строки
		for (int i = 0; i < m; i++)
		{
			arr[i] = new float[n];   //столбцы
		}

		//заполнение массива случайными вещественными числами
		cout << "Заполнение массива случайными вещественными числами и вывод:\n\n";
		srand(time(NULL));
		for (int i = 0; i < m; i++)
		{
			//cout << "Вывод массива:\n";
			for (int j = 0; j < n; j++)
			{
				arr[i][j] = (float)rand() * 64 / 1024;
				cout << arr[i][j] << "\t";
			}
			cout << endl;
		}

		//сортировка массива в строках в порядке убывания
		cout << "\nСортировка массива в строках в порядке убывания...\n";
		int count = 1;
		for (int i = 0; i < m; i++)
		{
			while (count != 0)
			{
				count = 0;
				for (int j = 0; j < n - 1; j++)
				{
					if (arr[i][j] < arr[i][j + 1])
					{
						count++;
						swap(arr[i][j], arr[i][j + 1]);
					}
				}
			}
			count = 1;
		}

		//вывод отсортированного массива в строках
		cout << "Вывод отсортиванного массива в строках в порядке убывания:\n\n";
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
				cout << arr[i][j] << "\t";
			cout << endl;
		}

		system("PAUSE");
		return 0;
	}

	//количество входных параметров не соответствует условиям задания
	else
	{
		cout << "Параметры не переданы! Завершение программы...\n";
		system("PAUSE");
		return 1;
	}
}