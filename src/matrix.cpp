#include "matrix.h"
#include <cmath>

// Реализация оператора () для изменения элемента матрицы:
math::real& math::Matrix::operator()(int col, int row){
    if(col >= cols_ || row >= rows_){
        throw invalid_argument("Matrix: col number is out of bounds!");
    }
    int pos{0};
    pos = cols_ * row + col;    // Вычисляем позицию элемента в векторе
    return mvec_.at(pos);       // Возвращаем ссылку на элемент
}


// Реализация оператора () для доступа к элементу матрицы для чтения
math::real math::Matrix::operator()(int col, int row) const{
    if(col >= cols_ || row >= rows_){
        throw invalid_argument("Matrix: col number is out of bounds!");
    }
    int pos{0};
    pos = cols_ * row + col;     // Вычисляем позицию элемента в векторе
    return mvec_.at(pos);       // Возвращаем значение элемента
}


// Метод для вывода матрицы
void math::Matrix::print() const{
    for(int i = 0; i < cols_; ++i){
        for(int j = 0; j < rows_; ++j){
            cout << mvec_.at(cols_ * i + j) << " ";
        }
        cout << endl;
    }
}


namespace math
{
    // Реализация оператора + для сложения матриц
    math::Matrix operator+(const Matrix &A, const Matrix &B)
    {
        // Проверка на совместимость матриц
        if ((A.cols_ != B.cols_) || (A.rows_ != B.rows_))
        {
            cerr << "Matrices are not compatible for addition!";
            return Matrix(0, 0); // Возвращаем пустую матрицу в случае ошибки
        }
        Matrix C(A.cols_, A.rows_);
        for (int i = 0; i < A.mvec_.size(); ++i)
        {
            C.mvec_.at(i) = A.mvec_.at(i) + B.mvec_.at(i); // Складываем элементы
        }
        return C;
    }

    // Реализация оператора - для вычитания матриц
    math::Matrix operator-(const Matrix &A, const Matrix &B)
    {
        // Проверка на совместимость матриц
        if ((A.cols_ != B.cols_) || (A.rows_ != B.rows_))
        {
            cerr << "Matrices are not compatible for substruction!";
            return Matrix(0, 0); // Возвращаем пустую матрицу в случае ошибки
        }
        Matrix C(A.cols_, A.rows_);
        for (int i = 0; i < A.mvec_.size(); ++i)
        {
            C.mvec_.at(i) = A.mvec_.at(i) - B.mvec_.at(i); // Вычитаем элементы
        }
        return C;
    }

    // Реализация оператора * для умножения матриц
    math::Matrix operator*(const Matrix &A, const Matrix &B)
    {
        // Проверка на совместимость
        if (A.cols_ != B.rows_)
        {
            cerr << "Matrices are not compatible for multiplication!";
            return Matrix(0, 0); // Возвращаем пустую матрицу в случае ошибки
        }
        Matrix C(A.rows_, B.cols_);
        for (int pos = 0; pos < C.mvec_.size(); ++pos)
        {
            int row = (int)floor(pos / C.cols_); // Определяем строку
            int col = pos - row * C.cols_;       // Определяем столбец

            for (int k = 0; k < A.cols_; ++k)
            {
                C.mvec_.at(pos) += A(row, k) * B(k, col); // Умножаем и суммируем элементы
            }
        }
        return C;
    }

    // Оператор += для матриц
    math::Matrix &Matrix::operator+=(const Matrix &B)
    {
        // Проверка на совместимость
        if ((this->cols_ != B.cols_) || (this->rows_ != B.rows_))
        {
            cerr << "Matrices must have the same dimensions for addition!";
            return *this; // Возвращаем сам объект в случае ошибки
        }
        for (int i = 0; i < this->mvec_.size(); ++i)
        {
            this->mvec_.at(i) += B.mvec_.at(i); // Складываем элементы
        }
        return *this; // Возвращаем сам объект
    }

    // Оператор -= для матриц
    math::Matrix &Matrix::operator-=(const Matrix &B)
    {
        // Проверка на совместимость
        if ((this->cols_ != B.cols_) || (this->rows_ != B.rows_))
        {
            cerr << "Matrices must have the same dimensions for substruction!";
            return *this; // Возвращаем сам объект в случае ошибки
        }
        for (int i = 0; i < this->mvec_.size(); ++i)
        {
            this->mvec_.at(i) -= B.mvec_.at(i);
        }
        return *this; // Возвращаем сам объект
    }

    // Оператор *= для матриц
    math::Matrix &Matrix::operator*=(const Matrix &B)
    {
        // Проверка на совместимость
        if (this->cols_ != B.rows_)
        {
            cerr << "Matrices cannot be multiplied!";
            return *this; // Возвращаем сам объект в случае ошибки
        }

        Matrix temp(this->rows_, B.cols_); // Создаем временную матрицу
        // Выполняем умножение
        for (int pos = 0; pos < temp.mvec_.size(); ++pos)
        {
            int row = (int)floor(pos / temp.cols_);
            int col = pos - row * temp.cols_;

            for (int k = 0; k < this->cols_; ++k)
            {
                temp.mvec_.at(pos) += this->operator()(row, k) * B(k, col);
            }
        }
        *this = temp; // Присваиваем результат текущей матрице
        return *this; // Возвращаем сам объект
    }

    // Перегрузка оператора >> для ввода матрицы
    istream &operator>>(istream &in, math::Matrix &M)
    {
        cout << "Enter elements for matrix of size " << M.rows_ << " by " << M.cols_ << ":\n";
        // Ввод элементов матрицы
        for (int i = 0; i < M.rows_; ++i)
        {
            for (int j = 0; j < M.cols_; ++j)
            {
                in >> M(i, j);
            }
        }
        return in;
    }

    // Перегрузка оператора << для вывода матрицы
    ostream &operator<<(ostream &out, math::Matrix &M)
    {
        // Вывод элементов матрицы
        for (int i = 0; i < M.rows_; ++i)
        {
            for (int j = 0; j < M.cols_; ++j)
            {
                out << M(i, j) << " ";
            }
            out << endl;
        }
        return out;
    }
}