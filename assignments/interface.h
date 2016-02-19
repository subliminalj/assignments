#ifndef _INTERFACE_H_
#define _INTERFACE_H_

#include "assignments.h"


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
			"Exit"
		};
		const size_t NUM_COMMANDS = 12;
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
			case 4: do_edit_date_entry(); break;
			case 5: do_edit_desc(); break;
			case 6: do_count_late(); break;
			case 7: do_sort(); break;
			case 8: do_undo(); break;
			case 9: do_redo(); break;
			case 10: do_save(); break;
			case 11: do_exit(); break;
			}
			system("CLS");
		} while (choice < NUM_COMMANDS - 1);
	}

	void do_display()
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

	void do_add_entry()
	{
		Date duedate, assigned;
		string desc;
		char status;
		assignments temp;

		cout << "Input due date: " << endl;
		cin >> duedate;
		temp.setDate(duedate);

		cout << "Input description: " << endl;
		cin >> desc;
		temp.setDesc(desc);
		
		cout << "Input date assigned: " << endl;
		cin >> assigned;
		temp.setAssDate(assigned);
		
		cout << "Input status (A = assigned, C = completed, & L = late): " << endl;
		cin >> status;
		temp.setStatus(status);
		
		due.push_front(temp);
	}
	void do_complete_entry()
	{}
	void do_delete()
	{
		string displaydel;
		cout << "Type the description of the pending assignment to delete";
		do_display();
		cout << "description: ";
		cin >> displaydel;
		list<assignments>::iterator deliter;
		for (deliter = due.begin(); deliter != due.end(); deliter++)
		{
			if (deliter->getDesc == displaydel)
			{
				deliter = due.erase(deliter);
				continue;
			}
		}
	}
	void do_edit_date_entry()
	{}
	void do_edit_desc()
	{}
	void do_count_late()
	{
		list<assignments>::iterator lateiter;
		assignments late;
		int count_late = 0;

		for (lateiter = completed.begin(); lateiter != completed.end(); lateiter++)
		{
			late = *lateiter;
			if (late.getStatus() == 2)
				count_late++;
		}

		cout << "There are " << count_late << " late assignments." << endl;
		cout << "Press the 'enter' key to continue...";
		cin.get();
	}

	void do_sort()
	{}
	void do_undo()
	{}
	void do_redo()
	{}
	void do_save()
	{}
	void do_exit()
	{
		exit(0);
	}



	bool compare(assignments& left, assignments& right)
	{
		return left.getDate < right.getDate();
	}
	void sort()

	{
		due.sort(compare);
		completed.sort(compare);

	}



};

#endif