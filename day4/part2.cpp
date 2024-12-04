#include <iostream>
#include <vector>
#include <string>

bool isXMASPattern(const std::vector<std::string> &grid, int x, int y) {
    int n = grid.size();
    int m = grid[0].size();

    return x - 1 >= 0 && x + 1 < n && y - 1 >= 0 && y + 1 < m &&
           ((grid[x - 1][y - 1] == 'M' && grid[x][y] == 'A' && grid[x + 1][y + 1] == 'S') ||
            (grid[x - 1][y - 1] == 'S' && grid[x][y] == 'A' && grid[x + 1][y + 1] == 'M')) &&
           ((grid[x + 1][y - 1] == 'M' && grid[x][y] == 'A' && grid[x - 1][y + 1] == 'S') ||
            (grid[x + 1][y - 1] == 'S' && grid[x][y] == 'A' && grid[x - 1][y + 1] == 'M'));
}

int countXMASPatterns(const std::vector<std::string> &grid) {
    int n = grid.size();
    int m = grid[0].size();
    int count = 0;

    for (int x = 0; x < n; ++x) {
        for (int y = 0; y < m; ++y) {
            if (isXMASPattern(grid, x, y)) {
                ++count;
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

    int result = countXMASPatterns(grid);

    std::cout << result << std::endl;

    return 0;
}
