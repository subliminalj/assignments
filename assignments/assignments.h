//assignments.h sets up the assignments class, which stores and manages assignment data input from interface.h and files.h
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
private:
	enum Status { assigned, completed, late };
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
	void setAssDate(Date assigned) { assignedDate = assigned; }
	void setStatus(Status status) { assStatus = status;	}
	//connects the enum values of each status to a string value for output
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
	//allows assignment objects to use the << operator in the ostream
	friend ostream& operator<<(ostream& os, assignments& ass)
	{
		os << ass.getDate().toString() << ", " << ass.getDesc() << ", " << ass.getAssDate().toString() << ", " << ass.statusAsString();
		return os;
	}
	//allows assignment objects to use the < operator for comparisons by comparing values currently assigned to 
	//assignment class variables to other entries in the list
	bool operator <(assignments& compareAss)
	{
		if (dueDate != compareAss.getDate())
			return compareAss.getDate() < dueDate;
		else if (description != compareAss.getDesc())
			return compareAss.getDesc() < description;
		else
			return compareAss.getAssDate() < assignedDate;
	}
	//iterates through the due or completed lists to confirm if an attempted entry already exists
	bool findAss(list<assignments> fAss)
	{
		bool reenter = 0;
		list<assignments>::iterator additer;

		for (additer = fAss.begin(); additer != fAss.end(); additer++)
		{
			if (additer->getDate() == dueDate &&
				additer->getDesc() == description &&
				additer->getAssDate() == assignedDate)
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
	//catches exceptions if a date is entered incorrectly and allows user to reenter the date until the format is correct
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
	//throws an exeption if the user doesn't input y or n as a status. If not, the user is prompted to reenter the status
	//until it is a y or n value.
	char inputStatus()
	{
		char iStatus;
		try
		{
			cin >> iStatus;

			if (iStatus != 'N' && iStatus != 'n' &&
				iStatus != 'Y' && iStatus != 'y')
				throw std::exception("Invalid entry!");
		}
		catch (exception&)
		{
			cout << "Please indicate whether or not the assignment is complete with Y or N!"
				<< "\nHas this assignment been completed?  ";
			inputStatus();
		}
		return iStatus;
	}
	//prompts user to state whether or not the assignment is complete. If it is, evaluateCompStatus is run based on
	//the current dueDate value. If it isn't, the assigned value is returned.
	Status evaluateStatus()
	{
		char compStatus;
		cout << "Is this assignment complete (enter Y or N)? ";
		compStatus = inputStatus();	//confirms the status is appropritaely entered
		if (compStatus == 'Y' || compStatus == 'y')
			evaluateCompStatus(dueDate);
		else
			return assigned;
	}
	//This evaluateStatus is used for reading files, taking the first letter of the file's status string, 
	//which will be 'a', 'c', or 'l'
	Status evaluateStatus(char stat)
	{
		if (stat == 'a')
			return assigned;
		else if (stat == 'c')
			return completed;
		else
			return late;
	}
	//prompts user to input the completion date. If it was completed after the due date, returns the late value. 
	//Otherwise, completed is returned
	Status evaluateCompStatus (Date cDueDate)
	{
		Date compDate;
		cout << "Please enter the completion date: ";
		compDate = inputDate();
		if (compDate > cDueDate)
		{
			cout << "This assignment is late. Sorry :(";
			return late;
		}
		else
		{
			cout << "This assignment was completed on time. Congrats!";
			return completed;
		}
	}
};

#endif

