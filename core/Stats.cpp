#include "Stats.h"

void Stats::handle(std::string filePath, std::string fileHash) {
    filePaths[fileHash].push_back(filePath);
}

std::vector<std::vector<std::string>> Stats::getDuplicates() {
    std::vector<std::vector<std::string>> result;
    for (const auto &it : filePaths) {
        if (it.second.size() > 1)
            result.push_back(it.second);
    }
    return result;
}
