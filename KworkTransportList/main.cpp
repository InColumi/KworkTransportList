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
Сам вариант:  Создать базовый класс «Транспорт» и производные от него классы «Автомобиль», «Поезд», «Самолет».
Создать базовый класс «Тип» и производные от него классы «Грузовой» и «Пассажирский».
На основе этих классов создать набор различных классов с использованием множественного наследования.

Что общего между машиной, поездом, самолётом ?
Поля класса Транспорт
1) у них есть название
2) посадочныe места
3) дата выпуска
4) цвет
5) вес
6) .... и хватит
Методы
1) получение каждого поля
2) метод перемещение
3) способ заправки

Что у них разного ?
Машина
	1) едет по дороге
Поезд
	1) едет по рельсам
Самолёт
	1) летит

Что общего у Грузгового и Пассажирского транспорта ?
1) пункт отправления
2) пункт назначение
3) транспортом собственно каким он является
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
	cout << "Введите информацию о транспорте:\n";
	cout << "Введите название: ";
	cin >> name;
	cout << "Введите кол-во мест для посадки: ";
	cin >> countofSeats;
	cout << "Введите дату выпуска вида(дд:мм:гггг): ";
	cin >> dateOfBirth;
	cout << "Введите цвет: ";
	cin >> color;
	cout << "Введите вес: ";
	cin >> weight;

	return Transport(name, countofSeats, dateOfBirth, color, weight);
}

TypeTransport inputTypeTransport()
{
	string pointA;
	string pointB;
	cout << "Введите информацию о типе транспорта: ";
	cout << "Введите пункт отправки: ";
	cin >> pointA;
	cout << "Введите пункт назначения: ";
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

	cout << "Выберете транспорт:\n";
	cout << "1) Машина\n";
	cout << "2) Поезд\n";
	cout << "3) Самолёт\n";
	cin >> userInput;
	try
	{
		numberCommand = stoi(userInput);
		cout << "Введите информацию о транспорте:\n";
		cout << "Введите название: ";
		cin >> name;
		cout << "Введите кол-во мест для посадки: ";
		cin >> countofSeats;
		cout << "Введите дату выпуска вида(дд:мм:гггг): ";
		cin >> dateOfBirth;
		cout << "Введите цвет: ";
		cin >> color;
		cout << "Введите вес: ";
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
		cout << "Вы выбрали Машину\n";
		cout << "Введите км, которое она прошла:";
		cin >> mileage;
		transport = Car(mileage, name, countofSeats, dateOfBirth, color, weight);
		break;
	}
	case 2:
	{
		double raiGage;
		cout << "Вы выбрали Поезд\n";
		cout << "Введите ширину рельс по которым он ездит:";
		cin >> raiGage;
		transport = Train(raiGage, name, countofSeats, dateOfBirth, color, weight);
		break;
	}
	case 3:
	{
		double flightAltitude;
		cout << "Вы выбрали Самолёт\n";
		cout << "Введите высоту, на которой он летает:";
		cin >> flightAltitude;
		transport = Airplane(flightAltitude, name, countofSeats, dateOfBirth, color, weight);
		break;
	}
	default:
		cout << "Неизвестная команда!\n";
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
		cout << "Выберете тип транспорта:\n";
		cout << "1) Грузовой\n";
		cout << "2) Пассажирский\n";
		cout << "3) Показать список транспорта\n";
		cout << "4) Показать список видов транспорта\n";
		cout << "5) Выход из программы\n";
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
			cout << "Введите информацию о типе транспорта:\n";
			cout << "Введите пункт отправки: ";
			cin >> pointA;
			cout << "Введите пункт назначения: ";
			cin >> pointB;

			double weightOfCargo;
			cout << "Вы выбрали Грузовой\n";
			cout << "Введите вес груза для перевозки:";
			cin >> weightOfCargo;
			transport = inputDifferentTransport();
			typeTransport = CargoTransport(weightOfCargo, transport, pointA, pointB);
			listTransport.push_back(transport);
			listTypeTransport.push_back(typeTransport);
			break;
		}
		case 2:
		{
			cout << "Введите информацию о типе транспорта:\n";
			cout << "Введите пункт отправки: ";
			cin >> pointA;
			cout << "Введите пункт назначения: ";
			cin >> pointB;

			unsigned int countPassengers;
			cout << "Вы выбрали Пассажирский\n";
			cout << "Введите кол-во пассажиров:";
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
			cout << "Неизвестная команда!\n";
			break;
		}
	}
	cout << "Программа закончила свою работу.\n";
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