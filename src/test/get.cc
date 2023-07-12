#include <gtest/gtest.h>
#include "../s21_matrix.h"

TEST(get_operator, test1) {
    S21Matrix m1(3, 4);
    m1.Fill();

    int Cols_test = m1.GetCol();
    int Cols_actual = 4; 

    EXPECT_EQ(Cols_actual, Cols_test);
}

TEST(get_operator, test2) {
    S21Matrix m1(3, 4);
    m1.Fill();

    int Rows_test = m1.GetRow();
    int Rows_actual = 3; 

    EXPECT_EQ(Rows_actual, Rows_test);
}

TEST(set_operator, test3) {
    S21Matrix m1(3, 4);
    m1.Fill();
    m1.SetRow(4);

    S21Matrix m2(4, 4);
    m2(0, 0) = 1.0;
    m2(0, 1) = 2.0;
    m2(0, 2) = 3.0;
    m2(0, 3) = 4.0;
    m2(1, 0) = 5.0;
    m2(1, 1) = 6.0;
    m2(1, 2) = 7.0;
    m2(1, 3) = 8.0;
    m2(2, 0) = 9.0;
    m2(2, 1) = 10.0;    
    m2(2, 2) = 11.0;
    m2(2, 3) = 12.0;
    m2(3, 0) = 0.0;
    m2(3, 1) = 0.0;
    m2(3, 2) = 0.0;
    m2(3, 3) = 0.0; 

    EXPECT_TRUE(m1.EqMatrix(m2));
}

TEST(set_operator, test4) {
    S21Matrix m1(3, 4);
    m1.Fill();
    m1.SetRow(2);
    
    S21Matrix m2(2, 4);
    m2(0, 0) = 1.0;
    m2(0, 1) = 2.0;
    m2(0, 2) = 3.0;
    m2(0, 3) = 4.0;
    m2(1, 0) = 5.0;
    m2(1, 1) = 6.0;
    m2(1, 2) = 7.0;
    m2(1, 3) = 8.0;

    EXPECT_TRUE(m1.EqMatrix(m2));
}


TEST(set_operator, test5) {
    S21Matrix m1(4, 3);
    m1.Fill();
    m1.SetCol(4);

    S21Matrix m2(4, 4);
    m2(0, 0) = 1.0;
    m2(0, 1) = 2.0;
    m2(0, 2) = 3.0;
    m2(0, 3) = 0.0;
    m2(1, 0) = 4.0;
    m2(1, 1) = 5.0;
    m2(1, 2) = 6.0;
    m2(1, 3) = 0.0;
    m2(2, 0) = 7.0;
    m2(2, 1) = 8.0;    
    m2(2, 2) = 9.0;
    m2(2, 3) = 0.0;
    m2(3, 0) = 10.0;
    m2(3, 1) = 11.0;
    m2(3, 2) = 12.0;
    m2(3, 3) = 0.0; 

    EXPECT_TRUE(m1.EqMatrix(m2));
}

TEST(set_operator, test6) {
    S21Matrix m1(3, 4);
    m1.Fill();
    m1.SetCol(3); 
    
    S21Matrix m2(3, 3);
    m2(0, 0) = 1.0;
    m2(0, 1) = 2.0;
    m2(0, 2) = 3.0;
    m2(1, 0) = 5.0;
    m2(1, 1) = 6.0;
    m2(1, 2) = 7.0;
    m2(2, 0) = 9.0;
    m2(2, 1) = 10.0;    
    m2(2, 2) = 11.0;

    EXPECT_TRUE(m1.EqMatrix(m2));
}

TEST(set_operator, test7) {
    S21Matrix m1(3, 4);
    m1.Fill(); 
    
    try {
        m1.SetCol(-3);
        FAIL() << "Expected std::row can't be negative or 0";
    }
    catch(std::out_of_range const & err) {
        EXPECT_EQ(err.what(),std::string("row can't be negative or 0"));
    }
    catch(...) {
        FAIL() << "Expected std::row can't be negative or 0";
    }
}

TEST(set_operator, test8) {
    S21Matrix m1(3, 4);
    m1.Fill(); 
    
    try {
        m1.SetCol(0);
        FAIL() << "Expected std::row can't be negative or 0";
    }
    catch(std::out_of_range const & err) {
        EXPECT_EQ(err.what(),std::string("row can't be negative or 0"));
    }
    catch(...) {
        FAIL() << "Expected std::row can't be negative or 0";
    }
}

TEST(set_operator, test9) {
    S21Matrix m1(3, 4);
    m1.Fill(); 
    
    try {
        m1.SetRow(-3);
        FAIL() << "Expected std::row can't be negative or 0";
    }
    catch(std::out_of_range const & err) {
        EXPECT_EQ(err.what(),std::string("row can't be negative or 0"));
    }
    catch(...) {
        FAIL() << "Expected std::row can't be negative or 0";
    }
}

TEST(set_operator, test10) {
    S21Matrix m1(3, 4);
    m1.Fill(); 
    
    try {
        m1.SetRow(0);
        FAIL() << "Expected std::row can't be negative or 0";
    }
    catch(std::out_of_range const & err) {
        EXPECT_EQ(err.what(),std::string("row can't be negative or 0"));
    }
    catch(...) {
        FAIL() << "Expected std::row can't be negative or 0";
    }
}

TEST(set_operator, test11) {
    S21Matrix m1(3, 4);
    m1.Fill(); 
    
    EXPECT_THROW(m1.SetRow(0), std::out_of_range);
}