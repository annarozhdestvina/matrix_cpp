#include <gtest/gtest.h>
#include "../s21_matrix.h"

TEST(transpose, test1) {
    S21Matrix m1(3, 4);
    m1.Fill();
    m1.Print();

    S21Matrix temp = m1.Transpose();

    S21Matrix m2(4, 3);
    m2(0, 0) = 1.0;
    m2(0, 1) = 5.0;
    m2(0, 2) = 9.0;
    m2(1, 0) = 2.0;
    m2(1, 1) = 6.0;
    m2(1, 2) = 10.0;
    m2(2, 0) = 3.0;
    m2(2, 1) = 7.0;
    m2(2, 2) = 11.0;
    m2(3, 0) = 4.0;
    m2(3, 1) = 8.0;
    m2(3, 2) = 12.0;

    EXPECT_TRUE(temp.EqMatrix(m2));
}

TEST(transpose, test2) {
    S21Matrix m1(3, 5);
    m1.Fill();
    m1.MulNumber(0);

    S21Matrix m2(3, 5);
    m2(0, 0) = 0;
    m2(0, 1) = 0;
    m2(0, 2) = 0;
    m2(0, 3) = 0;
    m2(0, 4) = 0;
    m2(1, 0) = 0;
    m2(1, 1) = 0;
    m2(1, 2) = 0;
    m2(1, 3) = 0;
    m2(1, 4) = 0;
    m2(2, 0) = 0;
    m2(2, 1) = 0;
    m2(2, 2) = 0;
    m2(2, 3) = 0;
    m2(2, 4) = 0;

    EXPECT_TRUE(m1.EqMatrix(m2));
}