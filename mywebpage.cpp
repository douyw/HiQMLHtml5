#include "mywebpage.h"
#include <QtNetwork/QNetworkRequest>
#include <QWebFrame>
#include <QUrl>
#include <QDebug>

MyWebPage::MyWebPage(QObject *parent) :
    QWebPage(parent)
{
}

bool MyWebPage::acceptNavigationRequest(QWebFrame *frame, const QNetworkRequest &request, NavigationType type)
{
    qDebug() << " type: " << type << ", request: " << request.url().toString();
    return QWebPage::acceptNavigationRequest( frame, request, type );
}
