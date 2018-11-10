#include "Stats.h"
#include <algorithm>

void Stats::preHandle(std::string &&filePath, int64_t size) {
    fileBySize[size].push_back(filePath);
}

void Stats::handle(std::string &&filePath, const std::string &fileHash) {
    fileByHash[fileHash].push_back(filePath);
}

Duplicates Stats::getDuplicates() const {
    Duplicates result;
    for (const auto &it : fileByHash) {
        if (it.second.size() > 1)
            result.push_back(it.second);
    }
    std::sort(result.begin(), result.end(), [](const auto &lhs, const auto &rhs) {
        return lhs.size() > rhs.size();
    });
    return result;
}

void Stats::clear() {
    fileByHash.clear();
}

std::vector<std::string> Stats::getSuspiciousFiles() const {
    std::vector<std::string> result;
    for (const auto &it : fileBySize) {
        const auto &files = it.second;
        if (files.size() > 1) {
            result.insert(result.end(), files.begin(), files.end());
        }
    }
    return result;
}
