#include "MyRequestHandler.h"

MyRequestHandler::MyRequestHandler(QObject* parent)
    : HttpRequestHandler(parent) {
    // empty
}

void MyRequestHandler::service(HttpRequest &request, HttpResponse &response) {

    QByteArray path=request.getPath();
    qDebug("RequestMapper: path=%s",path.data());

    if (path.startsWith("/en") || path.startsWith("/zh")) {
        staticFileController->service(request,response);
    }
    else if (path.startsWith("/hello") ) {
        response.write("Hello World",true);
    }
    else {
        response.setStatus(404,"Not found");
        response.write("The URL is wrong no such document.");
    }

    qDebug("RequestMapper: finished request");

    // Clear the log buffer
//    if (logger)
//    {
//       logger->clear();
//    }
}
