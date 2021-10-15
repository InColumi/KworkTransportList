#include <string>
#include <iostream>
#include "Transport.h"
#include "Car.h"
#include "Train.h"
#include "Airplane.h"
#include "TypeTransport.h"

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
		std::cout << "Грузовой тип\n";
		std::cout << "Вес моего груза: " << _weightOfCargo << " т.\n";
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

	Cargo cargo(10, train, "Россия", "Китай");
	cargo.ShowInfo();
	system("pause");
	return 0;
}