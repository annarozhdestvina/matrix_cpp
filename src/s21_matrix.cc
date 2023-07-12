#include <iostream>
#include "s21_matrix.h"
#include <cassert>
#include <cmath>

int minus_one_pow(int pow) { 
    return (((pow + 1) % 2) * 2.0 - 1.0); 
}

double s21_fabs(double a) {
    return (a < 0.0) ? -a : a;
}

S21Matrix S21Matrix::do_lit(int row_del, int col_del) const noexcept {
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
    return temp;
}

S21Matrix::S21Matrix() : rows_{0}, cols_{0}, matrix_{nullptr} {}; // Default constructor
    
S21Matrix::S21Matrix(int rows, int columns): rows_(rows), cols_(columns) {
    if (rows_ == 0)
        throw std::out_of_range("rows is 0");
    if (cols_ == 0)
        throw std::out_of_range("columns is 0");

    matrix_= new double* [rows_]; 
    for(int i = 0; i < rows_; i++) 
        matrix_[i] = new double[cols_] {}; //initialize all matrix[i][j] with 0.0
}

S21Matrix::~S21Matrix() {             // Destructor
    for(int i = 0; i < rows_; i++) 
        delete[] matrix_[i];
    delete[] matrix_;
    rows_ = 0;
    cols_ = 0;
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

void S21Matrix::Fill() noexcept {
    int k = 1;
    for(int i =0; i < rows_; i++) {
        for(int j =0; j < cols_; j++) {
            matrix_[i][j] = k++;
        }
    }
}

// void S21Matrix::Print() const noexcept {
//     for(int i = 0; i < rows_; i++) {
//         for(int j = 0; j < cols_; j++) {
//             std::cout<< matrix_[i][j] << '\t';
//         }
//         std::cout << '\n';
//     }
// }

void S21Matrix::SumMatrix(const S21Matrix& other) {
    if (cols_ != other.cols_ || rows_ != other.rows_) {
        throw std::out_of_range("Different matrix dimensions");
    }
    
    for(int i = 0; i < rows_; i++) {
        for(int j = 0; j < cols_; j++) {
            matrix_[i][j] += other.matrix_[i][j];
        }
    }  
}

void S21Matrix::SubMatrix(const S21Matrix& other) {
    if (cols_ != other.cols_ || rows_ != other.rows_) {
        throw std::out_of_range("Different matrix dimensions");
    }

    for(int i = 0; i < rows_; i++) {
            for(int j = 0; j < cols_; j++) {
                matrix_[i][j] -= other.matrix_[i][j];
            }
    }     
}

S21Matrix S21Matrix::Transpose() noexcept{
    S21Matrix temp(cols_, rows_);

    for(int i = 0; i < rows_; i++)
        for(int j = 0; j < cols_; j++)
            temp.matrix_[j][i] = matrix_[i][j];

    return temp;
}

double S21Matrix::Determinant() const  {
    // if (rows_ == 0)
        // throw std::out_of_range("rows is 0");
    // if (cols_ == 0)
        // throw std::out_of_range("columns is 0");

    if (rows_ != cols_)
        throw std::out_of_range("the matrix is not square");
    

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

S21Matrix S21Matrix::CalcComplements() {
    
    // if (rows_ == 0)
        // throw std::out_of_range("rows is 0");
    // if (cols_ == 0)
        // throw std::out_of_range("columns is 0");
    if (cols_ == 1 && rows_ == 1)
        throw std::out_of_range("inappropriate matrix rows and cols should be > 1");
    if (rows_ != cols_)
        throw std::out_of_range("the matrix is not square");

    S21Matrix temp(rows_, cols_);
    for(int i = 0; i < rows_; i++)
        for(int j = 0; j < cols_; j++)
            temp.matrix_[i][j] = matrix_[i][j];

    for(int i = 0; i < rows_; i++) {
        for (int j = 0; j < rows_; j++) {
            const S21Matrix little = do_lit(i, j);
            double det = 0.0;
            det = little.Determinant();
            temp.matrix_[i][j] =  det * minus_one_pow(i + j);
        }
    }
    return temp;
}

S21Matrix S21Matrix::InverseMatrix() {
    double det = 0.0;

    S21Matrix temp(rows_, cols_);
    for(int i = 0; i < rows_; i++)
        for(int j = 0; j < cols_; j++)
            temp.matrix_[i][j] = matrix_[i][j];
    det = temp.Determinant();

    if (det == 0)
        throw std::out_of_range("matrix determinant is 0");
    
    S21Matrix first = temp.Transpose();

    S21Matrix second = first.CalcComplements();
   
    for(int i = 0; i < rows_; i++) {
        for(int j = 0; j < cols_; j++) {
            temp.matrix_[i][j] = second.matrix_[i][j] / det;
        }
    }
   
    return temp;
}

void S21Matrix::MulNumber(const double num) noexcept{
for(int i = 0; i < rows_; i++) {
            for(int j = 0; j < cols_; j++) {
                matrix_[i][j] *= num;
            }
    }
}

void S21Matrix::MulMatrix(const S21Matrix& other) {
    S21Matrix temp(rows_, other.cols_);
    if (rows_ != other.cols_) {
        throw std::out_of_range("the number of columns of the first matrix is not equal to the number of rows of the second matrix");
    }

    for(int i = 0; i < rows_; i++) {
        for(int j = 0; j < other.cols_; j++) {
            temp.matrix_[i][j] = 0;
            for(int inner = 0; inner < cols_; inner++)
                temp.matrix_[i][j] += matrix_[i][inner] * other.matrix_[inner][j];
        }
    }
    
    *this = std::move(temp);
    // destroy temp
}

S21Matrix::S21Matrix(S21Matrix &&other) {
    rows_ = other.rows_;
    cols_ = other.cols_;

    matrix_ = other.matrix_;
    other.matrix_ = nullptr;
    other.rows_ = 0;
    other.cols_ = 0;
}

S21Matrix& S21Matrix::operator=(S21Matrix &&other) {
    if(this == &other)
        return *this;
    
    rows_ = other.rows_;
    cols_ = other.cols_;
    matrix_ = other.matrix_;

    other.cols_ = 0;
    other.rows_ = 0;
    other.matrix_ = nullptr;

    return *this;
}

bool S21Matrix::EqMatrix(const S21Matrix& other) const {
    if (rows_ != other.rows_ || cols_ != other.cols_) 
        return false;

    for(int i = 0; i < rows_; i++) 
        for(int j = 0; j < cols_; j++) 
            if (s21_fabs(matrix_[i][j] - other.matrix_[i][j]) > 1e-9) 
                return false;
    
    return true;
}

int S21Matrix::GetRow() { //функция получает значение числа строк
    return (rows_);
}

int S21Matrix::GetCol() { //функция получает значение числа столбцов
    return (cols_);
}

void S21Matrix::SetRow(const int number) {
    if (number <= 0 )
        throw std::out_of_range("row cant be negative or 0");

    S21Matrix temp(number, cols_);

    if (rows_ < number) {
        for(int i = 0; i < rows_; i++) 
            for(int j = 0; j < cols_; j++) 
                temp.matrix_[i][j] = matrix_[i][j];
        for (int i = rows_; i < number; i++)  
            for(int j = 0; j < cols_; j++) 
                temp.matrix_[i][j] = 0;  
    temp.rows_ = number;
    }

    if (rows_ > number) {
        for(int i = 0; i < number; i++) 
            for(int j = 0; j < cols_; j++) 
                temp.matrix_[i][j] = matrix_[i][j];
    temp.rows_ = number;    
    }
    *this = temp;
}

void S21Matrix::SetCol(const int number) {
    if (number <= 0 )
        throw std::out_of_range("row cant be negative or 0");

    S21Matrix temp(rows_, number);

    if (cols_ < number) {
        for(int i = 0; i < rows_; i++) 
            for(int j = 0; j < cols_; j++) 
                temp.matrix_[i][j] = matrix_[i][j];
        for (int i = 0; i < rows_; i++)  
            for(int j = cols_; j < number; j++) 
                temp.matrix_[i][j] = 0;  
    temp.cols_ = number;
    }

    if (cols_ > number) {
        for(int i = 0; i < rows_; i++) 
            for(int j = 0; j < number; j++) 
                temp.matrix_[i][j] = matrix_[i][j];
    temp.cols_ = number;    
    }
    *this = temp;
}

double S21Matrix::operator()(int row_index, int col_index) const//перегрузка круглых скобок для матрицы.
{                             // Если m - матрица, то m(i,j) будет
           // 3           2
// индекс от 0 включительно до размера не влючительно
    if (row_index >= rows_ || col_index >= cols_) {
            throw std::out_of_range("Index is outside the matrix");
        }

    if (row_index < 0 || col_index < 0) {
            throw std::out_of_range("Index is outside the matrix");
        }

    return (matrix_[row_index][col_index]);  //означать i,j-тый элемент матрицы
}

double& S21Matrix::operator()(int row, int col)//перегрузка круглых скобок для матрицы.
{                             // Если m - матрица, то m(i,j) будет
    if (row >= rows_ || col >= cols_) {
            throw std::out_of_range("Index is outside the matrix");
        }

    if (row < 0 || col < 0) {
            throw std::out_of_range("Index is outside the matrix");
        }
    return (matrix_[row][col]);  //означать i,j-тый элемент матрицы
}

S21Matrix& S21Matrix::operator= (const S21Matrix &other) {
    // Проверка на самоприсваивание
    if (this == &other)
        return *this;

    // освободить память
    S21Matrix::~S21Matrix();

    rows_ = other.rows_;
    cols_ = other.cols_;

    matrix_= new double* [rows_]; 
    for(int i = 0; i < rows_; i++) 
        matrix_[i] = new double[cols_];

    // Выполняем копирование значений

    for(int i = 0; i < rows_; i++)
            for(int j = 0; j < other.cols_; j++)
                matrix_[i][j] = other.matrix_[i][j];
 
    // Возвращаем текущий объект
    return *this;
}

bool operator==(const S21Matrix &a, const S21Matrix &b) {
    return (a.EqMatrix(b)); 
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
    } //else
    //     std::cout << "error calc\n";
    return temp;
}

S21Matrix& S21Matrix::operator+=(const S21Matrix &other) {
	if (other.rows_ != rows_ || other.cols_ != cols_) {
        throw std::out_of_range("Different matrix dimensions");
    }
    rows_ = other.rows_;
    cols_ = other.cols_;
    S21Matrix::SumMatrix(other);

	// Возвращаем текущий объект, чтобы иметь возможность выполнять цепочку операций с +=
	return *this;
}

S21Matrix& S21Matrix::operator-=(const S21Matrix &other) {
    if (other.rows_ != rows_ || other.cols_ != cols_) {
        throw std::out_of_range("Different matrix dimensions");
    }

    rows_ = other.rows_;
    cols_ = other.cols_;

    S21Matrix::SubMatrix(other);

    return *this;
}

S21Matrix& S21Matrix::operator*=(const double number) {
    S21Matrix::MulNumber(number);
    return *this;
}

S21Matrix& S21Matrix::operator*=(const S21Matrix &other) {
    // if (other.rows_ != rows_ || other.cols_ != cols_) {
        // throw std::out_of_range("Different matrix dimensions");
    // }
    S21Matrix::MulMatrix(other);
    // rows_ = other.rows_;
    // cols_ = other.cols_;
    return *this;
}
