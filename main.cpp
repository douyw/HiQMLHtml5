#include <QtGui/QApplication>
#include <QGraphicsObject>
#include <QDeclarativeContext>
#include <QDeclarativeEngine>
#include <QDeclarativeItem>
//#include <QDeclarativeWebView>
#include "qmlapplicationviewer.h"
#include "line.h"
#include <QGraphicsWebView>
#include "mywebview.h"

Q_DECL_EXPORT int main(int argc, char *argv[])
{
    QScopedPointer<QApplication> app(createApplication(argc, argv));

    qmlRegisterType<Line>("CustomComponents", 1, 0, "Line");
    qmlRegisterType<MyWebView>("CustomComponents", 1, 0, "MyWebView");

    QScopedPointer<QmlApplicationViewer> viewer(QmlApplicationViewer::create());

    viewer->setOrientation(QmlApplicationViewer::ScreenOrientationAuto);
//    viewer->setMainQmlFile(QLatin1String("qml/HiQMLHtml5/main.qml"));
//    viewer->setMainQmlFile(QLatin1String("qml/HiQMLHtml5/webbrowser.qml"));
    viewer->setMainQmlFile(QLatin1String("qml/HiQMLHtml5/mywebbrowser.qml"));
    viewer->showExpanded();

    QDeclarativeContext *context = viewer->rootContext();
    context->dumpObjectTree();

    qDebug() << " dump...";
    QGraphicsObject* root = viewer->rootObject();
    root->dumpObjectInfo();
    QDeclarativeItem *item = viewer->rootObject()->findChild<QDeclarativeItem*>("webView");
    if (item) {
        qDebug() << "found.";
//        item->dumpObjectInfo();
    }

    return app->exec();
}
