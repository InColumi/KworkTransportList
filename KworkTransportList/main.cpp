#include <string>
#include <iostream>
#include "Transport.h"
#include "Car.h"
#include "Train.h"
#include "Airplane.h"

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
		std::cout << "Выехал из: " << _pointA << '\n';
		std::cout << "Еду в: " << _pointB << '\n';
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