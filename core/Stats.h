#ifndef DUPLICATES_STATS_H
#define DUPLICATES_STATS_H

#include <string>
#include <vector>
#include <unordered_map>

class Stats {
public:
    void handle(std::string filePath, std::string fileHash);

    std::vector<std::vector<std::string>> getDuplicates();

private:
    std::unordered_map<std::string /* hash */, std::vector<std::string /* path */>> filePaths;
};


#endif //DUPLICATES_STATS_H
