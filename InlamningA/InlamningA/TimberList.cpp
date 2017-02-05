#include "TimberList.h"
#include "TimberRegister.h"
#include <string>
#include <fstream>
#include <iostream>
#include <array>
#include <fstream>

using namespace std;

TimberList::TimberList()
{
	this->capacity = 1;
	this->nrOfTimber = 0;
	
	allTimber = new Timber*[capacity];
	for (int i = 0; i < capacity; i++)
	{
		allTimber[i] = nullptr;
	}
}


TimberList::~TimberList()
{
	for (int i = 0; i < nrOfTimber; i++)
	{
		delete allTimber[i];
	}
	delete[] allTimber;
}

bool TimberList::addTimber(int width, int length, string dimension, int totalStock, float pricePerMeter)
{
	bool exists = false;

	if (this->nrOfTimber == capacity)
	{
		this->expand();
	}

	Timber temp(width, length, dimension, totalStock, pricePerMeter);
	for (int i = 0; i < nrOfTimber && !exists; i++)
	{
		if (temp == *allTimber[i])
		{
			exists = true;
		}
	}
	if (!exists)
	{
		allTimber[nrOfTimber++] = new Timber(width, length, dimension, totalStock, pricePerMeter);
	}
		return !exists;
		}

void TimberList::expand()
{
	this->capacity *= 2;
	Timber** temp = new Timber*[this->capacity];
	for (int i = 0; i < nrOfTimber; i++)
	{
		temp[i] = allTimber[i];
	}
	delete[] allTimber;
	allTimber = temp;
	temp = nullptr;
}

string TimberList::ShowAll() const
{
	string temp;
	for (int i = 0; i < nrOfTimber; i++)
	{
		temp += allTimber[i]->toString() + "\n";
	}
	return temp;
}

void TimberList::getTimberAsString(string arr[], int nrOf) const
{
	for (int i = 0; i < nrOf; i++)
	{
		arr[i] = allTimber[i]->toString();
	}
}


bool TimberList::removeTimber(string dimension)
{
	bool removed = false;
	for (int i = 0; i < this->nrOfTimber; i++)
	{
		if (this->allTimber[i]->getDimension() == dimension)
		{
			
			delete allTimber[i];
			allTimber[i] = allTimber[nrOfTimber - 1]; //sätter aktuella (som ska bort) timber till den som är sist i Arrayen


			//*allTimber[nrOfTimber - 1] = Timber();  //  Vi säger att 
			// Vi råkade göra en deepcopy. Då Sista timber var flyttad till allTimber[i]
			// 
			Timber *myTimber = new Timber();
			allTimber[nrOfTimber - 1] = myTimber;
			delete myTimber;
			
			removed = true;
			nrOfTimber--;
		}
	}
	return removed;
}

bool TimberList::doesItExist(string dimension) const
{
	bool exists = false;
	for (int i = 0; i < this->nrOfTimber; i++) 
	{
		if (this->allTimber[i]->getDimension() == dimension) 
		{
			exists = true;
		}
	}

	return exists;
}

string TimberList::searchFor(int meters) const
{
	string output;
	for (int i = 0; i < this->nrOfTimber; i++)
	{
		if (this->allTimber[i]->getTotalStock() == meters || this->allTimber[i]->getTotalStock() < meters)
		{
			output += allTimber[i]->toString() + "\n";
		}
	}
	return output;
}

float TimberList::totalSummary() const
{
	float sendSumBack = 0;
	for (int i = 0;  i < this->nrOfTimber; i++)
	{
		float toAdd = -1;
		float perMeter = this->allTimber[i]->getPricePerMeter();
		int perAmount = this->allTimber[i]->getTotalStock();
		toAdd = perMeter * perAmount;
		sendSumBack = sendSumBack + toAdd;
	}
	return sendSumBack;
}

bool TimberList::editContent(string dimension, int value)
{

}

void TimberList::saveFile(string fileName) const
{
	ofstream newFile(fileName, ios_base::app);
	if (newFile.is_open())
	{
		for (int i = 0; i < nrOfTimber; i++)
		{
			newFile << allTimber[i]->toString() << endl;
		}
	}
	newFile.close();
}

string TimberList::readFile(string fileName) const
{
	string line;
	string sendBack;
	ifstream loadFile(fileName);
	if (loadFile.is_open())
	{
		while (getline (loadFile,line))
		{
			sendBack += line + "\n";
		}
		loadFile.close();
	}
	return sendBack;
}