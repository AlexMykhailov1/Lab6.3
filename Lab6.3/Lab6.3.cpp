// Lab6.3.cpp
// �������� ���������
// ����������� ����������� ������ �� ��������� ��������� ������� �� �������
// ������ 24*

#include <iostream>
#include <Windows.h>
#include <cmath>
#include <time.h>

using namespace std;

void CreateIter(int mas[], const int n, const int Min, const int Max) {
	for (int i = 0; i < n; i++) {
		mas[i] = Min + rand() % (Max - Min + 1);
	}
}

void PrintIter(int mas[], const int n) {
	for (int i = 0; i < n; i++) {
		cout << mas[i] << "  ";
	}
	cout << endl << endl;
}

void MaxEvenIter(int mas[], const int n) {
	int Max = 0;
	int indexMax = -1;
	for (int i = 0; i < n; i++) {
		if (mas[i] % 2 == 0) {
			Max = mas[i];
			indexMax = i;
			break;
		}
	}
	for (int i = indexMax + 1; i < n; i++) {
		if (mas[i] > Max && mas[i] % 2 == 0)
			Max = mas[i];
	}
	cout << "��������� � ������ �������� ������: " << Max << endl << endl;
}

void CreateRekurs(int mas[], const int n, const int Min, const int Max, int i)
{
	mas[i] = Min + rand() % (Max - Min + 1);
	if (i < n - 1)
		CreateRekurs(mas, n, Min, Max, i + 1);
}

void PrintRekurs(int mas[], const int n, int i)
{
	cout << mas[i] << "  ";
	if (i < n - 1)
		PrintRekurs(mas, n, i + 1);
	else
		cout << endl << endl;
}

int MaxNum(int mas[], const int n, int& Max, int i)
{
	if (mas[i] % 2 == 0){
		Max = mas[i];
		return i;
	}
	if (i < n - 1)
		return MaxNum(mas, n, Max, i + 1);
}

int MaxEvenRekurs(int mas[], const int n, int Max, int i) {
	if (mas[i] > Max && mas[i] % 2 == 0)
		Max = mas[i];
	if (i < n - 1)
		return MaxEvenRekurs(mas, n, Max, i + 1);
	else
		return Max;
}

int main()
{
	srand((unsigned)time(NULL));
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int Min, Max;
	int n;
	cout << "������ �������� ������� �������� � �����: "; cin >> Min;
	cout << "������ ����������� ������� �������� � �����: "; cin >> Max;
	cout << "������ ������� �������� ������: "; cin >> n;
	cout << endl;


	int* a = new int[n];

	// �����������
	cout << "����������� �����:" << endl;
	cout << "�����: ";

	CreateIter(a, n, Min, Max);
	PrintIter(a, n);
	MaxEvenIter(a, n);

	// �����������
	cout << "����������� �����:" << endl;
	cout << "�����: ";

	int maxnum;
	int indexmaxnum = MaxNum(a, n, maxnum, 0);

	CreateRekurs(a, n, Min, Max, 0);
	PrintRekurs(a, n, 0);
	cout << "��������� � ������ �������� ������: " << MaxEvenRekurs(a, n, maxnum, indexmaxnum + 1) << endl;


	cin.get();
	delete[]a;
	return 0;
}