#include "tableoperations.h"


void fillTable(QVector<QStringList> &table, QString fname)
{
    QDir d;
    QString currPath = d.absolutePath();
    d.cdUp();
    QString path = d.absolutePath();
    d.setCurrent(path);

    QFile inF(fname);
    if (!inF.exists())
        return;
    else if (!inF.open(QIODevice::ReadOnly))
        return;

    while (!inF.atEnd())
    {
        QString str = inF.readLine();
        table.append(correctString(str));
    }

    inF.close();
    d.setCurrent(currPath);
}

QStringList correctString(QString &s)
{
    QStringList tmp = s.split(" ");
    QString date = tmp.last();
    while (date.back() == '\n' || date.back() == '\r')
        date.resize(date.size() - 1);
    tmp.replace(tmp.size() - 1, date);

    return tmp;
}

void checkTable(QVector<QStringList> &table)
{
    QVector<int> id;
    int sz = table.size();
    int sz_1 = sz - 1;
    int insz = table.at(0).size() - 1;
    for (int i = 0; i < sz_1; i++)
    {
        if (isIn(id, i))
            continue;
        for (int j = i + 1; j < sz; j++)
        {
            int check = 0;
            for (int k = 1; k < insz; k++)
                if (table.at(i).at(k) == table.at(j).at(k))
                    check++;
            if ((check == insz - 1) && !dateEqual(table.at(i).at(insz), table.at(j).at(insz)))
                id.push_back(j);
         }
    }

    sz_1 = id.size() - 1;
    for (int i = sz_1; i >= 0; i--)
        table.remove(id.at(i));
}

int isIn(QVector<int> &v, int n)
{
    int size = v.size();
    for (int i = 0; i < size; i++)
        if (v.at(i) == n)
            return 1;

    return 0;
}

int dateEqual(QString d1, QString d2)
{
    QStringList ld1 = d1.split(".");
    QStringList ld2 = d2.split(".");

    int size = ld1.size();
    for (int i = 0; i < size; i++)
        if (QString(ld1.at(i)).toInt() != QString(ld2.at(i)).toInt())
            return 1;

    return 0;
}
