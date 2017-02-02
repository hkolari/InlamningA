#include "TimberRegister.h"
#include "TimberList.h"
#include <string>


Timber::Timber()
{
	width = -1;
	length = -1;
	totalStock = -1;
	pricePerMeter = -1;
}

Timber::Timber(int width, int length, int totalStock, float pricePerMeter)
{
	this->width = width;
	this->length = length;
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
	this->totalStock = eeh.totalStock;
	this->getPricePerMeter = eeh.pricePerMeter;
	return *this;
}

bool Timber::operator==(const Timber& eeh)
{
	return (this->width == eeh.width) && (this->length == eeh.length) && (this->totalStock == eeh.totalStock) && (this->pricePerMeter == eeh.pricePerMeter);
}

int Timber::getWidth()
{
	return width;
}

int Timber::getLength()
{
	return length;
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

void Timber::setTotalStock(int totalStock)
{
	this->totalStock = totalStock;
}

void Timber::setPricePerMeter(float pricePerMeter)
{
	this->pricePerMeter = pricePerMeter;
}

string Timber::toString() {
	return to_string(width) + " " + to_string(length) + " " + to_string(totalStock) + " " + to_string(pricePerMeter);
}