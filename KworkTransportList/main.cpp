#include <string>
#include <iostream>
#include "Transport.h"
#include "Car.h"
#include "Train.h"

/*
��� �������:  ������� ������� ����� ���������� � ����������� �� ���� ������ ������������, ������, ��������.
������� ������� ����� ���� � ����������� �� ���� ������ ��������� � �������������.
�� ������ ���� ������� ������� ����� ��������� ������� � �������������� �������������� ������������.

��� ������ ����� �������, �������, �������� ?
���� ������ ���������
1) � ��� ���� ��������
2) ���������� ����
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
	2) ������������ ��� ������, ��� ���� ������
�����
	1) ���� �� �������
	2) ������������ ��� ������, ��� ���� ������
������
	1) �����
	2) ������������ � ���������
*/

using namespace std;

class Airplane : Transport
{
private:
	double _flightAltitude;

public:
	Airplane(): _flightAltitude(), Transport(){}
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
		std::cout << "� - ������. ���� �� ������: " << _flightAltitude << " ��\n";
	}
};

int main()
{
	setlocale(LC_ALL, "rus");
	Transport transport;

	transport.ShowInfo();
	transport.Move();

	Car car(123.3, "Ford", 5, "12:12:2020", "Red", 1.2);
	car.ShowInfo();
	car.Move();

	Train train(80, "Flesh", 5, "08:12:1967", "Broun", 1.2);
	train.ShowInfo();
	train.Move();

	Airplane airplane(8, "Bee", 5, "08:12:1987", "White", 10);
	airplane.ShowInfo();
	airplane.Move();

	system("pause");
	return 0;
}