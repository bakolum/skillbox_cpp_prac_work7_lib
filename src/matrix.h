#include <iostream>
#include <vector>

using namespace std;

// Определяем пространство имен math:
namespace math{
    typedef double real;    // Определяем тип real

    class Matrix{
    private:
        int cols_;  // Количество столбцов
        int rows_;  // Количество строк
        vector<real> mvec_; // Вектор, представляющий элементы матрицы
    public:
        Matrix() : cols_(0), rows_(0) {};   // Конструктор по умольчанию

        // Конструктор с параметрами:
        Matrix(int cols, int rows) : cols_(cols), rows_(rows), mvec_(cols * rows){};

        // Гетеры для получения количества строк и столбцов
        int getCols() const {return cols_;}
        int getRows() const {return rows_;}

        real& operator()(int col, int row); // Перегрузка оператора () для доступа к элементам для изменения
        real operator()(int row, int col) const;    // Перегрузка оператора () для доступа к элементам для чтения

        void print() const;   // Метод вывода матрицы

        // Операторы присваивания с операциями +=, -=, *=:
        Matrix& operator+=(const Matrix& B);
        Matrix& operator-=(const Matrix& B);
        Matrix& operator*=(const Matrix& B);

        // Дружественные функции для операторов +, -, *:
        friend Matrix operator+(const Matrix& A, const Matrix& B);
        friend Matrix operator-(const Matrix& A, const Matrix& B);
        friend Matrix operator*(const Matrix& A, const Matrix& B);

        // Операторы ввода и вывода:
        friend istream& operator>>(istream& in, Matrix& M);
        friend ostream& operator<<(ostream& out, Matrix& M);

    };
}   // namespace math