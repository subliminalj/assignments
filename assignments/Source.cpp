#include "inventory.h"


inventory temp;
list<inventory> stock;
list<inventory>::iterator it;
const int MAX = 5;
char input;
int searchterm;
int stocknum;
void outfile()
{

	ofstream fileout;
	fileout.open("inventory.dat", ios::binary | ios::out);

	if (!fileout)
	{
		cout << "Error opening db for output";
		exit(1);
	}

	cout << "Writing to file..." << endl;

	//fileout.write((char*)&stock, MAX * sizeof(list<inventory>));

	for (it = stock.begin(); it != stock.end(); it++)
	{
		fileout << it->get_stocknum() << endl << it->get_description() << endl << it->get_cost() << endl << it->get_quantity() << endl;

	}


	fileout.close();

}

void infile()
{

	ifstream filein;
	filein.open("inventory.dat", ios::binary | ios::in);
	if (!filein)
	{
		cout << "Error opening db for input";
		exit(1);
	}

	cout << "Reading from file..." << endl;

	//filein.read((char*)&stock, MAX * sizeof(list<inventory>));

	for (int i = 0; i < MAX; i++)
	{
		inventory temp;
		stock.push_back(temp);
	}

	for (it = stock.begin(); it != stock.end(); it++)
	{

		int i;
		string d;
		double c;
		int q;

		filein >> i;
		it->set_stocknum(i);
		filein >> d;
		it->set_description(d);
		filein >> c;
		it->set_cost(c);
		filein >> q;
		it->set_quantity(q);

	}




	filein.close();

}

bool compareinv(inventory& left, inventory& right)
{
	return left.get_stocknum() < right.get_stocknum();
}

void sort()

{
	stock.sort(compareinv);

}

void update()
{
	int editstocknum;
	string description;
	double cost;
	int qty;


	cout << endl << setw(5) << "SKU:" << setw(30) << "Description:" << setw(7) << "Cost:" << setw(8) << "Qty:" << endl;
	for (it = stock.begin(); it != stock.end(); it++)
	{
		cout << setw(5) << it->get_stocknum() << " " << setw(30) << it->get_description() << " " << setw(7) << it->get_cost() << " " << setw(8) << it->get_quantity() << endl;
	}

	cout << endl << "Enter Stock number of entry to modify:";
	cin >> stocknum;
	for (it = stock.begin(); it != stock.end(); it++)
	{
		if (it->get_stocknum() == stocknum)
		{
			cout << setw(5) << "SKU:" << setw(30) << "Description:" << setw(7) << "Cost:" << setw(8) << "Qty:" << endl;
			cout << setw(5) << it->get_stocknum() << " " << setw(30) << it->get_description() << " " << setw(7) << it->get_cost() << " " << setw(8) << it->get_quantity() << endl;
			cout << "Edit which field?:\n(S)tock Number\n(I)tem Description\n(U)nit Cost\n(Q)uantity\n:";
			cin >> input;
			switch (input)
			{
			default:
				break;
			case 's':
			case 'S':
				cout << "\nChange Stock Number\n:";
				cin >> editstocknum;
				it->set_stocknum(editstocknum);
				break;
			case 'I':
			case 'i':
				cout << "\nChange Item Description\n:";
				cin.ignore(2, '\n');
				getline(cin, description);
				it->set_description(description);
				break;
			case 'U':
			case 'u':
				cout << "\nChange Unit Cost\n:";
				cin >> cost;
				it->set_cost(cost);
				break;
			case 'Q':
			case 'q':
				cin >> qty;
				cout << "\nChange Quantity\n:";
				it->set_quantity(qty);
				break;
			}
		}
	}



}


void main(void)
{

	while (true)
	{

		cout << "Input selection:\n(F)ill database with " << MAX << " items" << endl;
		cout << "(D)isplay inventory\n(S)ort Inventory by SKU number\n(E)rase entry\n(U)pdate items\n(R)ead database\n(W)rite database\n(C)lear Database\n(Q)uit\n:";
		cin >> input;
		switch (input)
		{
			// Display inventory
		case 'D':
		case 'd':
			cout << setw(5) << "SKU:" << setw(30) << "Description:" << setw(7) << "Cost:" << setw(8) << "Qty:" << endl;
			for (it = stock.begin(); it != stock.end(); it++)
			{
				cout << setw(5) << it->get_stocknum() << " " << setw(30) << it->get_description() << " " << setw(7) << it->get_cost() << " " << setw(8) << it->get_quantity() << endl;
			}
			break;


			//Sort Database
		case 'S':
		case 's':
			sort();
			break;
			//Fill database
		case 'F':
		case 'f':
			for (int i = 0; i < MAX; i++)
			{
				temp.filldb();
				stock.push_back(temp);
			}


			break;

			//Erase entry
		case 'E':
		case 'e':
			cout << "Type in the SKU number to erase an item." << endl;
			cin >> searchterm;
			it = stock.begin();
			while (it != stock.end())
			{
				if (it->get_stocknum() == searchterm)
				{
					it = stock.erase(it);
					continue;
				}
				it++;
			}
			break;

			//Update items
		case 'U':
		case 'u':

			update();

			break;

			//Read in database
		case 'R':
		case 'r':

			infile();
			break;

			//Write database
		case 'W':
		case 'w':

			outfile();

			break;

			//Clear Database
		case 'c':
		case 'C':
			stock.clear();
			break;

			//Quit
		case 'Q':
		case 'q':
			exit(0);
			break;

		}

	}
}