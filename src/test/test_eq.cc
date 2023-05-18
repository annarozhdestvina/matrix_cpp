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

    S21Matrix m2(m1);
    m1(1, 4) = 5.333;
  
    EXPECT_FALSE(m1.EqMatrix(m2));
}

TEST(test_eq, test4) {
    S21Matrix m1(2, 4);
    m1.Fill();

    S21Matrix m2(m1);
    EXPECT_TRUE(m1.EqMatrix(m2));
}

TEST(test_eq, test5) {
    S21Matrix m1(2, 4);
    m1.Fill();

    S21Matrix m2(m1);
    m1(0, 0) = 55.12;

    EXPECT_EQ(m1.EqMatrix(m2), 0);
}

TEST(test_eq, test6) {
    S21Matrix m1(6, 6);
    m1.Fill();

    S21Matrix m2(7, 7);
    m2.Fill();

    EXPECT_FALSE(m2.EqMatrix(m1));
}

TEST(test_eq, test7) {
    S21Matrix m1(6, 6);
    m1.Fill();

    EXPECT_TRUE(m1.EqMatrix(m1));    
}

