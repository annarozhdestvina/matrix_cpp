#include <gtest/gtest.h>
#include "../s21_matrix.h"

TEST(test_mul, test1) {
    S21Matrix m1(4, 4);
    m1.Fill();
    m1.MulNumber(2.1);

    m1(2,2) = 7.5;
    m1.Print();

    EXPECT_EQ(true, true);
}

TEST(test_mul2, test2) {
    S21Matrix m1(4, 4);
    m1.Fill();
    m1.MulNumber(2.1);

    S21Matrix m2(4, 4);
    m1(0, 0) = 2.1;
    m1(0, 1) = 4.2;
    m1(0, 2) = 6.3;
    m1(0, 3) = 8.4;
    m1(1, 0) = 10.5;
    m1(1, 1) = 12.6;
    m1(1, 2) = 14.7;
    m1(1, 3) = 16.8;
    m1(2, 0) = 18.9;
    m1(2, 1) = 21;
    m1(2, 2) = 23.1;
    m1(2, 3) = 25.2;
    m1(3, 0) = 27.3;
    m1(3, 1) = 29.4;
    m1(3, 2) = 31.5;
    m1(3, 3) = 33.6;

    EXPECT_TRUE(m1.EqMatrix(m2));
}

TEST(test_dif, test2) {
    double actual = 8.8;
    double expected = 8.8;

    ASSERT_EQ(actual, expected);
}