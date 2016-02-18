#ifndef _ASSIGNMENTS_H_
#define _ASSIGNMENTS_H_

#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <list>
#include "Date.h"
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
	assignments(Date due, string desc, Date assigned, string status)
	{
		dueDate = due;
		description = desc;
		assignedDate = assigned;
		assStatus = status;

	}



	Date getDate() { return dueDate; }
	string getDesc() { return description; }
	Date getAssDate(){ return assignedDate; }
	string getStatus() { return assStatus; }

	void setDate(Date due) { dueDate = due; }
	void setDesc(string desc) { description = desc; }
	void setAssDate(Date assigned){ assignedDate = assigned; }
	void setStatus(string status) { assStatus = status; }
	friend ostream& operator<<(ostream& os, assignments& ass){
		os << ass.getDate().toString() << ", " << ass.getDesc() << ", " << ass.getAssDate().toString() << ", " << ass.getStatus();
		return os;
	}

};


#endif

