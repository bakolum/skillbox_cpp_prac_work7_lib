#include "c_api.h"
#include <src/matrix.h>

struct Matrix : public math::Matrix
{
public:
    Matrix(const struct math::Matrix &M) : math::Matrix(M) {};
};

// Создание матрицы
Matrix *MATRIXLIB_EXPORT math_createMatrix(int rows, int cols)
{
    return new Matrix(math::Matrix(rows, cols));
}

// Удаление матрицы
void MATRIXLIB_EXPORT math_deleteMatrix(Matrix *M)
{
    delete M;
}

// Доступ к элементам матрицы
real MATRIXLIB_EXPORT math_get(const Matrix *M, int row, int col)
{
    return M->operator()(row, col);
}

// Доступ к элементам матрицы
void MATRIXLIB_EXPORT math_set(Matrix *M, int row, int col, real val)
{
    M->operator()(row, col) = val;
}

// Сложение матриц
Matrix *MATRIXLIB_EXPORT math_add(const Matrix *A, const Matrix *B)
{
    return new Matrix(*A + *B);
}

// Разность матриц
Matrix *MATRIXLIB_EXPORT math_subtruct(const Matrix *A, const Matrix *B)
{
    return new Matrix(*A - *B);
}

// Умножение матриц
Matrix *MATRIXLIB_EXPORT math_dot(const Matrix *A, const Matrix *B)
{
    return new Matrix(*A * *B);
}



// Реализация операторов присваивания (+=, -=, *=)
void MATRIXLIB_EXPORT math_add_assign(Matrix *M, const Matrix *B)
{
    *M += *B;  // Оператор присваивания со сложением
}

void MATRIXLIB_EXPORT math_subtruct_assign(Matrix *M, const Matrix *B)
{
    *M -= *B;
}

void MATRIXLIB_EXPORT math_dot_assign(Matrix *M, const Matrix *B)
{
    *M *= *B;
}

// Перегрузка оператора << для вывода матрицы
void MATRIXLIB_EXPORT math_fprint(const Matrix *M)
{
    // Вывод элементов матрицы
    for(int i = 0; i < M->getRows(); ++i)
    {
        for(int j = 0; j < M->getCols(); ++j)
        {
            fprintf(stdout, "%.1f ", M->operator()(i, j));
        }
        fprintf(stdout, "\n");
    }
}

// Перегрузка оператора >> для ввода матрицы
void MATRIXLIB_EXPORT math_fscan(Matrix *M)
{
    printf("Enter elements for matrix of size %d by %d:\n", M->getRows(), M->getCols());
    // Ввод элементов матрицы
    for(int i = 0; i < M->getRows(); ++i)
    {
        for(int j = 0; j < M->getCols(); ++j)
        {
            fscanf(stdin, "%lf", &M->operator()(i, j));
        }
    }
}


// Печать матрицы
void MATRIXLIB_EXPORT math_print(const Matrix *M)
{
    M->print();
}
