## [simple case] Development of Student Information Management system

### Modal Dialog 模态对话框

#### 多分辨率布局（窗口多 尺寸布局）

通过设置组件的最大最小size，对齐方式，加入弹簧，设置grid属性等绝对属性, 来限制布局调整时自动相对约束。

![image-20220523161927530](https://s2.loli.net/2022/05/23/QAvqjYGz6klVu5b.png)

size Hint 大小提示

Fixed 固定

Sql Cmake

```cmake
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Sql REQUIRED)
target_link_libraries(StudentInfoMSys PRIVATE Qt${QT_VERSION_MAJOR}::Sql)
```



```c++
struct StructTypeA
{
   int a;
}

void test(StructTypeA info)
{
    cout << info.a;
}


int main()
{
    StructTypeA s;
    s.a = 12;
    
    test(s);
}
```



#### **打断点+ F10 下一行**（断点行不包含执行，断点之前的才执行  ）

![image-20220524014616988](https://s2.loli.net/2022/05/24/Kg8dbhMcwuGDmHy.png)

变量窗口可显示变量的值

![image-20220524015024930](https://s2.loli.net/2022/05/24/zrhjQdiLvOU9Ge8.png)





Table水平自动扩充铺满

![image-20220524144408776](https://s2.loli.net/2022/05/24/4AWa6DrGpU5sz9c.png)





Qt 样式加载

样式内置压缩到exe

外部调用加载（exe更小）



单例 ： 全局唯一的对象







```cpp

/*静态指针的初始化*/
// .h
    Class  StudentSQL
{
    public:
        static StudentSQL *studentSQL; //类内静态指针声明
}

// .cpp
         StudentSQL *StudentSQL::studentSQL = nullptr; //类外
 
 
```





谷歌代码命名规范

指针 p_xx   ptrXX

成员变量 m_xx

成员指针变量 m_ptrXX

空指针判断 ：nullptr == p_xx  不应 p_xx == nullptr



C/S项目  vs  B/S项目



Tab切换下个输入 跳转顺序设置

![image-20220524192810760](https://s2.loli.net/2022/05/24/p6cJAwfxhkXQte2.png)



去掉ID不清空自增

```sqlite
delete from sqlite_sequence where name = 'tableName';
```

