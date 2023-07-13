#include <gtest/gtest.h>
#include "../s21_matrix.h"

TEST(operator_move, test1) {
    S21Matrix m1(3, 4);
    m1.Fill();

    S21Matrix m3 = m1; // cкопировали потому что потом он удалится 

    S21Matrix m2 = (std::move(m1)); 

    EXPECT_TRUE(m3.EqMatrix(m2));
}

TEST(operator_move, test2) {
    S21Matrix m1(3, 4);
    m1.Fill();
    m1.MulNumber(-2);

    S21Matrix m3 = m1; 

    S21Matrix m2 = (std::move(m1)); 

    EXPECT_TRUE(m3.EqMatrix(m2));
}

// TEST(operator_move, test3) {
//     S21Matrix m1(3, 4);
//     m1.Fill();
//     m1.MulNumber(-2);

//     S21Matrix m2 = (std::move(m1)); 

//     m1 = m1; 


//     EXPECT_TRUE(m2.EqMatrix(m1));
// }
