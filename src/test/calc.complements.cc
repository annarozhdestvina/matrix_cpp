#include <gtest/gtest.h>
#include "../s21_matrix.h"

TEST(calc_complements, test1) {
    S21Matrix m1(3, 3);
    m1.Fill();

    S21Matrix temp = m1.CalcComplements();
    S21Matrix m2(3, 3);
    m2(0, 0) = -3;
    m2(0, 1) = 6;
    m2(0, 2) = -3;
    m2(1, 0) = 6;
    m2(1, 1) = -12;
    m2(1, 2) = 6;
    m2(2, 0) = -3;
    m2(2, 1) = 6;
    m2(2, 2) = -3;

    EXPECT_TRUE(temp.EqMatrix(m2));
}

TEST(calc_complements, test2) {
    S21Matrix m1(2, 2);
    m1.Fill();
    S21Matrix temp = m1.CalcComplements();

    S21Matrix m2(2, 2);
    m2(0, 0) = 4;
    m2(0, 1) = -3;
    m2(1, 0) = -2;
    m2(1, 1) = 1;

    EXPECT_TRUE(temp.EqMatrix(m2));
}

TEST(calc_complements, test3) {
    S21Matrix m1(3, 3);
    m1(0, 0) = 1;
    m1(0, 1) = 2;
    m1(0, 2) = 3;
    m1(1, 0) = 0;
    m1(1, 1) = 4;
    m1(1, 2) = 2;
    m1(2, 0) = 5;
    m1(2, 1) = 2;
    m1(2, 2) = 1;

    S21Matrix temp = m1.CalcComplements();
    S21Matrix m2(3, 3);
    m2(0, 0) = 0;
    m2(0, 1) = 10;
    m2(0, 2) = -20;
    m2(1, 0) = 4;
    m2(1, 1) = -14;
    m2(1, 2) = 8;
    m2(2, 0) = -8;
    m2(2, 1) = -2;
    m2(2, 2) = 4;

    EXPECT_TRUE(temp.EqMatrix(m2));
}

TEST(calc_complements, test4) {
    S21Matrix m1(0, 5);
    m1.Fill();

    try {
        m1.CalcComplements();
        FAIL() << "Expected std::rows is 0";
    }
    catch(std::out_of_range const & err) {
        EXPECT_EQ(err.what(),std::string("rows is 0"));
    }
    catch(...) {
        FAIL() << "Expected std::rows is 0";
    }
}

TEST(calc_complements, test5) {
    S21Matrix m1(0, 0);
    m1.Fill();

    try {
        m1.CalcComplements();
        FAIL() << "Expected std::rows is 0";
    }
    catch(std::out_of_range const & err) {
        EXPECT_EQ(err.what(),std::string("rows is 0"));
    }
    catch(...) {
        FAIL() << "Expected std::rows is 0";
    }
}

TEST(calc_complements, test6) {
    S21Matrix m1(1, 1);
    m1.Fill();

    try {
        m1.CalcComplements();
        FAIL() << "Expected std::inappropriate matrix rows and cols should be > 1";
    }
    catch(std::out_of_range const & err) {
        EXPECT_EQ(err.what(),std::string("inappropriate matrix rows and cols should be > 1"));
    }
    catch(...) {
        FAIL() << "Expected std::inappropriate matrix rows and cols should be > 1";
    }
}

TEST(calc_complements, test7) {
    S21Matrix m1(3, 0);
    m1.Fill();

    try {
        m1.CalcComplements();
        FAIL() << "Expected std::columns is 0";
    }
    catch(std::out_of_range const & err) {
        EXPECT_EQ(err.what(),std::string("columns is 0"));
    }
    catch(...) {
        FAIL() << "Expected std::columns is 0";
    }
}

TEST(calc_complements, test8) {
    S21Matrix m1(3, 7);
    m1.Fill();

    try {
        m1.CalcComplements();
        FAIL() << "Expected std::the matrix is not square";
    }
    catch(std::out_of_range const & err) {
        EXPECT_EQ(err.what(),std::string("the matrix is not square"));
    }
    catch(...) {
        FAIL() << "Expected std::the matrix is not square";
    }
}
