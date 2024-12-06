#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <tuple>

int simulate(const std::vector<std::string>& map, int x, int y, std::pair<int, int> dirs) {
    std::set<std::tuple<int, int, int, int>> visited;

    while (y >= 0 && y < map.size() && x >= 0 && x < map[y].size() && map[y][x]) {
		
		if (visited.count(std::make_tuple(x, y, dirs.first, dirs.second)))
			return true;

		visited.insert(std::make_tuple(x, y, dirs.first, dirs.second));

        if (y + dirs.second >= 0 && y + dirs.second < map.size() && x + dirs.first >= 0 && x + dirs.first < map[y].size() && map[y + dirs.second][x + dirs.first] == '#') {
            int tmp = dirs.first;
            dirs.first = -dirs.second;
            dirs.second = tmp;
        } 
		x += dirs.first;
		y += dirs.second;
    }
    return false;
}

int main() {
    std::vector<std::string> map;
    std::string lines;

    while (std::getline(std::cin, lines)) {
        map.push_back(lines);
    }

    std::pair<int, int> dirs = {};
    int x = 0, y = 0;

    for (auto line : map) {
        x = line.find('>');
        if (x != line.npos) {
            dirs = {1, 0};
            break;
        }
        x = line.find('<');
        if (x != line.npos) {
            dirs = {-1, 0};
            break;
        }
        x = line.find('v');
        if (x != line.npos) {
            dirs = {0, 1};
            break;
        }
        x = line.find('^');
        if (x != line.npos) {
            dirs = {0, -1};
            break;
        }
        y++;
    }

    int valid_positions = 0;
    for (int i = 0; i < map.size(); ++i) {
        for (int j = 0; j < map[i].size(); ++j) {
            if (map[i][j] == '.' && !(j == x && i == y)) {
                map[i][j] = '#';

                if (simulate(map, x, y, dirs))
                    ++valid_positions;
                map[i][j] = '.';
            }
        }
    }

    std::cout << valid_positions << std::endl;
    return 0;
}
