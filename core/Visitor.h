#ifndef DUPLICATES_VISITOR_H
#define DUPLICATES_VISITOR_H

#include <QDir>
#include <optional>
#include "Stats.h"

class Visitor {
public:
    Stats traverse(QDir root);

private:
    std::optional<QByteArray> calculateHash(const QString &fileName);
};


#endif //DUPLICATES_VISITOR_H
