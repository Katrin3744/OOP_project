#include "fio.h"
#include <string>
#include <iostream>
using namespace std;
fio::fio()
{
	surname = "Ivanov";
	name = "Ivan";
	secondname = "Ivanovich";
}
fio::fio(const string _surn, const string _name, const string _secn)
{
	surname = _surn;
	name = _name;
	secondname = _secn;
}
fio& fio:: operator=(const fio& _fio)
{
	if (this == &_fio)
		return *this;
	surname = _fio.surname;
	name = _fio.name;
	secondname = _fio.secondname;
	return *this;

}
string fio::get_fio_surname()
{
	return surname;
}
string fio::get_fio_name()
{
	return name;
}
string fio::get_fio_secondname()
{
	return secondname;
}

fio::~fio() { //cout << "f+++" << endl; 
}
