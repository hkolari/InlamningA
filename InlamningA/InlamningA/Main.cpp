//Written by Henry Kolari (heko16 - 199712038430)

#include <string>
#include <iostream>
#include "TimberList.h"
#include "TimberRegister.h"
#include <crtdbg.h>

using namespace std;

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
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
		int insertMeter = -1;
		string fileName = "EMPTY";
		int insertChoice = -1;


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
		{
			int stop = 0;
			cout << "Current stock:" << endl;
			cout << list.ShowAll() << endl;
			break;
		}
		case 2:
		{
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
			cout << "Please insert amount of meters that will be added to stock: " << endl;
			cin >> insertAmount; cin.ignore();
			cout << "Please insert the price per meter (You can use decimals): " << endl;
			cin >> insertPricePerMeter; cin.ignore();
			list.addTimber(insertWidth, insertLength, insertDimension, insertAmount, insertPricePerMeter);
			break;
		}
		case 3:
		{
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
		}
		case 4:
		{
			cout << "What is the maximal amount of meters you would like to search for?:" << endl;
			cin >> insertMeter; cin.ignore();
			cout << list.searchFor(insertMeter) << endl;
			break;
		}
		case 5:
		{
			cout << "Total value of your whole stock is: " << list.totalSummary() << "sek" << endl;
			break;
		}

		case 6:
		{
			cout << "What dimension is the item you want to edit? (example. 6x6, 5x7 or 10x2)" << endl;
			cin >> insertDimension; cin.ignore();
			if (list.doesItExist(insertDimension) == true)
			{
				cout << "What would you like to edit?" << endl;
				cout << "1.Amount of meter in stock" << endl;
				cout << "2.Price per meter" << endl;
				cin >> insertChoice; cin.ignore();
				if (insertChoice == 1)
				{
					cout << "What would you like to change the amount of meter in stock to?:" << endl;
					cin >> insertAmount; cin.ignore();
					list.editContent(insertDimension, insertAmount, insertChoice);
				}
				if (insertChoice == 2)
				{
					cout << "What would you like to change the price per meter to?:" << endl;
					cin >> insertPricePerMeter; cin.ignore();
					list.editContent(insertDimension, insertPricePerMeter, insertChoice);
				}
			}
			else
			{
				cout << "Unable to find dimension." << endl;
			}
			
			break;
		}

		case 7:
		{
			cout << "What would you like to name the file to (remember to insert file's format)?: " << endl;
			cin >> fileName; cin.ignore();
			list.saveFile(fileName);
			break;
		}

		case 8:
		{
			cout << "What would you like read/search (remember to insert file's format)?: " << endl;
			cin >> fileName; cin.ignore();
			cout << list.readFile(fileName) << endl;
			break;
		}

		case 9:
		{
			cout << "Shutting down" << endl;
			continueOrNot = 1;
			break;
		}
		default:
		{
			cout << "Error please try again" << endl;
			break;
		}
		}
	}
	getchar();
	return 0;
}