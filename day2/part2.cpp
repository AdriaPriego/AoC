#include <iostream>
#include <vector>
#include <cmath>
#include <sstream>
#include <algorithm>

bool increasing(const std::vector<long>& levels) {
    for (size_t i = 1; i < levels.size(); ++i) {
        long diff = levels[i] - levels[i - 1];
        if (diff <= 0 || diff > 3)
            return false;
    }
    return true;
}

bool decreasing(const std::vector<long>& levels) {
    for (size_t i = 1; i < levels.size(); ++i) {
        long diff = levels[i - 1] - levels[i];
        if (diff <= 0 || diff > 3)
            return false;
    }
    return true;
}

bool isValid(const std::vector<long>& levels) {

    if (increasing(levels) || decreasing(levels))
        return true;

    for (size_t i = 0; i < levels.size(); ++i) {
        std::vector<long> modifiedLevels = levels;
        modifiedLevels.erase(modifiedLevels.begin() + i);

        if (increasing(modifiedLevels) || decreasing(modifiedLevels))
            return true;
    }

    return false;
}

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
        if (isValid(list[i]))
            safe++;
    }
    
    std::cout << safe << std::endl;
    return 0;
}
