#pragma once
#include <string>
#include <iostream>
#include "TypeTransport.h"

class CargoTransport : public  TypeTransport
{
private:
	double _weightOfCargo;
public:
	CargoTransport() : _weightOfCargo(0), TypeTransport() {}
	CargoTransport(double weightOfCargo, Transport tansport, std::string pointA, std::string pointB) : TypeTransport(tansport, pointA, pointB)
	{
		_weightOfCargo = weightOfCargo;
	}

	void ShowInfo()
	{
		std::cout << "�������� ���\n";
		std::cout << "��� ����� �����: " << _weightOfCargo << " �.\n";
		PrintInfo();
	}
};