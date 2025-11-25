#include "Loan.h"
#include <cmath>   // for pow()
#include <stdexcept> // for exceptions

Loan::Loan(long double p, long double i, int t) {
    if(p <= 0 || i <= 0 || t <= 0)
        throw std::invalid_argument("All values must be positive!");
    
    principal = p;
    annualInterest = i;
    tenure = t;
}

void Loan::setPrincipal(long double p) { principal = p; }
void Loan::setInterest(long double i) { annualInterest = i; }
void Loan::setTenure(int t) { tenure = t; }

long double Loan::getPrincipal() const { return principal; }
long double Loan::getInterest() const { return annualInterest; }
int Loan::getTenure() const { return tenure; }

long double Loan::calculateEMI() const {
    // Monthly interest rate
    long double monthlyRate = (annualInterest / 12) / 100;
    // EMI formula
    long double emi = (principal * monthlyRate * pow(1 + monthlyRate, tenure)) /
                      (pow(1 + monthlyRate, tenure) - 1);
    return emi;
}
