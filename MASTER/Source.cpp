#include<iostream>
#include<windows.h>
#include<string>
#include<time.h>

using namespace std;

int main(int argc, char **argv)
{
	//10 вариант

	setlocale(LC_ALL, "Russian");

	cout << "MASTER запущен!\n\n";

	//количество входных параметров соответствует условиям задания
	if (argc == 2)
	{
		//переменные для работы с процессами
		cout << "Объявление переменных...\n";
		DWORD dwExitCode;
		STARTUPINFO cif;
		PROCESS_INFORMATION pi;
		LPSTR processname = argv[1];

		//запуск исполняемого файла
		cout << "Запуск исполняемого файла...\n";
		ZeroMemory(&cif, sizeof(STARTUPINFO));
		if (CreateProcess(NULL, processname, NULL, NULL, FALSE, CREATE_NEW_CONSOLE, NULL, NULL, &cif, &pi) == TRUE)
		{
			if (WaitForSingleObject(pi.hProcess, INFINITE) != WAIT_FAILED)
			{
				//ожидание завершения запущенного процесса
				cout << "Ожидание завершения приложения...\n";
				GetExitCodeProcess(pi.hProcess, &dwExitCode);
				cout << "Exit code: " << dwExitCode << endl;
			}
			CloseHandle(pi.hProcess);
		}
	}

	//количество входных параметров больше, чем необходимо
	else if (argc > 2)
	{
		cout << "Слишком много входных параметров! Завершение работы...\n";
		return 1;
	}

	//входные параметры не переданы
	else if (argc == 1)
	{
		srand(time(NULL));

		cout << "Параметры не переданы!\n";
		cout << "Генерация двух целых чисел...\n";
		int m = rand() % 4 + 5;   //чтобы размерность массива не была слишком большой
		int n = rand() % 4 + 5;
		cout << "Вывод сгенерированных чисел:\n\n";
		cout << m << " и " << n << endl << endl;

		//переменные для работы с процессами
		cout << "Объявление переменных...\n";
		DWORD dwExitCode;
		STARTUPINFO cif;
		PROCESS_INFORMATION pi;
		char processname[MAX_PATH];

		//получение идентификатора приложения
		cout << "Получение идентификатора приложения...\n";
		DWORD PID;
		PID = GetCurrentProcessId();

		//преобразование сгенерированных целых чисел в строки
		cout << "Преобразование сгенерированных чисел в строки...\n";

		string parameters = "SLAVE.exe " + to_string(m) + " " + to_string(n) + " " + to_string(PID);
		cout << "Объединение с именем исполняемого файла...\n";
		strcpy_s(processname, parameters.c_str());

		//запуск исполняемого файла
		cout << "Запуск SLAVE...\n";
		ZeroMemory(&cif, sizeof(STARTUPINFO));
		if (CreateProcess(NULL, processname, NULL, NULL, FALSE, CREATE_NEW_CONSOLE, NULL, NULL, &cif, &pi) == TRUE)
		{
			//ожидание завершения запущенного процесса
			cout << "Ожидание завершения SLAVE...\n";
			if (WaitForSingleObject(pi.hProcess, INFINITE) != WAIT_FAILED)
			{
				GetExitCodeProcess(pi.hProcess, &dwExitCode);
				cout << "Exit code: " << dwExitCode << endl;
			}
			CloseHandle(pi.hProcess);
		}

	}

	return 0;
}