#include "Utils.h"
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <iostream>

LoanConfig readConfig(const std::string& filename) {
    std::ifstream file(filename);
    if(!file) throw std::runtime_error("Could not open config.txt");

    LoanConfig cfg;
    std::string line;
    while(std::getline(file, line)) {
        auto pos = line.find('=');
        if(pos == std::string::npos) continue;

        std::string key = line.substr(0, pos);
        std::string value = line.substr(pos + 1);

        if(key == "principal") cfg.principal = std::stold(value);
        else if(key == "interest") cfg.interest = std::stold(value);
        else if(key == "tenure") cfg.tenure = std::stoi(value);
    }
    return cfg;
}

void parseCommandLine(int argc, char* argv[], LoanConfig& cfg) {
    for(int i = 1; i < argc; i+=2) {
        std::string key = argv[i];
        if(i + 1 >= argc) break;
        std::string value = argv[i+1];

        if(key == "-a") cfg.principal = std::stold(value);
        else if(key == "-i") cfg.interest = std::stold(value);
        else if(key == "-n") cfg.tenure = std::stoi(value);
    }
}
