#pragma once
#pragma once
#include <string>
#include <iostream>
using namespace std;
class fio
{
public:
	string surname;
	string name;
	string secondname;
	fio();
	fio(const string, const string, const string);
	fio& operator=(const fio&);
	~fio();
	string get_fio_surname();
	string get_fio_name();
    string get_fio_secondname();
	
};

