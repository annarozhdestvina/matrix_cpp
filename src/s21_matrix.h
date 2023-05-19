class S21Matrix {
private:
    // Attributes
    int rows_, cols_;         // Rows and columns
    double **matrix_;         // Pointer to the memory where the matrix is allocated
    static int s_id_;         // статическая переменная 
public:
    S21Matrix() : rows_{0}, cols_{0}, matrix_{nullptr} {}          // Default constructor
    ~S21Matrix();               // Destructor

    S21Matrix(const S21Matrix& other);

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

    void Print() const;

    bool EqMatrix(const S21Matrix& other);
    int GetRow(); //метод получает значение числа строк
    int GetCol(); //метод получает значение числа столбцов
    double& operator()(int, int); //перегрузка скобок для матрицы
    double operator()(int, int) const; //перегрузка скобок для матрицы
    
    friend S21Matrix operator+(const S21Matrix &a, const S21Matrix &b);
    friend S21Matrix operator-(const S21Matrix &a, const S21Matrix &b);

    // friend S21Matrix operator*(const S21Matrix &a, const S21Matrix &b);

    void MulNumber(const double num);
    void MulMatrix(const S21Matrix& other);
};