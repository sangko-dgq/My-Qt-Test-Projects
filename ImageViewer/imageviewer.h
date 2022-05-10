#ifndef IMAGEVIEWER_H
#define IMAGEVIEWER_H

#include <QMainWindow>

#include <QFileDialog>
#include <QMessageBox>
#include <QApplication>

#include <QPaintEvent>

/*右键菜单*/
#include <QListWidget>
#include <QMenu>
#include <QAction>
#include <QContextMenuEvent>
#include <QMouseEvent>

/*网页跳转*/
#include <QDesktopServices>
#include <QUrl>

/*屏幕*/
#include <QScreen>

QT_BEGIN_NAMESPACE
namespace Ui
{
    class ImageViewer;
}
QT_END_NAMESPACE

class ImageViewer : public QMainWindow
{
    Q_OBJECT

public:
    ImageViewer(QWidget *parent = nullptr);
    ~ImageViewer();

protected:
    /*事件重写*/
    /*paintEvent*/
    void paintEvent(QPaintEvent *event) override;
    /*鼠标事件*/
    void mousePressEvent(QMouseEvent *event) override;
    //鼠标滚轮滚动
    void wheelEvent(QWheelEvent *event) override;

private slots:
    void on_actionopen_triggered();

    void on_actionclose_triggered();

    void on_actionedit_triggered();

    void on_actionLast_triggered();

    void on_actionNext_triggered();

    void on_actionLeft_triggered();

    void on_actionRight_triggered();

    void on_actionZoom_In_triggered();

    void on_actionZoom_Out_triggered();

    void on_actionAbout_triggered();

    void on_BBox_SaveSetting_accepted();
    void on_BBox_SaveSetting_rejected();

    void on_Btn_CheckUpdate_clicked();

    void on_CBox_Theme_currentIndexChanged(int index);

private:
    Ui::ImageViewer *ui;

    void newObject(void);
    void initObject(void);

    // void initImageResource(void);
    int loadImageResource(void);
    int getFileInfoList(void);

    void ZoomOut();
    void ZoomIn();

    int GetScreenSize(int type);

    QLabel *label_real_img;
    int index;
    int angle;

    /*File*/
    QString filename;
    QImage image;
    QPixmap pixmap;

    /*Fille Information*/
    QSize size;
    QString path;
    QDir dir;
    QFileInfo fileInfo;
    QFileInfoList fileInfoList;

    /*鼠标右键菜单*/
    QMenu *m_contextMenu;
    QAction *mAction_CopyPath;
    QAction *mAction_SetBg;
    QAction *mAction_Reset;
};

//******************************************************** CommonHelper
#include <QFile>
#include <QApplication>
class CommonHelper
{
public:
    static void setStyle(const QString &style)
    {
        QFile qss(style);
        qss.open(QFile::ReadOnly);
        qApp->setStyleSheet(qss.readAll());
        qss.close();
    }
};

#endif // IMAGEVIEWER_H
