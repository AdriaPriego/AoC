#include <iostream>
#include <vector>
#include <cmath>
#include <sstream>
#include <algorithm>

int main() {
    std::vector<std::vector<long>> list;
    std::string line;
    long num;

    while (true) {
        std::getline(std::cin, line);
        if (line.empty()) break;

        std::stringstream ss(line);
        std::vector<long> nums;
        while(ss)
        {
            if (ss >> num)
                nums.push_back(num);
        }
        list.push_back(nums);
    }
    int safe = 0;
    for (size_t i = 0; i < list.size(); i++)
    {
        bool valid = true;
        size_t j = 1;
        if (!std::is_sorted(list[i].begin(), list[i].end()))
            if (!std::is_sorted(list[i].begin(), list[i].end(), std::greater<long>()))
                valid = false;
        for (; j < list[i].size() && valid; ++j)
        {
            if (std::abs(list[i][j] - list[i][j - 1]) > 3 || std::abs(list[i][j] - list[i][j - 1]) <= 0)
                valid = false;
        }
        if (valid)
            safe++;
        
    }
    
    std::cout << safe << std::endl;
    return 0;
}
