#include "assignments.h"

void outfile()
{

	ofstream fileout;
	fileout.open("assignments.dat", ios::out);

	if (!fileout)
	{
		cout << "Error opening db for output";
		exit(1);
	}

	cout << "Writing to file..." << endl;
	// output here



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