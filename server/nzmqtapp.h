#ifndef NZMQTAPP_H
#define NZMQTAPP_H

#include <QCoreApplication>

class QTextStream;
class Base;

class NzmqtApp : public QCoreApplication
{
    Q_OBJECT

    typedef QCoreApplication super;

public:
    explicit NzmqtApp(int& argc, char** argv);

    bool notify(QObject *obj, QEvent *event);

protected slots:
    void run();

protected:
    void printUsage(QTextStream& out);
};

#endif // NZMQTAPP_H
