#pragma once
#include "Transport.h"
#include <iostream>

class TypeTransport
{
private:
	std::string _pointA;
	std::string _pointB;
	Transport _transport;

public:
	TypeTransport() : _transport(), _pointA("default point A"), _pointB("default point B") {}
	TypeTransport(Transport tansport, std::string pointA, std::string pointB)
	{
		_pointA = pointA;
		_pointB = pointB;
		_transport = tansport;
	}

	virtual void ShowInfo()
	{
		std::cout << "TypeTransport\n";
		PrintInfo();
	}

protected:

	void PrintInfo()
	{
		std::cout << "Выехал из: " << _pointA << '\n';
		std::cout << "Еду в: " << _pointB << '\n';
		_transport.ShowInfo();
	}
};