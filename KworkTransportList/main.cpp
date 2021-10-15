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

Transport inputTransport()
{
	std::string name;
	unsigned int countofSeats;
	std::string dateOfBirth;
	std::string color;
	double weight;
	std::cout << "Введите информацию о транспорте:\n";
	std::cout << "Введите название: ";
	cin >> name;
	std::cout << "Введите кол-во мест для посадки: ";
	cin >> countofSeats;
	std::cout << "Введите дату выпуска вида(дд:мм:гггг): ";
	cin >> dateOfBirth;
	std::cout << "Введите цвет: ";
	cin >> color;
	std::cout << "Введите вес: ";
	cin >> weight;

	return Transport(name, countofSeats, dateOfBirth, color, weight);
}

TypeTransport inputTypeTransport()
{
	std::string pointA;
	std::string pointB;
	std::cout << "Введите информацию о типе транспорта: ";
	std::cout << "Введите пункт отправки: ";
	cin >> pointA;
	std::cout << "Введите пункт назначения: ";
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

	std::cout << "Выберете транспорт:\n";
	std::cout << "1) Машина\n";
	std::cout << "2) Поезд\n";
	std::cout << "3) Самолёт\n";
	cin >> userInput;
	try
	{
		std::cout << "Введите информацию о транспорте:\n";
		std::cout << "Введите название: ";
		cin >> name;
		std::cout << "Введите кол-во мест для посадки: ";
		cin >> countofSeats;
		std::cout << "Введите дату выпуска вида(дд:мм:гггг): ";
		cin >> dateOfBirth;
		std::cout << "Введите цвет: ";
		cin >> color;
		std::cout << "Введите вес: ";
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
		std::cout << "Вы выбрали Машину\n";
		std::cout << "Введите км, которое она прошла:";
		cin >> mileage;
		transport = Car(mileage, name, countofSeats, dateOfBirth, color, weight);
		break;
	}
	case 2:
	{
		double raiGage;
		std::cout << "Вы выбрали Поезд\n";
		std::cout << "Введите ширину рельс по которым он ездит:";
		cin >> raiGage;
		transport = Train(raiGage, name, countofSeats, dateOfBirth, color, weight);
		break;
	}
	case 3:
	{
		double flightAltitude;
		std::cout << "Вы выбрали Самолёт\n";
		std::cout << "Введите высоту, на которой он летает:";
		cin >> flightAltitude;
		transport = Airplane(flightAltitude, name, countofSeats, dateOfBirth, color, weight);
		break;
	}
	default:
		std::cout << "Неизвестная команда!\n";
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
		std::cout << "Выберете тип транспорта:\n";
		std::cout << "1) Грузовой\n";
		std::cout << "2) Пассажирский\n";
		std::cout << "3) Выход из программы\n";
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
			std::cout << "Вы выбрали Грузовой\n";
			break;
		}
		case 2:
		{
			std::cout << "Вы выбрали Пассажирский\n";
			break;
		}
		case 3:
		{
			isExist = true;
			break;
		}
		default:
			std::cout << "Неизвестная команда!\n";
			break;
		}
	}
	std::cout << "Программа закончила свою работу.\n";
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

	CargoTransport cargo(10, train, "Россия", "Китай");
	cargo.ShowInfo();
	std::cout << '\n';

	PassengerTransport passengerTransport(10, train, "Россия", "Китай");
	passengerTransport.ShowInfo();
	system("pause");
	return 0;
}