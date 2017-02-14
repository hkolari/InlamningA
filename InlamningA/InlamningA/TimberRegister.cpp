//Written by Henry Kolari (heko16 - 199712038430)

#include "TimberRegister.h"
#include "TimberList.h"
#include <string>

using namespace std;

Timber::Timber()
{
	dimension = "EMPTY";
	totalStock = -1;
	pricePerMeter = -1;
}
/*
Timber::Timber(Timber &copy)
{
	this->dimension = copy.dimension;
	this->totalStock = copy.totalStock;
	this->pricePerMeter = copy.pricePerMeter;
}
*/

Timber::Timber(string dimension,  int totalStock, float pricePerMeter)
{
	this->dimension = dimension;
	this->totalStock = totalStock;
	this->pricePerMeter = pricePerMeter;
}

Timber::~Timber()
{
}
/*
Timber& Timber::operator=(const Timber& eeh)
{
	this->dimension = eeh.dimension;
	this->totalStock = eeh.totalStock;
	this->pricePerMeter = eeh.pricePerMeter;
	return *this;
}
*/

bool Timber::operator==(const Timber& eeh)
{
	return (this->dimension == eeh.dimension);
}

/*
bool Timber::operator<(const Timber& eeh)
{
	
}
*/

string Timber::getDimension() const
{
	return dimension;
}

int Timber::getTotalStock() const
{
	return totalStock;
}

float Timber::getPricePerMeter() const
{
	return pricePerMeter;
}

void Timber::SetDimension(string dimension)
{
	this->dimension = dimension;
}

void Timber::setTotalStock(int totalStock)
{
	this->totalStock = totalStock;
}

void Timber::setPricePerMeter(float pricePerMeter)
{
	this->pricePerMeter = pricePerMeter;
}

string Timber::toString() {
	return dimension + " meter | " + to_string(totalStock) + " meters in stock | " + to_string(pricePerMeter) + "sek per meter";
}