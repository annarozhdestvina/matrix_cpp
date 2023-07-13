#include <gtest/gtest.h>
#include "../s21_matrix.h"

TEST(default_constructor, test1) {
    S21Matrix m1; 
}

TEST(default_constructor, test2) {
    S21Matrix m3; 
    S21Matrix m33; 
}

TEST(default_constructor, test3) {
    S21Matrix m3(2, 5); 
    S21Matrix m33(2, 5);
    EXPECT_TRUE(m33.EqMatrix(m3));
}