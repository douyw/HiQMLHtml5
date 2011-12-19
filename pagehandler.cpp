#include "pagehandler.h"

#include <QVariant>
#include <QDebug>

PageHandler::PageHandler(QObject *parent) :
    QObject(parent)
{
}

//PageHandler::~PageHandler()
//{
//}

void PageHandler::handleTestFormData(QVariant var1, QVariant var2)
{
    // 没有下面那个版本时将使用这个函数
    qDebug() << "var1:" << var1 << ", var2:" << var2;
}

void PageHandler::handleTestFormData(QString str1, QString str2)
{
    // 优先使用了此函数
    qDebug() << "str1:" << str1 << ", str2:" << str2;
}
