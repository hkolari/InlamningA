//Written by Henry Kolari (heko16 - 199712038430)

#ifndef TIMBERLIST_H
#define TIMBERLIST_H
#include "TimberRegister.h"
#include <string>

using namespace std;

class TimberList
{
private:
	Timber** allTimber;
	string dimension;
	int totalStock;
	float pricePerMeter;

	int capacity;
	int nrOfTimber;

public:
	TimberList(TimberList & copy);
	TimberList& operator=(const TimberList& eeh);

	int getCapacity()const;
	int getNr()const;

	TimberList();
	TimberList(int capacity);
	bool addTimber(string dimension, int totalStock, float pricePerMeter);
	void ShowAll(string *temp) const;
	bool removeTimber(string dimension);
	bool doesItExist(string dimension) const;
	void searchFor(int meters, string *temp) const;
	float totalSummary() const;
	bool TimberList::editContent(string dimension, float value, int whichOne);

	void TimberList::saveFile(string fileName) const;
	string TimberList::readFile(string fileName) const;


	~TimberList();
	void expand();

	void getTimberAsString(string *arr, int nrOf) const;
};

#endif
