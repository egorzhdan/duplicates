#include "File.h"
#include <QCryptographicHash>

FileHash File::calculateHash() {
    if (open(QFile::ReadOnly)) {
        QCryptographicHash hash(QCryptographicHash::Algorithm::Md5);
        if (hash.addData(this)) {
            return hash.result();
        }
    }
    return QByteArray();
}
