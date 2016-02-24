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
			"Sort pending assignments by due date",
			"Undo",
			"Redo",
			"Save",
			"Load",
			"Exit"
		};
		const size_t NUM_COMMANDS = 13;
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
				//			case 7: do_sort(); break;
			case 8: do_undo(); break;
			case 9: do_redo(); break;
			case 10: do_save(); break;
			case 11: do_load(); break;
			case 12: do_exit(); break;
			default: cout << "Incorrect selection! Please enter a number between 0 - 12." << endl; break;
			}
			system("CLS");
		} while (choice < NUM_COMMANDS - 1);
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
		Date duedate, assigned, completedate;
		string desc;
		int status;
		char compStatus;
		assignments addAss;
		list<assignments>::iterator additer;
		bool reenter = 0;

		cout << "Input description: ";
		getline(cin, desc);

		do
		{
			cout << "Input due date: ";
			duedate = addAss.inputDate();

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
		} while (reenter == 1);

		addAss.setDate(duedate);
		addAss.setDesc(desc);
		addAss.setAssDate(assigned);

		if (addAss.findAss(due) || addAss.findAss(completed))
			cout << "This entry already exists!" << endl;
		else
		{
			addAss.setStatus(addAss.evaluateStatus());
			if (addAss.getStatus() == 0)
			{
				due.push_front(addAss);
				due.sort();
			}
			else
			{
				completed.push_front(addAss);
				completed.sort();
			}
		}
	}

	void do_complete_entry() // mark an entry as completed
	{
		string compAss;
		char newStatus;
		list<assignments>::iterator compiter;
		assignments newComp;

		cout << "Which assignment would you like to update as completed?" << endl;
		cin >> compAss;

		for (compiter = due.begin(); compiter != due.end(); compiter++)
		{
			if (compiter->getDesc() == compAss)
			{
				cout << "Assignment to be updated:\n"
					<< *compiter << endl;
				compiter->setStatus(newComp.evaluateCompStatus(compiter->getDate()));

				newComp = *compiter;
				completed.push_front(newComp);
				completed.sort();

				compiter = due.erase(compiter);
				cout << "Status updated" << endl;
				break;
			}
		}
	}

	void do_delete()// remove an entry from the due list
	{
		string displaydel;
		cout << "Type the description of the pending assignment to delete" << endl;
		do_display();
		cout << "description: ";
		cin >> displaydel;
		list<assignments>::iterator deliter;
		for (deliter = due.begin(); deliter != due.end(); deliter++)
		{
			if (deliter->getDesc() == displaydel)
			{
				deliter = due.erase(deliter);
				continue;
				cout << "entry deleted" << endl;
			}
		}
	}

	void do_edit(int toEdit)// change the date or description of a pending assignment
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
				if (toEdit == 4)
				{
					cout << "\nEnter the new due date: ";
					edititer->setDate(editAss.inputDate());
				}
				else if (toEdit == 5)
				{
					cout << "\nEnter the new due description: ";
					getline(cin, newDesc);
					edititer->setDesc(newDesc);
				}
				cout << "Assignment updated." << endl;
				searchAgain = 'N';
			}
		}
		if (searchAgain != 'N')
		{
			cout << "\nAssignment not found! Do you want to search again (Y/N)? ";
			cin >> searchAgain;

			while (searchAgain != 'N' && searchAgain != 'n')
			{
				if (searchAgain == 'Y' || searchAgain == 'y')
				{
					do_edit(toEdit);
					searchAgain = 'N';
				}
				else if (searchAgain != 'N' && searchAgain != 'n')
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
			if (lateAss.getStatus() == 2)
				count_late++;
		}

		cout << "There are " << count_late << " late assignments." << endl;
		cout << "Press the 'enter' key to continue...";
		cin.get();
	}

	//void do_sort()// sort both lists by the due date
	//{
	//	sort();
	//}
	void do_undo() // undo last action
	{}
	void do_redo() // redo last undone action
	{}
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

	//bool compare(assignments& left, assignments& right) // compares two dates, used by the sort function
	//{
	//	return left.getDate() < right.getDate();
	//}
	//void sort()// sort both due and completed lists by the due date

	//{
	//	due.sort(compare);
	//	completed.sort(compare);
	//}



};

#endif