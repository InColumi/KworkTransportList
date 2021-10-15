#pragma once
#include "Transport.h"
#include <iostream>

class Airplane : public Transport
{
private:
	double _flightAltitude;

public:
	Airplane() : _flightAltitude(), Transport() {}
	Airplane(double flightAltitude, std::string name, unsigned int countOfSeats, std::string dateOfBirth, std::string color, double weight)
		: Transport(name, countOfSeats, dateOfBirth, color, weight)
	{
		_flightAltitude = flightAltitude;
	}

	void ShowInfo()
	{
		std::cout << "Airplane\n";
		PrintInfo();
	}

	void Move()
	{
		std::cout << "Я - самолёт. Лечу на высоте: " << _flightAltitude << " км\n";
	}
};
