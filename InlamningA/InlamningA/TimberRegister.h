//Written by Henry Kolari (heko16 - 199712038430)

#ifndef TIMBERREGISTER_H
#define TIMBERREGISTER_H
#include <string>

using namespace std;

class Timber
{
private:
	int width;
	int length;
	string dimension;
	int totalStock;
	float pricePerMeter;

public:
	Timber();
	Timber(int width, int length, string dimension, int totalStock, float pricePerMeter);
	~Timber();

	Timber& operator=(const Timber& eeh);
	bool operator==(const Timber& eeh);
	bool operator<(const Timber& eeh);
	
	int getWidth();
	int getLength();
	string getDimension();
	int getTotalStock();
	float getPricePerMeter();

	void setWidth(int width);
	void setLength(int length);
	void SetDimension(string dimension);
	void setTotalStock(int totalStock);
	void setPricePerMeter(float pricePerMeter);

	string toString();

	/*
	Timber& operator=(const Timber& copy);
	bool operator ==(const Timber& copy);

	void showInfo;
	void expand();
	*/
};

#endif // !TIMBERREGISTER_H
