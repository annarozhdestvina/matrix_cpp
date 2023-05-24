#include <iostream>
#include "s21_matrix.h"
#include <cmath>

double s21_fabs(double a) {
    return (a < 0.0) ? -a : a;
}

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
        for (int i = 0; i < rows_; i++) 
            matrix_[i] = new double[other.cols_];
        
    for (int i = 0; i < other.rows_; i++) {
        for (int j = 0; j < other.cols_; j++) 
            matrix_[i][j] = other.matrix_[i][j];
    }
}

void S21Matrix::MulMatrix(const S21Matrix& other) {
    S21Matrix temp(rows_, other.cols_);
    if (rows_ == other.cols_) {
        for(int i = 0; i < rows_; i++) {
            for(int j = 0; j < other.cols_; j++) {
                temp.matrix_[i][j] = 0;
                for(int inner = 0; inner < cols_; inner++)
                    temp.matrix_[i][j] += matrix_[i][inner] * other.matrix_[inner][j];
            }
        }
    } else
        std::cout << "error calc\n";
    *this = temp;
}

bool operator==(const S21Matrix &a, const S21Matrix &b) {
    return (a.EqMatrix(b)); 
}

S21Matrix& S21Matrix::operator= (const S21Matrix &drob) {
    // Проверка на самоприсваивание
    if (this == &drob)
        return *this;

    // освободить память
    S21Matrix::~S21Matrix();

    rows_ = drob.rows_;
    cols_ = drob.cols_;

    matrix_= new double* [rows_]; 
    for(int i = 0; i < rows_; i++) 
        matrix_[i] = new double[cols_];

    // Выполняем копирование значений

    for(int i = 0; i < rows_; i++)
            for(int j = 0; j < drob.cols_; j++)
                matrix_[i][j] = drob.matrix_[i][j];
 
    // Возвращаем текущий объект
    return *this;
}

void S21Matrix::MulNumber(const double num) {
for(int i = 0; i < rows_; i++) {
            for(int j = 0; j < cols_; j++) {
                matrix_[i][j] *= num;
            }
    }
}

int S21Matrix::GetRow() { //функция получает значение числа строк
    return (rows_);
}

int S21Matrix::GetCol() { //функция получает значение числа столбцов
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
}

S21Matrix operator-(const S21Matrix& a, const S21Matrix& b) {
    if (a.cols_ != b.cols_ || a.rows_ != b.rows_) {
        throw std::out_of_range("Different matrix dimensions");
    }
    S21Matrix temp(a.rows_, a.cols_);
    for (int i = 0; i < a.rows_; i++)
        for(int j = 0; j < a.cols_; j++)
            temp(i, j) = a(i, j) - b(i, j);
    return temp;
}

S21Matrix operator*(const S21Matrix &a, const S21Matrix &b) {
    if (a.rows_ != b.cols_) {
        throw std::out_of_range("The number of columns of the first matrix does not equal the number of rows of the second matrix");
    }
    S21Matrix temp(a.rows_, b.cols_);
    if(a.rows_ == b.cols_) {
        for(int i = 0; i < a.rows_; i++) {
            for(int j = 0; j < b.cols_; j++) {
                temp.matrix_[i][j] = 0;
                for(int inner = 0; inner < a.cols_; inner++)
                    temp.matrix_[i][j] += a.matrix_[i][inner] * b.matrix_[inner][j];
            }
        }
    } else
        std::cout << "error calc\n";
    return temp;
}

void S21Matrix::SumMatrix(const S21Matrix& other) {
    bool a;
    a = EqMatrix(other);
    std::cout << a <<std::endl;
    if (cols_ != other.cols_ || rows_ != other.rows_) {
        throw std::out_of_range("Different matrix dimensions");
    }
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

bool S21Matrix::EqMatrix(const S21Matrix& other) const {
    if (rows_ != other.rows_ || cols_ != other.cols_) 
        return false;

    for(int i = 0; i < rows_; i++) 
        for(int j = 0; j < cols_; j++) 
            if (s21_fabs(matrix_[i][j] - other.matrix_[i][j]) > 1e-7) 
                return false;
    
    return true;
}

S21Matrix::S21Matrix(int rows, int columns): rows_(rows), cols_(columns) {
    matrix_= new double* [rows_]; 
    for(int i = 0; i < rows_; i++) 
        matrix_[i] = new double[cols_];
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

S21Matrix S21Matrix::Transpose() {
    S21Matrix temp(cols_, rows_);

    for(int i = 0; i < rows_; i++)
        for(int j = 0; j < cols_; j++)
            temp.matrix_[j][i] = matrix_[i][j];

    *this = temp;

    return *this;
}

S21Matrix S21Matrix::do_lit(int row_del, int col_del) const {
    // if(rows_ != cols_ || rows_ == 1){
    //     throw std::out_of_range("exectution error");
    // }
    // if(row_del >= rows_ || col_del >= cols_) {
    //     throw std::out_of_range("input error");
    // }
    
    int size = rows_ - 1;
    S21Matrix temp(size, size);
    int i_l = 0;
    for (int i_b = 0; i_b < rows_; i_b++) {
        if(i_b != row_del) {
            int j_l = 0;
            for (int j_b = 0; j_b < cols_; j_b++) {
                if(j_b != col_del) {
                    temp.matrix_[i_l][j_l] = matrix_[i_b][j_b];
                    ++j_l;
                }
            }
            ++i_l;
        }
    }
    // *this = temp;
    return temp;
}

double S21Matrix::Determinant2() {
    if (rows_ != cols_) {
        throw std::out_of_range("the matrix is not square");
    }
    // S21Matrix temp(rows_, cols_);
    // for(int i = 0; i < rows_; i++)
    //     for(int j = 0; j < cols_; j++)
    //         temp.matrix_[j][i] = matrix_[i][j];

    double determinant = 0.0;
    int k = 1;
    if(rows_ == 1) {
        return matrix_[0][0];
    } else if (rows_ == 2) {
        return determinant = (matrix_[0][0] * matrix_[1][1] - matrix_[1][0] * matrix_[0][1]);
    } else if(rows_ > 2) {
        for(int i = 0; i < cols_; i++) {
            S21Matrix temp(rows_, cols_);
    for(int i = 0; i < rows_; i++)
        for(int j = 0; j < cols_; j++)
            temp.matrix_[j][i] = matrix_[i][j];
            std::cout << "matrix before lit\n";
            temp.Print();
            if(temp.rows_ > 1) {
            temp.do_lit(i, 0);
            std::cout << "matrix after lit\n";
            temp.Print();
            std::cout << "det in i = " << i << "  det = " << determinant << '\n';
            determinant = determinant + matrix_[i][0] * k * temp.Determinant();
            std::cout << "matrix["<<i<<"][0] = " << matrix_[i][0] << '\n';
            k = -k;
            }
        }
    }
    return determinant;
}

double S21Matrix::Determinant() const  {
    if (rows_ != cols_)
        throw std::out_of_range("the matrix is not square");
    
    if (rows_ == 0)
        throw std::out_of_range("rows is 0");
    if (cols_ == 0)
        throw std::out_of_range("columns is 0");
    

    assert(rows_ > 0 && "rows is 0 or negative");

    if(rows_ == 1)
        return matrix_[0][0];
    if (rows_ == 2)
        return matrix_[0][0] * matrix_[1][1] - matrix_[1][0] * matrix_[0][1];

    double det = 0.0;
    int k = 1;
    for(int i = 0; i < cols_; i++) {
        const S21Matrix little = do_lit(i, 0);  // constructor not operator= because little is newly created
        det = det + matrix_[i][0] * k * little.Determinant();
        k = -k;
    }

    return det;
}

int minus_one_pow(int pow) { return (((pow + 1) % 2) * 2.0 - 1.0); }


S21Matrix S21Matrix::CalcComplements() {
    if (rows_ != cols_)
        throw std::out_of_range("the matrix is not square");
    
    if (rows_ == 0)
        throw std::out_of_range("rows is 0");
    if (cols_ == 0)
        throw std::out_of_range("columns is 0");
    if (cols_ == 1 && rows_ == 1)
        throw std::out_of_range("inappropriate matrix rows and cols should be > 1");
    

        S21Matrix temp(rows_, cols_);
    for(int i = 0; i < rows_; i++)
        for(int j = 0; j < cols_; j++)
            temp.matrix_[j][i] = matrix_[i][j];
    
    for (int i = 0; i < rows_; i++) {
        for (int j = 0; j < rows_; j++) {
            const S21Matrix little = do_lit(i, j);
            double det = 0.0;
            det = little.Determinant();
            temp.matrix_[i][j] =  det * minus_one_pow(i + j);
        }
    }
    *this = temp;
    return temp;
}

S21Matrix::~S21Matrix() {             // Destructor
    for(int i = 0; i < rows_; i++) 
        delete[] matrix_[i];
    delete[] matrix_;
    rows_ = 0;
    cols_ = 0;
}

