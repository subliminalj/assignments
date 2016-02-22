#ifndef _ASSIGNMENTS_H_
#define _ASSIGNMENTS_H_

#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <list>
#include <algorithm>
#include <cstdlib>
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
		else
			assStatus = late;
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

	friend ostream& operator<<(ostream& os, assignments& ass)
	{
		os << ass.getDate().toString() << ", " << ass.getDesc() << ", " << ass.getAssDate().toString() << ", " << ass.statusAsString();
		return os;
	}

	bool operator <(assignments& compareAss)
	{
		if (dueDate != compareAss.getDate())
			return dueDate < compareAss.getDate();
		else if (description != compareAss.getDesc())
			return description < compareAss.getDesc();
		else
			return assignedDate < compareAss.getAssDate();
	}

	bool findAss(list<assignments> fAss)
	{
		bool reenter = 0;
		list<assignments>::iterator additer;

		for (additer = fAss.begin(); additer != fAss.end(); additer++)
		{
			if (additer->getDate() == dueDate &&
				additer->getDesc() == description &&
				additer->getAssDate() == assignedDate &&
				additer->getStatus() == assStatus)
			{
				cout << "This entry already exists!" << endl;
				reenter = 1;
				system("PAUSE");
				return 1;
			}
		}
		if (reenter == 0)
			return 0;
	}

	Date inputDate()
	{
		Date iDate;
		try
		{
			cin >> iDate;
		}
		catch (exception&)
		{
			cout << "Invalid date! Please reenter (year/mon/day or mon/day/year): ";
			inputDate();
		}
		return iDate;
	}

	char inputStatus()
	{
		char iStatus;
		try
		{
			cin >> iStatus;

			if (iStatus != 'A' && iStatus != 'a' &&
				iStatus != 'C' && iStatus != 'c' &&
				iStatus != 'L' && iStatus != 'l')
				throw std::exception("The status can only be A, C, or L!");
		}
		catch (exception&)
		{
			cout << "The status can only be A, C, or L!"
				<< "\nPlease reenter status: ";
			inputStatus();
		}
		return iStatus;
	}
	/*void orderedInsert(list<assignments>& type, assignments insAss)
	{
	list<assignments>::iterator orderiter = type.begin();

	while (orderiter != type.end() && *orderiter < insAss)
	++orderiter;
	type.insert(orderiter, insAss);
	}*/
};

#endif

