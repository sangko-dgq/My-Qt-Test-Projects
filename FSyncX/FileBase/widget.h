
/*
 * @FilePath: \FileBase\widget.h
 * @Description:
 * @Author: MrDeng
 * @LastEditors: MrDeng
 */
#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "APP/FileBase.h"

QT_BEGIN_NAMESPACE
namespace Ui
{
    class Widget;
}
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void slot_File(const QString &fileName, const QByteArray &data);
    void slot_Del(const QString &fileName);
    void slot_Rename(const QString &fileOld, const QString &fileNew);

    void slot_ServerListen(bool isServerListenOK);

private:
    Ui::Widget *ui;
    FileBase fileBase;

    QString fileBasePath;


};
#endif // WIDGET_H
