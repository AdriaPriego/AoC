#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <sstream>
#include <string>
#include <algorithm>

std::vector<std::string> split(const std::string &str, char delimiter) {
    std::vector<std::string> tokens;
    std::stringstream ss(str);
    std::string token;
    while (getline(ss, token, delimiter))
        tokens.push_back(token);
    return tokens;
}

bool isValidOrder(const std::vector<int>& update, const std::unordered_map<int, std::unordered_set<int>>& rules) {
    std::unordered_map<int, int> pagePositions;
    for (int i = 0; i < update.size(); ++i)
        pagePositions[update[i]] = i;
    for (const auto& [before, vecafter] : rules) {
        if (pagePositions.find(before) != pagePositions.end()) {
            for (int after : vecafter) {
                if (pagePositions.find(after) != pagePositions.end() && pagePositions[before] > pagePositions[after])
                    return false;
            }
        }
    }
    return true;
}

std::vector<int> reorderUpdate(std::vector<int> update, const std::unordered_map<int, std::unordered_set<int>>& rules) {
    // aun doy gracias al señor de la existencia de unordered_set con el count como funcion
    std::sort(update.begin(), update.end(), [&rules](int a, int b) {
        if (rules.count(a) && rules.at(a).count(b))
            return true;
        if (rules.count(b) && rules.at(b).count(a))
            return false;
        return a < b;
    });
    return update;
}

int main() {
    std::string line;
    std::vector<std::string> rulesLines;
    std::vector<std::string> updatesLines;
    bool readingUpdates = false;

    while (std::getline(std::cin, line)) {
        if (line.empty())
            readingUpdates = true;
		else {
			if (readingUpdates)
				updatesLines.push_back(line);
			else
				rulesLines.push_back(line);
		}
    }

    std::unordered_map<int, std::unordered_set<int>> rules;
    for (const std::string& ruleLine : rulesLines) {
        std::vector<std::string> pages = split(ruleLine, '|');
        int before = stoi(pages[0]);
        int after = stoi(pages[1]);
        rules[before].insert(after);
    }

    int middleSum = 0;
    for (const std::string& updateLine : updatesLines) {
        std::vector<std::string> pages = split(updateLine, ',');
        std::vector<int> update;
        for (const std::string& page : pages)
            update.push_back(stoi(page));
        if (!isValidOrder(update, rules)) {
            update = reorderUpdate(update, rules);
            int middleIndex = update.size() / 2;
            middleSum += update[middleIndex];
        }
    }

    std::cout << middleSum << std::endl;
    return 0;
}
