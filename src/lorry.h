#include "src/car.h"

// Класс реализации грузовика, у которого добавляется характеристика грузоподъемности
class Lorry : public Car
{
private:
    int capacity_;              // Приватный атрибут хранения грузоподъемности

public:
    // Конструктор грузовика (можно было конечно сделать и 2 конструктора: без исходных атрибутов, но принцип такой же как в классе Car)
    Lorry(std::string model, int cylinders, int power, int capacity): Car(model, cylinders, power) { this->capacity_ = capacity; };
    
    // Сетер и гетер для приватного атрибута
    void set_capacity(int capacity) { capacity_ = capacity; };
    int get_capacity() const noexcept { return capacity_; };

};

// Объявление перегрузки опереаторов ввода / вывода
std::ostream &operator<<(std::ostream &stream, const Lorry &lorry);
std::istream &operator>>(std::istream &in, Lorry &lorry);