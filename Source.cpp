#define _CRT_SECURE_NO_WARNINGS
#include "fio.h"
//#include <vld.h>
#include "ticket.h"
#include <algorithm>
#include <iostream>
#include <vector>
#include <fstream>
#include "sortTicket.h"
using namespace std;

void add1(vector<ticket>& _tic)
{
	ticket _tictime= ticket();
	cin >> _tictime;
	_tic.push_back(_tictime);
}
void add2(vector<ticket>& _tic)
{
	ifstream file("ticket.txt");
	string str1;
	string str2;
	string str3;
	string str4;
	char buff[100];
	while (file.peek() != EOF) {
		getline(file, str1);
		getline(file, str2);
		getline(file, str3);
		getline(file, str4);
		file.getline(buff, 100);
		ticket newtic = ticket(fio(str1, str2, str3), str4, 0);
		newtic.set_price(newtic.defense(buff));
		_tic.push_back(newtic);
	}

}
void found(vector<ticket>& _tic1, vector<ticket>& _tic2)
{
	vector<ticket>::iterator iter1;
	string str1;
	string str2;
	string str3;

	cout << "Surname of passenger:    ";
	cin >> str1;
	cout << "Name of passenger:       ";
	cin >> str2;
	cout << "Secondname of passenger: ";
	cin >> str3;

	fio _fio = fio(str1, str2, str3);

	for (iter1 = _tic1.begin(); iter1 != _tic1.end(); iter1++)
	{
		if (*iter1 == _fio)
			_tic2.push_back(*iter1);
	}
}
void savebase(vector<ticket>& _tic)
{
	ofstream fp("ticket.txt");
	vector<ticket>::iterator iter1;
	for (iter1 = _tic.begin(); iter1 != _tic.end(); iter1++)
	{
		fp << (iter1)->get_fio_surname() << endl;
		fp << (iter1)->get_fio_name() << endl;
		fp << (iter1)->get_fio_secondname() << endl;
		fp << (iter1)->get_destination() << endl;
		fp << (iter1)->get_price() << endl;
	}
	fp.close();
}

void display(vector<ticket>_tic)
{
	vector<ticket>::iterator iter1;
	for (iter1 = _tic.begin(); iter1 != _tic.end() ; iter1++)
	{
		cout << *iter1;

	}

}

int main()
{
	vector<ticket> _tic;
	vector<ticket> _tic2;
	FILE* fp;
	char c;
	int i = 0;
	int count = 0;
	fp = fopen("ticket.txt", "r");
	if (fp == NULL)
		cout << "error in open" << endl;
	else
	{
		c = getc(fp);
		if (feof(fp) != NULL)
		{
			cout << "your file is empty" << endl;
			add1(_tic);
			count = 1;
		}
		fseek(fp, -1, SEEK_CUR);
		if (count != 1 && feof(fp) == NULL)
		{
			fclose(fp);
			add2(_tic);
		}
		while (i != 5)
		{
			char* l = new char[1];
			system("cls");
			cout << "Please, choose comand:" << endl;
			cout << "1) print base" << endl;
			cout << "2) add new ticet" << endl;
			cout << "3) sort ticet with point of destination" << endl;
			cout << "4) find passengers with such fio" << endl;
			cout << "5) exit" << endl;
			cin >> *l;
			if (isdigit(*l) != NULL)
				i = atof(l);
			if (i == 0 && i > 5)
				cout << "error in comand" << endl;
			else
				switch (i)
				{
				case 1:
					cout << "             Base of passangers      " << endl;
					display(_tic);
					cout << "Number of passengers..............." << _tic.size() << endl;
					cout << "-----------------------------------------------------" << endl;
					system("PAUSE");
					break;
				case 2:
					add1(_tic);
					system("PAUSE");
					break;
				case 3:
					sort(_tic.begin(), _tic.end(), [](const ticket a, const ticket b) {
						return a.get_destination() < b.get_destination();
						});
					cin.get();
					system("PAUSE");
					break;
				case 4:
					found(_tic, _tic2);
					if (_tic2.size() != 0)
					{
						cout << "             Base of passangers with such fio         " << endl;
						display(_tic2);
						cout << "Number of passengers..............." << _tic2.size() << endl;
						cout << "-----------------------------------------------------" << endl;
						_tic2.pop_back();//иначе получим историю поиска
					}
					else
						cout << "No passangers with such fio" << endl;
					cin.get();
					system("PAUSE");
					break;
				case 5:
					savebase(_tic);
					break;
				}

		}
	}


	return 0;
}