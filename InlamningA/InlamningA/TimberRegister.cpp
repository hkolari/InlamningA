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

Timber::Timber(string dimension,  int totalStock, float pricePerMeter)
{
	this->dimension = dimension;
	this->totalStock = totalStock;
	this->pricePerMeter = pricePerMeter;
}

Timber::~Timber()
{
}

bool Timber::operator==(const Timber& eeh) const
{
	return (this->dimension == eeh.dimension);
}

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

string Timber::toString() const
{
	return dimension + " meter | " + to_string(totalStock) + " meters in stock | " + to_string(pricePerMeter) + "sek per meter";
}

string Timber::toFile() const
{
	return dimension + "\n" + to_string(totalStock) + "\n" + to_string(pricePerMeter);
}