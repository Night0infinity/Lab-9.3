#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <algorithm>
#include <Windows.h> // ������������ ����������� ��������
using namespace std;


struct Student
{
	string prizv;
	double bal1;
	double bal2;
	double bal3;
};

void Create(Student* p, const int N);
void Print(Student* p, const int N);
void Sortprizv(Student* p, const int N);
void Sortavg(Student* p, const int N);
void Sortbal1(Student* p, const int N);
void Sortbal2(Student* p, const int N);
void Sortbal3(Student* p, const int N);
void SaveToFile(Student* p, const int N, const char* filename);
void LoadFromFile(Student*& p, int& N, const char* filename);
void Remove(Student*& p, int& size, int index);
void Add(Student*& p, int& size);
void Change(Student* p, const int size, int index, int option);

int main()
{ // ������������ ����������� ��������:
	SetConsoleCP(1251); // ������������ ������� win-cp1251 � ���� �����
	SetConsoleOutputCP(1251); // ������������ ������� win-cp1251 � ���� ������
	int N, index, option;
	cout << "������ N: "; cin >> N;

	Student* p = new Student[N];

	char filename[100];
	string prizv;

	int menuItem;
	do {
		cout << endl << endl << endl;
		cout << "������� ��:" << endl << endl;
		cout << " [1] - �������� ����� � ���������" << endl;
		cout << " [2] - ���� ����� �� �����" << endl;
		cout << " [3] - ���������� �� ������� �����" << endl;
		cout << " [4] - ���������� �� ��������" << endl;
		cout << " [5] - ���������� �� 1 ���. �����" << endl;
		cout << " [6] - ���������� �� 2 ���. �����" << endl;
		cout << " [7] - ���������� �� 3 ���. �����" << endl;
		cout << " [8] - ����� ����� � ����" << endl;
		cout << " [9] - ���������� ����� �� �����" << endl;
		cout << " [10] - ��������� ����������" << endl;
		cout << " [11] - ���������� ����������" << endl;
		cout << " [12] - ����������� ����������" << endl;
		cout << " [0] - ���������� ��������" << endl << endl;
		cout << "������ ��������: "; cin >> menuItem;
		cout << endl << endl << endl;
		switch (menuItem)
		{
		case 1:
			Create(p, N);
			break;
		case 2:
			Print(p, N);
			break;
		case 3:
			Sortavg(p, N);
			break;
		case 4:
			Sortprizv(p, N);
			break;
		case 5:
			Sortbal1(p, N);
			break;
		case 6:
			Sortbal2(p, N);
			break;
		case 7:
			Sortbal3(p, N);
			break;
		case 8:
			cin.get(); // ������� ����� ��������� � �� ����������� �������
			cin.sync(); // "����� �����", �� �� ����� ������ ��������� ������� �����

			cout << "������ ��'� �����: "; cin.getline(filename, 99);
			SaveToFile(p, N, filename);
			break;
		case 9:
			cin.get(); // ������� ����� ��������� � �� ����������� �������
			cin.sync(); // "����� �����", �� �� ����� ������ ��������� ������� �����

			cout << "������ ��'� �����: "; cin.getline(filename, 99);
			LoadFromFile(p, N, filename);
			break;
		case 10:
			cout << "����� ����� � ������ ��������, ���� ����� ��������: "; cin >> index;
			Remove(p, N, index);
			break;
		case 11:
			Add(p, N);
			break;
		case 12:
			cout << "����� ����� �������� � ������, ���������� ��� ����� ����� ������: "; cin >> index;
			cout << "�� ����� ������?" << endl;
			cout << "[1] - �������" << endl;
			cout << "[2] - 1 ���. ���" << endl;
			cout << "[3] - 2 ���. ���" << endl;
			cout << "[4] - 3 ���. ���" << endl;
			cout << "������ ��: "; cin >> option;
			cout << endl;
			Change(p, N, index, option);
			break;
		case 0:
			break;
		default:
			cout << "�� ����� ��������� ��������! "
				"��� ������ ����� - ����� ��������� ������ ����" << endl;
		}
	} while (menuItem != 0);
	return 0;
}
void Create(Student* p, const int N)
{
	for (int i = 0; i < N; i++)
	{
		int n = 0;
		cout << "������� � " << i + 1 << ":" << endl;
		cin.get(); // ������� ����� ��������� � �� ����������� �������
		cin.sync(); // "����� �����", �� �� ����� ������ ��������� ������� �����

		cout << " �������: "; getline(cin, p[i].prizv);
		cout << " ��� � 1 ��������: "; cin >> p[i].bal1;
		cout << " ��� � 2 ��������: "; cin >> p[i].bal2;
		cout << " ��� � 3 ��������: "; cin >> p[i].bal3;
		cout << endl;
	}
}

void Print(Student * p, const int N)
{
		cout << "==============================================================="
			<< endl;
		cout << "| � |     �������     | 1 ���. ��� | 2 ���. ��� | 3 ���. ��� |"
			<< endl;
		cout << "---------------------------------------------------------------"
			<< endl;
		for (int i = 0; i < N; i++)
		{
			cout << "| " << setw(1) << right << i + 1 << " ";
			cout << "| " << setw(17) << left << p[i].prizv
				<< "| " << setw(10) << right << p[i].bal1 << " "
				<< "| " << setw(10) << right << p[i].bal2 << " "
				<< "| " << setw(10) << right << p[i].bal3 << " |" << endl;
		}
		cout << "==============================================================="
			<< endl;
		cout << endl;
}
void Sortprizv(Student* p, const int N)
{
	Student tmp;
	for (int i0 = 0; i0 < N - 1; i0++) // ����� "���������"
		for (int i1 = 0; i1 < N - i0 - 1; i1++)
			if ((p[i1].prizv > p[i1 + 1].prizv))
			{
				tmp = p[i1];
				p[i1] = p[i1 + 1];
				p[i1 + 1] = tmp;
			}
}

void Sortavg(Student* p, const int N)
{
	Student tmp;
	double avg1, avg2;
	for (int i0 = 0; i0 < N - 1; i0++) // ����� "���������"
		for (int i1 = 0; i1 < N - i0 - 1; i1++)
		{
			avg1 = (p[i1].bal1 + p[i1].bal2 + p[i1].bal3) / 3.0;
			avg2 = (p[i1 + 1].bal1 + p[i1 + 1].bal2 + p[i1 + 1].bal3) / 3.0;;
			if (avg1 < avg2)
			{
				tmp = p[i1];
				p[i1] = p[i1 + 1];
				p[i1 + 1] = tmp;
			}
		}
}

void Sortbal1(Student* p, const int N)
{
	Student tmp;
	for (int i0 = 0; i0 < N - 1; i0++) // ����� "���������"
		for (int i1 = 0; i1 < N - i0 - 1; i1++)
			if ((p[i1].bal1 < p[i1 + 1].bal1))
			{
				tmp = p[i1];
				p[i1] = p[i1 + 1];
				p[i1 + 1] = tmp;
			}
}
void Sortbal2(Student* p, const int N)
{
	Student tmp;
	for (int i0 = 0; i0 < N - 1; i0++) // ����� "���������"
		for (int i1 = 0; i1 < N - i0 - 1; i1++)
			if ((p[i1].bal2 < p[i1 + 1].bal2))
			{
				tmp = p[i1];
				p[i1] = p[i1 + 1];
				p[i1 + 1] = tmp;
			}
}
void Sortbal3(Student* p, const int N)
{
	Student tmp;
	for (int i0 = 0; i0 < N - 1; i0++) // ����� "���������"
		for (int i1 = 0; i1 < N - i0 - 1; i1++)
			if ((p[i1].bal3 < p[i1 + 1].bal3))
			{
				tmp = p[i1];
				p[i1] = p[i1 + 1];
				p[i1 + 1] = tmp;
			}
}
void SaveToFile(Student* p, const int N, const char* filename)
{
	ofstream fout(filename, ios::binary); // ������� ������� ���� ������
	fout.write((char*)&N, sizeof(N)); // �������� ������� ��������
	for (int i = 0; i < N; i++)
		fout.write((char*)&p[i], sizeof(Student)); // �������� �������� ������
	fout.close(); // ������� ����
}

void LoadFromFile(Student*& p, int& N, const char* filename)
{
	delete[] p; // ������� �������� ���
	ifstream fin(filename, ios::binary); // ������� ������� ���� ����������
	fin.read((char*)&N, sizeof(N)); // ��������� ������� ��������
	p = new Student[N]; // �������� ��������� �����
	for (int i = 0; i < N; i++)
		fin.read((char*)&p[i], sizeof(Student)); // ��������� �������� ������
	fin.close(); // ������� ����
}

void Remove(Student*& p, int& size, int index)
{
	index -= 1;
	int K = 0;
	for (int i = 0; i < size; i++)
		if (i != index)
			K++;
	Student* tmp = new Student[K];
	int j = 0;
	for (int i = 0; i < size; i++)
		if (i != index)
			tmp[j++] = p[i];
	delete[] p;
	p = tmp;
	size = K;
}

void Add(Student*& p, int& size)
{
	string prizv;
	double bal1, bal2, bal3;
	size += 1;
	Student* tmp = new Student[size];
	for (int i = 0; i < size - 1; i++)
	{
		tmp[i].prizv = p[i].prizv;
		tmp[i].bal1 = p[i].bal1;
		tmp[i].bal2 = p[i].bal2;
		tmp[i].bal3 = p[i].bal3;
	}
	cin.get();
	cin.sync();
	cout << "�������: "; getline(cin, prizv);
	cout << "1 ���. ��� :"; cin >> bal1;
	cout << "2 ���. ��� :"; cin >> bal2;
	cout << "3 ���. ��� :"; cin >> bal3;
	tmp[size - 1].prizv = prizv;
	tmp[size - 1].bal1 = bal1;
	tmp[size - 1].bal2 = bal2;
	tmp[size - 1].bal3 = bal3;
	delete[] p;
	p = tmp;
}

void Change(Student* p, const int size, int index, int option)
{
	index -= 1;
	string prizv;
	double bal1, bal2, bal3;
	cin.get();
	cin.sync();
	switch (option)
	{
	case 1:
		cout << "�������: "; getline(cin, prizv);
		p[index].prizv = prizv;
		break;

	case 2: //type 
		cout << "1 ���. ��� : ";  cin >> bal1;
		p[index].bal1 = bal1;
		break;

	case 3: //time 
		cout << "2 ���. ���: "; cin >> bal2;
		p[index].bal2 = bal2;
		break;

	case 4: //time 
		cout << "3 ���. ���: "; cin >> bal3;
		p[index].bal3 = bal3;
		break;
	default:
		cout << "�� ����� ��������� ��������! "
			"��� ������ ����� - ����� ��������� ������ ����" << endl;
	}
}
