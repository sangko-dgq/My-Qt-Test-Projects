#include "imageviewer.h"
#include "./ui_imageviewer.h"

ImageViewer::ImageViewer(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::ImageViewer)
{
    ui->setupUi(this);

    //加载默认Qss
    CommonHelper::setStyle(":/Default.qss");

    /*默认窗口尺寸800*600, 且显示在电脑屏幕中央*/
    setGeometry(
        GetScreenSize(0) / 2 - this->width() / 2, GetScreenSize(1) / 2 - this->height() / 2,
        800, 600);

    ///初始化
    // initImageResource();
    newObject();
    initObject();
}

ImageViewer::~ImageViewer()
{
    delete ui;
}

//******************************************************** New/Init Objects
void ImageViewer::newObject()
{
    //图片容器
    label_real_img = new QLabel(ui->imagePanel);
    //鼠标右键_菜单
    m_contextMenu = new QMenu;
    //鼠标右键_菜单子项
    mAction_CopyPath = new QAction("复制图片地址", this);
    mAction_SetBg = new QAction("设置为桌面壁纸", this);
    mAction_Reset = new QAction("复位", this);
}
void ImageViewer::initObject()
{
    /*添加鼠标右键菜单子项*/
    m_contextMenu->addAction(mAction_Reset);
    m_contextMenu->addAction(mAction_CopyPath);
    m_contextMenu->addAction(mAction_SetBg);
    //隐藏设置面板
    ui->SettingPanel->hide();

    /*ImageInfo初始化*/
    index = -1;
    angle = 0;
    size = QSize(0, 0);
    filename.clear();
    path.clear();
}

//******************************************************** QEvent listening

/*根据 窗口尺寸动态 自动重绘 回调函数*/
//窗口大小改变后，自动重新绘制调用，实现settingPanel相对窗口位置的保持
void ImageViewer::paintEvent(QPaintEvent *event)
{

    /*限定窗口最小尺寸*/
    if (this->width() <= 800)
        ImageViewer::setMinimumWidth(800);
    if (this->height() <= 600)
        ImageViewer::setMinimumHeight(600);

    /*SettingPanel*/
    //因为paintEvent会在开始就调用一次，则SettingPanel一开始就会显示出来
    //我们的目的是，只有SettingPanel显示了才调用以下函数来重绘或者根据窗口改变重绘
    if (!ui->SettingPanel->isHidden())
        ui->SettingPanel->move(this->width() / 2 - 250, this->height() / 2 - 200);

    /*imagePanel*/
    ui->imagePanel->setGeometry(0, 0, this->width(), this->height());

    /*图片居中*/
    //创建一个虚拟label,尺寸为导入图片的size
    label_real_img->setGeometry(
        ui->imagePanel->width() / 2 - pixmap.width() / 2, ui->imagePanel->height() / 2 - pixmap.height() / 2,
        pixmap.width(), pixmap.height());

    /*相对于imagePanel窗口区域-动态居中*/
    ui->SettingPanel->move(this->width() / 2 - 250, this->height() / 2 - 200);

    /*未打卡图片文件时候，默认显示的是软件LOGO,始终相对显示在imagePanel对象中心上*/
    ui->MainLogo->move(this->width() / 2 - 250, this->height() / 2 - 100);
    
}

/*鼠标右键事件*/
void ImageViewer::mousePressEvent(QMouseEvent *event)
{
    if (index == -1)
        return; //如果没打开文件，不执行右键菜单

    //确保右键点击，然后跳出菜单.
    if (event->button() == Qt::RightButton)
    {
        m_contextMenu->exec(event->globalPos());
    }
}
/*鼠标滚轮事件*/
void ImageViewer::wheelEvent(QWheelEvent *event)
{
    if (index == -1)
        return; //如果没打开文件，不执行鼠标滚轮操作

    if (event->delta() > 0) //向上滚动
    {
        ZoomOut();
    }
    else
    {
        ZoomIn();
    }
}

//******************************************************** Common

// ///初始化ImageResource相关参数(UI绘制后)
// void ImageViewer::initImageResource(void)
// {
//     index = -1;
//     angle = 0;
//     size = QSize(0, 0);
//     filename.clear();
//     path.clear();
// }

/*获取屏幕分辨率，0为宽，1为高*/
int ImageViewer::GetScreenSize(int type)
{
    QRect screenRect = QGuiApplication::primaryScreen()->geometry();
    int screenW, screenH;
    switch (type) // width
    {
    case 0: // width
        screenW = screenRect.width();
        return screenW;
        break;

    case 1: // height
        screenH = screenRect.height();
        return screenH;
        break;
    default:
        return -1;
        break;
    }
}

////打开本地某文件夹中的一个图片
int ImageViewer::loadImageResource(void)
{
    //文件对话框
    filename = QFileDialog::getOpenFileName(
        this, tr("选择图片"),
        "D:\\Documents\\Pictures",
        tr("Images(*.png *.bmp *.jpg *.gif)"));

    // file为空
    if (filename.isEmpty())
        return -1;

    // image file加载失败
    if (!image.load(filename))
    {
        //弹出错误消息框
        QMessageBox::information(this, tr("错误"), tr("打开文件失败"));
        return -1;
    }
    // QImage->QPixmap
    //更新pixmap，size变量
    pixmap = QPixmap::fromImage(image);
    size = pixmap.size();

    //获取图片信息
    getFileInfoList();
    return 0;
}

///读取图片所在文件夹的路径和目录列表信息
int ImageViewer::getFileInfoList(void)
{
    QFileInfo info; //定义变量
    QFileInfoList infoList;

    path = QFileInfo(filename).absolutePath(); //返回绝对路径
    dir = QFileInfo(filename).absoluteDir();   //返回目录名称
    /* clear list */
    fileInfoList.clear();
    infoList = dir.entryInfoList(QDir::Files); //列出dir(path)目录文件下所有文件和目录信息，存储到infoList 容器

    //进行文件夹递归遍历，将内容存入infoList 容器
    for (int i = 0; i < infoList.count(); i++)
    {                                   //文件数目：fileInfo.count();
        info = infoList.at(i);          //文件名称：fileInfo.at(i)
        QString suffix = info.suffix(); //后缀名
        if (suffix == "jpg" || suffix == "bmp" || suffix == "png")
        {
            fileInfoList.append(info);
        }
    }
    QFileInfo curImageInfo = QFileInfo(filename);
    for (int j = 0; j < fileInfoList.count(); j++)
    {
        info = fileInfoList.at(j); //进行文件夹递归遍历
        if (info.fileName() == curImageInfo.fileName())
        {
            index = j; //记录索引值
        }
    }
    return 0;
}

/*放大*/
void ImageViewer::ZoomOut()
{
    //加载图片后，已得到image、size等数据，这里直接进行处理
    QImage imgScaled;
    QImage imgRotate;
    QMatrix matrix;
    // 调用image.scaled函数，进行尺度变换
    imgScaled = image.scaled(size.width() * 1.2, //放大倍数1.2
                             size.height() * 1.2,
                             Qt::KeepAspectRatio);
    /* modify angle */
    matrix.rotate(angle * 90);                 //读取当前旋转角度
    imgRotate = imgScaled.transformed(matrix); //变换

    pixmap = QPixmap::fromImage(imgScaled);
    size = pixmap.size();
    // Label标签上显示图片
    label_real_img->setPixmap(pixmap);
    label_real_img->resize(size); //实现图片自适应大小
    return;
}

/*缩小*/
void ImageViewer::ZoomIn()
{

    //加载图片后，已得到image、size等数据，这里直接进行处理
    QImage imgScaled;
    QImage imgRotate;
    QMatrix matrix;
    // 调用image.scaled函数，进行尺度变换
    imgScaled = image.scaled(size.width() * 0.8, //缩小倍数1.2
                             size.height() * 0.8,
                             Qt::KeepAspectRatio);
    /* modify angle */
    matrix.rotate(angle * 90);                 //读取当前旋转角度
    imgRotate = imgScaled.transformed(matrix); //变换

    pixmap = QPixmap::fromImage(imgScaled);
    size = pixmap.size();
    // Label标签上显示图片
    label_real_img->setPixmap(pixmap);
    label_real_img->resize(size); //实现图片自适应大小
    return;
}

//******************************************************** Qt Slots

/// open
void ImageViewer::on_actionopen_triggered()
{
    //打开图片
    loadImageResource();
    //显示在imageLabel上
    label_real_img->setPixmap(pixmap);
    //基于size变量自适应显示
    label_real_img->resize(size);
    //程序窗口标替换题显示为-图片名字信息
    setWindowTitle(QFileInfo(filename).fileName() + tr("-imageViewer"));
    //隐藏主界面Logo
    ui->MainLogo->hide();

}
// Close
void ImageViewer::on_actionclose_triggered()
{
    //清除图片显示
    ui->imagePanel->clear();
    label_real_img->clear();

    index = -1; //图片序列号复位为-1
    filename.clear();
    path.clear();

    //显示主界面
    ui->MainLogo->show();

    // // //读取资源文件中+号图片
    // image.load(":/iconsA/images/icon_pack001/add.png");
    // pixmap = QPixmap::fromImage(image);
    // size = pixmap.size();
    // ui->imagePanel->setPixmap(pixmap);

    // ui->imagePanel->resize(size); //实现图片自适应大小
    // ui->imagePanel->setAlignment(Qt::AlignCenter); //居中显示

    //复原程序窗口标题
    setWindowTitle(tr("imageViewer"));
}
// Exit
void ImageViewer::on_actionedit_triggered()
{
    if (!(QMessageBox::information(
            this, tr("exit"), tr("确认退出程序?"), tr("确认"), tr("取消"))))
    {
        close();
    }
}
// Last
void ImageViewer::on_actionLast_triggered()
{
    if (index == -1)
        return; //如果没打开文件就点击，则直接返回，不执行下面操作

    index = index - 1;                //更新索引值，减一
    int count = fileInfoList.count(); //读取文件个数的统计值
                                      //判断是否第一张图片
    if (index < 0)
    {
        QMessageBox::information(this, tr("Tip"), tr("所在目录无上一张"));
        index = count - 1;
    }
    //读取当前路径path下索引值index – 1的文件名
    filename.clear();
    filename.append(path);
    filename += "/";
    filename += fileInfoList.at(index).fileName();
    //根据文件名加载图片，否则错误提示
    if (!image.load(filename))
    {
        QMessageBox::information(this, tr("Error"), tr("Open file error"));
        return;
    }
    // QImage转换成QPixmap
    pixmap = QPixmap::fromImage(image);
    size = pixmap.size();

    // Label标签上显示图片
    label_real_img->setPixmap(pixmap);
    label_real_img->resize(size); //实现图片自适应大小
    //标题栏上，添加图片名和-imageViewer
    setWindowTitle(QFileInfo(filename).fileName() + tr(" - imageViewer"));
    return;
}

// Next

void ImageViewer::on_actionNext_triggered()
{
    if (index == -1)
        return; //如果没打开文件就点击，则直接返回，不执行下面操作

    index = index + 1;                //更新索引值，减一
    int count = fileInfoList.count(); //读取文件个数的统计值
                                      //判断是否最后一张图片
    if (index == count)
    {
        QMessageBox::information(this, tr("Tip"), tr("所在目录无下一张"));
        index = 0;
    }
    //读取当前路径path下索引值index – 1的文件名
    filename.clear();
    filename.append(path);
    filename += "/";
    filename += fileInfoList.at(index).fileName();
    //根据文件名加载图片，否则错误提示
    if (!image.load(filename))
    {
        QMessageBox::information(this, tr("Error"), tr("Open file error"));
        return;
    }
    // QImage转换成QPixmap
    pixmap = QPixmap::fromImage(image);
    size = pixmap.size();
    // Label标签上显示图片
    label_real_img->setPixmap(pixmap);
    label_real_img->resize(size); //实现图片自适应大小
    //标题栏上，添加图片名和- imageViewer
    setWindowTitle(QFileInfo(filename).fileName() + tr(" - imageViewer"));
    return;
}

// Left
void ImageViewer::on_actionLeft_triggered()
{
    if (index == -1)
        return; //如果没打开文件就点击，则直接返回，不执行下面操作

    //预先加载图片后，已得到image、size等数据，这里直接进行左旋处理
    QImage imgRotate; //定义局部变量
    QMatrix matrix;

    angle += 3;
    angle = angle % 4;                     //取余数
    matrix.rotate(angle * 90);             //得到旋转角度，逆时针旋转
    imgRotate = image.transformed(matrix); //尺度变换函数transformed(matrix)
    pixmap = QPixmap::fromImage(imgRotate);
    size = pixmap.size();
    // Label标签上显示图片
    label_real_img->setPixmap(pixmap);
    label_real_img->resize(size); //实现图片自适应大小
    return;
}

// Right
void ImageViewer::on_actionRight_triggered()
{
    if (index == -1)
        return; //如果没打开文件就点击，则直接返回，不执行下面操作

    //预先加载图片后，已得到image、size等数据，这里直接进行左旋处理
    QImage imgRotate; //定义局部变量
    QMatrix matrix;

    angle += 1;
    angle = angle % 4;                     //取余数
    matrix.rotate(angle * 90);             //得到旋转角度，逆时针旋转
    imgRotate = image.transformed(matrix); //尺度变换函数transformed(matrix)
    pixmap = QPixmap::fromImage(imgRotate);
    size = pixmap.size();
    // Label标签上显示图片
    label_real_img->setPixmap(pixmap);
    label_real_img->resize(size); //实现图片自适应大小
    return;
}

// Zoom In
void ImageViewer::on_actionZoom_In_triggered()
{
    if (index == -1)
        return; //如果没打开文件就点击，则直接返回，不执行下面操作

    ZoomIn();
}

// Zoom Out
void ImageViewer::on_actionZoom_Out_triggered()
{
    if (index == -1)
        return; //如果没打开文件就点击，则直接返回，不执行下面操作

    ZoomOut();
}

/// Setting
void ImageViewer::on_actionAbout_triggered()
{
    ui->SettingPanel->show();
    ui->MainLogo->hide();

    /*禁用其他操作*/
    ui->menubar->setEnabled(false);
    ui->toolBar->setEnabled(false);
}

void ImageViewer::on_BBox_SaveSetting_accepted()
{
    QMessageBox::information(this, tr(""), tr("设置生效"));
    /*隐藏*/
    ui->SettingPanel->hide();
    ui->MainLogo->show();

    /*激活其他操作*/
    ui->menubar->setEnabled(1);
    ui->toolBar->setEnabled(1);
}
void ImageViewer::on_BBox_SaveSetting_rejected()
{
    /*复位默认设置*/

    /*隐藏*/
    ui->SettingPanel->hide();
    ui->MainLogo->show();

    /*激活其他操作*/
    ui->menubar->setEnabled(1);
    ui->toolBar->setEnabled(1);
}

void ImageViewer::on_Btn_CheckUpdate_clicked()
{
    QDesktopServices::openUrl(QUrl(QString("https://github.com/sangko-dgq/My-Qt-Test-Projects/releases/")));
}

/*主题切换*/
void ImageViewer::on_CBox_Theme_currentIndexChanged(int index)
{
    if (ui->CBox_Theme->currentText() == "AquaStyle")
    {
        CommonHelper::setStyle(":/AquaStyle.qss");
        // QMessageBox::information(this, tr("错误"), tr("失败"));
    }
    if (ui->CBox_Theme->currentText() == "Default")
    {
        CommonHelper::setStyle(":/Default.qss");
    }
    if (ui->CBox_Theme->currentText() == "ElegantDark")
    {
        CommonHelper::setStyle(":/ElegantDark.qss");
        /*修订补充*/
        // QString ElegantDark_Ex = "background-color:rgb(82, 82, 82);";
        // ui->imagePanel->setStyleSheet(ElegantDark_Ex);
    }
}