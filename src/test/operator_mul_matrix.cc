#include <gtest/gtest.h>
#include "../s21_matrix.h"
#include <stdexcept>

TEST(operator_mul_matrix, test1) {
    S21Matrix m1(2, 3);
    m1.Fill();

    S21Matrix m2(3, 2);
    m2.Fill();

    m1 *= m2;

    S21Matrix m3(2, 2);
    m3(0, 0) = 22.0;
    m3(0, 1) = 28.0;
    m3(1, 0) = 49.0;
    m3(1, 1) = 64.0;

    EXPECT_TRUE(m1.EqMatrix(m3));
}

TEST(operator_mul_matrix, test2) {
    S21Matrix m1(2, 3);
    m1.Fill();

    S21Matrix m2(3, 2);
    m2(0, 0) = 0.0;
    m2(0, 1) = 0.0;
    m2(1, 0) = 0.0;
    m2(1, 1) = 0.0;
    m2(2, 0) = 0.0;
    m2(2, 1) = 0.0;

    m1 *= m2;

    S21Matrix m3(2, 2);
    m3(0, 0) = 0.0;
    m3(0, 1) = 0.0;
    m3(1, 0) = 0.0;
    m3(1, 1) = 0.0;

    EXPECT_TRUE(m1.EqMatrix(m3));
}

TEST(operator_mul_matrix, test3) {
    S21Matrix m1(2, 3);
    m1.Fill();

    S21Matrix m3(3, 2);
    m3(0, 0) = -3.0;
    m3(0, 1) = -4.0;
    m3(1, 0) = -1.0;
    m3(1, 1) = -5.0;
    m3(2, 0) = -2.0;
    m3(2, 1) = -3.0;
    m1 *= m3;

    S21Matrix m2(2, 2);
    m2(0, 0) = -11.0;
    m2(0, 1) = -23.0;
    m2(1, 0) = -29.0;
    m2(1, 1) = -59.0;
    

    EXPECT_TRUE(m1.EqMatrix(m2));
}

TEST(operator_mul_matrix, test4) {
    S21Matrix m1(4, 3);
    m1.Fill();

    S21Matrix m2(7, 7);
    m2.Fill();

    EXPECT_THROW(m1.MulMatrix(m2), std::out_of_range);
}

 