/**
  @file
  @author Stefan Frings
*/

#include <QCoreApplication>
#include <QDir>
#include <QFile>
#include <httpserver/httplistener.h>
#include <logging/filelogger.h>
#include "requesthandler.h"

using namespace stefanfrings;

/**
  Entry point of the program.
*/
int main(int argc, char *argv[])
{

    // Initialize the core application
    QCoreApplication app(argc, argv);
    app.setApplicationName("Demo2");

    // Collect hardcoded configarion settings
    QSettings* settings=new QSettings(&app);
    // settings->setValue("host","192.168.0.100");
    settings->setValue("port",QString("8080"));
    settings->setValue("minThreads",QString("4"));
    settings->setValue("maxThreads",QString("100"));
    settings->setValue("cleanupInterval",QString("60000"));
    settings->setValue("readTimeout",QString("60000"));
    settings->setValue("maxRequestSize",QString("16000"));
    settings->setValue("maxMultiPartSize",QString("10000000"));
    // settings->setValue("sslKeyFile","ssl/my.key");
    // settings->setValue("sslCertFile","ssl/my.cert");

    // Configure and start the TCP listener    
    new HttpListener(settings,new RequestHandler(&app),&app);

    qWarning("Application has started");
    app.exec();
    qWarning("Application has stopped");
}
