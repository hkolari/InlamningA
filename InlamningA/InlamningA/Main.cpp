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
	
	while (continueOrNot == 0)
	{
		int insertWidth = -1;
		int insertLength = -1;
		string insertDimension = "EMPTY";
		int insertAmount = -1;
		float insertPricePerMeter = -1;


		cout << "-----------------------" << endl;
		cout << "Welcome to TimberStore!" << endl;
		cout << "Select an option" << endl << endl;
		cout << "1.Show Current Stock" << endl;
		cout << "2.Add New Timber" << endl;
		cout << "3.Remove Timber" << endl;
		cout << "4.Show Specific Meters Timber" << endl;
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
				int stop = 0;
				cout << "Current stock:" << endl;
				cout << list.ShowAll() << endl;
				break;

			case 2:
				cout << "Please insert the timber's width: " << endl;
				cin >> insertWidth; cin.ignore();
				cout << "Please insert the timber's length: " << endl;
				cin >> insertLength; cin.ignore();

				//Dimension
				insertDimension = to_string(insertWidth) + "x" + to_string(insertLength);
				
				if (list.doesItExist(insertDimension) == true)
				{
					cout << "Duplicate found, try again" << endl;
					break;
				}

				cout << "Please insert amount of timber added to stock: " << endl;
				cin >> insertAmount; cin.ignore();
				cout << "Please insert the price per meter (You can use decimals): " << endl;
				cin >> insertPricePerMeter; cin.ignore();
				list.addTimber(insertWidth, insertLength, insertDimension, insertAmount, insertPricePerMeter);
				break;

			case 3:
				cout << "Please insert the dimension width:" << endl;
				cin >> insertWidth; cin.ignore();
				cout << "Please insert the dimension length :" << endl;
				cin >> insertLength; cin.ignore();

				insertDimension = to_string(insertWidth) + "x" + to_string(insertLength);

				if (list.doesItExist(insertDimension) == true)
				{
					list.removeTimber(insertDimension);
				}
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