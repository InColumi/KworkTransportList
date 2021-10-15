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
		std::cout << "� - �����. ��� �� ������� � ������� �����: " << _raiGage << " ��.\n";
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

	Train train(80, "flesh", 5, "08:12:1967", "Broun", 1.2);
	train.ShowInfo();
	train.Move();
	system("pause");
	return 0;
}