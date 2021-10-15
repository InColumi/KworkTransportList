#include <iostream>
#include <string>

#include "Transport.h"
#include "Car.h"
#include "Train.h"
#include "Airplane.h"
#include "TypeTransport.h"
#include "Cargo.h"
#include "PassengerTransport.h"

/*
��� �������:  ������� ������� ����� ���������� � ����������� �� ���� ������ ������������, ������, ��������.
������� ������� ����� ���� � ����������� �� ���� ������ ��������� � �������������.
�� ������ ���� ������� ������� ����� ��������� ������� � �������������� �������������� ������������.

��� ������ ����� �������, �������, �������� ?
���� ������ ���������
1) � ��� ���� ��������
2) ���������e �����
3) ���� �������
4) ����
5) ���
6) .... � ������
������
1) ��������� ������� ����
2) ����� �����������
3) ������ ��������

��� � ��� ������� ?
������
	1) ���� �� ������
�����
	1) ���� �� �������
������
	1) �����

��� ������ � ���������� � ������������� ���������� ?
1) ����� �����������
2) ����� ����������
3) ����������� ���������� ����� �� ��������
*/

using namespace std;

Transport inputTransport()
{
	std::string name;
	unsigned int countofSeats;
	std::string dateOfBirth;
	std::string color;
	double weight;
	std::cout << "������� ���������� � ����������:\n";
	std::cout << "������� ��������: ";
	cin >> name;
	std::cout << "������� ���-�� ���� ��� �������: ";
	cin >> countofSeats;
	std::cout << "������� ���� ������� ����(��:��:����): ";
	cin >> dateOfBirth;
	std::cout << "������� ����: ";
	cin >> color;
	std::cout << "������� ���: ";
	cin >> weight;

	return Transport(name, countofSeats, dateOfBirth, color, weight);
}

TypeTransport inputTypeTransport()
{
	std::string pointA;
	std::string pointB;
	std::cout << "������� ���������� � ���� ����������: ";
	std::cout << "������� ����� ��������: ";
	cin >> pointA;
	std::cout << "������� ����� ����������: ";
	cin >> pointB;
	Transport transport = inputTransport();

	return TypeTransport(transport, pointA, pointB);
}

Transport inputDifferentTransport()
{
	int numberCommand;
	std::string userInput;
	Transport transport;

	std::string name;
	unsigned int countofSeats;
	std::string dateOfBirth;
	std::string color;
	double weight;

	std::cout << "�������� ���������:\n";
	std::cout << "1) ������\n";
	std::cout << "2) �����\n";
	std::cout << "3) ������\n";
	cin >> userInput;
	try
	{
		std::cout << "������� ���������� � ����������:\n";
		std::cout << "������� ��������: ";
		cin >> name;
		std::cout << "������� ���-�� ���� ��� �������: ";
		cin >> countofSeats;
		std::cout << "������� ���� ������� ����(��:��:����): ";
		cin >> dateOfBirth;
		std::cout << "������� ����: ";
		cin >> color;
		std::cout << "������� ���: ";
		cin >> weight;
	}
	catch (const std::exception&)
	{
		numberCommand = 4;
	}

	switch (numberCommand)
	{
	case 1:
	{
		double mileage;
		std::cout << "�� ������� ������\n";
		std::cout << "������� ��, ������� ��� ������:";
		cin >> mileage;
		transport = Car(mileage, name, countofSeats, dateOfBirth, color, weight);
		break;
	}
	case 2:
	{
		double raiGage;
		std::cout << "�� ������� �����\n";
		std::cout << "������� ������ ����� �� ������� �� �����:";
		cin >> raiGage;
		transport = Train(raiGage, name, countofSeats, dateOfBirth, color, weight);
		break;
	}
	case 3:
	{
		double flightAltitude;
		std::cout << "�� ������� ������\n";
		std::cout << "������� ������, �� ������� �� ������:";
		cin >> flightAltitude;
		transport = Airplane(flightAltitude, name, countofSeats, dateOfBirth, color, weight);
		break;
	}
	default:
		std::cout << "����������� �������!\n";
		break;
	}
	return transport;
}

void ShowMenu()
{
	bool isExist = false;
	int numberCommand;
	std::string userInput;
	while (isExist == false)
	{
		std::cout << "�������� ��� ����������:\n";
		std::cout << "1) ��������\n";
		std::cout << "2) ������������\n";
		std::cout << "3) ����� �� ���������\n";
		cin >> userInput;
		try
		{
			numberCommand = stoi(userInput);
		}
		catch (const std::exception&)
		{
			numberCommand = 4;
		}

		switch (numberCommand)
		{
		case 1:
		{
			std::cout << "�� ������� ��������\n";
			break;
		}
		case 2:
		{
			std::cout << "�� ������� ������������\n";
			break;
		}
		case 3:
		{
			isExist = true;
			break;
		}
		default:
			std::cout << "����������� �������!\n";
			break;
		}
	}
	std::cout << "��������� ��������� ���� ������.\n";
}

int main()
{
	setlocale(LC_ALL, "rus");
	ShowMenu();
	Transport transport = inputTransport();
	transport.ShowInfo();
	transport.Move();
	std::cout << '\n';

	Car car(123.3, "Ford", 5, "12:12:2020", "Red", 1.2);
	car.ShowInfo();
	car.Move();
	std::cout << '\n';

	Train train(80, "Flesh", 5, "08:12:1967", "Broun", 1.2);
	train.ShowInfo();
	train.Move();
	std::cout << '\n';

	Airplane airplane(8, "Bee", 5, "08:12:1987", "White", 10);
	airplane.ShowInfo();
	airplane.Move();
	std::cout << '\n';

	TypeTransport typeTransport;
	typeTransport.ShowInfo();
	std::cout << '\n';

	CargoTransport cargo(10, train, "������", "�����");
	cargo.ShowInfo();
	std::cout << '\n';

	PassengerTransport passengerTransport(10, train, "������", "�����");
	passengerTransport.ShowInfo();
	system("pause");
	return 0;
}