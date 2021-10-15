#include <string>
#include <iostream>
#include "Transport.h"
#include "Car.h"
#include "Train.h"
#include "Airplane.h"

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

class TypeTransport
{
private:
	std::string _pointA;
	std::string _pointB;
	Transport _transport;

public:
	TypeTransport(): _transport(), _pointA("default point A"), _pointB("default point B") {}
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
		std::cout << "������ ��: " << _pointA << '\n';
		std::cout << "��� �: " << _pointB << '\n';
		_transport.ShowInfo();
	}
};

int main()
{
	setlocale(LC_ALL, "rus");
	Transport transport;

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
	system("pause");
	return 0;
}