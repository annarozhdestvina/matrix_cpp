#include <gtest/gtest.h>
#include "../s21_matrix.h"

TEST(equal, test1) {
    S21Matrix m1(3, 4);
    m1.Fill();

    S21Matrix m2(3, 4);
    m2.Fill();

    EXPECT_TRUE(m1.EqMatrix(m2));
}

TEST(equal, test2) {
    S21Matrix m1(2, 5);
    m1.Fill();

    S21Matrix m2(2, 5);
    m2.Fill();
    EXPECT_TRUE(m1.EqMatrix(m2));
}

TEST(equal, test3) {
    S21Matrix m1(2, 5);
    m1.Fill();

    S21Matrix m2(m1);
    m1(1, 4) = 5.333;
  
    EXPECT_FALSE(m1.EqMatrix(m2));
}

TEST(equal, test4) {
    S21Matrix m1(2, 4);
    m1.Fill();

    S21Matrix m2(m1);
    EXPECT_TRUE(m1.EqMatrix(m2));
}

TEST(equal, test5) {
    S21Matrix m1(2, 4);
    m1.Fill();

    S21Matrix m2(m1);
    m1(0, 0) = 55.12;

    EXPECT_EQ(m1.EqMatrix(m2), 0);
}

TEST(equal, test6) {
    S21Matrix m1(6, 6);
    m1.Fill();

    S21Matrix m2(7, 7);
    m2.Fill();

    EXPECT_FALSE(m2.EqMatrix(m1));
}

TEST(equal, test7) {
    S21Matrix m1(6, 6);
    m1.Fill();

    EXPECT_TRUE(m1.EqMatrix(m1));    
}

TEST(equal, test8) {
    S21Matrix m1(2, 4);
    m1.Fill();

    S21Matrix m2(2, 4);
    m2(0, 0) = 1.0;
    m2(0, 1) = 2.0;
    m2(0, 2) = 3.0;
    m2(0, 3) = 4.0;
    m2(1, 0) = 5.0;
    m2(1, 1) = 6.0;
    m2(1, 2) = 7.0;
    m2(1, 3) = 8.0;

    EXPECT_TRUE(m2.EqMatrix(m1));    
}

