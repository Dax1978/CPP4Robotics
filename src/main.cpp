#include <clocale>
#include <memory>
#include <iostream>
#include <cmath>
#include "vector3d.h"



Vector3D normalize(std::shared_ptr<double[]>& v)
{
    double magnitude = std::sqrt(v[0]*v[0] + v[1]*v[1] + v[2]*v[2]);
    if (magnitude > 0)
	{
		double invertedMag = 1 / magnitude;
		v[0] *= invertedMag;
		v[1] *= invertedMag;
		v[2] *= invertedMag;
        return Vector3D(v[0], v[1], v[2]);
	} else {
        return Vector3D();
    }
}


int main()
{
    Vector3D v1;
    std::cout << "v1: ";
    v1.print();
    Vector3D v2(7., 7., 7.);
    std::cout << "v2: ";
    v2.print();
    Vector3D v3(v2);
    std::cout << "v3: ";
    v3.print();
    Vector3D v4 = v2;
    std::cout << "v4: ";
    v4.print();
    Vector3D v5(std::move(v2));
    std::cout << "v5: ";
    v5.print();
    Vector3D v6 = std::move(v3);
    std::cout << "v6: ";
    v6.print();

    Vector3D v7 = normalize(v6.getCoords());
    std::cout << "v7: ";
    v7.print();

    return 0;
}