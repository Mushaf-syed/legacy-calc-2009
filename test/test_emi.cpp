#include "Loan.h"
#include <gtest/gtest.h>

// Test 1: Normal EMI calculation
TEST(LoanTest, NormalEMI) {
    Loan loan(100000, 12, 360);
    long double emi = loan.calculateEMI();
    EXPECT_NEAR(emi, 1028.61, 0.1); // small tolerance
}

// Test 2: Invalid input handling
TEST(LoanTest, InvalidValues) {
    EXPECT_THROW(Loan(-1000, 12, 360), std::invalid_argument);
    EXPECT_THROW(Loan(1000, -12, 360), std::invalid_argument);
    EXPECT_THROW(Loan(1000, 12, -360), std::invalid_argument);
}

// Test 3: Large tenure without overflow
TEST(LoanTest, LargeTenure) {
    Loan loan(1000000, 10, 480); // 40 years
    EXPECT_GT(loan.calculateEMI(), 0);
}

// Main function for GoogleTest
int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

