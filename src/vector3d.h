#include <memory>


using namespace std;

class Vector3D {
private:
    // unique_ptr - не даст создать копию!
    // std::unique_ptr<double[]> coords = std::make_unique<double[]>(3);
    std::shared_ptr<double[]> coords = std::make_shared<double[]>(3);

public:
    Vector3D();
    Vector3D(double x, double y, double z);
    // Правило 3-х!!! Деструктор, Конструктор копирования, Оператор присваивания
    // Деструктор
    ~Vector3D();
    // Конструктор копирования
    Vector3D(const Vector3D& v);
    // Перегрузка оператора присваивания
    Vector3D& operator=(const Vector3D& v);
    // Правило 5-и: к 3 еще 2
    // Конструктор перемещения
    Vector3D(Vector3D&& v);
    // Перегрузка оператора присваивания по перемещению
    Vector3D& operator=(Vector3D&& v);

    void print();
    std::shared_ptr<double[]>& getCoords();
};




// template<typename T>
// class Vector3D
// {
// private:    
//     // Динамический массив из 3 чисел
//     // double* coords{new double[3]};
//     // std::unique_ptr<T[]> coords = std::make_unique<T[]>(3);
//     std::unique_ptr<T[]> coords = std::make_unique<T[]>(3);
//     // std::unique_ptr<T[]> coords(new T[3]);
//     // Точность при сравнении векторов
//     const float EPSILON = 0.001l;

// public:
    // Обычные конструкторы
    // Vector3D();	
	// Vector3D(T x, T y, T z);
    // Обычный конструктор копирования
    // Vector3D(const Vector3D& v);
    // Конструктор перемещения
    // Vector3D(Vector3D&& moved);

    // Присваиваение векторов
	// Vector3D& operator= (const Vector3D& v);
    // Величина вектора (от magnitude - величина)
	// double magnitude();
    // Нормализация вектора
	// void normalize();

    // Деструктор
    // ~Vector3D();

    // Вывод вектора
    // void print();
// };