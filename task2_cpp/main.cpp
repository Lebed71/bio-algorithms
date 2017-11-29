#include <fstream>
#include <iostream>

using std::string;

unsigned long int patternMatchesCount(const std::string& inputString, const std::string& requiredPattern) {
    if (inputString.empty() || requiredPattern.empty()) return 0;

    unsigned long int totalMatchesCount = 0;
    const unsigned long int N = inputString.size();
    const unsigned long int k = requiredPattern.size();

    for (unsigned long int i(0); i < N - k + 1; i++) {
        if (inputString.substr(i, k) == requiredPattern) {
            totalMatchesCount++;
        }
    }

    return totalMatchesCount;
}

void frequentWords(const string& inputString, const unsigned long int k, string* commonSting) {
    if (inputString.empty() || k == 0) {
        *commonSting = "Empty input!";
        return;
    }

    unsigned long int N = inputString.size();
    auto* summaryCount = new unsigned long int[N - k + 1];

    for (unsigned long int i = 0; i < N - k + 1; i++) {
        summaryCount[i] = patternMatchesCount(inputString, inputString.substr(i, k));
    }

    unsigned long int maxCount = summaryCount[0];

    for (int j(1); j < N - k + 1; j++) {
        if (summaryCount[j] > maxCount) {
            maxCount = summaryCount[j];
        }
    }
    for (unsigned long int j(0); j < N - k + 1; j++) {
        if (summaryCount[j] == maxCount && (patternMatchesCount(*commonSting, inputString.substr(j, k)) == 0)) {
            *commonSting += inputString.substr(j, k);
            *commonSting += ' ';
        }
    }
}

int main() {
    unsigned long int patternCount;
    string inputString;
    string frequentSubstrings;

    std::ifstream inputFile;
    inputFile.open("input.txt", std::ios::out);
    inputFile >> inputString;
    inputFile >> patternCount;
    inputFile.close();

    std::cout << "INPUT: " << inputString << " " << patternCount << std::endl;

    frequentWords(inputString, patternCount, &frequentSubstrings);

    std::cout << "OUTPUT: " << frequentSubstrings << std::endl;

    std::ofstream outputFile;
    outputFile.open("output.txt");
    outputFile << frequentSubstrings;
    outputFile.close();

    return 0;
}