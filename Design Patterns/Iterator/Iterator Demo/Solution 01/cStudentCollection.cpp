#include "cStudentCollection.h"

cStudentCollection::cStudentCollection()
{
	this->Students = nullptr;
	this->N = 0;
}

cStudentCollection::~cStudentCollection()
{
	delete[] this->Students;
}

void cStudentCollection::input_all_infos()
{
	cout << "Input the quantity of Students: ";
	cin >> this->N;

	this->Students = new cStudent[this->N];
	for (int i = 0; i < this->N; i++)
	{
		cout << "#" << i + 1 << endl;
		this->Students[i].input_info();
	}
}

void cStudentCollection::show_all_infos()
{
	cout << "~ Student Collection ~" << endl;
	for (int i = 0; i < this->N; i++)
	{
		cout << "#" << i + 1 << endl;
		this->Students[i].show_info();
	}
}
