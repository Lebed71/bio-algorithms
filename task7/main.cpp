#include <fstream>
#include <iostream>
#include <vector>
#include <limits>
#include <cstring>

#define _INFINITY_ std::numeric_limits<unsigned long>::max()

const unsigned long DPChange(const unsigned long& M, const std::vector<unsigned long>& c) {
    std::vector<unsigned long> bestNumCoins(M + 1);
    bestNumCoins[0] = 0;

    for (int i(1); i <= M; i++) {
        bestNumCoins[i] = _INFINITY_;

        for(const auto& currentCoin : c) {
            if (i >= currentCoin) {
                if (bestNumCoins[i - currentCoin] + 1 < bestNumCoins[i]) {
                    bestNumCoins[i] = bestNumCoins[i - currentCoin] + 1;
                }
            }
        }
    }

    return bestNumCoins[M];
}

std::vector<unsigned long> Separate(const std::string& source) {
    auto *s = new char[source.size() + 1];
    std::vector<unsigned long> result;
    strcpy(s, source.c_str());

    char *p = strtok(s, ",");

    while (p != nullptr) {
        result.push_back(std::stoul(p));
        p = strtok(nullptr, ",");
    }

    delete[] s;

    return result;
}

int main()
{
    unsigned long M;

    std::ifstream file;
    file.open("input.txt", std::ios::out);

    file >> M;
    std::string inputString;
    file >> inputString;
    file.close();

    std::cout << "INPUT: " << M << std::endl;
    std::cout << "INPUT: " << inputString << std::endl;

    std::vector<unsigned long> separateInputString = Separate(inputString);

    const unsigned long result = DPChange(M, separateInputString);
    std::cout << "OUTPUT: " << result << std::endl;

    std::ofstream fout;
    fout.open("output.txt");
    fout << result;
    fout.close();

    return 0;
}
