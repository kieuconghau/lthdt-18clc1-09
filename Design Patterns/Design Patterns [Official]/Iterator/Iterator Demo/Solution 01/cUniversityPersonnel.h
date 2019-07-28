#pragma once

class cUniversityPersonnel
{
public:
	cUniversityPersonnel() = default;
	virtual ~cUniversityPersonnel() {};
	virtual void input_info() = 0;
	virtual void show_info() = 0;
};