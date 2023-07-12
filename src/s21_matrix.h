class S21Matrix {
private:
    // Attributes
    int rows_, cols_;         // Rows and columns
    double **matrix_;         // Pointer to the memory where the matrix is allocated

private:
    S21Matrix do_lit(int row_del, int col_del) const noexcept;

public:
    S21Matrix(); // Default constructor
    S21Matrix(int rows, int columns); 
    ~S21Matrix();               // Destructor
    S21Matrix(const S21Matrix& other);
    
    void Fill() noexcept;
    void Print() const noexcept;

    // Other methods..
    void SumMatrix(const S21Matrix& other); 
    void SubMatrix(const S21Matrix& other); 

    S21Matrix Transpose() noexcept;
    double Determinant() const;
    S21Matrix CalcComplements();
    S21Matrix InverseMatrix();

    void MulNumber(const double num) noexcept;
    void MulMatrix(const S21Matrix& other);

    S21Matrix(S21Matrix &&other);
    S21Matrix& operator=(S21Matrix &&other);

    bool EqMatrix(const S21Matrix& other) const;
    int GetRow();
    int GetCol(); 
    void SetRow(const int number);
    void SetCol(const int number);
    double operator()(int, int) const; 
    double& operator()(int, int); 

    S21Matrix& operator=(const S21Matrix &str);
    bool friend operator==(const S21Matrix &a, const S21Matrix &b);
    
    friend S21Matrix operator+(const S21Matrix &a, const S21Matrix &b);
    friend S21Matrix operator-(const S21Matrix &a, const S21Matrix &b);
    friend S21Matrix operator*(const S21Matrix &a, const S21Matrix &b);

    S21Matrix& operator+=(const S21Matrix &other);
    S21Matrix& operator-=(const S21Matrix &other);
    S21Matrix& operator*=(const double number) noexcept;
    S21Matrix& operator*=(const S21Matrix &other);
};