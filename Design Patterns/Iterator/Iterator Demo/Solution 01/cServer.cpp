#include "cServer.h"

cServer::cServer()
{
	this->Head = nullptr;
}

cServer::~cServer()
{
	cClient* temp = this->Head;

	while (this->Head != nullptr)
	{
		temp = this->Head;
		this->Head = this->Head->Next;
		delete temp;
	}
}

void cServer::add_a_client(cPerson* person)
{
	cClient* client;
	client->create_client(person);

	client->Next = this->Head;
	this->Head = client;
}

void cServer::show_all_infos()
{
	for (cClient* cur = this->Head, int i = 0; cur != nullptr; cur = cur->Next, ++i)
	{
		cout << "#" << i + 1 << endl;
		cur->show_info();
	}
}
