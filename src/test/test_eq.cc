#include <gtest/gtest.h>
#include "../s21_matrix.h"

TEST(my_tests_eq, test1) {
    S21Matrix m1(3, 4);
    m1.Fill();

    S21Matrix m2(3, 4);
    m2.Fill();


    EXPECT_TRUE(m1.EqMatrix(m2));
}

TEST(my_tests_eq, test2) {
    S21Matrix m1(2, 5);
    m1.Fill();

    S21Matrix m2(2, 5);
    m2.Fill();
    EXPECT_TRUE(m1.EqMatrix(m2));
}

TEST(my_tests_eq, test3) {
    S21Matrix m1(2, 5);
    m1.Fill();

    double m2[2][5] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    // EXPECT_TRUE(m1.EqMatrix(m2));
    // EXPECT_TRUE(false);
}

TEST(test_eq, test4) {
    S21Matrix m1(2, 4);
    m1.Fill();

    // S21Matrix m2(m1);
    // EXPECT_TRUE(m1.EqMatrix(m2));
}

