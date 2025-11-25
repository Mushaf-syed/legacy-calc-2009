#ifndef LOAN_H
#define LOAN_H

#include <iostream>

/**
 * @class Loan
 * @brief Represents a loan and calculates EMI (Equated Monthly Installment)
 */
class Loan {
private:
    long double principal;   // Loan amount
    long double annualInterest; // Annual interest rate in %
    int tenure;             // Number of months

public:
    // Constructor
    Loan(long double p, long double i, int t);

    // Setters
    void setPrincipal(long double p);
    void setInterest(long double i);
    void setTenure(int t);

    // Getters
    long double getPrincipal() const;
    long double getInterest() const;
    int getTenure() const;

    // EMI Calculation
    long double calculateEMI() const;
};

#endif

