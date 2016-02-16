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
	enum status;

public:
	assignments();
	assignments(Date due, string desc, Date assigned, enum assStatus);
	~assignments();
	
	Date getDate() { return dueDate; }
	string getDesc() { return description; }
	Date getAssDate(){ return assignedDate; }
	enum getStatus() { return status; }
	

};

assignments::assignments(Date due, string desc, Date assigned, enum assStatus)
{
	dueDate = due;
	description = desc;
	assignedDate = assigned;
	status = assStatus;

}

assignments::~assignments()
{
}

#endif