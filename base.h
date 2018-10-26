#ifndef BASE_H
#define BASE_H

#include "nzmqt/nzmqt.hpp"

#include <QDebug>
#include <QEventLoop>
#include <QThread>

class Base : public QObject
{
    Q_OBJECT
    typedef QObject super;

signals:
    void finished();
    void failure(const QString& what);

public slots:
    void start();
    void stop();

protected:
    Base(QObject* parent);

    virtual void startImpl() = 0;

    static void sleep(unsigned long msecs);

private:
    class ThreadTools : private QThread
    {
    public:
        using QThread::msleep;

    private:
        ThreadTools() {}
    };
};

#endif // BASE_H
