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
template <typename T>
struct Node
{
	T val;
	Node* next;

	Node(T _val) : val(_val), next(nullptr) {}
};

template <typename T>
struct List
{
	Node<T>* first;
	Node<T>* last;

	List() : first(nullptr), last(nullptr) {}

	bool is_empty()
	{
		return first == nullptr;
	}

	void push_back(T _val)
	{
		Node<T>* p = new Node<T>(_val);
		if (is_empty())
		{
			first = p;
			last = p;
			return;
		}
		last->next = p;
		last = p;
	}

	void Show()
	{
		if (is_empty()) return;
		Node<T>* p = first;
		while (p)
		{
			p->val.ShowInfo();
			p = p->next;
		}
		cout << endl;
	}
};

Transport inputTransport()
{
	string name;
	unsigned int countofSeats;
	string dateOfBirth;
	string color;
	double weight;
	cout << "������� ���������� � ����������:\n";
	cout << "������� ��������: ";
	cin >> name;
	cout << "������� ���-�� ���� ��� �������: ";
	cin >> countofSeats;
	cout << "������� ���� ������� ����(��:��:����): ";
	cin >> dateOfBirth;
	cout << "������� ����: ";
	cin >> color;
	cout << "������� ���: ";
	cin >> weight;

	return Transport(name, countofSeats, dateOfBirth, color, weight);
}

TypeTransport inputTypeTransport()
{
	string pointA;
	string pointB;
	cout << "������� ���������� � ���� ����������: ";
	cout << "������� ����� ��������: ";
	cin >> pointA;
	cout << "������� ����� ����������: ";
	cin >> pointB;
	Transport transport = inputTransport();

	return TypeTransport(transport, pointA, pointB);
}

Transport inputDifferentTransport()
{
	int numberCommand;
	string userInput;
	Transport transport;

	string name;
	unsigned int countofSeats;
	string dateOfBirth;
	string color;
	double weight;

	cout << "�������� ���������:\n";
	cout << "1) ������\n";
	cout << "2) �����\n";
	cout << "3) ������\n";
	cin >> userInput;
	try
	{
		numberCommand = stoi(userInput);
		cout << "������� ���������� � ����������:\n";
		cout << "������� ��������: ";
		cin >> name;
		cout << "������� ���-�� ���� ��� �������: ";
		cin >> countofSeats;
		cout << "������� ���� ������� ����(��:��:����): ";
		cin >> dateOfBirth;
		cout << "������� ����: ";
		cin >> color;
		cout << "������� ���: ";
		cin >> weight;
	}
	catch (const exception&)
	{
		numberCommand = 4;
	}

	switch (numberCommand)
	{
	case 1:
	{
		double mileage;
		cout << "�� ������� ������\n";
		cout << "������� ��, ������� ��� ������:";
		cin >> mileage;
		transport = Car(mileage, name, countofSeats, dateOfBirth, color, weight);
		break;
	}
	case 2:
	{
		double raiGage;
		cout << "�� ������� �����\n";
		cout << "������� ������ ����� �� ������� �� �����:";
		cin >> raiGage;
		transport = Train(raiGage, name, countofSeats, dateOfBirth, color, weight);
		break;
	}
	case 3:
	{
		double flightAltitude;
		cout << "�� ������� ������\n";
		cout << "������� ������, �� ������� �� ������:";
		cin >> flightAltitude;
		transport = Airplane(flightAltitude, name, countofSeats, dateOfBirth, color, weight);
		break;
	}
	default:
		cout << "����������� �������!\n";
		break;
	}
	return transport;
}

void ShowMenu()
{
	bool isExist = false;
	int numberCommand;
	string userInput;
	Transport transport;
	TypeTransport typeTransport;
	string pointA;
	string pointB;
	List<Transport> listTransport;
	List<TypeTransport> listTypeTransport;
	while (isExist == false)
	{
		cout << "�������� ��� ����������:\n";
		cout << "1) ��������\n";
		cout << "2) ������������\n";
		cout << "3) �������� ������ ����������\n";
		cout << "4) �������� ������ ����� ����������\n";
		cout << "5) ����� �� ���������\n";
		cin >> userInput;
		try
		{
			numberCommand = stoi(userInput);
		}
		catch (const exception&)
		{
			numberCommand = -1;
		}

		switch (numberCommand)
		{
		case 1:
		{
			cout << "������� ���������� � ���� ����������:\n";
			cout << "������� ����� ��������: ";
			cin >> pointA;
			cout << "������� ����� ����������: ";
			cin >> pointB;

			double weightOfCargo;
			cout << "�� ������� ��������\n";
			cout << "������� ��� ����� ��� ���������:";
			cin >> weightOfCargo;
			transport = inputDifferentTransport();
			typeTransport = CargoTransport(weightOfCargo, transport, pointA, pointB);
			listTransport.push_back(transport);
			listTypeTransport.push_back(typeTransport);
			break;
		}
		case 2:
		{
			cout << "������� ���������� � ���� ����������:\n";
			cout << "������� ����� ��������: ";
			cin >> pointA;
			cout << "������� ����� ����������: ";
			cin >> pointB;

			unsigned int countPassengers;
			cout << "�� ������� ������������\n";
			cout << "������� ���-�� ����������:";
			cin >> countPassengers;
			transport = inputDifferentTransport();
			typeTransport = PassengerTransport(countPassengers, transport, pointA, pointB);
			listTransport.push_back(transport);
			listTypeTransport.push_back(typeTransport);
			break;
		}
		case 3:
		{
			listTransport.Show();
			break;
		}
		case 4:
		{
			listTypeTransport.Show();
			break;
		}
		case 5:
		{
			isExist = true;
			break;
		}
		default:
			cout << "����������� �������!\n";
			break;
		}
	}
	cout << "��������� ��������� ���� ������.\n";
}

int main()
{
	setlocale(LC_ALL, "rus");
	ShowMenu();
	Transport transport;
	Airplane airplane(8, "Bee", 5, "08:12:1987", "White", 10);
	Train train(80, "Flesh", 5, "08:12:1967", "Broun", 1.2);
	Car car(123.3, "Ford", 5, "12:12:2020", "Red", 1.2);

	system("pause");
	return 0;
}