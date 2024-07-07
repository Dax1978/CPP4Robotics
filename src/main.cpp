#include <src/matrix.h>
#include <iostream>

int main()
{
    math::Matrix m(3, 3);
    // m.print();
    // std::cout << "Element at pos (1, 1) = " << m(1, 1) << std::endl;
    // std::cout << std::endl;
    
    // m(1, 1) = 12.;
    // m.print();
    // std::cout << "Element at pos (1, 1) = " << m(1, 1) << std::endl;
    m(0, 0) = 1.;
    m(1, 1) = 1.;
    // std::cout << "Matrix m is:" << std::endl;
    // m.print();

    math::Matrix m1(3, 3);
    m1(0, 0) = 5.;
    m1(1, 1) = 5.;
    std::cout << "Matrix m1 is:" << std::endl;
    m1.print();

    math::Matrix m2 = m + m1;
    std::cout << "Summ of m and m1 is:" << std::endl;
    m2.print();

    // math::Matrix m3 = m - m1;
    // std::cout << "Subtract of m and m1 is:" << std::endl;
    // m3.print();

    math::Matrix m4 = m * m1;
    std::cout << "Multiplication of matrices m and m1 is:" << std::endl;
    // m4.print();
    // Показ матрицы через переопределенный метод вывода
    std::cout << m4 << std::endl;

    // Показ переопределения метода ввода
    std::cin >> m4;
    std::cout << m4 << std::endl;

    // Показ метода сложения матриц с присваиванием
    m4 += m;
    std::cout << "Add the m to the m4:" << std::endl;
    std::cout << m4 << std::endl;

    // Показ метода вычитания матриц с присваиванием
    m4 -= m1;
    std::cout << "Subtract the m1 to the m4:" << std::endl;
    std::cout << m4 << std::endl;

    // Показ метода умножения матрицы на число с присваиванием
    m4 *= 7.7;
    std::cout << "Multiplicate m4 on value:" << std::endl;
    std::cout << m4 << std::endl;

    return 0;
}