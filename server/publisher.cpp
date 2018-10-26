#include "publisher.h"

Publisher::Publisher(nzmqt::ZMQContext &context, const QString &address, const QString &topic, QObject *parent)
    : super(parent)
    , address_(address), topic_(topic)
    , socket_(nullptr)
{
    socket_ = context.createSocket(nzmqt::ZMQSocket::TYP_PUB, this);
    socket_->setObjectName("Publisher.Socket.socket(PUB)");
}

void Publisher::startImpl()
{
    socket_->bindTo(address_);

    fillTable(table, "student_file_1.txt");
    fillTable(table, "student_file_2.txt");
    checkTable(table);

    QTimer::singleShot(3000, this, SLOT(sendPing()));
}

void Publisher::sendPing()
{
    static quint64 counter = 0;
    if (counter == table.size())
        return;

    QList< QByteArray > msg;
    msg += topic_.toLocal8Bit();
    for (int i = 0; i < table.at(counter).size(); i++)
        msg += QString("%1").arg(table.at(counter).at(i)).toLocal8Bit();

    counter++;
    socket_->sendMessage(msg);
    emit pingSent(msg);

    QTimer::singleShot(1000, this, SLOT(sendPing()));
}
