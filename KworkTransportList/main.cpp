#include <string>
#include <iostream>
#include "Transport.h"
#include "Car.h"
#include "Train.h"
#include "Airplane.h"
#include "TypeTransport.h"

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

class Cargo: public  TypeTransport
{
private:
	double _weightOfCargo;
public:
	Cargo() : _weightOfCargo(0), TypeTransport() {}
	Cargo(double weightOfCargo, Transport tansport, std::string pointA, std::string pointB) : TypeTransport(tansport, pointA, pointB)
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
	std::cout << '\n';

	Cargo cargo(10, train, "������", "�����");
	cargo.ShowInfo();
	system("pause");
	return 0;
}