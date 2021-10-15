#pragma once
#include <iostream>
#include "Transport.h"

class Car : public Transport
{
private:
	double _mileage;

public:
	Car() : _mileage(), Transport() {}
	Car(double mileage, std::string name, unsigned int countOfSeats, std::string dateOfBirth, std::string color, double weight)
		: Transport(name, countOfSeats, dateOfBirth, color, weight)
	{
		_mileage = mileage;
	}

	void ShowInfo()
	{
		std::cout << "Car\n";
		PrintInfo();
	}

	void Move()
	{
		std::cout << "Я - машина. Еду по дороге уже " << _mileage << " км\n";
	}
};
