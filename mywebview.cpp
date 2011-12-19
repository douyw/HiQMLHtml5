#include "mywebview.h"
#include "mywebpage.h"
#include "pagehandler.h"
#include <QDir>
#include <QCoreApplication>
#include <QWebFrame>
#include <QDebug>

QString MyWebView::adjustPath(const QString &path)
{
#ifdef Q_OS_UNIX
#ifdef Q_OS_MAC
    if (!QDir::isAbsolutePath(path))
        return QCoreApplication::applicationDirPath()
                + QLatin1String("/../Resources/") + path;
#else
    const QString pathInInstallDir = QCoreApplication::applicationDirPath()
        + QLatin1String("/../") + path;
    if (pathInInstallDir.contains(QLatin1String("opt"))
            && pathInInstallDir.contains(QLatin1String("bin"))
            && QFileInfo(pathInInstallDir).exists()) {
        return pathInInstallDir;
    }
#endif
#endif
    return path;
}

MyWebView::MyWebView(QDeclarativeItem *parent) :
        QDeclarativeItem(parent)
{
    // Important, otherwise the paint method is never called
    setFlag(QGraphicsItem::ItemHasNoContents, true);
    webView_ = new QGraphicsWebView (this);
    webView_->setAcceptTouchEvents(true);
    webView_->setAcceptHoverEvents(false);

    MyWebPage* page = new MyWebPage(webView_);
    webView_->setPage( page );
    connect(webView_->page()->mainFrame(),
            SIGNAL(javaScriptWindowObjectCleared()), SLOT(addToJavaScript()));

//    webView_->setPreferredWidth();
//    webView_->load(QLatin1String("html/index.html"));

}

void MyWebView::setUrl(QString const &url)
{
    if ( url != url_ ) {
        url_ = url;
        if ( url_.indexOf( QLatin1String("://") ) < 0 ) {
            webView_->setUrl(QUrl(MyWebView::adjustPath(url_)));
        }
        else
            webView_->setUrl( QUrl( url ) );
        Q_EMIT urlChanged();
    }
}

QString MyWebView::title() const
{
    return webView_->title();
}

QIcon MyWebView::icon() const
{
    return webView_->icon();
}

void MyWebView::addToJavaScript()
{
    webView_->page()->mainFrame()->addToJavaScriptWindowObject("Qt", this);
    PageHandler *handler = new PageHandler( this );
    webView_->page()->mainFrame()->addToJavaScriptWindowObject("handler", handler);
}

void MyWebView::loadFile(QString const& fileName)
{
    qDebug() << "MyWebView::loadFile -- fileName:" << fileName;
    webView_->setUrl(QUrl(MyWebView::adjustPath(fileName)));
}

qreal MyWebView::preferredWidth() const
{
    return webView_->preferredWidth();
}

qreal MyWebView::preferredHeight() const
{
    return webView_->preferredHeight();
}

void MyWebView::setPreferredWidth(qreal width)
{    
    webView_->setPreferredWidth( width );
    Q_EMIT preferredWidthChanged();
}

void MyWebView::setPreferredHeight(qreal height)
{
    webView_->setPreferredHeight( height );
    Q_EMIT preferredHeightChanged();
}

qreal MyWebView::contentsScale() const
{
    return webView_->scale();
}

void MyWebView::setContentsScale(qreal scale)
{
    webView_->setScale( scale );
    Q_EMIT contentsScaleChanged();
}

void MyWebView::back()
{
    webView_->back();
}

void MyWebView::stop()
{
    webView_->stop();
}

void MyWebView::relad()
{
    webView_->reload();
}

void MyWebView::forward()
{
    webView_->forward();
}

void MyWebView::progress()
{
//    webView_->
}
