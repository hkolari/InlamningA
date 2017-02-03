#include <string>
#include <iostream>
#include "TimberList.h"
#include "TimberRegister.h"

using namespace std;

int main()
{
	TimberList list;
	int menuChoice = 0;
	int continueOrNot = 0;

	int insertWidth = -1;
	int insertLength = -1;
	int insertAmount = -1;
	float insertPricePerMeter = -1;
	
	while (continueOrNot == 0)
	{
		cout << "-----------------------" << endl;
		cout << "Welcome to TimberStore!" << endl;
		cout << "Select an option" << endl << endl;
		cout << "1.Show Current Stock" << endl;
		cout << "2.Add New Timber" << endl;
		cout << "3.Remove Timber" << endl;
		cout << "4.Search Timber" << endl;
		cout << "5.Total Timber Stock Value" << endl;
		cout << "6.Edit Timber" << endl;
		cout << "7.Save Timber Stock" << endl;
		cout << "8.Read Timber Stock" << endl;
		cout << "9.Close application" << endl;
		cout << "-----------------------" << endl;
		cin >> menuChoice; cin.ignore();

			switch (menuChoice)
			{
			case 1:
				cout << "Current stock:" << endl;
				list.ShowAll();
				break;

			case 2:
				cout << "Please insert the timber's width: " << endl;
				cin >> insertWidth; cin.ignore();
				cout << "Please insert the timber's length: " << endl;
				cin >> insertLength; cin.ignore();
				cout << "Please insert amount of timber added to stock: " << endl;
				cin >> insertAmount; cin.ignore();
				cout << "Please insert the price per meter (You can use decimals): " << endl;
				cin >> insertPricePerMeter; cin.ignore();
				list.addTimber(insertWidth, insertLength, insertAmount, insertPricePerMeter);
				break;

			case 3:
				break;

			case 4:
				break;

			case 5:
				break;

			case 6:
				break;

			case 7:
				break;

			case 8:
				break;

			case 9:
				cout << "Shutting down" << endl;
				continueOrNot = 1;
				break;

			default:
				cout << "Error please try again" << endl;
				break;
			}
	}
	getchar();
	return 0;
}