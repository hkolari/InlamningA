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

bool TimberList::addTimber(int width, int length, string dimension, string dimension2, int totalStock, float pricePerMeter)
{
	bool exists = false;

	if (this->nrOfTimber == capacity)
	{
		this->expand();
	}

	Timber temp(width, length, dimension, dimension2, totalStock, pricePerMeter);
	for (int i = 0; i < nrOfTimber && !exists; i++)
	{
		if (temp == *allTimber[i])
		{
			exists = true;
		}
	}
	if (!exists)
	{
		allTimber[nrOfTimber++] = new Timber(width, length, dimension, dimension2, totalStock, pricePerMeter);
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

void TimberList::ShowAll() const
{
	for (int i = 0; i < nrOfTimber; i++)
	{
		cout << allTimber[i]->toString() << endl;
	}
}

void TimberList::getTimberAsString(string arr[], int nrOf) const
{
	if (nrOfTimber < nrOf)
	{
		nrOf = nrOfTimber;
	}

	for (int i = 0; i < nrOf; i++)
	{
		arr[i] = allTimber[i]->toString();
	}
}

bool TimberList::removeTimber(int width, int length, string dimension, string dimension2, int totalStock, float pricePerMeter)
{
	Timber temp(width, length, dimension, dimension2, totalStock, pricePerMeter);
	bool removed = false;


	return removed;
}

bool TimberList::doesItExist(string dimension) const
{
	bool exists = false;
	for (int i = 0; i < this->nrOfTimber; i++) {
		if (this->allTimber[i]->getDimension() == dimension) {
			exists = true;
		}
	}

	return exists;
}
