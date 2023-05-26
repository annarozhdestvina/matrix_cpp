#include <gtest/gtest.h>
#include "../s21_matrix.h"

TEST(mul_matrix, test1) {
    S21Matrix m1(3, 3);
    m1(0, 0) = 0;
    m1(0, 1) = 2;
    m1(0, 2) = 0;
    m1(1, 0) = 0;
    m1(1, 1) = 0;
    m1(1, 2) = 0;
    m1(2, 0) = 0;
    m1(2, 1) = 0;
    m1(2, 2) = 0;

    S21Matrix m2(3, 3);
    m2(0, 0) = 0;
    m2(0, 1) = 0;
    m2(0, 2) = 0;
    m2(1, 0) = 3;
    m2(1, 1) = 2;
    m2(1, 2) = -1;
    m2(2, 0) = 0;
    m2(2, 1) = 0;
    m2(2, 2) = 0;

    S21Matrix m3(3, 3);
    m3(0, 0) = 6;
    m3(0, 1) = 4;
    m3(0, 2) = -2;
    m3(1, 0) = 0;
    m3(1, 1) = 0;
    m3(1, 2) = 0;
    m3(2, 0) = 0;
    m3(2, 1) = 0;
    m3(2, 2) = 0;

    m1.MulMatrix(m2);

    EXPECT_TRUE(m1.EqMatrix(m3));
}

TEST(mul_matrix, test2) {
    S21Matrix m1(2, 3);
    m1.Fill();

    S21Matrix m2(3, 2);
    m2.Fill();

    m1.MulMatrix(m2);

    S21Matrix m3(2, 2);
    m3(0, 0) = 22;
    m3(0, 1) = 28;
    m3(1, 0) = 49;
    m3(1, 1) = 64;

    EXPECT_TRUE(m1.EqMatrix(m3));
}

TEST(mul_matrix, test3) {
    S21Matrix m1(3, 3);
    m1(0, 0) = 1;
    m1(0, 1) = 2;
    m1(0, 2) = 3;
    m1(1, 0) = 4;
    m1(1, 1) = 5;
    m1(1, 2) = 6;
    m1(2, 0) = -1;
    m1(2, 1) = 5;
    m1(2, 2) = -1;

    S21Matrix m2(3, 3);
    m2(0, 0) = 1;
    m2(0, 1) = 2;
    m2(0, 2) = -1;
    m2(1, 0) = 3;
    m2(1, 1) = -1;
    m2(1, 2) = 4;
    m2(2, 0) = 5;
    m2(2, 1) = 6;
    m2(2, 2) = 2;

    S21Matrix m3(3, 3);
    m3(0, 0) = 22;
    m3(0, 1) = 18;
    m3(0, 2) = 13;
    m3(1, 0) = 49;
    m3(1, 1) = 39;
    m3(1, 2) = 28;
    m3(2, 0) = 9;
    m3(2, 1) = -13;
    m3(2, 2) = 19;

    m1.MulMatrix(m2);
    
    EXPECT_TRUE(m1.EqMatrix(m3));
}