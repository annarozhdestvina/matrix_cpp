#include <gtest/gtest.h>

#include "../s21_matrix.h"

TEST(my_tests, test1) {
    EXPECT_EQ(true, true);
    EXPECT_TRUE(true);
}

TEST(my_tests, test2) {
    EXPECT_EQ(true, false);
}

TEST(my_tests_false, test1) {
    EXPECT_EQ(true, true);
    EXPECT_TRUE(false);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);

    // manual_tests();
    
    return RUN_ALL_TESTS();
    // return -1;
}

/*
void manual_tests() {
    S21Matrix matA(4, 3);
    matA.Fill();
    std::cout << "matrix A:\n";
    matA.Print();

    S21Matrix matB(3, 3);
    matB.Fill();
    std::cout << "matrix B:\n";
    matB.Print();

    S21Matrix matC(3, 3);
    matC.FillC();
    std::cout << "matrix C:\n";
    matC.Print();

    bool a;
    a = matA.EqMatrix(matB);
    std::cout << "res of equalizing is " << a << std::endl;

    S21Matrix matA1(4, 3);
    matA1.Fill();
    std::cout << "matrix A1:\n";
    matA1.Print();
    a = matA.EqMatrix(matA1);
    std::cout << "res of equalizing is " << a << std::endl;

    matB.SumMatrix(matB);
    std::cout << "after sum\n";
    matB.Print();

    S21Matrix matD(3, 3);
    matD.Fill();
    std::cout << "matrix D:\n";
    matD.Print();

    std::cout << "matric C before sub\n";
    matC.Print();
    matC.SubMatrix(matD);
    std::cout << "after sub\n";
    matC.Print();

    std::cout << "matric A before mul on number\n";
    matA.Print();
    matA.MulNumber(4);
    std::cout << "after mul on number\n";
    matA.Print();

    S21Matrix mul1(3, 3);
    mul1.Fill();
    S21Matrix mul2(3, 3);
    mul2.FillC();

    std::cout << "matric mul1 before mul on number\n";
    mul1.Print();
    std::cout << "matric mul2 before mul on number\n";
    mul2.Print();
    mul1.MulMatrix(mul2);
    std::cout << "after mul on number\n";
    mul1.Print();

    // S21Matrix result_sub(3, 3);
    // result_sub.Fill();
    // result_sub = matA + matD;
    // std::cout << "overloading operator +\n";
    // result_sub.Print();
}
*/