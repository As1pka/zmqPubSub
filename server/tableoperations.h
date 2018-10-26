#ifndef TABLEOPERATIONS_H
#define TABLEOPERATIONS_H

#include <QFile>
#include <QDir>
#include <QList>
#include <QVector>
#include <QStringList>

void fillTable(QVector<QStringList> &table, QString fname);
QStringList correctString(QString &s);
void checkTable(QVector<QStringList> &table);
int isIn(QVector<int> &v, int n);
int dateEqual(QString d1, QString d2);

#endif // TABLEOPERATIONS_H
