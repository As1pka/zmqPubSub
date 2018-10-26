#ifndef TABLEMODIFICATION_H
#define TABLEMODIFICATION_H

#include <QByteArray>
#include <QList>

void updateTable(QList<QList<QString>> &table, QList<QByteArray> message);
void sortTable(QList<QList<QString>> &table);
bool listQStringLessThen(QList<QString> s1, QList<QString> s2);
void printTable(QList<QList<QString>> &table);

#endif // TABLEMODIFICATION_H
