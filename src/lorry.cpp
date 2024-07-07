#include <src/lorry.h>
#include <iostream>

// Файл реализации функций перегрузки операторов ввода и вывода

std::ostream &operator<<(std::ostream &stream, const Lorry &lorry)
{
    stream << "Lorry: ";
    stream << lorry.get_model() << ", cylinders: " << lorry.get_cylinders() << ", power: " << lorry.get_power() << ", capacity: " << lorry.get_capacity();
    return stream;
};

std::istream &operator>>(std::istream &in, Lorry &lorry)
{
    std::string model;
    int cylinders;
    int power;
    int capacity;
    in >> model >> cylinders >> power >> capacity;
    lorry.set_model(model);
    lorry.set_cylinders(cylinders);
    lorry.set_power(power);
    lorry.set_capacity(capacity);
    return in;
};