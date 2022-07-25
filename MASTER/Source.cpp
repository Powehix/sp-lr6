#include<iostream>
#include<windows.h>
#include<string>
#include<time.h>

using namespace std;

int main(int argc, char **argv)
{
	//10 �������

	setlocale(LC_ALL, "Russian");

	cout << "MASTER �������!\n\n";

	//���������� ������� ���������� ������������� �������� �������
	if (argc == 2)
	{
		//���������� ��� ������ � ����������
		cout << "���������� ����������...\n";
		DWORD dwExitCode;
		STARTUPINFO cif;
		PROCESS_INFORMATION pi;
		LPSTR processname = argv[1];

		//������ ������������ �����
		cout << "������ ������������ �����...\n";
		ZeroMemory(&cif, sizeof(STARTUPINFO));
		if (CreateProcess(NULL, processname, NULL, NULL, FALSE, CREATE_NEW_CONSOLE, NULL, NULL, &cif, &pi) == TRUE)
		{
			if (WaitForSingleObject(pi.hProcess, INFINITE) != WAIT_FAILED)
			{
				//�������� ���������� ����������� ��������
				cout << "�������� ���������� ����������...\n";
				GetExitCodeProcess(pi.hProcess, &dwExitCode);
				cout << "Exit code: " << dwExitCode << endl;
			}
			CloseHandle(pi.hProcess);
		}
	}

	//���������� ������� ���������� ������, ��� ����������
	else if (argc > 2)
	{
		cout << "������� ����� ������� ����������! ���������� ������...\n";
		return 1;
	}

	//������� ��������� �� ��������
	else if (argc == 1)
	{
		srand(time(NULL));

		cout << "��������� �� ��������!\n";
		cout << "��������� ���� ����� �����...\n";
		int m = rand() % 4 + 5;   //����� ����������� ������� �� ���� ������� �������
		int n = rand() % 4 + 5;
		cout << "����� ��������������� �����:\n\n";
		cout << m << " � " << n << endl << endl;

		//���������� ��� ������ � ����������
		cout << "���������� ����������...\n";
		DWORD dwExitCode;
		STARTUPINFO cif;
		PROCESS_INFORMATION pi;
		char processname[MAX_PATH];

		//��������� �������������� ����������
		cout << "��������� �������������� ����������...\n";
		DWORD PID;
		PID = GetCurrentProcessId();

		//�������������� ��������������� ����� ����� � ������
		cout << "�������������� ��������������� ����� � ������...\n";

		string parameters = "SLAVE.exe " + to_string(m) + " " + to_string(n) + " " + to_string(PID);
		cout << "����������� � ������ ������������ �����...\n";
		strcpy_s(processname, parameters.c_str());

		//������ ������������ �����
		cout << "������ SLAVE...\n";
		ZeroMemory(&cif, sizeof(STARTUPINFO));
		if (CreateProcess(NULL, processname, NULL, NULL, FALSE, CREATE_NEW_CONSOLE, NULL, NULL, &cif, &pi) == TRUE)
		{
			//�������� ���������� ����������� ��������
			cout << "�������� ���������� SLAVE...\n";
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