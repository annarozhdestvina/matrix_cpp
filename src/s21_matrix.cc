#include <iostream>

class S21Matrix {
private:
    // Attributes
    int rows_, cols_;         // Rows and columns
    double **matrix_;         // Pointer to the memory where the matrix is allocated
    static int s_id_;         // статическая переменная 
public:
    S21Matrix() : rows_{0}, cols_{0}, matrix_{nullptr} {}          // Default constructor
    ~S21Matrix();               // Destructor

    //int S21Matrix2; 
    
    void SumMatrix(const S21Matrix& other); 
    void SubMatrix(const S21Matrix& other); 
    // Other methods..
    S21Matrix(int rows, int columns);

    void Fill();
    void FillC();

    double getMatrix() const {
        return **matrix_;
    }

    void Print() const {
        for(int i = 0; i < rows_; i++) {
            for(int j = 0; j < cols_; j++) {
                std::cout<< matrix_[i][j] << ' ';
            }
            std::cout << '\n';
        }
    }

    bool EqMatrix(const S21Matrix& other);
    int GetRow(); //метод получает значение числа строк
    int GetCol(); //метод получает значение числа столбцов
    double& operator()(int, int); //перегрузка скобок для матрицы
    double operator()(int, int) const; //перегрузка скобок для матрицы
    
    friend S21Matrix operator+(const S21Matrix &a, const S21Matrix &b);

    void MulNumber(const double num);
};

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
        delete[] matrix_;
        rows_ = 0;
        cols_ = 0;
}

int main() {
    S21Matrix matA(4, 3);
    matA.Fill();
    std::cout << "matrix A:\n";
    matA.Print();

    S21Matrix matB(3, 3);
    matB.Fill();
    std::cout << "matrix B:\n";
    matB.Print();

    S21Matrix matC(3, 3);
    matC.FillC();
    std::cout << "matrix C:\n";
    matC.Print();

    bool a;
    a = matA.EqMatrix(matB);
    std::cout << "res of equalizing is " << a << std::endl;

    S21Matrix matA1(4, 3);
    matA1.Fill();
    std::cout << "matrix A1:\n";
    matA1.Print();
    a = matA.EqMatrix(matA1);
    std::cout << "res of equalizing is " << a << std::endl;

    matB.SumMatrix(matB);
    std::cout << "after sum\n";
    matB.Print();

    S21Matrix matD(3, 3);
    matD.Fill();
    std::cout << "matrix D:\n";
    matD.Print();

    std::cout << "matric C before sub\n";
    matC.Print();
    matC.SubMatrix(matD);
    std::cout << "after sub\n";
    matC.Print();

    std::cout << "matric A before mul on number\n";
    matA.Print();
    matA.MulNumber(4);
    std::cout << "after mul on number\n";
    matA.Print();

    /*S21Matrix result_sub(3, 3);
    result_sub.Fill();
    result_sub = matA + matD;
    std::cout << "overloading operator +\n";
    result_sub.Print();*/

    return 0;
}