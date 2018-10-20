#ifndef DUPLICATES_FILE_H
#define DUPLICATES_FILE_H

#include <QFile>

using FileHash = QByteArray;

class File : private QFile {
public:
    FileHash calculateHash();
};


#endif //DUPLICATES_FILE_H
