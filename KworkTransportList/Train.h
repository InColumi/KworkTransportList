#pragma once
#include "Transport.h"
#include <iostream>

class Train :Transport
{
private:
	double _raiGage;

public:
	Train() : _raiGage(0), Transport() {}
	Train(double raiGage, std::string name, unsigned int countOfSeats, std::string dateOfBirth, std::string color, double weight)
		: Transport(name, countOfSeats, dateOfBirth, color, weight)
	{
		_raiGage = raiGage;
	}

	void ShowInfo()
	{
		std::cout << "Car\n";
		PrintInfo();
	}

	void Move()
	{
		std::cout << "я - поезд. ≈ду по рельсам с шириной колеи: " << _raiGage << " см.\n";
	}
};