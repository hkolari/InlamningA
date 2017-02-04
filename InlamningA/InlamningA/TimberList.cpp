#include "TimberList.h"
#include "TimberRegister.h"
#include <string>
#include <fstream>
#include <iostream>

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
	for (int i = 0; i < capacity; i++)
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
		temp = allTimber[i]->toString();
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
			allTimber[i] = allTimber[nrOfTimber - 1];
			*allTimber[nrOfTimber - 1] = Timber();
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
