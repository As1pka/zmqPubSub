#ifndef PUBLISHER_H
#define PUBLISHER_H

#include "../base.h"
#include "tableoperations.h"
#include <nzmqt/nzmqt.hpp>

#include <QByteArray>
#include <QTimer>

class Publisher : public Base
{
    Q_OBJECT
    typedef Base super;

public:
    explicit Publisher(nzmqt::ZMQContext& context, const QString& address, const QString& topic, QObject* parent = nullptr);

signals:
    void pingSent(const QList<QByteArray>& message);

protected:
    void startImpl();

protected slots:
    void sendPing();

private:
    QVector<QStringList> table;
    QString address_;
    QString topic_;

    nzmqt::ZMQSocket* socket_;
};

#endif // PUBLISHER_H
