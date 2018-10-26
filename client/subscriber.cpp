#include "subscriber.h"

Subscriber::Subscriber(nzmqt::ZMQContext &context, const QString &address, const QString &topic, QObject *parent)
    : super(parent)
    , address_(address), topic_(topic)
    , socket_(nullptr)
{
    socket_ = context.createSocket(nzmqt::ZMQSocket::TYP_SUB, this);
    socket_->setObjectName("Subscriber.Socket.socket(SUB)");
    connect(socket_, SIGNAL(messageReceived(const QList<QByteArray>&)), SLOT(messageReceived(const QList<QByteArray>&)));
}

void Subscriber::startImpl()
{
    socket_->subscribeTo(topic_);
    socket_->connectTo(address_);
}

void Subscriber::messageReceived(const QList<QByteArray> &message)
{
    updateTable(table, message);
    printTable(table);
    emit pingReceived(message);
}
