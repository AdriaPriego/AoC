#include <iostream>
#include <vector>
#include <string>

const std::vector<std::pair<int, int>> directions = {
    {0, 1},
    {0, -1},
    {1, 0},
    {-1, 0},
    {1, 1},
    {1, -1},
    {-1, 1},
    {-1, -1}
};

bool isWordPresent(const std::vector<std::string> &grid, int x, int y, const std::string &word, int dx, int dy) {
    int n = grid.size();
    int m = grid[0].size();
    int len = word.size();

    for (int i = 0; i < len; ++i) {
        int nx = x + i * dx;
        int ny = y + i * dy;
        if (nx < 0 || nx >= n || ny < 0 || ny >= m || grid[nx][ny] != word[i]) {
            return false;
        }
    }
    return true;
}

int countWordOccurrences(const std::vector<std::string> &grid, const std::string &word) {
    int n = grid.size();
    int m = grid[0].size();
    int count = 0;

    for (int x = 0; x < n; ++x) {
        for (int y = 0; y < m; ++y) {
            for (const auto &[dx, dy] : directions) {
                if (isWordPresent(grid, x, y, word, dx, dy)) {
                    ++count;
                }
            }
        }
    }

    return count;
}

int main() {

    std::vector<std::string> grid;

    std::string line;
    while (true) {
        std::getline(std::cin, line);
        if (line.empty()) break;

        grid.push_back(line);
    }

    std::string word = "XMAS";

    int result = countWordOccurrences(grid, word);

    std::cout << result << std::endl;

    return 0;
}
