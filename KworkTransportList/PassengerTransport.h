#pragma once
#include <string>
#include <iostream>
#include "TypeTransport.h"

class PassengerTransport : public TypeTransport
{
private:
	unsigned int _countPassengers;
public:
	PassengerTransport() : _countPassengers(0), TypeTransport() {}
	PassengerTransport(int countPassengers, Transport tansport, std::string pointA, std::string pointB) : TypeTransport(tansport, pointA, pointB)
	{
		_countPassengers = countPassengers;
	}

	void ShowInfo()
	{
		std::cout << "Пассажирский тип\n";
		std::cout << "Кол-во пассажиров: " << _countPassengers << " ч.\n";
		PrintInfo();
	}
};