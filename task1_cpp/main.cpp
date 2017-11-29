#include <fstream>
#include <iostream>

unsigned long int patternMathesCount(const std::string& inputString, const std::string& requiredPattern) {
    if (inputString.empty() || requiredPattern.empty()) return 0;

    unsigned long int sum = 0;
    const unsigned long int N = inputString.size();
    const unsigned long int k = requiredPattern.size();

    for (unsigned long int i(0); i < N - k + 1; i++) {
        if (inputString.substr(i, k) == requiredPattern) {
            sum++;
        }
    }

    return sum;
}

int main() {
    std::string inputString;
    std::string requiredPattern;

    std::ifstream inputFile;
    inputFile.open("input.txt", std::ios::out);
    inputFile >> inputString;
    inputFile >> requiredPattern;
    inputFile.close();

    std::cout << "INPUT: " << inputString << " " << requiredPattern << std::endl;

    unsigned long int totalMatchesCount = patternMathesCount(inputString, requiredPattern);

    std::cout << "OUTPUT: " << totalMatchesCount << std::endl;

    std::ofstream outputFile;
    outputFile.open("output.txt");
    outputFile << totalMatchesCount;
    outputFile.close();

    return 0;
}