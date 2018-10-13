#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

struct Date
{
	string day;
	string month;
	string year;
};

struct PhoneBook
{
	string phoneNumber;
	string firstName;
	string secondName;
	string patronymic;
	Date birthDate;
};

void fillFromFile(vector <PhoneBook> &arr)
{
	cout << "Structs from file:" << endl << endl;
	fstream f;
	string tempString;
	PhoneBook tempStruct;
	f.open("Structs.txt");
	while(!f.eof()) {
		getline(f, tempStruct.phoneNumber);
		getline(f, tempStruct.firstName);
		getline(f, tempStruct.secondName);
		getline(f, tempStruct.patronymic);
		getline(f, tempStruct.birthDate.day);
		getline(f, tempStruct.birthDate.month);
		getline(f, tempStruct.birthDate.year);
		arr.push_back(tempStruct);
	}
}

void sort(vector <PhoneBook> &arr)
{
	for (int i = 0; i < arr.size() - 1; i++) {
		for (int k = 0; k < arr.size() - i - 1; k++) {
			if (arr[i].secondName == arr[i + 1].secondName) {
				if (arr[i].firstName == arr[i + 1].firstName) {
					if (arr[i].patronymic == arr[i + i].patronymic) {
						//lol
					}
					else {
						for (int p = 0; p < arr[i].patronymic.size() - (arr[i].patronymic.size() - arr[i + 1].patronymic.size()); p++) {
							if (arr[i].patronymic[p] < arr[i + 1].patronymic[p]) {
								swap(arr[i], arr[i + 1]);
							}
						}
					}
				}
				else {
					for (int s = 0; s < arr[i].firstName.size() - (arr[i].firstName.size() - arr[i + 1].firstName.size()); s++) {
						if (arr[i].firstName[s] < arr[i + 1].firstName[s]) {
							swap(arr[i], arr[i + 1]);
						}
					}
				}
			}
			else {
				for (int j = 0; j < arr[i].secondName.size() - (arr[i].secondName.size() - arr[i + 1].secondName.size()); j++) {
					if (arr[i].secondName[j] < arr[i + 1].secondName[j]) {
						swap(arr[i], arr[i + 1]);
					}
				}
			}
		}
	}
}

void display(vector <PhoneBook> arr)
{
	for (int i = 0; i < arr.size(); i++) {
		cout << arr[i].phoneNumber << '\t';
		cout << arr[i].secondName << '\t';
		cout << arr[i].firstName << '\t';
		cout << arr[i].patronymic << '\t';
		cout << arr[i].birthDate.day << "." << arr[i].birthDate.month << "." << arr[i].birthDate.year << endl << endl;
	}
}

void displayOne(vector <PhoneBook> arr, int index)
{
	cout << endl << "Struct was found" << endl << endl;
	cout << arr[index].phoneNumber << '\t';
	cout << arr[index].secondName << '\t';
	cout << arr[index].firstName << '\t';
	cout << arr[index].patronymic << '\t';
	cout << arr[index].birthDate.day << "." << arr[index].birthDate.month << "." << arr[index].birthDate.year << endl << endl;
}

void NOTbinarySearch(vector <PhoneBook> arr)
{
	string key;
	cout << "Enter key: ";
	cin >> key;
	int count = 0;
	for (int i = 0; i < arr.size(); i++) {
		if (arr[i].firstName == key || arr[i].secondName == key || arr[i].patronymic == key) {
			displayOne(arr, i);
			count++;
		}
	}
	if (count == 0) {
		cout << "Struct was not found" << endl;
	}
}

void createBin(vector <PhoneBook> arr)
{
	ofstream out("BinaryStructs.bin", std::ios::binary);
	if (out.is_open())
	{
		for (int i = 0; i < arr.size(); i++) {
			for (int q = 0; q < arr[i].phoneNumber.size(); q++) {
				out.write((char *)&arr[i].phoneNumber[q], sizeof(char));
			}
			for (int w = 0; w < arr[i].secondName.size(); w++) {
				out.write((char *)&arr[i].secondName[w], sizeof(char));
			}
			for (int e = 0; e < arr[i].firstName.size(); e++) {
				out.write((char *)&arr[i].firstName[e], sizeof(char));
			}
			for (int r = 0; r < arr[i].patronymic.size(); r++) {
				out.write((char *)&arr[i].patronymic[r], sizeof(char));
			}
			for (int t = 0; t < arr[i].birthDate.day.size(); t++) {
				out.write((char *)&arr[i].birthDate.day[t], sizeof(char));
			}
			for (int y = 0; y < arr[i].birthDate.month.size(); y++) {
				out.write((char *)&arr[i].birthDate.month[y], sizeof(char));
			}
			for (int u = 0; u < arr[i].birthDate.year.size(); u++) {
				out.write((char *)&arr[i].birthDate.year[u], sizeof(char));
			}
		}
		out.close();
	}
}

void readBin()
{
	cout << "Bin File Open" << endl;
	ifstream instrm("BinaryStructs.bin", std::ios::binary);
	char a;
	while (instrm.read((char *)&a, sizeof(char)))
		cout << a << ' ';
	cout << endl;
}

int main()
{
	setlocale(LC_ALL, "rus");
	cout << "Лабораторная работа 11, Вариант 3, Данилов Дмитрий, ИКБО-02-17" << endl;
	cout << "Задание : 'Работа с файлами'" << endl << endl;
	vector <PhoneBook> arr;
	fillFromFile(arr);
	sort(arr);
	display(arr);
	NOTbinarySearch(arr);
	createBin(arr);
	readBin();
	system("pause");
	return 0;
}