#include "stdafx.h"
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

char text[] = "Lol, Kek.Puk; Myau!";
char separators[] = ";,.! ";

void fill(map <string, int> &newMap)
{
	char *word = strtok(text, separators);
	cout << word;
	while (word != 0) {
		newMap[word]++;
		word = strtok(0, separators);
		//	cout << word << endl;
	}
}

void display(map <string, int> &newMap)
{
	for (auto i = newMap.begin(); i != newMap.end(); i++) {
		cout << i->first << " " << i->second << endl;
	}
}

int main()
{
	/*map <char[], int > newMap;
	setlocale(LC_ALL, "rus");
	cout << "������������ ������ 5, ������� 3, ������� �������, ����-02-17" << endl;
	cout << "�������:'��������� ��������� ������� ������: ��� ������� �� ���� ������ ������� ���������� ��� ��������� � �����'" << endl << endl;
	fill(newMap);
	display(newMap);
	system("pause");
	return 0;*/

	map<char[], int> words;
	char separators[] = " ,.!?:;-"; //������ ������������
	char text[81]; //�������� �����
	char *word; //��������� �� ��������� �����
	cout << "s: ";
	cin.getline(text, 81); //���� ������ � ���������
	word = strtok(text, separators); // ��������� ������ �������
	while (word != 0)
	{
		words[word]++;
		word = strtok(0, separators);
	}
	system("pause");
}
