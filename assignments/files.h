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
		fileout << dueit->getDate().toString() << "," << dueit->getDesc() << "," << dueit->getAssDate().toString() << "," << dueit->statusAsString() << endl;
	}




	fileout.close();

}

void infile(list<assignments>& due, list<assignments>& completed)
{

	ifstream filein;
	filein.open("assignments.dat", ios::in);
	if (!filein)
	{
		cout << "Error opening db for input";
		exit(1);
	}

	cout << "Reading from file..." << endl;
	while (due.empty() != true)
	{
		due.pop_front();
	}

	while (completed.empty() != true)
	{
		completed.pop_front();
	}

	while (!filein.eof())
	{
		assignments temp;
		string input;
		
		while (getline(filein, input))//read the next line in the file, if no more lines are availble, the while loop will exit.
		{
			String_Tokenizer st(input, ",");//a tokenizer for parsing a line of tokens (the tokens are seperated by commas)
			Date duedate = st.next_token();//the first token in line is the due date
			string desc = st.next_token();//the next token is the description
			Date assigned = st.next_token();//the next token is the assigned date
			string status = st.next_token();// the next token is the status
			temp.setDate(duedate);
			temp.setDesc(desc);
			temp.setAssDate(assigned);
			char statchar = status[0];
			temp.setStatus(temp.evaluateStatus(statchar));
			if (temp.getStatus() == 0)//if the status is assigned push on the due list
				due.push_back(temp);
			else
				completed.push_back(temp);// otherwise push on the completed list
		}
	}
	filein.close();

}