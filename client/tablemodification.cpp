#include "tablemodification.h"

#include <QtAlgorithms>
#include <iostream>

void updateTable(QList<QList<QString>> &table, QList<QByteArray> message)
{
    message.pop_front();
    QList<QString> str;
    int size = message.size();
    for (int i = 0; i < size; i++)
        str.append(QString::fromStdString(message.at(i).toStdString()));
    table.append(str);

    if (table.size() > 1)
        sortTable(table);
}

void sortTable(QList<QList<QString>> &table)
{
    qSort(table.begin(), table.end(), listQStringLessThen);
}

bool listQStringLessThen(QList<QString> s1, QList<QString> s2)
{
    int fl = (s1.at(2) == s2.at(2));
    if (fl)
        return s1.at(1) <= s2.at(1);

    return s1.at(2) < s2.at(2);
}

void printTable(QList<QList<QString>> &table)
{
    system("cls");
    int size = table.size();
    for (int i = 0; i < size; i++)
        std::cout << table.at(i).at(0).toStdString() << " "
                  << table.at(i).at(1).toStdString() << " "
                  << table.at(i).at(2).toStdString() << " "
                  << table.at(i).at(3).toStdString() << "\n";
}
