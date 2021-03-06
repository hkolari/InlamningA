//Written by Henry Kolari (heko16 - 199712038430)

#include "TimberList.h"
#include <fstream>
#include <iostream>

//TODO: DEEP COPYING

TimberList& TimberList::operator=(const TimberList& eeh)
{
	if (this != &eeh) {

		

		for (int i = 0; i < this->nrOfTimber; i++) {
			delete this->allTimber[i];
		}
		delete[] this->allTimber;


		this->capacity = eeh.capacity;
		this->nrOfTimber = eeh.nrOfTimber;


		this->allTimber = new Timber*[eeh.capacity];

		for (int i = 0; i < eeh.nrOfTimber; i++)
		{
			//this->allTimber[i] = new Timber();
			//*this->allTimber[i] = *eeh.allTimber[i];

			this->allTimber[i] = new Timber(*eeh.allTimber[i]);
		}

		
	}

	return *this;
}

TimberList::TimberList(const TimberList &copy)
{
	
	
	this->capacity = copy.capacity;
	this->nrOfTimber = copy.nrOfTimber;

	this->allTimber = new Timber*[copy.capacity];
	 
	for (int i = 0; i < copy.nrOfTimber; i++)
	{
		this->allTimber[i] = new Timber(*copy.allTimber[i]);
		//*this->allTimber[i] = *copy.allTimber[i];
	}
	

	
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
	for (int i = 0; i < this->nrOfTimber; i++)
	{
		delete this->allTimber[i];
	}
	
	delete[] this->allTimber;
}






bool TimberList::addTimber(string dimension, int totalStock, float pricePerMeter)
{
	bool exists = false;

	if (this->nrOfTimber == capacity)
	{
		this->expand();
	}

//	Timber(dimension, totalStock, pricePerMeter);
	for (int i = 0; i < nrOfTimber && !exists; i++)
	{
		if (Timber(dimension, totalStock, pricePerMeter) == *this->allTimber[i])
		{
			exists = true;
		}
	}

	if (!exists)
	{
		this->allTimber[this->nrOfTimber] = new Timber(dimension, totalStock, pricePerMeter);
		this->nrOfTimber++;
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
	this->allTimber = temp;
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
			allTimber[i] = allTimber[nrOfTimber - 1]; //s�tter aktuella (som ska bort) timber till den som �r sist i Arrayen


			//*allTimber[nrOfTimber - 1] = Timber();  //  Vi s�ger att 
			// Vi r�kade g�ra en deepcopy. D� Sista timber var flyttad till allTimber[i]
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
		loadFile.close();
	}
}