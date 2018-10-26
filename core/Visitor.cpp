#include "Visitor.h"
#include "Log.h"
#include <QDir>
#include <QtCore>
#include <QCryptographicHash>
#include <iostream>
#include <unordered_map>

Stats Visitor::traverse(QDir root) {
    QDirIterator it(root.path(), QDir::Files, QDirIterator::FollowSymlinks | QDirIterator::Subdirectories);
    Stats stats;
    while (it.hasNext()) {
        auto file = it.next();
        auto hash = calculateHash(file);
        if (!hash) {
            log(std::string("Failed to calc hash for file"));
            continue;
        }

        log(file.toStdString());
        stats.handle(file.toStdString(), hash->toStdString());
    }
    return stats;
}

std::optional<QByteArray> Visitor::calculateHash(const QString &fileName) {
    QFile f(fileName);
    if (f.exists() && f.open(QFile::ReadOnly)) {
        QCryptographicHash hash(QCryptographicHash::Algorithm::Md5);
        if (hash.addData(&f)) {
            return hash.result();
        }
    }
    return std::nullopt;
}
