#pragma once
#include <src/export.h>

#ifdef MATH_DOUBLE_PREC_DEFINE
typedef double real;
#else
typedef float real;
#endif

#ifdef __cplusplus
extern "C"
{
#endif

typedef struct Matrix Matrix;

Matrix* MATRIXLIB_EXPORT math_createMatrix(int rows, int cols);
void MATRIXLIB_EXPORT math_deleteMatrix(Matrix* M);

real MATRIXLIB_EXPORT math_get(const Matrix* M, int row, int col);
void MATRIXLIB_EXPORT math_set(Matrix* M, int row, int col, real val);

Matrix* MATRIXLIB_EXPORT math_summation(const Matrix* A, const Matrix* B);
Matrix* MATRIXLIB_EXPORT math_subtracting(const Matrix* A, const Matrix* B);
Matrix* MATRIXLIB_EXPORT math_multiply(const Matrix* A, const Matrix* B);
void MATRIXLIB_EXPORT math_print(const Matrix* M);

void MATRIXLIB_EXPORT math_add(Matrix* M, const Matrix* other);
void MATRIXLIB_EXPORT math_sub(Matrix* M, const Matrix* other);
void MATRIXLIB_EXPORT math_mul(Matrix* M, const real a);
// Matrix* MATRIXLIB_EXPORT math_add(Matrix* M, const Matrix* other);
// Matrix* MATRIXLIB_EXPORT math_sub(Matrix* M, const Matrix* other);
// Matrix* MATRIXLIB_EXPORT math_mul(Matrix* M, const real a);
// std::ostream& operator << (std::ostream &out, const Matrix &M);
// std::istream& operator >> (std::istream &in,  Matrix &M);

#ifdef __cplusplus
}
#endif