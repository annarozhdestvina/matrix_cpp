#include <gtest/gtest.h>
#include "../s21_matrix.h"

TEST(operator_assign, test1) {
    S21Matrix m1(2, 3);
    m1.Fill();

    S21Matrix m2(8, 9);
    m2 = m1;

    EXPECT_TRUE(m1.EqMatrix(m2));
}

TEST(operator_assign, test2) {
    S21Matrix m1(2, 3);
    m1.Fill();
    m1.MulNumber(-1);

    S21Matrix m2(8, 1);
    m2 = m1;

    EXPECT_TRUE(m1.EqMatrix(m2));
}

TEST(operator_assign, test3) {
    S21Matrix m1(2, 3);
    m1.Fill();

    S21Matrix m2(3, 6);
    m2 = m1;

    EXPECT_TRUE(m1.EqMatrix(m2));
}

TEST(operator_assign, test4) {
    S21Matrix m1(2, 3);
    m1.Fill();
    // m1 = m1;

    // EXPECT_TRUE(m1.EqMatrix(m1));
}