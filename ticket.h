#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include "fio.h"
#include <iostream>
#include "stdlib.h"
using namespace std;
class ticket
{
private:
	fio passanger;
	string destination;
	double price_of_ticket;
public:
	ticket() {
		destination = "Moscow";
		price_of_ticket = 0.0;
	};
	ticket(fio _pas, const string _des, const double _price )
	{
		passanger=_pas;
		destination = _des;
		price_of_ticket = _price;
	}
	ticket(const ticket& _tic)
	{
		passanger = _tic.passanger;
		destination = _tic.destination;
		price_of_ticket = _tic.price_of_ticket;
	}
	~ticket(){
		//cout << "+++" << endl;
	}
	ticket& operator =(const ticket& _tic)
	{
		if (this == &_tic) {
			return *this;
		}
		passanger = _tic.passanger;
		passanger = _tic.passanger;
		destination = _tic.destination;
		price_of_ticket = _tic.price_of_ticket;
		return *this;
	}
	friend bool operator ==(ticket& _tic1, fio& _fio)
	{
		return (_tic1.get_fio_name() == _fio.get_fio_name() && _tic1.get_fio_secondname() == _fio.get_fio_secondname() && _tic1.get_fio_surname() == _fio.get_fio_surname());

	}
	string get_fio_surname()
	{
		return passanger.surname;
	}

	string get_fio_name()
	{
		return  passanger.name;
	}

	string get_fio_secondname()
	{
		return  passanger.secondname;
	}
	string get_destination() const
	{
		return destination;
	}
	double get_price()
	{
		return price_of_ticket;
	}
	void set_price(const double value)
	{
		price_of_ticket = value;
	}
	void set_fio_surname(const string _sur)
	{
		passanger.surname = _sur;
	}

	void set_fio_name(const string _name)
	{
		passanger.name = _name;
	}

	void set_fio_secondname(const string _sname)
	{
		passanger.secondname = _sname;
	}
	double  defense(char buff[100])
	{
		double n = -1;
		unsigned int k = 0;
		int flg = 0;
		int count = 0;
		try {
			while (k < strlen(buff))
			{

				if (isdigit(buff[k]) != NULL)
				{
					count++;
				}
				if (buff[k] == '.' && flg == 0)
				{
					count++;
					flg = 1;
				}
				k++;
			}
			if (count == strlen(buff))
			{
				n = atof(buff);
			}
			else {
				throw "Price of ticet should be a double format";
			}
		}
		catch (const char* exception)
		{
			cerr << "Error: " << exception << endl;
		}
		return n;
	}

	bool fiodefense(char buff[100])
	{
		unsigned int k = 0;
		bool flg = true;
		try {
			while (k < strlen(buff))
			{
				if ((int)(buff[k]) < 64 || ((int)(buff[k]) > 90 && (int)(buff[k]) < 97) || (int)(buff[k]) > 122)
				{
					flg = false;
				}
				k++;
			}
			if (flg == false)
				throw "FIO cannot contain characters that are not letters of the Latin alphabet";
			else return true;
		}
		catch (const char* exception) {
			return false;
			cerr << "Error: " << exception << endl;
		}
		return false;
	}
	friend istream& operator >> (istream& in, ticket& _tic)
	{

		char buff[100];
		char buff1[100];

		int flg = 0;
		while (flg != 1)
		{
			cout << "Surname of passenger:    ";
			in >> buff;
			strcpy(buff1, buff);
			if (_tic.fiodefense(buff1) == true)
			{
				flg = 1;
				_tic.set_fio_surname(buff);
			}
		}

		flg = 0;
		while (flg != 1)
		{
			cout << "Name of passenger:       ";
			in >> buff;
			strcpy(buff1, buff);
			if (_tic.fiodefense(buff1) == true)
			{
				flg = 1;
				_tic.set_fio_name(buff);
			}
		}

		flg = 0;
		while (flg != 1)
		{
			cout << "Secondname of passenger: ";
			in >> buff;
			strcpy(buff1, buff);
			if (_tic.fiodefense(buff) == true)
			{
				flg = 1;
				_tic.set_fio_secondname(buff);
			}
		}
		cout << "Point of destination:    ";
		in >> _tic.destination;
		flg = 0;
		while (flg != 1)
		{
			cout << "Price of ticet:          ";
			in >> buff;
			if (_tic.defense(buff) != -1)
			{
				flg = 1;
				_tic.set_price(_tic.defense(buff));
			}
		}


		return in;

	}
	friend ostream& operator << (ostream& out, ticket& _tic)
	{
		out << "-----------------------------------------------------" << endl;
		out << "Surname of passangare......." << _tic.get_fio_surname() << endl;
		out << "Name of passanger..........." << _tic.get_fio_name() << endl;
		out << "Second name of passanger...." << _tic.get_fio_secondname() << endl;
		out << "Destination................." << _tic.get_destination() << endl;
		out << "Price of ticet.............." << _tic.get_price() << endl;
		out << "-----------------------------------------------------" << endl;
		return out;
	}
};

