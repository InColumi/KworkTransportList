#include <string>
#include <iostream>
#include "Transport.h"
#include "Car.h"
#include "Train.h"
#include "Airplane.h"
#include "TypeTransport.h"
#include "Cargo.h"

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
class PassengerTransport : TypeTransport
{
private:
	unsigned int _countPassengers;
public:
	PassengerTransport() : _countPassengers(0), TypeTransport() {}
	PassengerTransport(int countPassengers, Transport tansport, std::string pointA, std::string pointB) : TypeTransport(tansport, pointA, pointB)
	{
		_countPassengers = countPassengers;
	}

	void ShowInfo()
	{
		std::cout << "Пассажирский тип\n";
		std::cout << "Кол-во пассажиров: " << _countPassengers << " т.\n";
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

	CargoTransport cargo(10, train, "Россия", "Китай");
	cargo.ShowInfo();
	std::cout << '\n';

	PassengerTransport passengerTransport;
	passengerTransport.ShowInfo();
	system("pause");
	return 0;
}