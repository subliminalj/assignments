//Sets up the options the user has for interacting with the program. interface.h calls functions from assignments.h and 
//files.h to execute the user's commands
#ifndef _INTERFACE_H_
#define _INTERFACE_H_

#include "assignments.h"
#include "files.h"

class User_Interface{
private:
	list<assignments> due;
	list<assignments> completed;
	Date current_date;

public:
	User_Interface(list<assignments>& due, list<assignments>& complete){}
	void process_commands()
	{
		string commands[] = { //the options the user is given
			"Display the Assignments",
			"Add a new assignment",
			"Complete Assignment",
			"Delete Assignment",
			"Edit Due Date",
			"Edit Description",
			"Count Late Assignments",
			"Save",
			"Load",
			"Exit"
		};
		// establishes a total of 10 commands for the do while loop to display and select based on user input
		const size_t NUM_COMMANDS = 10;
		size_t choice = NUM_COMMANDS - 1;
		do {
			for (size_t i = 0; i < NUM_COMMANDS; i++) {
				cout << "Select: " << i << " " << commands[i] << "\n";
			}
			cin >> choice;
			cin.ignore(numeric_limits<int>::max(), '\n');
			switch (choice) {
			case 0: do_display(); break;
			case 1: do_add_entry(); break;
			case 2: do_complete_entry(); break;
			case 3: do_delete(); break;
			case 4:
			case 5: do_edit(choice); break;
			case 6: do_count_late(); break;
			case 7: do_save(); break;
			case 8: do_load(); break;
			case 9: do_exit(); break;
			default: cout << "Incorrect selection! Please enter a number between 0 - 9." << endl; break;
			}
			system("CLS");
		} while (choice < NUM_COMMANDS - 1); // exits loop when the last case (do_exit) is selected
	}

	void do_display()// cycle through both due and completed lists and display contents
	{
		list<assignments>::iterator dueiter;
		list<assignments>::iterator compiter;

		cout << "Format: Due Date, Description, Assigned Date, Status" << endl;

		for (dueiter = due.begin(); dueiter != due.end(); dueiter++)
			cout << *dueiter << endl;

		for (compiter = completed.begin(); compiter != completed.end(); compiter++)
			cout << *compiter << endl;

		system("PAUSE");
	}

	void do_add_entry()// add a new entry to the due list
	{
		Date duedate, assigned;
		string desc;
		assignments addAss;
		list<assignments>::iterator additer;
		bool reenter = 0;

		cout << "Input description: ";
		getline(cin, desc);

		do
		{
			cout << "Input due date: ";
			duedate = addAss.inputDate();	//inputDate() prompts the user for a date and has them reenter if 
											//the format is incorrect
			cout << "Input date assigned: ";
			assigned = addAss.inputDate();

			if (duedate <= assigned)
			{
				cout << "The assignment cannot be due before or on the day it was assigned!" << endl
					<< "Please reenter both dates." << endl;
				reenter = 1; 
			}
			else
				reenter = 0;
		} while (reenter == 1); //loops if the due date is equal to or less than the assignment date

		addAss.setDate(duedate); //set date and description values to establish the assignment identity
		addAss.setDesc(desc);
		addAss.setAssDate(assigned);

		if (addAss.findAss(due) || addAss.findAss(completed))
			cout << "This entry already exists!" << endl;
		else
		{
			addAss.setStatus(addAss.evaluateStatus());	//evaluateStatus() prompts user for assignment status and 
			if (addAss.getStatus() == 0)				//returns the appropriate enum Status value
			{
				due.push_front(addAss);		// 0 means the assignment is assigned but not complete
				due.sort();
			}
			else
			{
				completed.push_front(addAss); // 1 or 2 indicates the assignment is complete or late, respectively
				completed.sort();
			}
		}
	}

	void do_complete_entry() // mark an entry as completed
	{
		string compAss;
		list<assignments>::iterator compiter;
		assignments newComp;

		cout << "Which assignment would you like to update as completed?" << endl;
		getline(cin, compAss);

		for (compiter = due.begin(); compiter != due.end(); compiter++)
		{
			if (compiter->getDesc() == compAss)
			{
				cout << "Assignment to be updated:\n"
					<< *compiter << endl;
				compiter->setStatus(newComp.evaluateCompStatus(compiter->getDate()));	//evaluateCompStatus requires the
																						//appropriate due date to compare
				newComp = *compiter;													//with the completion date
				completed.push_front(newComp);
				completed.sort();

				compiter = due.erase(compiter);			//pop the assignment from the due list after it's been added
				cout << "Status updated" << endl;		//to the completed list
				system("PAUSE");
				break;
			}
		}
	}

	void do_delete()// remove an entry from the due list
	{
		string displaydel;
		cout << "Type the description of the pending assignment to delete" << endl;
		cout << "description: ";
		getline(cin, displaydel);
		list<assignments>::iterator deliter;
		for (deliter = due.begin(); deliter != due.end(); deliter++)
		{
			if (deliter->getDesc() == displaydel) //deletes the assignment when the description is located
			{
				deliter = due.erase(deliter);
				continue;
				cout << "entry deleted" << endl;
				system("PAUSE");
			}
		}
	}

	void do_edit(int toEdit)// change the due date or description of a pending assignment
	{
		string editDesc, newDesc;
		assignments editAss;
		list<assignments>::iterator edititer;
		char searchAgain = 'Y';
		
		cout << "Enter the name of the assignment to be updated: ";
		getline(cin, editDesc);

		for (edititer = due.begin(); edititer != due.end(); edititer++)
		{
			if (edititer->getDesc() == editDesc)
			{
				cout << "Below is the assignment to be edited." << endl
					<< *edititer << endl;
				if (toEdit == 4)						//updates the due date if the user entered option 4 from the menu
				{
					cout << "\nEnter the new due date: ";
					edititer->setDate(editAss.inputDate());
				}
				else if (toEdit == 5)					//updates the description if the user entered option 5 from the menu
				{
					cout << "\nEnter the new due description: ";
					getline(cin,newDesc);
					edititer->setDesc(newDesc);
				}
				cout << "Assignment updated." << endl;
				searchAgain = 'N';
			}
		}
		if (searchAgain != 'N') //only runs if a matching description was not found
		{
			cout << "\nAssignment not found! Do you want to search again (Y/N)? ";
			cin >> searchAgain;

			while (searchAgain != 'N' && searchAgain != 'n')
			{
				if (searchAgain == 'Y' || searchAgain == 'y')
				{
					do_edit(toEdit); //reruns function if the user wants to search again
					searchAgain = 'N';
				}
				else if (searchAgain != 'N' && searchAgain != 'n') //reprompts if the user enters anything other than y or n
				{
					cout << "Incorrect entry! Please enter Y or N: ";
					cin >> searchAgain;
				}
			}
		}
	}

	void do_count_late()// count the number of late items
	{
		list<assignments>::iterator lateiter;
		assignments lateAss;
		int count_late = 0;

		for (lateiter = completed.begin(); lateiter != completed.end(); lateiter++)
		{
			lateAss = *lateiter;
			if (lateAss.getStatus() == 2)	//counts all assignments in the completed list with the enum Status value of 2
				count_late++;				//which correlates with late.
		}

		cout << "There are " << count_late << " late assignments." << endl;
		system("PAUSE");
	}

	void do_save() // save all entries
	{
		outfile(due, completed);

	}
	void do_load() // load database and overwrite all items
	{
		infile(due, completed);
	}
	void do_exit() // exit program
	{
		exit(0);
	}

};

#endif