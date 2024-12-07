#include <iostream>
#include <deque>
#include <sstream>
#include <string>
#include <cmath>
#include <bitset>

const int MAX_BITS = 20;

std::deque<std::string> split(const std::string &str, char delimiter) {
    std::deque<std::string> tokens;
    std::stringstream ss(str);
    std::string token;
    while (getline(ss, token, delimiter)) {
        if (!token.empty())
            tokens.push_back(token);
    }
    return tokens;
}

std::deque<int> generateCombinations(size_t size) {
    std::deque<int> combinations;
    int qttcombinations = std::pow(3, size);
    for (size_t bits = 0; bits < qttcombinations; bits++) {
        combinations.push_back(bits);
    }
    return combinations;
}

bool doOperations(long result, std::deque<long> values, std::deque<int> combis) {
    unsigned long long res = 0;
    int numBits = 0;
    int sbits = values.size() - 1;
    for (auto combi : combis) {
        res = 0;
        std::deque<long> copy = values;
        for (int i = sbits - 1; i >= 0; i--) {
            long num1 = copy.front();
            copy.pop_front();
            long num2 = copy.front();
            copy.pop_front();
            int operation = combi % 3;
            combi /= 3;
            if (operation == 0)
                copy.push_front(num1 + num2);
            else if (operation == 1)
                copy.push_front(num1 * num2);
            else if (operation == 2) {
                std::string combined = std::to_string(num1) + std::to_string(num2);
                copy.push_front(std::stol(combined));
            }
        }
        if (copy.front() == result)
            return true;
    }
    return false;
}

int main() {
    std::string lines;
    unsigned long long qtt = 0;
    while (std::getline(std::cin, lines)) {
        std::deque<std::string> splited = split(lines, ':');
        long result = std::stol(splited[0]);
        std::istringstream iss(splited[1]);
        std::deque<long> values;
        long value;
        while (iss >> value)
            values.push_back(value);

        std::deque<int> combis = generateCombinations(values.size() - 1);
        if (doOperations(result, values, combis))
            qtt += result;
    }

    std::cout << qtt << std::endl;
    return 0;
}
