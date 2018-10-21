#ifndef DUPLICATES_LOG_H
#define DUPLICATES_LOG_H

#include <string>
#include <iostream>

void log(const std::string& s) {
//#ifdef IN_DEBUG
    std::cout << s << std::endl;
//#endif
}

#endif //DUPLICATES_LOG_H
