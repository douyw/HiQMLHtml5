#ifndef MYWEBVIEW_H
#define MYWEBVIEW_H

#include <QDeclarativeItem>
#include <QGraphicsWebView>
#include <QUrl>

class MyWebView : public QDeclarativeItem
{
    Q_OBJECT
    Q_PROPERTY(QString url READ url WRITE setUrl NOTIFY urlChanged);
    Q_PROPERTY(QString title READ title);
    Q_PROPERTY(qreal preferredWidth READ preferredWidth WRITE setPreferredWidth NOTIFY preferredWidthChanged);
    Q_PROPERTY(qreal preferredHeight READ preferredHeight WRITE setPreferredHeight NOTIFY preferredHeightChanged);
    Q_PROPERTY(qreal contentsScale READ contentsScale WRITE setContentsScale NOTIFY contentsScaleChanged);

public:
    MyWebView(QDeclarativeItem *parent = 0);
    static QString adjustPath(const QString &path);

public:
    QString url() const { return url_; }
    void setUrl(QString const &url);
    QString title() const;
    QIcon icon() const;
    qreal preferredWidth() const;
    qreal preferredHeight() const;
    void setPreferredWidth(qreal width);
    void setPreferredHeight(qreal height);

    qreal contentsScale() const;
    void setContentsScale(qreal contentsScale);

public Q_SLOTS:
    void addToJavaScript();
    Q_INVOKABLE void loadFile(QString const& filename);
    Q_INVOKABLE void back();
    Q_INVOKABLE void stop();
    Q_INVOKABLE void relad();
    Q_INVOKABLE void forward();
    Q_INVOKABLE void progress();

Q_SIGNALS:
    void urlChanged();
    void preferredWidthChanged();
    void preferredHeightChanged();
    void contentsScaleChanged();

protected:
    QGraphicsWebView *webView_;
    QString url_;
};

QML_DECLARE_TYPE(MyWebView)

#endif // MYWEBVIEW_H
