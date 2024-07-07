#pragma once

#include <vector>
#include <iostream>

namespace math
{
    typedef double real;

    class Matrix
    {
    private:
        int cols_;
        int rows_;
        std::vector<real> mvec_;

    public:
        Matrix() {};
        Matrix(int rows, int cols) : cols_(cols), rows_(rows), mvec_(std::vector<real>(rows * cols)) {};

        real& operator() (int row, int col);
        real operator() (int row, int col) const;
        void print();

        Matrix& operator += (const Matrix &M);
        Matrix& operator -= (const Matrix &M);
        Matrix& operator *= (const real a);

        friend Matrix operator + (const Matrix &A, const Matrix &B);
        friend Matrix operator - (const Matrix &A, const Matrix &B);
        friend Matrix operator * (const Matrix &A, const Matrix &B);

        // Объявление перегрузки опереаторов ввода / вывода
        friend std::ostream& operator << (std::ostream &out, const Matrix &M);
        friend std::istream& operator >> (std::istream &in,  Matrix &M);
    };
} // namespace math