#include <gtest/gtest.h>
#include "../s21_matrix.h"
#include <stdexcept>

TEST(operator_mul_number, test1) {
    S21Matrix m1(2, 3);
    m1.Fill();

    m1 *= 3;

    S21Matrix m2(2, 3);
    m2(0, 0) = 3.0;
    m2(0, 1) = 6.0;
    m2(0, 2) = 9.0;
    m2(1, 0) = 12.0;
    m2(1, 1) = 15.0;
    m2(1, 2) = 18.0;

    EXPECT_TRUE(m1.EqMatrix(m2));
}

TEST(operator_mul_number, test2) {
    S21Matrix m1(2, 3);
    m1.Fill();

    m1 *= 0;

    S21Matrix m2(2, 3);
    m2(0, 0) = 0.0;
    m2(0, 1) = 0.0;
    m2(0, 2) = 0.0;
    m2(1, 0) = 0.0;
    m2(1, 1) = 0.0;
    m2(1, 2) = 0.0;

    EXPECT_TRUE(m1.EqMatrix(m2));
}

TEST(operator_mul_number, test3) {
    S21Matrix m1(2, 3);
    m1.Fill();

    m1 *= -3;

    S21Matrix m2(2, 3);
    m2(0, 0) = -3.0;
    m2(0, 1) = -6.0;
    m2(0, 2) = -9.0;
    m2(1, 0) = -12.0;
    m2(1, 1) = -15.0;
    m2(1, 2) = -18.0;

    EXPECT_TRUE(m1.EqMatrix(m2));
}