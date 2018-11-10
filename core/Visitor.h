#ifndef DUPLICATES_VISITOR_H
#define DUPLICATES_VISITOR_H

#include <QThread>
#include <QDir>
#include <optional>
#include "Stats.h"

class Visitor : public QThread {
Q_OBJECT

public:
    Visitor(QObject *parent, QDir root);

    void run() override;

    Stats getStats();

signals:

    void processedFile(int idx);

    void processingFinished();

private:
    QDir root;
    Stats stats;

    std::optional<QByteArray> calculateHash(const QString &fileName);
};


#endif //DUPLICATES_VISITOR_H
