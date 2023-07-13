#include <gtest/gtest.h>
#include "../s21_matrix.h"

TEST(operator_bool, test1) {
    S21Matrix m1(2, 3);
    m1.Fill();

    S21Matrix m2(2, 3);
    m2.Fill();
    bool a = (m2 == m1);

    EXPECT_EQ(true, a);
}

TEST(operator_bool, test2) {
    S21Matrix m1(2, 3);
    m1.Fill();

    S21Matrix m2(3, 3);
    m2.Fill();
    bool a = (m2 == m1);

    EXPECT_EQ(false, a);
}

TEST(operator_bool, test3) {
    S21Matrix m1(2, 3);
    m1.Fill();
    m1.MulNumber(-1);

    S21Matrix m2(2, 3);
    m2.Fill();
    bool a = (m2 == m1);

    EXPECT_EQ(false, a);
}

TEST(operator_bool, test4) {
    S21Matrix m1(2, 3);
    m1.Fill();
    m1.MulNumber(-1);

    S21Matrix m2(2, 3);
    m2.Fill();
    m2.MulNumber(-1);
    bool a = (m2 == m1);

    EXPECT_EQ(true, a);
}