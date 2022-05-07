# 如何使用VSCode开发Qt项目？

*为何使用VSCode开发Qt项目？*

*因为Qt自带的编辑器丑丑丑.....，颜值时代还得是vscode大妹子...*

#### **最终效果预览**

![image-20220506000234586](https://s2.loli.net/2022/05/06/onuA8lEifG4cOwj.png)

#### 前期准备

**一、环境工具**

- Qt 5.15.2  (含MingW64构建工具）

- Visual Studio Code  

  必要拓展： C++ 、 CMake、CMake Tools

**二、配置系统环境变量**

   （自行根据自己的Qt安装路径配置）

1. **MingW** 根目录和bin目录

   ```
   D:\Qt5\5.15.2\mingw81_64\
   D:\Qt5\5.15.2\mingw81_64\bin\
   ```

2. **cmake.exe**

   ```
   D:\Qt5\Tools\mingw810_64\bin\   (cmake.exe)
   ```

3. **gcc.exe**

   ```
   D:\Qt5\Tools\mingw810_64\bin\   (gcc.exe)
   ```

效果：

![image-20220505213645265](https://s2.loli.net/2022/05/05/uJS21GjLKlzFZnR.png)

cmd检验：

![image-20220505213559882](https://s2.loli.net/2022/05/05/SGiX9QLxKdrBkvP.png)



**三、在VSCode配置好扩展CmakeTools里的 Cmake Path**

![image-20220505212223785](https://s2.loli.net/2022/05/05/tpKjhoP2lzMIrE9.png)



#### 项目实践

一、在**非中文路径目录**下，创建一个基于**MingW / CMake**的Qt工程

![创建Qt工程](https://s2.loli.net/2022/05/05/4gHLAUNXDumrnfP.gif)

**（注意工程路径不能是中文路径下面，否则编译会出现X fille no found 错误，接下来cmake编译等操作会失败!!!）**

 在Qt里，`Ctrl+R` 运行项目



**二、VSCode打开该工程目录(CMakeLists.txt所在目录)**

1. 选择kit ： GCC / mingw32 

   (如果未检测到对应的kit, 请检查以上的环境配置是否正确)

![image-20220505224140143](https://s2.loli.net/2022/05/05/ZFCUhnvoIwlMJEW.png)

2. `F7`构建(Build)项目 

3. `Shift + F5`运行

若有插件快捷键冲突，点击下面的按钮来操作：

![image-20220505224659792](https://s2.loli.net/2022/05/05/c6qLjYuNnidv4ye.png)

4. 成功运行（无报错，弹出程序窗口）

![image-20220505224904022](https://s2.loli.net/2022/05/05/YLtvX9UNSHwZoWg.png)

5. 测试一下代码提示是否可用

   ![image-20220505225215816](https://s2.loli.net/2022/05/05/csWtUdjw9DuGMl1.png)



#### 可能会出现的报错与解决方法

1. 在Qt里报错：

   ```
    ...'QDialog' file not found...
   ```

​       原因：工程路径是中文路径...

​       解决：将工程移动/重建于非中文路径下，清理后重新构建运行。

2. 在VSCode里：

   ```
   The "cmake" command is not found in PATH. Install it or use `cmake.cmakePath
   ```

   原因：未进行或配置失败这一步：**VSCode配置好扩展CmakeTools里的 Cmake Path**

​       解决：检查/配置扩展CmakeTools里的 Cmake Path

