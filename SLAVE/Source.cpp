#include<iostream>
#include<windows.h>
#include<time.h>

using namespace std;

int main(int argc, char **argv)
{
	//10 �������

	setlocale(LC_ALL, "Russian");

	cout << "SLAVE �������!\n\n";

	//���������� ������� ���������� ������������� �������� �������
	if (argc >= 3)
	{
		//���������� ������� ���������� ����� ����, ���� SLAVE �� �������� PID ���������� MASTER (������� ���������� �� ����)
		if (argc == 3)
		{
			cout << "SLAVE ������� ���������� �� MASTER.\n";
		}

		//���������� ������� ���������� ����� �������, ���� SLAVE �������� PID ���������� MASTER (������� ��� ������ MASTER)
		if (argc == 4)
		{
			cout << "SLAVE ������� ��� ������ MASTER.\n";
			cout << "PID: " << argv[3] << endl;
		}

		//�������������� ���������� ���������� � �����
		cout << "�������������� ���������� ���������� � �����...\n";
		const int m = atoi(argv[1]);
		const int n = atoi(argv[2]);

		//������������� ���������� ������� ������������ �����
		cout << "������������� ���������� ������� ������������ �����...\n";
		float **arr = new float*[m];   //������
		for (int i = 0; i < m; i++)
		{
			arr[i] = new float[n];   //�������
		}

		//���������� ������� ���������� ������������� �������
		cout << "���������� ������� ���������� ������������� ������� � �����:\n\n";
		srand(time(NULL));
		for (int i = 0; i < m; i++)
		{
			//cout << "����� �������:\n";
			for (int j = 0; j < n; j++)
			{
				arr[i][j] = (float)rand() * 64 / 1024;
				cout << arr[i][j] << "\t";
			}
			cout << endl;
		}

		//���������� ������� � ������� � ������� ��������
		cout << "\n���������� ������� � ������� � ������� ��������...\n";
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

		//����� ���������������� ������� � �������
		cout << "����� �������������� ������� � ������� � ������� ��������:\n\n";
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
				cout << arr[i][j] << "\t";
			cout << endl;
		}

		system("PAUSE");
		return 0;
	}

	//���������� ������� ���������� �� ������������� �������� �������
	else
	{
		cout << "��������� �� ��������! ���������� ���������...\n";
		system("PAUSE");
		return 1;
	}
}