# Qt开发串口上位机

## 开发环境

1. VSCode( MingW/CMake) 

2. Qt Designer （,ui文件设计）

## 开发

信号与槽： 触发条件(事件)与回调函数（动作） --当点击则跳转

在QtDesiogner,F3/F4切换编辑模式。



UI开发

1. 串口号下拉列表-下拉列表框

   拖入Combo box

   属性面板，设置object Name（对象ID）

   子选项设置(代码实现动态获取添加)

   在SerialPort类中所需的函数：

   设置串口号

   设置波特率

   



1. 开启SerialPort宏开关

   - qmake，在.pro文件中追加serialport

   ```c++
   QT += core gui serialport
   ```

   - cmake(本项目采用cmake)

   在CMakeList.txt中添加Qt5SerialPort组件

   ```
    find_package(Qt5SerialPort REQUIRED)               //find 
    target_link_libraries(mytarget PRIVATE SerialPort) //link
    
   ```

   (其中mytarget 为工程名)

2. 在mianwindow.h中引入头文件

   ```
   #include <QSerialPort>
   ```

**如果找不到该文件，改为以下写法**

```
#include <QtSerialPort/QSerialPort>
```

3. 在MainWindow中实例一个SerialPort，作为MainWindow的一个新私有成员

```
...
private:
    Ui::MainWindow *ui;
    QSerialPort serialPort;
};
...
```

报错：类似于undefined reference  to  _imp_ZN11....serialport....的错

（废了一天的时间，查了各种资料都不行，最后终于发现还必须将模块与工程Link起来(target_link_libraries))

![image-20220506212903343](https://s2.loli.net/2022/05/06/2YgI5OwziSk7R1C.png)

Qt5.1后Cmake采用以下配置:

![Cmake_SerialPort](https://s2.loli.net/2022/05/06/BDSETgYV6kKeqtG.png)









## 如何代码加载QSS：

[zoukankan](http://t.zoukankan.com/)

- HTML
- CSS
- PHP
- JAVA

- # Qt之加载QSS文件

  ------

  # 简述

  Qt中关于样式的使用很常见，为了降低耦合性（与逻辑代码分离），我们通常会定义一个QSS文件，然后编写各种部件（例如：QLable、QLineEdit、QPushButton）的样式，最后使用QApplication进行样式加载，这样，就可以让整个应用程序就共享同一个样式。

  

  - [简述](http://t.zoukankan.com/itrena-p-5938250.html#简述)
  - [新建QSS文件](http://t.zoukankan.com/itrena-p-5938250.html#新建qss文件)
  - [编写QSS](http://t.zoukankan.com/itrena-p-5938250.html#编写qss)
  - [加载QSS](http://t.zoukankan.com/itrena-p-5938250.html#加载qss)
  - [实现原理](http://t.zoukankan.com/itrena-p-5938250.html#实现原理)
  - [更多参考](http://t.zoukankan.com/itrena-p-5938250.html#更多参考)

  

  # 新建QSS文件

  首先，新建一个后缀名为qss的文件，例如：style.qss，将其加入资源文件（qrc）中。

  **提示：**也可以使用绝对路径或相对路径。

  # 编写QSS

  在style.qss文件中编写自己的样式代码，例如：

  ```QSS
  QToolTip {
          border: 1px solid rgb(45, 45, 45);
          background: white;
          color: black;
  }
  ```

  # 加载QSS

  为了方便以后调用，可以写一个静态加载样式的函数：

  ```QSS
  #include <QFile>
  #include <QApplication>
  
  class CommonHelper
  {
  public:
      static void setStyle(const QString &style) {
          QFile qss(style);
          qss.open(QFile::ReadOnly);
          qApp->setStyleSheet(qss.readAll());
          qss.close();
      }
  };
  ```

  然后，在主函数里进行加载：

  ```QSS
  int main(int argc, char *argv[])
  {
      QApplication a(argc, argv);
  
      // 加载QSS样式
      CommonHelper::setStyle("style.qss");
  
      MainWindow window;
      window.show();
  
      return a.exec();
  }
  ```

  # 实现原理

  很容易发现，原来qApp是QCoreApplication的一个单例，然后，将其转换为QApplication。

  ```Qt
  #if defined(qApp)
  #undef qApp
  #endif
  #define qApp (static_cast<QApplication *>(QCoreApplication::instance()))
  ```

  那么，QApplication调用setStyleSheet()以后为何所有的部件样式都改变了呢？

  通过逐层分析，我们发现其主要是调用了setStyle()：

  ```Qt
  void QApplication::setStyle(QStyle *style)
  {
      if (!style || style == QApplicationPrivate::app_style)
          return;
  
      QWidgetList all = allWidgets();
  
      // clean up the old style
      if (QApplicationPrivate::app_style) {
          if (QApplicationPrivate::is_app_running && !QApplicationPrivate::is_app_closing) {
              for (QWidgetList::ConstIterator it = all.constBegin(), cend = all.constEnd(); it != cend; ++it) {
                  QWidget *w = *it;
                  if (!(w->windowType() == Qt::Desktop) &&        // except desktop
                       w->testAttribute(Qt::WA_WState_Polished)) { // has been polished
                      QApplicationPrivate::app_style->unpolish(w);
                  }
              }
          }
          QApplicationPrivate::app_style->unpolish(qApp);
      }
  
      QStyle *old = QApplicationPrivate::app_style; // save
  
      QApplicationPrivate::overrides_native_style =
          nativeStyleClassName() == QByteArray(style->metaObject()->className());
  
  #ifndef QT_NO_STYLE_STYLESHEET
      if (!QApplicationPrivate::styleSheet.isEmpty() && !qobject_cast<QStyleSheetStyle *>(style)) {
          // we have a stylesheet already and a new style is being set
          QStyleSheetStyle *newProxy = new QStyleSheetStyle(style);
          style->setParent(newProxy);
          QApplicationPrivate::app_style = newProxy;
      } else
  #endif // QT_NO_STYLE_STYLESHEET
          QApplicationPrivate::app_style = style;
      QApplicationPrivate::app_style->setParent(qApp); // take ownership
  
      // take care of possible palette requirements of certain gui
      // styles. Do it before polishing the application since the style
      // might call QApplication::setPalette() itself
      if (QApplicationPrivate::set_pal) {
          QApplication::setPalette(*QApplicationPrivate::set_pal);
      } else if (QApplicationPrivate::sys_pal) {
          clearSystemPalette();
          initSystemPalette();
          QApplicationPrivate::initializeWidgetPaletteHash();
          QApplicationPrivate::initializeWidgetFontHash();
          QApplicationPrivate::setPalette_helper(*QApplicationPrivate::sys_pal, /*className=*/0, /*clearWidgetPaletteHash=*/false);
      } else if (!QApplicationPrivate::sys_pal) {
          // Initialize the sys_pal if it hasn't happened yet...
          QApplicationPrivate::setSystemPalette(QApplicationPrivate::app_style->standardPalette());
      }
  
      // initialize the application with the new style
      QApplicationPrivate::app_style->polish(qApp);
  
      // re-polish existing widgets if necessary
      if (QApplicationPrivate::is_app_running && !QApplicationPrivate::is_app_closing) {
          for (QWidgetList::ConstIterator it = all.constBegin(), cend = all.constEnd(); it != cend; ++it) {
              QWidget *w = *it;
              if (w->windowType() != Qt::Desktop && w->testAttribute(Qt::WA_WState_Polished)) {
                  if (w->style() == QApplicationPrivate::app_style)
                      QApplicationPrivate::app_style->polish(w);                // repolish
  #ifndef QT_NO_STYLE_STYLESHEET
                  else
                      w->setStyleSheet(w->styleSheet()); // touch
  #endif
              }
          }
  
          for (QWidgetList::ConstIterator it = all.constBegin(), cend = all.constEnd(); it != cend; ++it) {
              QWidget *w = *it;
              if (w->windowType() != Qt::Desktop && !w->testAttribute(Qt::WA_SetStyle)) {
                      QEvent e(QEvent::StyleChange);
                      QApplication::sendEvent(w, &e);
                      w->update();
              }
          }
      }
  
  #ifndef QT_NO_STYLE_STYLESHEET
      if (QStyleSheetStyle *oldProxy = qobject_cast<QStyleSheetStyle *>(old)) {
          oldProxy->deref();
      } else
  #endif
      if (old && old->parent() == qApp) {
          delete old;
      }
  
      if (QApplicationPrivate::focus_widget) {
          QFocusEvent in(QEvent::FocusIn, Qt::OtherFocusReason);
          QApplication::sendEvent(QApplicationPrivate::focus_widget->style(), &in);
          QApplicationPrivate::focus_widget->update();
      }
  }
  ```

  主要分为4步：

  1. 清理旧样式 - unpolish()
  2. 初始化新样式 - polish()
  3. 加载新样式 - polish() + sendEvent()、update()
  4. 删除旧样式 - delete

  通过调用QWidgetList all = allWidgets()获取了所有控件的集合，然后，利用迭代器QWidgetList::ConstIterator对每一个控件进行处理，最后，通过QApplication::sendEvent()来发送QEvent::StyleChange事件，达到全局样式更改。
