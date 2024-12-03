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
    std::regex do_pattern(R"(do\(\))");
    std::regex dont_pattern(R"(don't\(\))");

    int total_sum = 0;
    bool mul_enabled = true;

    auto search_start = corrupted_memory.cbegin();
    std::smatch match;
    std::smatch matchdo;
    std::smatch matchdont;

    while (std::regex_search(search_start, corrupted_memory.cend(), match, valid_mul_pattern)) {
        std::regex_search(search_start, corrupted_memory.cend(), match, valid_mul_pattern);
        std::regex_search(search_start, corrupted_memory.cend(), matchdo, do_pattern);
        std::regex_search(search_start, corrupted_memory.cend(), matchdont, dont_pattern);
        if ((matchdo.empty() || match.position(0) < matchdo.position(0)) && (matchdont.empty() || match.position(0) < matchdont.position(0))) {
            if (mul_enabled) {
                int x = std::stoi(match[1].str());
                int y = std::stoi(match[2].str());
                total_sum += x * y;
            }
            search_start = match.suffix().first;
        } else if (matchdo.position(0) < matchdont.position(0)) {
            mul_enabled = true;
            search_start = matchdo.suffix().first;
        } else {
            mul_enabled = false;
            search_start = matchdont.suffix().first;
        }
    }
    std::cout << total_sum << std::endl;

    return 0;
}
