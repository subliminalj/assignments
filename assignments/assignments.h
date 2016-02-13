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
public:
	assignments();
	assignments(Date due, string desc, Date assigned, enum status);
	~assignments();

private:
	Date dueDate;
	string description;
	Date assignedDate;
	enum status;
};

assignments::assignments()
{
}

assignments::~assignments()
{
}

#endif