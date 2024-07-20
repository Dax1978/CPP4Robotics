#pragma once
#include <pybind11/pybind11.h>
#include <string>
#include <iostream>

using std::cout;
using std::endl;

namespace py = pybind11;


int add(const int &, const int &);

class Pet {
public:
    Pet(const std::string &name) : name(name) { }
    void setName(const std::string &name_) { name = name_; }
    const std::string &getName() const { return name; }

private:
    std::string name;
};

class Vector3D
{
private:
    union
	{
		struct
		{
			double x, y, z;
		};
		double v[3];
	};
    double EPSILON = 0.001l;

public:
    Vector3D() : x(0), y(0), z(0) {}
    Vector3D(Vector3D& other) : x(other.x), y(other.y), z(other.z) {}           // Конструктор копирования
    Vector3D(Vector3D&& moved) { x=moved.x; y=moved.y; z=moved.z; }             // Конструктор перемещения
    Vector3D(double _x, double _y, double _z) : x(_x),y(_y),z(_z){}
    void setX(double x) { this->x = x; };
    void setY(double y) { this->y = y; };
    void setZ(double z) { this->z = z; };
    double getX() { return this->x; };
    double getY() { return this->y; };
    double getZ() { return this->z; };
     // Строка с координатами вектора
    std::string toString() const { return "[" + std::to_string(x) + ", " + std::to_string(y) + ", " + std::to_string(z) + "]"; };
    // Присваивание векторов
    Vector3D& operator= (Vector3D& other) { x=other.x; y=other.y; z=other.z; return *this; };
    // Сравнение векторов
	bool operator== (Vector3D& other);
    // Величина вектора (magnitude - величина)
    double magnitude() { return std::sqrt(x * x + y * y + z * z); };
    // Отрицательный вектор (унарная операция!!!)
    Vector3D& operator- () { x=-x; y=-y; z=-z; return *this; };
    // Сложение с присвоением
    Vector3D& operator-= (Vector3D& other) { x-=other.x; y-=other.y; z-=other.z; return *this; };
    // Вычитание с присвоением
    Vector3D& operator+= (Vector3D& other) { x+=other.x; y+=other.y; z+=other.z; return *this; };
    // Умножение вектора на скаляр
    Vector3D& operator*= (double& a) { x*=a; y*=a; z*=a; return *this; };
    // Деление вектора на скаляр
    Vector3D& operator/= (double& a) { x/=a; y/=a; z/=a; return *this; };
    // Скалярное умножение векторов
    double operator* (Vector3D& other) { return x*other.x + y*other.y + z*other.z; };
    // Векторное произведение векторов
    Vector3D cross(const Vector3D& other) const { return Vector3D(y*other.z - z*other.y, z*other.x - x*other.z, x*other.y - y*other.x); };
    // Сложение векторов
    Vector3D sum(const Vector3D& other) const { return Vector3D(x+other.x, y+other.y, z+other.z); };
    // Вычитание векторов
    Vector3D sub(const Vector3D& other) const { return Vector3D(x-other.x, y-other.y, z-other.z); };
    // Нормализация вектора
    Vector3D& normalize();
};