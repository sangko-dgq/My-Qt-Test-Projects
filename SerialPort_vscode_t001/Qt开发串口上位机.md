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
