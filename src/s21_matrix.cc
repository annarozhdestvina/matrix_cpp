#include <iostream>
#include "s21_matrix.h"

double s21_fabs(double a) {
    return (a < 0.0) ? -a : a;
}
//#include "googletest/googletest/gtest/include/gtest/gtest.h"

void S21Matrix::Print() const {
    for(int i = 0; i < rows_; i++) {
        for(int j = 0; j < cols_; j++) {
            std::cout<< matrix_[i][j] << '\t';
        }
        std::cout << '\n';
    }
}

S21Matrix::S21Matrix(const S21Matrix& other) : 
    rows_{other.rows_}, cols_{other.cols_}, matrix_{new double* [other.rows_]} {
        for (int i =0; i < rows_; i++) 
            matrix_[i] = new double[other.cols_];
        
    for (int i = 0; i < other.rows_; i++) {
        for (int j = 0; j < other.cols_; j++) 
            matrix_[i][j] = other.matrix_[i][j];
    }
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

S21Matrix operator+(const S21Matrix& a, const S21Matrix& b) {
    if (a.cols_ != b.cols_ || a.rows_ != b.rows_) {
            throw std::out_of_range("Different matrix dimensions");
        }
    S21Matrix temp(a.rows_, a.cols_);
    for (int i = 0; i < a.rows_; i++)
        for (int j = 0; j < a.cols_; j++)
            temp(i, j) = a(i, j) + b(i, j);
    return(temp);
    // return a.SubMatrix(b);
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
    if (a) {
        for(int i = 0; i < rows_; i++) {
                for(int j = 0; j < cols_; j++) {
                    matrix_[i][j] -= other.matrix_[i][j];
                }
            }
        }
}

bool S21Matrix::EqMatrix(const S21Matrix& other) {
    if (rows_ != other.rows_ || cols_ != other.cols_) 
        return false;

    for(int i = 0; i < rows_; i++) 
        for(int j = 0; j < cols_; j++) 
            if (s21_fabs(matrix_[i][j] - other.matrix_[i][j]) > 1e-7) 
                return false;
    
    return true;
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

S21Matrix::~S21Matrix() {             // Destructor
        delete matrix_[0];
        delete[] matrix_;
        rows_ = 0;
        cols_ = 0;
}


/*int main() {
    S21Matrix m1(2, 4);
    m1.Fill();
    m1.Print();
    m1(1, 1) = 6.4;
    m1.Print();

    S21Matrix m2(m1);
    m1(1, 1) = 33.4;
    std::cout << "m1 print\n";
    m1.Print();
    std::cout << "m2 print\n";
    m2.Print();
}*/
