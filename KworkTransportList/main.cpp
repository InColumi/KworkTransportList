#include <string>
#include <iostream>
#include "Transport.h"
#include "Car.h"
#include "Train.h"

/*
Сам вариант:  Создать базовый класс «Транспорт» и производные от него классы «Автомобиль», «Поезд», «Самолет».
Создать базовый класс «Тип» и производные от него классы «Грузовой» и «Пассажирский».
На основе этих классов создать набор различных классов с использованием множественного наследования.

Что общего между машиной, поездом, самолётом ?
Поля класса Транспорт
1) у них есть название
2) посадочных мест
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
	2) заправляется где угодно, где есть бензин
Поезд
	1) едет по рельсам
	2) заправляется где угодно, где есть бензин
Самолёт
	1) летит
	2) заправляется в аэропорту
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
		std::cout << "Я - самолёт. Лечу на высоте: " << _flightAltitude << " км\n";
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