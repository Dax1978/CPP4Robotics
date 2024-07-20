#include "vector3d.h"
#include <cmath>
#include <pybind11/operators.h>


int add(const int &a, const int &b) {
    return a + b;
}

bool Vector3D::operator== (Vector3D& other)
{
	if (fabs(x-other.x) < EPSILON)
		if (fabs(y-other.y) < EPSILON)
			if (fabs(z-other.z) < EPSILON)
				return true;
	return false;
}

Vector3D& Vector3D::normalize()
{
    double mag = magnitude();
	if (mag > 0)
	{
		double invertedMag = 1 / mag;
		x *= invertedMag;
		y *= invertedMag;
		z *= invertedMag;
	}
    return *this;
}


// class Vector3D {
// public:
//     Vector3D(float x, float y) : x(x), y(y) { std::cout << "Value constructor" << std::endl; }
//     Vector3D(const Vector3D &v) : x(v.x), y(v.y) { std::cout << "Copy constructor" << std::endl; }
//     Vector3D(Vector3D &&v) : x(v.x), y(v.y) { std::cout << "Move constructor" << std::endl; v.x = v.y = 0; }
//     ~Vector3D() { std::cout << "Destructor." << std::endl; }

//     std::string toString() const {
//         return "[" + std::to_string(x) + ", " + std::to_string(y) + "]";
//     }

//     void operator=(const Vector3D &v) {
//         cout << "Assignment operator" << endl;
//         x = v.x;
//         y = v.y;
//     }

//     void operator=(Vector3D &&v) {
//         cout << "Move assignment operator" << endl;
//         x = v.x; y = v.y; v.x = v.y = 0;
//     }

//     Vector3D operator+(const Vector3D &v) const { return Vector3D(x + v.x, y + v.y); }
//     Vector3D operator-(const Vector3D &v) const { return Vector3D(x - v.x, y - v.y); }
//     Vector3D operator-(float value) const { return Vector3D(x - value, y - value); }
//     Vector3D operator+(float value) const { return Vector3D(x + value, y + value); }
//     Vector3D operator*(float value) const { return Vector3D(x * value, y * value); }
//     Vector3D operator/(float value) const { return Vector3D(x / value, y / value); }
//     Vector3D& operator+=(const Vector3D &v) { x += v.x; y += v.y; return *this; }
//     Vector3D& operator-=(const Vector3D &v) { x -= v.x; y -= v.y; return *this; }
//     Vector3D& operator*=(float v) { x *= v; y *= v; return *this; }
//     Vector3D& operator/=(float v) { x /= v; y /= v; return *this; }

//     friend Vector3D operator+(float f, const Vector3D &v) { return Vector3D(f + v.x, f + v.y); }
//     friend Vector3D operator-(float f, const Vector3D &v) { return Vector3D(f - v.x, f - v.y); }
//     friend Vector3D operator*(float f, const Vector3D &v) { return Vector3D(f * v.x, f * v.y); }
//     friend Vector3D operator/(float f, const Vector3D &v) { return Vector3D(f / v.x, f / v.y); }
// private:
//     float x, y;
// };