#include <iostream>
#include <string>
#include <regex>

int main() {
    std::string corrupted_memory;
    std::string line;
    while (true) {
        std::getline(std::cin, line);
        if (line.empty()) break;

        corrupted_memory.append(line);
    }

    std::regex valid_mul_pattern(R"(mul\(\s*(\d+)\s*,\s*(\d+)\s*\))");
    std::smatch match;

    long total_sum = 0;

    auto search_start = corrupted_memory.cbegin();
    while (std::regex_search(search_start, corrupted_memory.cend(), match, valid_mul_pattern)) {
        long x = std::stoi(match[1].str());
        long y = std::stoi(match[2].str());

        total_sum += x * y;

        search_start = match.suffix().first;
    }

    std::cout << total_sum << std::endl;

    return 0;
}
