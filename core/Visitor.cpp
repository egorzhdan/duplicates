#include "Visitor.h"
#include "Log.h"
#include <QDir>
#include <QtCore>
#include <QCryptographicHash>
#include <iostream>
#include <memory>
#include <unordered_map>

Visitor::Visitor(QObject *parent, QDir root) : QThread(parent), root(root) {}

void Visitor::run() {
    QDirIterator it(root.path(), QDir::Files, QDirIterator::Subdirectories);
    stats.clear();
    size_t totalCount = 0;
    while (it.hasNext()) {
        if (isInterruptionRequested()) break;

        auto filePath = it.next();
        auto fileSize = QFile(filePath).size();
        stats.preHandle(filePath.toStdString(), fileSize);
        totalCount++;
    }

    size_t counter = 0;
    auto suspiciousFiles = stats.getSuspiciousFiles();
    for (auto &file : suspiciousFiles) {
        counter++;
        auto hash = calculateHash(QString::fromStdString(file));
        if (!hash) {
            log(std::string("Failed to calc hash for file"));
            continue;
        }

        log(file);
        stats.handle(std::move(file), hash->toStdString());

        emit processedFile((int) counter, (int) totalCount);
    }
    emit processingFinished();
}

std::optional<QByteArray> Visitor::calculateHash(const QString &fileName) {
    QFile f(fileName);
    if (f.open(QFile::ReadOnly)) {
        QCryptographicHash hash(QCryptographicHash::Algorithm::Md5);
        if (hash.addData(&f)) {
            return hash.result();
        }
    }
    return std::nullopt;
}

Stats Visitor::getStats() {
    return stats;
}
