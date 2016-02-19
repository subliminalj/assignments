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
	enum Status { assigned, completed, late };
private:
	Date dueDate;
	string description;
	Date assignedDate;
	Status assStatus;
	string statString;

public:
	assignments() {};
	assignments(Date due, string desc, Date assigned, Status status)
	{
		dueDate = due;
		description = desc;
		assignedDate = assigned;
		assStatus = status;
	}

	Date getDate() { return dueDate; }
	string getDesc() { return description; }
	Date getAssDate() { return assignedDate; }
	Status getStatus() { return assStatus; }

	void setDate(Date due) { dueDate = due; }
	void setDesc(string desc) { description = desc; }
	void setAssDate(Date assigned){ assignedDate = assigned; }
	void setStatus(char status) 
	{
		if (status == 'A' || status == 'a')
			assStatus = assigned;
		else if (status == 'C' || status == 'c')
			assStatus = completed;
		else if (status == 'L' || status == 'l')
			assStatus = late;
		else
			throw std::exception("Incorrect entry!");
		cout << assStatus;
	}

	string statusAsString()
	{
		switch (assStatus)
		{
		case 0:
			statString = "assigned";
			break;
		case 1:
			statString = "completed";
			break;
		case 2:
			statString = "late";
			break;
		}

		return statString;
	}

	friend ostream& operator<<(ostream& os, assignments& ass){
		os << ass.getDate().toString() << ", " << ass.getDesc() << ", " << ass.getAssDate().toString() << ", " << ass.statusAsString();
		return os;
	}

};


#endif

