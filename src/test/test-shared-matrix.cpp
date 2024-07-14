#include <iostream>

// 1 вариант, когда у меня есть заголовочный файл, в котором определен интерфейс
// #include <src/matrix.h>
// #include <src/c/c_api.h>

// 2 вариант, когда у меня отсутствует заголовочный файл, в котором определен интерфейс
#include <src/export.h>
struct Matrix;
#ifdef __cplusplus
extern "C"
{
#endif
extern Matrix* MATRIXLIB_EXPORT math_createMatrix(int, int);
extern void MATRIXLIB_EXPORT math_set(Matrix*, int, int, double);
extern void MATRIXLIB_EXPORT math_print(Matrix*);
extern void MATRIXLIB_EXPORT math_deleteMatrix(Matrix*);
extern Matrix* MATRIXLIB_EXPORT math_summation(const Matrix*, const Matrix*);
extern Matrix* MATRIXLIB_EXPORT math_subtracting(const Matrix*, const Matrix*);
extern Matrix* MATRIXLIB_EXPORT math_multiply(const Matrix*, const Matrix*);
// extern void MATRIXLIB_EXPORT math_print(const Matrix*);
extern void MATRIXLIB_EXPORT math_add(Matrix*, const Matrix*);
extern void MATRIXLIB_EXPORT math_sub(Matrix*, const Matrix*);
extern void MATRIXLIB_EXPORT math_mul(Matrix*, const double);
#ifdef __cplusplus
}
#endif



int main()
{
    // Вариант, когда у меня есть заголовочный файл, в котором определен интерфейс
    Matrix* m = math_createMatrix(3, 3);
    math_set(m, 0, 0, 1.);
    math_set(m, 1, 1, 1.);
    std::cout << "Matrix m is"  << std::endl;
    math_print(m);
    
    Matrix* m1 = math_createMatrix(3, 3);
    math_set(m1, 0, 0, 7.);
    math_set(m1, 1, 1, 7.);
    std::cout << "Matrix m1 is"  << std::endl;
    math_print(m1);

    Matrix* m2 = math_summation(m, m1);
    std::cout << "Matrix m2 = m + m1 is"  << std::endl;
    math_print(m2);

    Matrix* m3 = math_subtracting(m, m1);
    std::cout << "Matrix m3 = m - m1 is"  << std::endl;
    math_print(m3);

    Matrix* m4 = math_multiply(m, m1);
    std::cout << "Matrix m4 = m * m1 is"  << std::endl;
    math_print(m4);

    math_add(m3, m1);
    std::cout << "Matrix m3 = m3 + m1 is"  << std::endl;
    math_print(m3);

    math_sub(m3, m);
    std::cout << "Matrix m3 = m3 - m is"  << std::endl;
    math_print(m3);

    math_mul(m4, 7.);
    std::cout << "Matrix m4 = m4 * 7.0 is"  << std::endl;
    math_print(m4);

    math_deleteMatrix(m);
    math_deleteMatrix(m1);
    math_deleteMatrix(m2);
    math_deleteMatrix(m3);
    math_deleteMatrix(m4);

    return 0;
}