#include "nzmqtapp.h"

#include <stdexcept>
#include <QDebug>
#include <QStringList>
#include <QTextStream>
#include <QTimer>

#include "nzmqt/nzmqt.hpp"
#include "publisher.h"

NzmqtApp::NzmqtApp(int &argc, char **argv)
    : super(argc, argv)
{
    QTimer::singleShot(0, this, SLOT(run()));
}

bool NzmqtApp::notify(QObject *obj, QEvent *event)
{
    try
    {
        return super::notify(obj, event);
    }
    catch (std::exception& ex)
    {
        qWarning() << ex.what();
        return false;
    }
}

void NzmqtApp::run()
{
    QTextStream cout(stdout);
    try
    {
        QStringList args = arguments();

        if (args.size() == 1 || "-h" == args[1] || "--help" == args[1])
        {
            printUsage(cout);
            quit();
            return;
        }

        Base* commandImpl = nullptr;

        nzmqt::ZMQContext* context = nzmqt::createDefaultContext(this);
        context->start();

        if (args.size() < 3)
            throw std::runtime_error("Mandatory argument(s) missing!");

        QString address = args[1];
        QString topic = args[2];
        commandImpl = new Publisher(*context, address, topic, this);

        // If command is finished we quit application.
        connect(commandImpl, SIGNAL(finished()), SLOT(quit()));
        // Start command.
        commandImpl->start();
    }
    catch (std::exception& ex)
    {
        qWarning() << ex.what();
        exit(-1);
    }
}

void NzmqtApp::printUsage(QTextStream &out)
{
    QString executable = arguments().at(0);
    out << QString(
"\n\
USAGE: %1 [-h|--help]\
\n\
USAGE: %1 <address> <topic>\
Sample:\n\
%1 tcp://127.0.0.1:1234 ping\n\
\n").arg(executable);
}
