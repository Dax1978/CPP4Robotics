#include "vector3d.h"
#include <iostream>
#include <cmath>

Vector3D::Vector3D()
{
    this->coords[0] = 0.l;
    this->coords[1] = 0.l;
    this->coords[2] = 0.l;
    std::cout << "Constructor" << std::endl;
}

Vector3D::Vector3D(double x, double y, double z)
{
    this->coords[0] = x;
    this->coords[1] = y;
    this->coords[2] = z;
    std::cout << "Constructor" << std::endl;
}

Vector3D::~Vector3D()
{
    // Так как это smart-pointer, то уничтожать массив координат coords не требуется
    // (я бы сказал компилятор даже не даст это написать)
    std::cout << "Destructor" << std::endl;
}

Vector3D::Vector3D(const Vector3D& v)
{
    this->coords[0] = v.coords[0];
    this->coords[1] = v.coords[1];
    this->coords[2] = v.coords[2];
    std::cout << "Constructor copy" << std::endl;
}

Vector3D &Vector3D::operator=(const Vector3D& v)
{
    if (this == &v) return *this;
    coords = v.coords;
    std::cout << "= copy" << std::endl;
    return *this;
}

Vector3D::Vector3D(Vector3D&& v)
{
    coords = v.coords;
    v.coords = nullptr;
    // что можно сократить в: coords = std::move(v.coords);
    std::cout << "Constructor &&" << std::endl;
}

Vector3D &Vector3D::operator=(Vector3D&& v)
{
    if (this == &v) return *this;
    coords = std::move(v.coords);
    return *this;
}

void Vector3D::print()
{
    std::cout << "Vector 3D: (" << this->coords[0] << "; " << this->coords[1] << "; " << this->coords[2] << ")" << std::endl;
}

std::shared_ptr<double[]>& Vector3D::getCoords()
{
    return this->coords;
}
