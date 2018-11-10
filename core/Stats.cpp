#include "Stats.h"
#include <algorithm>

void Stats::handle(std::string&& filePath, const std::string& fileHash) {
    filePaths[fileHash].push_back(filePath);
}

Duplicates Stats::getDuplicates() const {
    Duplicates result;
    for (const auto &it : filePaths) {
        if (it.second.size() > 1)
            result.push_back(it.second);
    }
    std::sort(result.begin(), result.end(), [](const auto& lhs, const auto& rhs) {
        return lhs.size() > rhs.size();
    });
    return result;
}

void Stats::clear() {
    filePaths.clear();
}
