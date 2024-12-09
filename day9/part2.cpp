#include <iostream>
#include <fstream>
#include <vector>

unsigned long search_last(std::vector<unsigned long> &disc) {
    while (disc.back() == -1)
        disc.pop_back();
    
    size_t size = 0;

    return ;
}

int sizeZone(std::vector<unsigned long> disc, size_t pos, int num)
{
    size_t size = 0;
    while (disc[pos] == num)
    {
        size++;
        pos++;
    }
    return size;
}

void compact_disc(std::vector<unsigned long> &disc) {
    size_t sizeZ = 0;
    for (size_t j = 0; j < disc.size(); j++) {
        if (disc[j] == -1)
        {
            sizeZ = sizeZone(disc, j, -1);
        }
        disc[j] = search_last(disc);
    }
}

unsigned long long calculate_checksum(const std::vector<unsigned long> &disc) {
    unsigned long long checksum = 0;
    for (size_t i = 0; i < disc.size(); i++) {
        if (disc[i] != -1) {
            checksum += disc[i] * i;
        }
    }
    return checksum;
}

int main() {
    std::ifstream file("input.txt");

    std::string line;
    getline(file, line);

    std::vector<unsigned long> disc;
    bool free = false;
    unsigned long qtt = 0, j = 0;

    for (size_t i = 0; i < line.size(); i++) {
        qtt = line[i] - '0';
        while (qtt--) {
            disc.push_back(free ? -1 : j);
        }
        if (!free) j++;
        free = !free;
    }

    compact_disc(disc);
    unsigned long long checksum = calculate_checksum(disc);

    std::cout << checksum << std::endl;
    return 0;
}
