#include <fstream>
#include <iostream>
#include <vector>

using std::string;

bool incrementPattern(string* pattern) {
    const unsigned long patternLength = (*pattern).size();
    if ((*pattern)[0] == 'T') {
        (*pattern)[0] = 'A';
        int i = 1;
        while (((*pattern)[i] == 'T') && (i < patternLength)) {
            (*pattern)[i] = 'A';
            i++;
        }

        if (i == patternLength) return false;

        if ((*pattern)[i] == 'A') (*pattern)[i] = 'C';

        else if ((*pattern)[i] == 'C') (*pattern)[i] = 'G';

        else if ((*pattern)[i] == 'G') (*pattern)[i] = 'T';

        return true;
    }

    if ((*pattern)[0] == 'A') {
        (*pattern)[0] = 'C';
    }
    else if ((*pattern)[0] == 'C') {
        (*pattern)[0] = 'G';
    }
    else if ((*pattern)[0] == 'G') {
        (*pattern)[0] = 'T';
    }

    return true;
}

const unsigned long XEM(string pattern, string pattern2, const unsigned long &templateLength) {
    unsigned long res = 0;

    for (int i = 0; i < templateLength; i++) {
        if (pattern[i] != pattern2[i]) res++;
    }

    return res;
}


const string medianStringFinder(const unsigned long &templateLength, const std::vector<string> &consistencyDNA, const int &length) {
    string result;
    string pattern;
    unsigned long totalDist = 0;

    for (int i = 0; i < templateLength; i++) {
        pattern.append("A");
    }

    const unsigned long n = consistencyDNA[0].size();
    unsigned long bestDist = templateLength * length;
    bool flag = true;

    while (flag) {
        unsigned long distance = 0;
        unsigned long minDistance = templateLength;

        for (int i(0); i < length; i++) {
            for (unsigned long j(0); j < n - templateLength + 1; j++) {
                distance = XEM(pattern, consistencyDNA[i].substr(j, templateLength), templateLength);
                if (minDistance >= distance) {
                    minDistance = distance;
                }
            }
            totalDist += minDistance;
            minDistance = templateLength;
        }
        if (bestDist >= totalDist) {
            bestDist = totalDist;
            result = pattern;
        }
        totalDist = 0;
        flag = incrementPattern(&pattern);
    }

    return result;
}

int main() {
    string inputString;
    std::vector<string> consistencyDNA;
    std::ifstream inputFile;

    inputFile.open("input.txt", std::ios::out);
    inputFile >> inputString;
    const unsigned long templateLength = std::stoul(inputString);

    string buffer;
    int i = 0;
    std::cout << "INPUT: " << templateLength << std::endl;
    while (!inputFile.eof()) {
        inputFile >> buffer;
        std::cout << buffer << std::endl;
        consistencyDNA.push_back(buffer);
        i++;
    }
    inputFile.close();

    const string totalResult = medianStringFinder(templateLength, consistencyDNA, i);

    std::cout << "OUTPUT: " << totalResult << std::endl;
    std::ofstream outputFile;
    outputFile.open("output.txt");
    outputFile << totalResult;
    outputFile.close();

    return 0;
}