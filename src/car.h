#pragma once // Исключение множественного включения библиотек

#include <string>
#include <iostream>

class Car
{
    // Дружественная функция вывода количества объектов
    friend void count(Car &);

private:
    // Приватные атрибуты согласно задания
    std::string model_;
    int cylinders_;
    int power_;
    static inline unsigned count_{}; // статическое поле - счетчик объектов Car

public:
    // Конструктор Car, при создании нового объекта увеличиваем счетчик
    Car() { ++count_; };
    Car(std::string model, int cylinders, int power) : model_(model), cylinders_(cylinders), power_(power) { ++count_; };

    // Деструктор Car, при уничтожении объекта уменьшаем счетчик
    ~Car() { --count_; };

    // Гетеры и сетеры приватных атрибутов
    void set_model(std::string model) { model_ = model; };
    std::string get_model() const noexcept { return model_; };
    void set_cylinders(int cylinders) { cylinders_ = cylinders; };
    int get_cylinders() const noexcept { return cylinders_; };
    void set_power(int power) { power_ = power; };
    int get_power() const noexcept { return power_; };

    // Публичный метод получения количества объектов
    unsigned get_count() { return count_; };
};

// Объявление перегрузки опереаторов ввода / вывода
std::ostream &operator<<(std::ostream &stream, const Car &car);
std::istream &operator>>(std::istream &in, Car &car);
