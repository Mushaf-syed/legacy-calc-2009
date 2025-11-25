#ifndef UTILS_H
#define UTILS_H

#include <string>

/**
 * @struct LoanConfig
 * @brief Stores loan configuration read from file or command line
 */
struct LoanConfig {
    long double principal = 0;
    long double interest = 0;
    int tenure = 0;
};

/**
 * @brief Reads loan configuration from a file
 * @param filename Path to config file
 * @return LoanConfig with principal, interest, tenure
 * @throws std::runtime_error if file cannot be opened
 */
LoanConfig readConfig(const std::string& filename);

/**
 * @brief Parses command-line arguments to override config
 */
void parseCommandLine(int argc, char* argv[], LoanConfig& cfg);

#endif
