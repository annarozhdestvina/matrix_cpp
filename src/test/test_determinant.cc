#include <gtest/gtest.h>
#include "../s21_matrix.h"

TEST(determinant, test1) {
    S21Matrix m1(1, 1);
    m1.Fill();

    double a = 1.0;
    double b = m1.Determinant();

    EXPECT_EQ(a, b);
}

TEST(determinant, test2) {
    S21Matrix m1(2, 2);
    m1.Fill();

    double a = -2.0;
    double b = m1.Determinant();

    EXPECT_EQ(a, b);
}

TEST(determinant, test32) {
    S21Matrix m1(2, 4);
    m1.Fill();

    try {
        m1.Determinant();
        FAIL() << "Expected std::the matrix is not square";
    }
    catch(std::out_of_range const & err) {
        EXPECT_EQ(err.what(),std::string("the matrix is not square"));
    }
    catch(...) {
        FAIL() << "Expected std::the matrix is not square";
    }
}

TEST(determinant, test4) {
    S21Matrix m1(4, 4);
    m1.Fill();
    std::cout << "m1 before do_lit\n";
    m1.Print();
    // double a = m1.Determinant();
    // std::cout << "det m1: " << a;
    S21Matrix lit;
    m1.do_lit(1, 1);
    std::cout << "m1 after do_lit\n";
    m1.Print();
}

TEST(determinant, test5) {
    S21Matrix m1(4, 4);
    m1.Fill();
    double a = m1.Determinant();

    std::cout << "det a: " << a;
}

TEST(determinant, test6) {
    S21Matrix m1(3, 3);
    m1.Fill();
    const double a = m1.Determinant();

    EXPECT_DOUBLE_EQ(0.0, a);
}

TEST(determinant, test7) {
    S21Matrix m1(3, 3);
    m1(0, 0) = 1.5;
    m1(0, 1) = 2.5;
    m1(0, 2) = 3.5;
    m1(1, 0) = 5.5;
    m1(1, 1) = 5.5;
    m1(1, 2) = 5.5;
    m1(2, 0) = 7.5;
    m1(2, 1) = 0.5;
    m1(2, 2) = 5.5;
    double a = m1.Determinant();

    EXPECT_DOUBLE_EQ(-66.0, a);
}