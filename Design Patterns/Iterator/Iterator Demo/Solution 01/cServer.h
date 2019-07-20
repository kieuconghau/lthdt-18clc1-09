#pragma once

#include "cClient.h"

class cServer
{
public:
	cServer();
	~cServer();

	void add_a_client(cPerson* person);
	//void remove_a_client(cClient* client);

	void show_all_infos();
	
private:
	cClient* Head;
};
