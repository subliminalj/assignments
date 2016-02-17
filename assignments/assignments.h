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
	string assStatus;

public:
	assignments();
	assignments(Date, string, Date, string);
	~assignments();
	
	Date getDate() { return dueDate; }
	string getDesc() { return description; }
	Date getAssDate(){ return assignedDate; }
	string getStatus() { return assStatus; }
	//friend ostream& operator<<(ostream& os, const assignments& ass);
};

//assignments::ostream& operator<<(ostream& os, const assignments& ass)
//{
//	output << getDate() << wset(20) << getDesc() << wset(10) << getAssDate() << wset(10) << getStatus();
//	return output;
//}

assignments::assignments(Date due, string desc, Date assigned, string status)
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