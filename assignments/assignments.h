#ifndef _ASSIGNMENTS_H_
#define _ASSIGNMENTS_H_

#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <list>
#include "Date.h"
#include "interface.h"
#include "String_Tokenizer.h"

using namespace std;

class assignments
{
private:
	Date dueDate;
	string description;
	Date assignedDate;
	enum assStatus;

public:
	assignments();
	assignments(Date, string, Date, enum);
	~assignments();
	
	Date getDate() { return dueDate; }
	string getDesc() { return description; }
	Date getAssDate(){ return assignedDate; }
	enum getStatus() { return status; }
	ostream& operator<<(ostream& os, const assignments& ass);
};

assignments::ostream& operator<<(ostream& os, const assignments& ass)
{
	cout << getDate() << wset(20) << getDesc() << wset(10) << getAssDate() << wset(10) << getStatus();
}

assignments::assignments(Date due, string desc, Date assigned, enum status)
{
	dueDate = due;
	description = desc;
	assignedDate = assigned;
	assStatus = status;

}

assignments::~assignments()
{
}

#endif