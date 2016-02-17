#ifndef _INTERFACE_H_
#define _INTERFACE_H_

#include "assignments.h"

class User_Interface{
private:


public:

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
			"Sort pending assignments by due date"
			"Undo"
			"Redo"
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
		} while (choice < NUM_COMMANDS - 1);
	}

	void do_display(assignments& due, assignments& complete)
	{
		list<assignments>::iterator dueiter;
		list<assignments>::iterator compiter;
		
		for (due = dueiter.begin(); due != dueiter.end(); dueiter++)
		{
			cout << due << endl;

		}
	
		for (complete = compiter.begin(); complete != compiter.end(); compiter++)
		{
			cout << complete << endl;

		}
	}
	void do_add_entry(assignments list_to_add, Date due, string desc, Date assigned, string status)
	{
		assignments temp;
		temp.setDate(due);
		temp.setDesc(desc);
		temp.setAssDate(assigned);
		temp.setStatus(status);
	}
	void do_complete_entry()
	{}
	void do_delete()
	{}
	void do_edit_date_entry()
	{}
	void do_edit_desc()
	{}
	void do_count_late()
	{}
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





};

#endif