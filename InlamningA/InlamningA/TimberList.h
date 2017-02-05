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
	bool addTimber(int width, int length, string dimension, int totalStock, float pricePerMeter);
	string ShowAll() const;
	bool removeTimber(string dimension);
	bool doesItExist(string dimension) const;
	string searchFor(int meters) const;
	float totalSummary() const;

	FILE TimberList::saveFile(string fileName) const;

	~TimberList();
	void expand();

	void getTimberAsString(string arr[], int nrOf) const;
};

#endif
