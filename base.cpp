#include "base.h"

Base::Base(QObject *parent)
    : super(parent)
{
}

void Base::sleep(unsigned long msecs)
{
    ThreadTools::msleep(msecs);
}

void Base::start()
{
    try
    {
        startImpl();
    }
    catch (const nzmqt::ZMQException& ex)
    {
        qWarning() << Q_FUNC_INFO << "Exception:" << ex.what();
        emit failure(ex.what());
        emit finished();
    }
}

void Base::stop()
{
    emit finished();
}
