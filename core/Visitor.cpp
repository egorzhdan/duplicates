#include "Visitor.h"
#include "Log.h"
#include <QDir>
#include <QtCore>
#include <QCryptographicHash>
#include <iostream>
#include <unordered_map>

Visitor::Visitor(QObject *parent, QDir root) : QThread(parent), root(root) {}

void Visitor::run() {
    QDirIterator it(root.path(), QDir::Files, QDirIterator::Subdirectories);
    stats.clear();
    size_t counter = 0;
    while (it.hasNext()) {
        if (isInterruptionRequested()) break;

        auto file = it.next();
        counter++;
        auto hash = calculateHash(file);
        if (!hash) {
            log(std::string("Failed to calc hash for file"));
            continue;
        }

        log(file.toStdString());
        stats.handle(file.toStdString(), hash->toStdString());

        emit processedFile((int) counter);
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
