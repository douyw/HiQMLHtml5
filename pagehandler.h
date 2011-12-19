#ifndef PAGEHANDLER_H
#define PAGEHANDLER_H

#include <QObject>

class PageHandler : public QObject
{
    Q_OBJECT
public:
    explicit PageHandler(QObject *parent = 0);
//    ~PageHandler();

public slots:
    void handleTestFormData(QVariant var1, QVariant var2);
    void handleTestFormData(QString str1, QString str2);

};

#endif // PAGEHANDLER_H
