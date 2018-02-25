#include <fstream>
#include <iostream>
#include <vector>

const unsigned long ManhattanTourist(const std::vector<std::vector<unsigned long>>& south,
                                     const std::vector< std::vector<unsigned long>>& eath,
                                     const unsigned long& n,
                                     const unsigned long& m) {
    std::vector<std::vector<unsigned long>> result(n + 1);

    for (auto& vector : result) {
        vector.resize(m + 1);
    }

    result[0][0] = 0;

    for (int i(1); i <= n; i++) {
        result[i][0] = result[i - 1][0] + south[i - 1][0];
    }

    for (int i(1); i <= m; i++) {
        result[0][i] = result[0][i - 1] + eath[0][i - 1];
    }

    for (int i(1); i <= n; i++) {
        for (int j(1); j <= m; j++) {
            if ((result[i - 1][j] + south[i - 1][j]) > (result[i][j - 1] + eath[i][j - 1])) {
                result[i][j] = result[i - 1][j] + south[i - 1][j];
            } else {
                result[i][j] = result[i][j - 1] + eath[i][j - 1];
            }
        }
    }

    return result[n][m];
}

int main() {
    unsigned long n, m;
    std::ifstream file;
    file.open("input.txt", std::ios::out);
    file >> n;
    file >> m;

    std::vector< std::vector<unsigned long> > south(n);
    std::vector< std::vector<unsigned long> > eath(m + 1);

    for (int i(0); i < n; i++) {
        south[i].resize(m + 1);

        for (int k(0); k < m + 1; k++) {
            file >> south[i][k];
        }
    }

    std::string separator; // @TODO: using fseek
    file >> separator;

    if (separator == "-");
    else throw 1;

    for (int i(0); i < m + 1; i++) {
        eath[i].resize(m + 1);

        for (int k(0); k < n ; k++) {
            file >> eath[i][k];
        }
    }

    file.close();

    const unsigned long result = ManhattanTourist(south, eath, n, m);

    std::ofstream fout;
    fout.open("output.txt");
    fout << result;
    fout.close();

    return 0;
}