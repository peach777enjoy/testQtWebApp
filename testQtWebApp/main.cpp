#include <QCoreApplication>
#include <QSettings>
#include "httplistener.h"
#include "MyRequestHandler.h"
#include "global.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QString binDir=QCoreApplication::applicationDirPath();
    QString fileName = binDir + "/httpServer/httpServer.ini";

//    QSettings* logSettings=new QSettings(fileName,QSettings::IniFormat,&a);
//    logSettings->beginGroup("logging");
//    FileLogger* logger=new FileLogger(logSettings,10000,&a);
//    logger->installMsgHandler();

    QSettings* fileSettings=new QSettings(fileName,QSettings::IniFormat,&a);
    fileSettings->beginGroup("document");
    staticFileController=new StaticFileController(fileSettings,&a);

    QSettings* listenerSettings = new QSettings(fileName,QSettings::IniFormat,&a);
    listenerSettings->beginGroup("listener");
    new HttpListener(listenerSettings, new MyRequestHandler(&a),&a);

    return a.exec();
}
