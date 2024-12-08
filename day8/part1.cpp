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

std::set<std::pair<int, int>> calculateAntinodes(const std::map<char, std::vector<std::pair<int, int>>>& antennas, const std::vector<std::string>& map) {
    std::set<std::pair<int, int>> antinodes;
    for (const auto& [freq, positions] : antennas) {
        for (int i = 0; i < positions.size(); ++i) {
            for (int j = i + 1; j < positions.size(); ++j) {
                int x1 = positions[i].first, y1 = positions[i].second;
                int x2 = positions[j].first, y2 = positions[j].second;

                int dx = x2 - x1;
                int dy = y2 - y1;

                int ax1 = x1 - dx;
                int ay1 = y1 - dy;
                int ax2 = x2 + dx;
                int ay2 = y2 + dy;

                if (ax1 >= 0 && ax1 < map.size() && ay1 >= 0 && ay1 < map[0].size()) {
                    antinodes.emplace(ax1, ay1);
                }
                if (ax2 >= 0 && ax2 < map.size() && ay2 >= 0 && ay2 < map[0].size()) {
                    antinodes.emplace(ax2, ay2);
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
