#include "stdafx.h"
#include <iostream>
#include <vector>

using namespace std;

int n;
vector <int> newArray;
vector <int> deleted;

void fill(int n, vector <int> &array)
{
	for (int i = 0; i < n; i++) {
		array.push_back(rand() % 10000 + 1);
	}
}

void display(vector <int> &array)
{
	for (int i = 0; i < array.size(); i++) {
		cout << array[i] << " ";
	}
	cout << endl << endl;
}

void deleteElements(vector <int> &array)
{
	int first, second;
	for (int i = 0; i < array.size(); i++) {
		first = array[i] % 10;
		second = array[i];
		while (second/10 != 0) {
			second /= 10;
		}
		if (first == second) {
			deleted.push_back(array[i]);
			array.erase(array.begin() + i);
		}
	} 
}

int main()
{
	setlocale(LC_ALL, "rus");
	cout << "������������ ������ 2, ������� 3, ������� �������, ����-02-17" << endl;
	cout << "������� : '�������� ��������� ������� � ����������� �������� � �������� �������'" << endl << endl;
	cout << "������� ���������� ��������� �������" << endl;
	cin >> n;
	while (n > 100 || n < 1) {
		cout << "������" << endl;
		cout << "������� ���������� ��������� �������" << endl;
		cin >> n;
	}
	fill(n, newArray);
	cout << "����������� ������" << endl;
	display(newArray);
	deleteElements(newArray);
	cout << "����� ������" << endl;
	display(newArray);
	cout << "�������" << endl;
	display(deleted);
	system("pause");
    return 0;
}

