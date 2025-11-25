#include <iostream>
#include <fstream>
#include <string>
#include "Loan.h"

int main() {
    long double principal = 0;
    long double interest = 0;
    int tenure = 0;

    // Read config.txt
    std::ifstream config("config.txt");
    if(!config) {
        std::cerr << "Could not open config.txt\n";
        return 1;
    }

    std::string line;
    while(std::getline(config, line)) {
        size_t pos = line.find('=');
        if(pos == std::string::npos) continue;

        std::string key = line.substr(0, pos);
        std::string value = line.substr(pos + 1);

        if(key == "principal") principal = std::stold(value);
        else if(key == "interest") interest = std::stold(value);
        else if(key == "tenure") tenure = std::stoi(value);
    }

    try {
        Loan loan(principal, interest, tenure);
        long double emi = loan.calculateEMI();

        std::cout << "Loan Amount: " << loan.getPrincipal() << "\n";
        std::cout << "Annual Interest Rate: " << loan.getInterest() << "%\n";
        std::cout << "Tenure (months): " << loan.getTenure() << "\n";
        std::cout << std::fixed;
        std::cout.precision(2);
        std::cout << "Monthly EMI: " << emi << "\n";
    } catch(const std::invalid_argument& e) {
        std::cerr << "Error: " << e.what() << "\n";
        return 1;
    }

    return 0;
}
