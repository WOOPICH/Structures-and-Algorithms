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
	cout << "Лабораторная работа 5, Вариант 3, Данилов Дмитрий, ИКБО-02-17" << endl;
	cout << "Задание:'Составить частотный словарь текста: для каждого из слов текста указать количество его вхождений в текст'" << endl << endl;
	fill(newMap);
	display(newMap);
	system("pause");
	return 0;*/

	map<char[], int> words;
	char separators[] = " ,.!?:;-"; //массив разделителей
	char text[81]; //исходный текст
	char *word; //указатель на очередное слово
	cout << "s: ";
	cin.getline(text, 81); //ввод текста с пробелами
	word = strtok(text, separators); // выделение первой лексемы
	while (word != 0)
	{
		words[word]++;
		word = strtok(0, separators);
	}
	system("pause");
}
