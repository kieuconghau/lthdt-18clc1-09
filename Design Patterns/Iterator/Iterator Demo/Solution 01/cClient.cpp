#include "cClient.h"

cClient::cClient()
{
	this->Person = nullptr;
	this->Next = nullptr;
}

cClient::~cClient()
{
	delete this->Person;
	delete this->Next;
}

void cClient::show_info()
{
	cout << "  - Type: Client" << endl;
	this->Person->show_info();
}

cClient* cClient::create_client(cPerson* person)
{
	cClient* res = new cClient;

	*res->Person = *person;
	res->Next = nullptr;

	return res;
}
