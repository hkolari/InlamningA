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
	string dimension2;
	int totalStock;
	float pricePerMeter;

public:
	Timber();
	Timber(int width, int length, string dimension, string dimension2, int totalStock, float pricePerMeter);
	~Timber();

	Timber& operator=(const Timber& eeh);
	bool operator==(const Timber& eeh);
	bool operator<(const Timber& eeh);
	
	int getWidth();
	int getLength();
	string getDimension();
	string getDimension2();
	int getTotalStock();
	float getPricePerMeter();

	void setWidth(int width);
	void setLength(int length);
	void SetDimension(string dimension);
	void SetDimension2(string dimension2);
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
