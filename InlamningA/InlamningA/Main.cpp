//Written by Henry Kolari (heko16 - 199712038430)

#include <string>
#include <iostream>
#include "TimberList.h"
#include "TimberRegister.h"
#include <crtdbg.h>
#include "Main.h"

using namespace std;

void showCurrentStock(TimberList *list);
void specificStock(TimberList *list);
void addStock(TimberList *list);
void removeFromStock(TimberList *list);
void stockValue(TimberList *list);
void editStock(TimberList *list);

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	TimberList list;
	int menuChoice = 0;
	int continueOrNot = 0;

	while (continueOrNot == 0)
	{
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
			showCurrentStock(&list);
			break;
		}
		case 2:
		{
			addStock(&list);
			break;
		}
		case 3:
		{
			removeFromStock(&list);
			break;
		}
		case 4:
		{
			specificStock(&list);
			break;
		}
		case 5:
		{
			stockValue(&list);
			break;
		}

		case 6:
		{
			editStock(&list);
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


void showCurrentStock(TimberList *list) 
{

	int stringArrLength = 0;
	if (list->getNr() == 0) {
		stringArrLength = 1;
	}
	else {
		stringArrLength = list->getNr();
	}
	string *arr = new string[stringArrLength];
	cout << "Current stock:" << endl;
	list->getTimberAsString(arr, list->getNr());
	for (int i = 0; i < stringArrLength; i++ ) 
	{
		cout << arr[i] << endl;
	}
	delete[] arr;
	
}

void specificStock(TimberList *list)
{
	/*
	int insertMeter = -1;
	cout << "What is the maximal amount of meters you would like to search for?:" << endl;
	cin >> insertMeter; cin.ignore();
	string *myString = new string();
	list->searchFor(insertMeter, myString);
	cout << *myString << endl;
	delete myString;
	*/
}

void addStock(TimberList *list)
{
	string insertDimension = "EMPTY";
	int insertAmount = -1;
	float insertPricePerMeter = -1;

	cout << "Please insert the timber's dimension (example 10x5): " << endl;
	cin >> insertDimension; cin.ignore();

	if (list->doesItExist(insertDimension) == true)
	{
		cout << "Duplicate found, try again" << endl;
	}
	else
	{
		cout << "Please insert amount of meters that will be added to stock: " << endl;
		cin >> insertAmount; cin.ignore();
		cout << "Please insert the price per meter (You can use decimals): " << endl;
		cin >> insertPricePerMeter; cin.ignore();
		list->addTimber(insertDimension, insertAmount, insertPricePerMeter);
	}
}

void removeFromStock(TimberList *list)
{
	string insertDimension = "EMPTY";
	cout << "Please insert the dimension (example 10x5): " << endl;
	cin >> insertDimension; cin.ignore();

	if (list->doesItExist(insertDimension) == true)
	{
		list->removeTimber(insertDimension);
	}
}

void stockValue(TimberList *list)
{
	cout << "Total value of your whole stock is: " << list->totalSummary() << "sek" << endl;
}

void editStock(TimberList *list)
{
	string insertDimension = "EMPTY";
	float insertAmount = -1;
	float insertPricePerMeter = -1;
	int insertChoice = -1;

	cout << "What dimension is the item you want to edit? (example. 6x6, 5x7 or 10x2)" << endl;
	cin >> insertDimension; cin.ignore();
	if (list->doesItExist(insertDimension) == true)
	{
		cout << "What would you like to edit?" << endl;
		cout << "1.Amount of meter in stock" << endl;
		cout << "2.Price per meter" << endl;
		cin >> insertChoice; cin.ignore();
		if (insertChoice == 1)
		{
			cout << "What would you like to change the amount of meter in stock to?:" << endl;
			cin >> insertAmount; cin.ignore();
			list->editContent(insertDimension, insertAmount, insertChoice);
		}
		if (insertChoice == 2)
		{
			cout << "What would you like to change the price per meter to?:" << endl;
			cin >> insertPricePerMeter; cin.ignore();
			list->editContent(insertDimension, insertPricePerMeter, insertChoice);
		}
	}
	else
	{
		cout << "Unable to find dimension." << endl;
	}

}