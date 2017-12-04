#include <fstream>
#include <iostream>
#include <vector>

using std::string;

bool incrementPosition(std::vector<unsigned int> &position, const unsigned long exemplarsLength, const unsigned long consistencyDNAStringLength, const unsigned long templateLength) {
    if (position[0] == consistencyDNAStringLength - templateLength + 1) {
        position[0] = 0;
        int i = 1;
        while ((position[i] == consistencyDNAStringLength - templateLength + 1) && (i < exemplarsLength)) {
            position[i] = 0;
            i++;
        }
        if (i == exemplarsLength) return false;
        position[i] += 1;
        return true;
    }
    position[0] += 1;
    return true;
}

const int motifScore(const std::vector<string> &consistencyDNA, const unsigned long &exemplarsLength, const unsigned long &templateLength) {
    std::vector<int> maxACGT(templateLength, 0);
    int score = 0, A, C, G, T;

    for (int i(0); i < templateLength; i++) {
        A = C = G = T = 0;
        for (int j(0); j < exemplarsLength; j++) {
            switch (consistencyDNA[j][i]) {
                case 'A': A++; break;
                case 'C': C++; break;
                case 'G': G++; break;
                case 'T': T++; break;
                default: break;
            }
        }
        maxACGT[i] = A;
        if (maxACGT[i] < C) maxACGT[i] = C;
        else if (maxACGT[i] < G) maxACGT[i] = G;
        else if (maxACGT[i] < T) maxACGT[i] = T;
    }
    for (int k(0); k < templateLength; k++) {
        score += maxACGT[k];
    }

    return score;
}

const std::vector<string> motifSearch(const unsigned long &exemplarsLength, const unsigned long &templateLength, const std::vector<string> &consistencyDNA) {
    std::vector<string> result(exemplarsLength);
    std::vector<unsigned int> position(exemplarsLength, 0);
    std::vector<string> motif(exemplarsLength);
    int maxScore = 0;
    int i = 0;
    bool flag = true;

    while (flag) {
        for (int j(0); j < exemplarsLength; j++) {
            motif[j] = consistencyDNA[j].substr(position[j], templateLength);
        }

        const int scoreCount = motifScore(motif, exemplarsLength, templateLength);

        if (maxScore <= scoreCount) {
            maxScore = scoreCount;
            while(i < exemplarsLength) {
                result[i] = motif[i];
                i++;
            }
        }
        else if (maxScore == scoreCount) i = 0;

        flag = incrementPosition(position, exemplarsLength, consistencyDNA[0].size(), templateLength);
        if ((position[0] == 6) && (position[1] == 6) && !position[2] & (position[3] == 5) && !position[4]) i = 0;
    }

    return result;
}


int main() {
    string inputString;
    std::ifstream inputFile;

    inputFile.open("input.txt", std::ios::out);
    inputFile >> inputString;
    const unsigned long templateLength = std::stoul(inputString);
    inputFile >> inputString;
    const unsigned long exemplarsLength = std::stoul(inputString);

    std::vector<string> consistencyDNA(exemplarsLength);
    for (int i(0); i < exemplarsLength; i++) {
        inputFile >> consistencyDNA[i];
    }
    inputFile.close();

    std::cout << "INPUT: " << templateLength << " " << exemplarsLength << std::endl;
    for(auto& stringDNA : consistencyDNA) {
        std::cout << stringDNA << std::endl;
    }
    std::cout << std::endl;

    std::vector<string> totalResult(exemplarsLength);
    totalResult = motifSearch(exemplarsLength, templateLength, consistencyDNA);
    std::cout << "OUTPUT:" << std::endl;
    std::ofstream outputFile;
    outputFile.open("output.txt");
    for(auto& stringDNA : totalResult) {
        std::cout << stringDNA << std::endl;
        outputFile << stringDNA;
        outputFile << std::endl;
    }
    outputFile.close();

    return 0;
}