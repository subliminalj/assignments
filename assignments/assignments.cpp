#include "assignments.h"


//
//
//void outfile()
//{
//
//	ofstream fileout;
//	fileout.open("inventory.dat", ios::binary | ios::out);
//
//	if (!fileout)
//	{
//		cout << "Error opening db for output";
//		exit(1);
//	}
//
//	cout << "Writing to file..." << endl;
//
//	//fileout.write((char*)&stock, MAX * sizeof(list<inventory>));
//
//	for (it = stock.begin(); it != stock.end(); it++)
//	{
//		fileout << it->get_stocknum() << endl << it->get_description() << endl << it->get_cost() << endl << it->get_quantity() << endl;
//
//	}
//
//
//	fileout.close();
//
//}
//
//void infile()
//{
//
//	ifstream filein;
//	filein.open("inventory.dat", ios::binary | ios::in);
//	if (!filein)
//	{
//		cout << "Error opening db for input";
//		exit(1);
//	}
//
//	cout << "Reading from file..." << endl;
//
//	//filein.read((char*)&stock, MAX * sizeof(list<inventory>));
//
//	for (int i = 0; i < MAX; i++)
//	{
//		inventory temp;
//		stock.push_back(temp);
//	}
//
//	for (it = stock.begin(); it != stock.end(); it++)
//	{
//
//		int i;
//		string d;
//		double c;
//		int q;
//
//		filein >> i;
//		it->set_stocknum(i);
//		filein >> d;
//		it->set_description(d);
//		filein >> c;
//		it->set_cost(c);
//		filein >> q;
//		it->set_quantity(q);
//
//	}
//
//
//
//
//	filein.close();
//
//}
//
//bool compareinv(inventory& left, inventory& right)
//{
//	return left.get_stocknum() < right.get_stocknum();
//}
//
//void sort()
//
//{
//	stock.sort(compareinv);
//
//}
//
//
