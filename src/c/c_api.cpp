#include "c_api.h"
#include <src/matrix.h>

struct Matrix : public math::Matrix
{
public:
    Matrix(const struct math::Matrix &M) : math::Matrix(M) {};
};

Matrix* MATRIXLIB_EXPORT  math_createMatrix(int rows, int cols)
{
    return new Matrix(math::Matrix(rows, cols));
}

void MATRIXLIB_EXPORT math_deleteMatrix(Matrix* M)
{
    delete M;
}

real MATRIXLIB_EXPORT math_get(const Matrix* M, int row, int col)
{
    return M->operator()(row, col);
}

void MATRIXLIB_EXPORT math_set(Matrix* M, int row, int col, real val)
{
    M->operator()(row, col) = val;
}

Matrix* MATRIXLIB_EXPORT math_summation(const Matrix* A, const Matrix* B)
{
    return new Matrix(*A + *B);
}

Matrix* MATRIXLIB_EXPORT math_subtracting(const Matrix* A, const Matrix* B)
{
    return new Matrix(*A - *B);
}

Matrix* MATRIXLIB_EXPORT math_multiply(const Matrix* A, const Matrix* B)
{
    return new Matrix(*A * *B);
}

void MATRIXLIB_EXPORT math_print(const Matrix* M)
{
    M->print();
}

void MATRIXLIB_EXPORT math_add(Matrix* M, const Matrix* other)
{
    M->operator+=(*other);
}

void MATRIXLIB_EXPORT math_sub(Matrix* M, const Matrix* other)
{
    M->operator-=(*other);
}

void MATRIXLIB_EXPORT math_mul(Matrix* M, const real a)
{
    M->operator*=(a);
}

// void MATRIXLIB_EXPORT operator << (std::ostream &out, const Matrix &M)
// {
//     M->operator<<()
// }

// void MATRIXLIB_EXPORT operator >> (std::istream &in,  Matrix &M)
// {
//     return
// }

// Matrix* MATRIXLIB_EXPORT math_add(Matrix* M, const Matrix* other)
// {
//     return new Matrix(M->operator+=(*other));
//     // return M->operator+=(*other);
// }

// Matrix* MATRIXLIB_EXPORT math_sub(Matrix* M, const Matrix* other)
// {
//     return new Matrix(M->operator-=(*other));
// }

// Matrix* MATRIXLIB_EXPORT math_mul(Matrix* M, const real a)
// {
//     return new Matrix(M->operator*=(a));
// }