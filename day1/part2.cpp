#include <iostream>
#include <vector>
#include <cmath>
#include <sstream>
#include <algorithm>

int main() {
    std::vector<long> leftList, rightList;
    std::string line;
    long num1, num2;

    while (true) {
        std::getline(std::cin, line);
        if (line.empty()) break;

        std::stringstream ss(line);
        if (ss >> num1 >> num2) {
            leftList.push_back(num1);
            rightList.push_back(num2);
        } else {
            std::cerr << "Error" << std::endl;
            return 1;
        }
    }

    if (leftList.size() != rightList.size()) {
        std::cerr << "Error" << std::endl;
        return 1;
    }


    std::sort(leftList.begin(), leftList.end());
    std::sort(rightList.begin(), rightList.end());

    long totalSimilarity = 0;
    for (size_t i = 0; i < leftList.size(); i++) {
        long repeat = 0;
        for (size_t j = 0; j < rightList.size(); j++)
        {
            if (leftList[i] == rightList[j])
            {
                repeat++;
            }
        }
        totalSimilarity += leftList[i] * repeat; 
    }

    std::cout << totalSimilarity << std::endl;

    return 0;
}
