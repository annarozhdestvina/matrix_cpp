class S21Matrix {
private:
    // Attributes
    int rows_, cols_;         // Rows and columns
    double **matrix_;         // Pointer to the memory where the matrix is allocated
    static int s_id_;         // статическая переменная 
public:
    S21Matrix() : rows_{0}, cols_{0}, matrix_{nullptr} {}; // Default constructor

    ~S21Matrix();               // Destructor

    S21Matrix(const S21Matrix& other);
    
    void SumMatrix(const S21Matrix& other); 
    void SubMatrix(const S21Matrix& other); 
    // Other methods..
    S21Matrix(int rows, int columns);

    S21Matrix Transpose();
    double Determinant() const;
    S21Matrix CalcComplements();
    S21Matrix InverseMatrix();
private:
    S21Matrix do_lit(int row_del, int col_del) const;

public:
    void Fill();

    double getMatrix() const {
        return **matrix_;
    }

    void Print() const noexcept;

    S21Matrix(S21Matrix &&other);
    S21Matrix& operator=(S21Matrix &&other);

    bool EqMatrix(const S21Matrix& other) const;
    int GetRow(); //метод получает значение числа строк
    int GetCol(); //метод получает значение числа столбцов
    void SetRow(const int number);
    void SetCol(const int number);
    double& operator()(int, int); //перегрузка скобок для матрицы
    double operator()(int, int) const; //перегрузка скобок для матрицы

    S21Matrix& operator=(const S21Matrix &str);
    bool friend operator==(const S21Matrix &a, const S21Matrix &b);
    
    friend S21Matrix operator+(const S21Matrix &a, const S21Matrix &b);
    friend S21Matrix operator-(const S21Matrix &a, const S21Matrix &b);
    friend S21Matrix operator*(const S21Matrix &a, const S21Matrix &b);

    S21Matrix& operator+=(const S21Matrix &other);
    S21Matrix& operator-=(const S21Matrix &other);
    S21Matrix& operator*=(const double number);
    S21Matrix& operator*=(const S21Matrix &other);

    void MulNumber(const double num);
    void MulMatrix(const S21Matrix& other);
};