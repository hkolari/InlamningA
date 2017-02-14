//Written by Henry Kolari (heko16 - 199712038430)

#include "TimberList.h"
#include "TimberRegister.h"
#include <string>
#include <fstream>
#include <iostream>
#include <array>
#include <fstream>

using namespace std;

TimberList& TimberList::operator=(const TimberList& eeh)
{
	this->capacity = eeh.capacity;
	this->nrOfTimber = eeh.nrOfTimber;
	return *this;
}

TimberList::TimberList(const TimberList &copy)
{
	this->capacity = copy.capacity;
	this->nrOfTimber = copy.nrOfTimber;
}


int TimberList::getCapacity() const
{
	return capacity;
}

int TimberList::getNr() const
{
	return nrOfTimber;
}



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

TimberList::TimberList(int capacity)
{
	this->capacity = capacity;
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






bool TimberList::addTimber(string dimension, int totalStock, float pricePerMeter)
{
	bool exists = false;

	if (this->nrOfTimber == capacity)
	{
		this->expand();
	}

	Timber temp(dimension, totalStock, pricePerMeter);
	for (int i = 0; i < nrOfTimber && !exists; i++)
	{
		if (temp == *allTimber[i])
		{
			exists = true;
		}
	}
	if (!exists)
	{
		allTimber[nrOfTimber++] = new Timber(dimension, totalStock, pricePerMeter);
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

void TimberList::ShowAll(string *temp) const
{
	for (int i = 0; i < nrOfTimber; i++)
	{
		*temp += allTimber[i]->toString() + "\n";
	}
}

void TimberList::getTimberAsString(string *arr, int nrOf) const
{
	for (int i = 0; i < nrOf; i++)
	{
		arr[i] = allTimber[i]->toString();
	}
}

void TimberList::searchFor(int meters, string *arr, int nrOf) const
{

	for (int i = 0; i < nrOf; i++)
	{
		if (this->allTimber[i]->getTotalStock() == meters || this->allTimber[i]->getTotalStock() < meters)
		{
			arr[i] = allTimber[i]->toString();
		}
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

bool TimberList::editContent(string dimension, float valueFromMain, int whichOne)
{
	bool exists = false;
	for (int i = 0; i < this->nrOfTimber; i++)
	{
		if (this->allTimber[i]->getDimension() == dimension)
		{
			if (whichOne == 1)
			{
				this->allTimber[i]->setTotalStock(valueFromMain);
			}
			if (whichOne == 2)
			{
				this->allTimber[i]->setPricePerMeter(valueFromMain);
			}
		}
	}
	return exists;
}

void TimberList::saveFile(string fileName) const
{
	ofstream newFile(fileName, ios_base::app);
	if (newFile.is_open())
		newFile << getNr() << endl;
	{
		for (int i = 0; i < nrOfTimber; i++)
		{
			newFile << allTimber[i]->toFile() << endl;
		}
	}
	newFile.close();
}

void TimberList::readFile(string fileName)
{
	int lineOne;
	ifstream loadFile(fileName);
	if (loadFile.is_open())
	{
		loadFile >> lineOne; loadFile.ignore();
		
		for (int i = 0; i < lineOne; i++)
		{
			string dimensionFromFile = "EMPTY";
			int amountFromFile = -1;
			float priceFromFile = -1;
			loadFile >> dimensionFromFile; loadFile.ignore();
			loadFile >> amountFromFile; loadFile.ignore();
			loadFile >> priceFromFile; loadFile.ignore();
			addTimber(dimensionFromFile, amountFromFile, priceFromFile);
		}
		/*
		while (getline (loadFile,line))
		{
			sendBack += line + "\n";
		}
		*/
		loadFile.close();
	}
}