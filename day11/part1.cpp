#include <iostream>
#include <vector>
#include <cmath>
#include <unordered_map>

long long simulateBlinks(std::vector<long long> stones, long long blinks) {
    std::unordered_map<long long, long long> stoneCount;

    for (long long stone : stones) {
        stoneCount[stone]++;
    }

    for (long long b = 0; b < blinks; ++b) {
        std::unordered_map<long long, long long> newStoneCount;

        for (const auto& [stone, count] : stoneCount) {
            if (stone == 0) {
                newStoneCount[1] += count;
            } else if (std::to_string(stone).size() % 2 == 0) {
                std::string digits = std::to_string(stone);
                long long mid = digits.size() / 2;
                long long left = std::stoi(digits.substr(0, mid));
                long long right = std::stoi(digits.substr(mid));
                newStoneCount[left] += count;
                newStoneCount[right] += count;
            } else {
                newStoneCount[stone * 2024] += count;
            }
        }

        stoneCount = newStoneCount;
    }

    long long totalStones = 0;
    for (const auto& [_, count] : stoneCount) {
        totalStones += count;
    }

    return totalStones;
}

int main(int argc, char* argv[]) {
    long long blinks = std::stoi(argv[1]);
    std::vector<long long> stones;

    for (long long i = 2; i < argc; ++i) {
        stones.push_back(std::stoi(argv[i]));
    }

    long long result = simulateBlinks(stones, blinks);
    std::cout << result << std::endl;

    return 0;
}
