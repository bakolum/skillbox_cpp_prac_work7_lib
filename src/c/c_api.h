#pragma once
#include <export_shared.h>

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

    // Создание и удаление матрицы
    Matrix *MATRIXLIB_EXPORT math_createMatrix(int rows, int cols);
    void MATRIXLIB_EXPORT math_deleteMatrix(Matrix *M);

    // Доступ к элементам матрицы
    real MATRIXLIB_EXPORT math_get(const Matrix *M, int row, int col);
    void MATRIXLIB_EXPORT math_set(Matrix *M, int row, int col, real val);

    // Операции с матрицами
    Matrix *MATRIXLIB_EXPORT math_add(const Matrix *A, const Matrix *B);
    Matrix *MATRIXLIB_EXPORT math_subtruct(const Matrix *A, const Matrix *B);
    Matrix *MATRIXLIB_EXPORT math_dot(const Matrix *A, const Matrix *B);

    // Операторы присваивания с операциями +=, -=, *=:
    void MATRIXLIB_EXPORT math_add_assign(Matrix *M, const Matrix *B);

    void MATRIXLIB_EXPORT math_subtruct_assign(Matrix *M, const Matrix *B);

    void MATRIXLIB_EXPORT math_dot_assign(Matrix *M, const Matrix *B);


    // Перегрузка оператора >> для ввода матрицы
    void MATRIXLIB_EXPORT math_fscan(Matrix *M);  

    // Перегрузка оператора << для вывода матрицы
    void MATRIXLIB_EXPORT math_fprint(const Matrix *M);  

    // Печать матрицы
    void MATRIXLIB_EXPORT math_print(const Matrix *M);


#ifdef __cplusplus
}
#endif