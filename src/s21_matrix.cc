#include <iostream>
#include "s21_matrix.h"
//#include "googletest/googletest/gtest/include/gtest/gtest.h"

void S21Matrix::Print() const {
    for(int i = 0; i < rows_; i++) {
        for(int j = 0; j < cols_; j++) {
            std::cout<< matrix_[i][j] << '\t';
        }
        std::cout << '\n';
    }
}

// S21Matrix::S21Matrix(const S21Matrix& other) : 
// rows_{other.rows_}, cols_{other.cols_}, matrix_{other.matrix_} {}

S21Matrix::S21Matrix(const S21Matrix& other) : 
    rows_{other.rows_}, cols_{other.cols_}, matrix_{new double* [rows_]} {
        for (int i =0; i < rows_; i++) 
            matrix_[i] = new double[other.cols_];
    }

void S21Matrix::MulMatrix(const S21Matrix& other) {
    S21Matrix temp(rows_, cols_);
    if (rows_ == other.cols_) {
        for(int i = 0; i < rows_; i++) {
            for(int j = 0; j < other.cols_; j++) {
                for(int inner = 0; inner < cols_; inner++) {
                    temp.matrix_[i][j] = 0;
                    temp.matrix_[i][j] += matrix_[i][inner] * other.matrix_[inner][j];
                    matrix_[i][j] = 0;
                    matrix_[i][j] = temp.matrix_[i][j];
                    //matrix_[i][j] = temp.matrix_[i][j];
                }
            }
        }
    } else
        std::cout << "error calc\n";
}

void S21Matrix::MulNumber(const double num) {
for(int i = 0; i < rows_; i++) {
            for(int j = 0; j < cols_; j++) {
                matrix_[i][j] *= num;
            }
    }
}

int S21Matrix::GetRow() //функция получает значение числа строк
{
    return (rows_);
}

int S21Matrix::GetCol() //функция получает значение числа столбцов
{
    return (cols_);
}

double S21Matrix::operator()(int row, int col) const//перегрузка круглых скобок для матрицы.
{                             // Если m - матрица, то m(i,j) будет
    return (matrix_[row][col]);  //означать i,j-тый элемент матрицы
}

double& S21Matrix::operator()(int row, int col)//перегрузка круглых скобок для матрицы.
{                             // Если m - матрица, то m(i,j) будет
    return (matrix_[row][col]);  //означать i,j-тый элемент матрицы
}

S21Matrix operator+(S21Matrix& a, S21Matrix& b) {
    //return S21Matrix(a.getMatrix() + b.getMatrix());
    S21Matrix temp(a.GetRow(), a.GetCol());
    for (int i = 0; i < a.GetRow(); i++)
        for (int j = 0; j < a.GetCol(); j++)
            temp(i, j) = a(i, j) + b(i, j);
    return(temp);
}

void S21Matrix::SumMatrix(const S21Matrix& other) {
    bool a;
    a = EqMatrix(other);
    std::cout << a <<std::endl;
    if (a) {
        for(int i = 0; i < rows_; i++) {
                for(int j = 0; j < cols_; j++) {
                    matrix_[i][j] += other.matrix_[i][j];
                }
            }
        }
}

void S21Matrix::SubMatrix(const S21Matrix& other) {
    bool a;
    a = EqMatrix(other);
    //std::cout << a <<std::endl;
    if (a) {
        for(int i = 0; i < rows_; i++) {
                for(int j = 0; j < cols_; j++) {
                    matrix_[i][j] -= other.matrix_[i][j];
                }
            }
        }
}

bool S21Matrix::EqMatrix(const S21Matrix& other) {
    if (rows_ == other.rows_ && cols_ == other.cols_) {
        return true;
        for(int i = 0; i < rows_; i++) {
            for(int j = 0; j < cols_; j++) {
                if (matrix_[i][j] - other.matrix_[i][j] > 1e-7) 
                    return false;
            }
        }
    } else 
        return false;
}

S21Matrix::S21Matrix(int rows, int columns): rows_(rows), cols_(columns) {
    double *pointer = new double[rows_ * cols_ *sizeof(double)];
    double **matrix_local = new double*[rows_ * sizeof(double*)];

        for(int i = 0; i < rows_; i++) {
            *(matrix_local + i) = pointer + i*cols_;
        }
        matrix_ = matrix_local;
}

void S21Matrix::Fill() {
    int k = 1;
    for(int i =0; i < rows_; i++) {
        for(int j =0; j < cols_; j++) {
            matrix_[i][j] = k++;
        }
    }
}

void S21Matrix::FillC() {
    Fill();
    matrix_[2][2] = 25;
}

//int S21Matrix::s_id_ = 8;

S21Matrix::~S21Matrix() {             // Destructor
        delete matrix_[0];
        delete[] matrix_;
        rows_ = 0;
        cols_ = 0;
}

// TEST(Test_Name, Subtest) {
    // ASSERT_TRUE(1 == 1);
// }

