#include "TimberRegister.h"
#include "TimberList.h"
#include <string>


Timber::Timber()
{
	width = -1;
	length = -1;
	dimension = "EMPTY";
	totalStock = -1;
	pricePerMeter = -1;
}

Timber::Timber(int width, int length, string dimension, string dimension2, int totalStock, float pricePerMeter)
{
	this->width = width;
	this->length = length;
	this->dimension = dimension;
	this->totalStock = totalStock;
	this->pricePerMeter = pricePerMeter;
}

Timber::~Timber()
{
}

Timber& Timber::operator=(const Timber& eeh)
{
	this->width = eeh.width;
	this->length = eeh.length;
	this->dimension = eeh.dimension;
	this->dimension2 = eeh.dimension2;
	this->totalStock = eeh.totalStock;
	this->pricePerMeter = eeh.pricePerMeter;
	return *this;
}

bool Timber::operator==(const Timber& eeh)
{
	return (this->width == eeh.width) && (this->length == eeh.length) && (this->dimension == eeh.dimension) && (this->dimension2 == eeh.dimension2) && (this->totalStock == eeh.totalStock) && (this->pricePerMeter == eeh.pricePerMeter);
}

bool Timber::operator<(const Timber& eeh)
{
	return (this->width * this->length == eeh.width * eeh.length);
}

int Timber::getWidth()
{
	return width;
}

int Timber::getLength()
{
	return length;
}

string Timber::getDimension()
{
	//For later use when removing a dimension
	return dimension;
}

string Timber::getDimension2()
{
	//For later use when removing a dimension
	return dimension2;
}

int Timber::getTotalStock()
{
	return totalStock;
}

float Timber::getPricePerMeter()
{
	return pricePerMeter;
}

void Timber::setWidth(int width)
{
	this->width = width;
}

void Timber::setLength(int length)
{
	this->length = length;
}

void Timber::SetDimension(string dimension)
{
	this->dimension = dimension;
}

void Timber::SetDimension2(string dimension2)
{
	this->dimension2 = dimension2;
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