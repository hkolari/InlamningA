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
	/*
	int width;
	int length;
	int totalStock;,
	float pricePerMeter;
	*/
	int capacity;
	int nrOfTimber;

public:
	TimberList();
	TimberList(int capacity);
	bool addTimber(int width, int length, string dimension, int totalStock, float pricePerMeter);
	string ShowAll() const;
	bool removeTimber(string dimension);
	bool doesItExist(string dimension) const;
	string searchFor(int meters) const;
	float totalSummary() const;
	bool TimberList::editContent(string dimension, float value, int whichOne);

	void TimberList::saveFile(string fileName) const;
	string TimberList::readFile(string fileName) const;


	~TimberList();
	void expand();

	void getTimberAsString(string arr[], int nrOf) const;
};

#endif
