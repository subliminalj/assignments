#include "assignments.h"

void outfile(list<assignments> due, list<assignments> completed)
{
	list<assignments>::iterator dueit;
	list<assignments>::iterator compit;

	ofstream fileout;
	fileout.open("assignments.dat", ios::out);

	if (!fileout)
	{
		cout << "Error opening db for output";
		exit(1);
	}

	cout << "Writing to file..." << endl;
	
	for (dueit = due.begin(); dueit != due.end(); dueit++)
	{
		fileout << dueit->getDate << "," << dueit->getDesc << "," << dueit->getAssDate << "," << dueit->getStatus << endl;
	}




	fileout.close();

}

void infile()
{

	ifstream filein;
	filein.open("assignments.dat", ios::in);
	if (!filein)
	{
		cout << "Error opening db for input";
		exit(1);
	}

	cout << "Reading from file..." << endl;

	//input here




	filein.close();

}