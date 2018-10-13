#include "stdafx.h"
#include <iostream>
#include <string>
#include <map>
#include <Windows.h>

using namespace std;

void fillMap(map<string, int> &newMap, string text)
{
	string word = "";
	for (int i = 0; i < text.size() + 1; ++i)
	{
		if (text[i] != ' ' && text[i] != '\0' && !isdigit(text[i]) && !ispunct(text[i]))
		{
			word += text[i];
		}
		else
		{
			if (word != "")
			{
				newMap[word]++;
				word = "";
			}
		}
	}
	if (newMap.empty())
	{
		cout << "������� ������" << endl;
	}
}

void display(map<string, int> newMap)
{
	cout << "���������� �������" << endl << endl;
	for (auto i : newMap) {
		cout << i.first << "\t" << i.second << endl;
	}
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	cout << "������������ ������ 5, ������� 3, ������� �������, ����-02-17" << endl;
	cout << "������� : '����������� ���������� �������'" << endl << endl;
	string text;
	map<string, int> newMap;
	cout << "Enter text" << endl;
	getline(cin, text);
	fillMap(newMap, text);
	display(newMap);
	system("pause");
	return 0;
}

