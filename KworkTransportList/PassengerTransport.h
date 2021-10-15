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
		std::cout << "������������ ���\n";
		std::cout << "���-�� ����������: " << _countPassengers << " �.\n";
		PrintInfo();
	}
};