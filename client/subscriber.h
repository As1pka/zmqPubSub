#ifndef SUBSCRIBER_H
#define SUBSCRIBER_H

#include "../base.h"
#include "tablemodification.h"
#include <nzmqt/nzmqt.hpp>

class Subscriber : public Base
{
    Q_OBJECT
    typedef Base super;

public:
    explicit Subscriber(nzmqt::ZMQContext& context, const QString& address, const QString& topic, QObject *parent = nullptr);

signals:
    void pingReceived(const QList<QByteArray>& message);

protected:
    void startImpl();

protected slots:
    void messageReceived(const QList<QByteArray>& message);

private:
    QString address_;
    QString topic_;
    QList<QList<QString>> table;

    nzmqt::ZMQSocket* socket_;
};

#endif // SUBSCRIBER_H
