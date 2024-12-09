#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

long find_free_space(const std::vector<unsigned long> &disc, size_t file_size, size_t block) {
    size_t free_count = 0;
    long start_index = -1;

    for (size_t i = 0; i < block; i++) {
        if (disc[i] == -1) {
            if (free_count == 0) start_index = i;
            free_count++;
            if (free_count == file_size) return start_index;
        } else {
            free_count = 0;
            start_index = -1;
        }
    }
    return -1;
}

void compact_disc(std::vector<unsigned long> &disc, const std::vector<size_t> &file_sizes) {
    for (long file_id = file_sizes.size() - 1; file_id >= 0; file_id--) {
        size_t file_size = file_sizes[file_id];
        size_t block = 0;
        while(block < disc.size() && disc[block] != file_id)
            block++;

        long free_space_index = find_free_space(disc, file_size, block);

        if (free_space_index != -1) {
            for (size_t i = 0; i < disc.size(); i++) {
                if (disc[i] == file_id) disc[i] = -1;
            }
            for (size_t i = 0; i < file_size; i++) {
                disc[free_space_index + i] = file_id;
            }
        }
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
    std::vector<size_t> file_sizes;
    bool free = false;
    unsigned long qtt = 0, j = 0;

    for (size_t i = 0; i < line.size(); i++) {
        qtt = line[i] - '0';
        if (!free) file_sizes.push_back(qtt);
        while (qtt--) {
            disc.push_back(free ? -1 : j);
        }
        if (!free) j++;
        free = !free;
    }

    compact_disc(disc, file_sizes);

    unsigned long long checksum = calculate_checksum(disc);

    std::cout << checksum << std::endl;
    return 0;
}
