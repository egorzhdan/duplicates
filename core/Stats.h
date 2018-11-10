#ifndef DUPLICATES_STATS_H
#define DUPLICATES_STATS_H

#include <string>
#include <vector>
#include <unordered_map>

typedef std::vector<std::vector<std::string>> Duplicates;

class Stats {
public:
    void handle(std::string&& filePath, const std::string& fileHash);

    void clear();

    std::vector<std::vector<std::string>> getDuplicates() const;

private:
    std::unordered_map<std::string /* hash */, std::vector<std::string /* path */>> filePaths;
};


#endif //DUPLICATES_STATS_H
