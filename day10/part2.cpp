#include <iostream>
#include <vector>
#include <string>
#include <utility>

const std::vector<std::pair<int, int>> directions = 
{
    {-1, 0}, 
    {1, 0}, 
    {0, -1}, 
    {0, 1}
};

bool isValid(int x, int y, int prevHeight, const std::vector<std::vector<int>> &map) {
    int n = map.size(), m = map[0].size();
    return x >= 0 && x < n && y >= 0 && y < m && map[x][y] == prevHeight + 1;
}

int search(int x, int y, const std::vector<std::vector<int>> &map, std::vector<std::vector<int>> &memo) {
    if (map[x][y] == 9) return 1;

    if (memo[x][y] != -1) return memo[x][y];

    int totalTrails = 0;

    for (const auto &dir : directions) {
        int newX = x + dir.first;
        int newY = y + dir.second;

        if (isValid(newX, newY, map[x][y], map)) {
            totalTrails += search(newX, newY, map, memo);
        }
    }

    memo[x][y] = totalTrails;
    return totalTrails;
}

int main() {
    std::vector<std::vector<int>> map;
    std::string line;

    while (getline(std::cin, line) && !line.empty()) {
        std::vector<int> row;
        for (char c : line) {
            row.push_back(c - '0');
        }
        map.push_back(row);
    }

    int totalRating = 0;
    int n = map.size(), m = map[0].size();

    std::vector<std::vector<int>> memo(n, std::vector<int>(m, -1));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (map[i][j] == 0) {
                totalRating += search(i, j, map, memo);
            }
        }
    }

    std::cout << totalRating << std::endl;

    return 0;
}
