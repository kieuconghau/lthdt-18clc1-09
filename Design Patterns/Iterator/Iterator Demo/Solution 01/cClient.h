#pragma once

#include "cPerson.h"

class cClient
{
public:
	cClient();
	~cClient();

	void show_info();

	cClient* create_client(cPerson* person);

public:
	cClient* Next;
private:
	cPerson* Person;
};

