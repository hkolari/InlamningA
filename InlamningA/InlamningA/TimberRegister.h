//Written by Henry Kolari (heko16 - 199712038430)

#ifndef TIMBERREGISTER_H
#define TIMBERREGISTER_H
#include <string>

using namespace std;

class Timber
{
private:
	string dimension;
	int totalStock;
	float pricePerMeter;

public:
	Timber();
	Timber(string dimension, int totalStock, float pricePerMeter);
	~Timber();

	bool operator==(const Timber& eeh) const;
	
	string getDimension()const;
	int getTotalStock()const;
	float getPricePerMeter()const;

	void SetDimension(string dimension);
	void setTotalStock(int totalStock);
	void setPricePerMeter(float pricePerMeter);

	string toString() const;
	string toFile() const;
};

#endif // !TIMBERREGISTER_H
