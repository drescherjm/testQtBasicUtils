#include "qbuGUIDev2LoggerJob.h"
#include <QEventLoop>
#include <QxtLogger>
#include "qbuLog/qbuLog.h"
#include <QThread>
#include <iostream>

/////////////////////////////////////////////////////////////////////////////////////////

QxtLogger::LogLevel generateRandomLogLevel();
QString generateInfoMessage();

/////////////////////////////////////////////////////////////////////////////////////////

void qbuGUIDev2LoggerJob::stopJob()
{
    emit quit();
}

/////////////////////////////////////////////////////////////////////////////////////////

qbuGUIDev2LoggerJob::qbuGUIDev2LoggerJob() /*: m_pTimer{}*/
{

    
}

/////////////////////////////////////////////////////////////////////////////////////////

qbuGUIDev2LoggerJob::~qbuGUIDev2LoggerJob()
{
	std::cout << __FUNCTION__ << " ending." << std::endl;
}

/////////////////////////////////////////////////////////////////////////////////////////

void qbuGUIDev2LoggerJob::run()
{

    QTimer timer;

    connect(&timer, SIGNAL(timeout()), this, SLOT(generateLogDataTimer()), Qt::QueuedConnection);
    timer.start(500);

    QEventLoop loop;

    connect(this, SIGNAL(quit()), &loop, SLOT(quit()));

    loop.exec();

	std::cout << __FUNCTION__ << " ending." << std::endl;

    timer.stop();

}

/////////////////////////////////////////////////////////////////////////////////////////

void qbuGUIDev2LoggerJob::generateLogDataTimer()
{

    QxtLogger::LogLevel level = generateRandomLogLevel();

    static int i = 0;

    i++;

    QString strMsg = QString("Thread Message %1: - ").arg(i);

    switch (level) {
    case QxtLogger::InfoLevel:
        QLOG_INFO() << strMsg << generateInfoMessage();
        break;
    case QxtLogger::CriticalLevel:
        QLOG_CRIT() << strMsg << "Something really bad happened!" << "Should I be worried?";
        break;
    case QxtLogger::WarningLevel:
        QLOG_WARN() << strMsg << "What is this warning about?";
        break;
    case QxtLogger::TraceLevel:
        QLOG_TRACE() << strMsg << "John was debugging!";
        break;
    case QxtLogger::ErrorLevel:
        QLOG_ERROR() << strMsg << "Some type of error occurred.";
        break;
    case QxtLogger::DebugLevel:
        QLOG_DEBUG() << strMsg << "John was debugging!" << "What is the difference between TRACE and DEBUG again?";
        break;
    case QxtLogger::WriteLevel:
        QLOG_WRITE() << strMsg << "Lets write something" << "I don't understand the randomization here!";
        break;
    case QxtLogger::FatalLevel:
        QLOG_FATAL() << strMsg << "Should we exit the program?"
            << "I don't know"
            << "Lets generate some more data instead."
            << "Why should I generate data if there is a FATAL error?"
            << "I don't know but keep going.";
        break;
    default:
        qxtLog->log(level, QVariantList() << strMsg << "What is this!" << "Level=" << level);
    }
}

/////////////////////////////////////////////////////////////////////////////////////////
