#include <iostream>
#include <iomanip>
#include "Loan.h"
#include "Utils.h"

int main(int argc, char* argv[]) {
    LoanConfig cfg;

    try {
        cfg = readConfig("config.txt");     // read from file
        parseCommandLine(argc, argv, cfg);  // optional CLI override

        Loan loan(cfg.principal, cfg.interest, cfg.tenure);

        std::cout << std::fixed << std::setprecision(2);
        std::cout << "Loan Amount: " << loan.getPrincipal() << "\n"
                  << "Annual Interest Rate: " << loan.getInterest() << "%\n"
                  << "Tenure (months): " << loan.getTenure() << "\n"
                  << "Monthly EMI: " << loan.calculateEMI() << "\n";
    } catch(const std::exception& e) {
        std::cerr << "Error: " << e.what() << "\n";
        return 1;
    }

    return 0;
}
