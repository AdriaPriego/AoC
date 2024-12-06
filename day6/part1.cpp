#include <iostream>
#include <vector>
#include <unordered_map>
#include <sstream>
#include <string>


int main() {
    std::vector<std::string> map;
	std::string lines;

    while (std::getline(std::cin, lines)) {
		map.push_back(lines);
    }

    std::pair<int, int> dirs = {};
	int x = 0, y = 0;
	for (auto line: map) {
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
	int qtt = 0;

	while (y >= 0 && y < map.size() && map[y][x])
	{
		if (map[y][x] != 'X')
			qtt++;
		if (y + dirs.second >= 0 && y + dirs.second < map.size() && map[y + dirs.second][x + dirs.first] && map[y + dirs.second][x + dirs.first] == '#') {
			int tmp = dirs.first;
			dirs.first = -dirs.second;
			dirs.second = tmp;
		}
		map[y][x] = 'X';
		y += dirs.second;
		x += dirs.first;
	}
	
    std::cout << qtt << std::endl;
    return 0;
}
