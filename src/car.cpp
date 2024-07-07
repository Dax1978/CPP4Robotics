#include <src/car.h>
#include <iostream>

// Реализация метода вывода количества объектов
void count(Car& car)
{
    // Работа с русским текстом (но не работает...)
    setlocale(LC_ALL, "Russian");
    std::cout << "Count objects Car: " << car.get_count() << std::endl;
}

// Реализация функции перегрузки оператора вывода объекта Car
std::ostream& operator << (std::ostream& stream, const Car& car)
{
    stream << "Car: ";
    // stream << car.get_model();
    stream << car.get_model() << ", cylinders: " << car.get_cylinders() << ", power: " << car.get_power();
    return stream;
}

// Реализация функции перегрузки оператора ввода объекта Car
std::istream& operator >> (std::istream& in, Car& car)
{
    std::string model;
    int cylinders;
    int power;
    in >> model >> cylinders >> power;
    car.set_model(model);
    car.set_cylinders(cylinders);
    car.set_power(power);
    return in;
}