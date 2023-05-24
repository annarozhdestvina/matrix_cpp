#include <gtest/gtest.h>
#include "../s21_matrix.h"

TEST(inverse_matrix, test1) {
    S21Matrix m1(3, 3);
    m1.Fill();

    try {
        m1.InverseMatrix();
        FAIL() << "Expected std::matrix determinant is 0";
    }
    catch(std::out_of_range const & err) {
        EXPECT_EQ(err.what(),std::string("matrix determinant is 0"));
    }
    catch(...) {
        FAIL() << "Expected std::matrix determinant is 0";
    }
}

TEST(inverse_matrix, test2) {
    S21Matrix m1(3, 3);
    m1(0, 0) = 2;
    m1(0, 1) = 5;
    m1(0, 2) = 7;
    m1(1, 0) = 6;
    m1(1, 1) = 3;
    m1(1, 2) = 4;
    m1(2, 0) = 5;
    m1(2, 1) = -2;
    m1(2, 2) = -3;

    m1.InverseMatrix();

    S21Matrix m2(3, 3);
    m2(0, 0) = 1;
    m2(0, 1) = -1;
    m2(0, 2) = 1;
    m2(1, 0) = -38;
    m2(1, 1) = 41;
    m2(1, 2) = -34;
    m2(2, 0) = 27;
    m2(2, 1) = -29;
    m2(2, 2) = 24;

    EXPECT_TRUE(m1.EqMatrix(m2));
}

TEST(inverse_matrix, test3) {
    S21Matrix m1(0, 5);
    m1.Fill();

    try {
        m1.InverseMatrix();
        FAIL() << "Expected std::the matrix is not square";
    }
    catch(std::out_of_range const & err) {
        EXPECT_EQ(err.what(),std::string("the matrix is not square"));
    }
    catch(...) {
        FAIL() << "Expected std::the matrix is not square";
    }
}

TEST(inverse_matrix, test4) {
    S21Matrix m1(0, 0);
    m1.Fill();

    try {
        m1.InverseMatrix();
        FAIL() << "Expected std::rows is 0";
    }
    catch(std::out_of_range const & err) {
        EXPECT_EQ(err.what(),std::string("rows is 0"));
    }
    catch(...) {
        FAIL() << "Expected std::rows is 0";
    }
}

TEST(inverse_matrix, test5) {
    S21Matrix m1(1, 1);
    m1.Fill();

    try {
        m1.InverseMatrix();
        FAIL() << "Expected std::inappropriate matrix rows and cols should be > 1";
    }
    catch(std::out_of_range const & err) {
        EXPECT_EQ(err.what(),std::string("inappropriate matrix rows and cols should be > 1"));
    }
    catch(...) {
        FAIL() << "Expected std::inappropriate matrix rows and cols should be > 1";
    }
}