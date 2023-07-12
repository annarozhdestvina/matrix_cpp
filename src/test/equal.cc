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

TEST(equal, test9) {
    S21Matrix m1(2, 4);
    m1.Fill();

    try {
        S21Matrix m2(0, 7);
        FAIL() << "Expected std::rows is 0 or negative";
    }
    catch(std::out_of_range const & err) {
        EXPECT_EQ(err.what(),std::string("rows is 0 or negative"));
    }
    catch(...) {
        FAIL() << "Expected std::rows is 0 or negative";
    }
}

TEST(equal, test10) {
    try {
        S21Matrix m2(3, 0);
        FAIL() << "Expected std::columns is 0 or negative";
    }
    catch(std::out_of_range const & err) {
        EXPECT_EQ(err.what(),std::string("columns is 0 or negative"));
    }
    catch(...) {
        FAIL() << "Expected std::columns is 0 or negative";
    }
}

TEST(equal, test11) {
    S21Matrix m1(3, 2);
    m1.Fill();
    m1(0, 0) = 1.0;
    m1(0, 1) = 2.0;
    m1(1, 0) = 3.0;
    m1(1, 1) = 4.0;
    m1(2, 0) = 5.0;
    m1(2, 1) = 6.0;

    S21Matrix m2(3, 2);
    m2(0, 0) = 1.0000001;
    m2(0, 1) = 2.0000005;
    m2(1, 0) = 3.0000009;
    m2(1, 1) = 3.9999991;
    m2(2, 0) = 4.9999995;
    m2(2, 1) = 5.9999999;

    EXPECT_FALSE(m2.EqMatrix(m1));
}
