#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <utility>

const std::vector<std::pair<int, int>> directions = 
{
    {-1, 0}, 
    {1, 0}, 
    {0, -1}, 
    {0, 1}
};

bool isValid(int x, int y, int prevHeight, const std::vector<std::vector<int>> &map, const std::vector<std::vector<bool>> &visited) {
    int n = map.size(), m = map[0].size();
    return x >= 0 && x < n && y >= 0 && y < m && !visited[x][y] && map[x][y] == prevHeight + 1;
}

int search(int startX, int startY, const std::vector<std::vector<int>> &map) {
    int n = map.size(), m = map[0].size();
    std::vector<std::vector<bool>> visited(n, std::vector<bool>(m, false));
    std::queue<std::pair<int, int>> q;

    q.push({startX, startY});
    visited[startX][startY] = true;

    int score = 0;

    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();

        if (map[x][y] == 9) {
            score++;
            continue;
        }

        for (const auto &dir : directions) {
            int newX = x + dir.first;
            int newY = y + dir.second;

            if (isValid(newX, newY, map[x][y], map, visited)) {
                visited[newX][newY] = true;
                q.push({newX, newY});
            }
        }
    }

    return score;
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

    int totalScore = 0;

    for (int i = 0; i < map.size(); ++i) {
        for (int j = 0; j < map[i].size(); ++j) {
            if (map[i][j] == 0) {
                totalScore += search(i, j, map);
            }
        }
    }
    std::cout << totalScore << std::endl;
    return 0;
}
