#include <iostream>

class S21Matrix {
private:
    // Attributes
    int rows_, cols_;         // Rows and columns
    double **matrix_;         // Pointer to the memory where the matrix is allocated


    static int s_id_;         // статическая переменная 
public:
    S21Matrix() : rows_{0}, cols_{0}, matrix_{nullptr} {

    }              // Default constructor
    ~S21Matrix();               // Destructor

    //int S21Matrix2; 
    
    void SumMatrix(const S21Matrix& other); 
    // Other methods..
    S21Matrix(int rows, int columns);

    void Fill();

    void Print() const {
        for(int i = 0; i < rows_; i++) {
            for(int j = 0; j < cols_; j++) {
                std::cout<< matrix_[i][j] << ' ';
            }
            std::cout << '\n';
        }
    }

    bool EqMatrix(const S21Matrix& other);
};

S21Matrix::S21Matrix(int rows, int columns): rows_(rows), cols_(columns) {
    double *pointer = new double[rows_ * cols_ *sizeof(double)];
    double **matrix_local = new double*[rows_ * sizeof(double*)];

        for(int i = 0; i < rows_; i++) {
            *(matrix_local + i) = pointer + i*cols_;
        }
        matrix_ = matrix_local;
}

void S21Matrix::Fill() {
    for(int i =0; i < rows_; i++) {
        for(int j =0; j < cols_; j++) {
            matrix_[i][j] = i+j;
        }
    }
}

//int S21Matrix::s_id_ = 8;

S21Matrix::~S21Matrix() {             // Destructor
        delete[] matrix_;
        rows_ = 0;
        cols_ = 0;
}

int main() {
    const int rows = 3;
    const int columns = 4;

    S21Matrix mat(4, 3);
    mat.Fill();
    mat.Print();

    S21Matrix mat2;


    return 0;
}