#include "assignments.h"
#include "interface.h"

//bool compare(assignments& left, assignments& right)
//{
//	return left.getDate < right.getDate();
//}
//void sort()
//
//{
//	assigned.sort(compare);
//	completed.sort(compare);
//
//}
void main(void)
{
	// One list for assignments pending, one list for assignments completed
	list<assignments> assigned;
	list<assignments> completed;
	//iterators for assignments
	list<assignments>::iterator it;
	list<assignments>::const_iterator const_it;

	
	User_Interface ui(list<assignments> assigned, list<assignments>completed);
	ui.process_commands();






}