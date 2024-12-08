#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <utility>
#include <cmath>

std::map<char, std::vector<std::pair<int, int>>> findAntennas(const std::vector<std::string>& mapa) {
    std::map<char, std::vector<std::pair<int, int>>> antennas;
    for (int i = 0; i < mapa.size(); ++i) {
        for (int j = 0; j < mapa[i].size(); ++j) {
            char c = mapa[i][j];
            if (c != '.') {
                antennas[c].emplace_back(i, j);
            }
        }
    }
    return antennas;
}

std::set<std::pair<int, int>> calculateAntinodes(const std::map<char, std::vector<std::pair<int, int>>>& antennas, const std::vector<std::string>& mapa) {
    std::set<std::pair<int, int>> antinodes;
    for (const auto& [freq, positions] : antennas) {
        if (positions.size() > 1) {
            for (const auto& pos : positions) {
                antinodes.insert(pos);
            }
        }

        for (int i = 0; i < positions.size(); ++i) {
            for (int j = i + 1; j < positions.size(); ++j) {
                int x1 = positions[i].first, y1 = positions[i].second;
                int x2 = positions[j].first, y2 = positions[j].second;

                int dx = x2 - x1;
                int dy = y2 - y1;

                for (int k = -1; k <= 1; k += 2) {
                    int ax = x1 + k * dx;
                    int ay = y1 + k * dy;
                    while (ax >= 0 && ax < mapa.size() && ay >= 0 && ay < mapa[0].size()) {
                        antinodes.emplace(ax, ay);
                        ax += k * dx;
                        ay += k * dy;
                    }
                }
            }
        }
    }
    return antinodes;
}

int main() {
    std::vector<std::string> mapa;
    std::string line;

    while (getline(std::cin, line))
        mapa.push_back(line);

    std::map<char, std::vector<std::pair<int, int>>> antennas = findAntennas(mapa);
    std::set<std::pair<int, int>> antinodes = calculateAntinodes(antennas, mapa);

    std::cout << antinodes.size() << std::endl;

    return 0;
}
