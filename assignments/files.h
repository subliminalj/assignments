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

void infile(list<assignments> due, list<assignments> completed)
{

	ifstream filein;
	filein.open("assignments.dat", ios::in);
	if (!filein)
	{
		cout << "Error opening db for input";
		exit(1);
	}

	cout << "Reading from file..." << endl;

	while (!filein.eof())
	{
		Date duedate, assigned;
		
		char status;
		assignments temp;
		string input;
		
		while (getline(filein, input))//read the next line in the file, if no more lines are availble, the while loop will exit.
		{
			String_Tokenizer st(input, ",");//a tokenizer for parsing a line of tokens (the tokens are seperated by commas)
			Date duedate = trim(st.next_token());//the first token in line is the due date
			string desc = trim(st.next_token());//the next token is the description
			Date assigned = trim(st.next_token());//the next token is the assigned date
			char status = trim(st.next_token());// the next token is the status
			temp.setDate(duedate);
			temp.setDesc(desc);
			temp.setAssDate(assigned);
			temp.setStatus(status);
			if (temp.getStatus == 'a' || temp.getStatus == 'A')//if the status is assigned push on the due list
				due.push_back(temp);
			else
				completed.push_back(temp);// otherwise push on the completed list
		}
	}
	filein.close();

}