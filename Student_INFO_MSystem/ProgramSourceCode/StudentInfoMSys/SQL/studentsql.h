#ifndef STUDENTSQL_H
#define STUDENTSQL_H

#include <QObject>
#include <QCoreApplication>
#include <QMessageBox>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>

struct StudentInfo
{
    int id;
    QString student_name;
    quint8  student_age;
    quint16 student_grade;
    quint16 student_class;
    quint32 student_id;
    QString student_phoneNum;
    QString student_wechat;
    
};
struct UserInfo
{
    QString username;
    QString password;
    QString aut;
};

class StudentSQL : public QObject
{
    Q_OBJECT
public:
    explicit StudentSQL(QObject *parent = nullptr);


    //Singalton
    static StudentSQL *ptr_studentSQL;
    static StudentSQL *getInstance()
    {
        if(nullptr == ptr_studentSQL)
        {
            ptr_studentSQL = new StudentSQL;
        }
        return ptr_studentSQL;
    }

    
    void initSQL();
    
    //查询所有学生数量
    quint32 getStudentCount();
    //查询第几页学生数据(从第0页开始)
    QList<StudentInfo> getPageStudent(quint32 pageIndex, quint32 count);
    
    //增加学生
   // bool addStudent(StudentInfo info); //速度慢
    bool addStudent(QList<StudentInfo> l); //速度快

    //删除学生
    bool removeStudent(int id);
    //清空学生表
    bool clearStudentTable();
    //修改学生信息
    bool updateStudentInfo(StudentInfo info);
    
    //////////////////
    //查询所有用户
    QList<UserInfo> getAllUser();
    //查询用户名是否存在
    bool isExit(QString username);
    //更新用户信息
    bool updateUser(UserInfo info);
    //添加单个用户
    bool addUser(UserInfo info);
    //删除单个用户
    bool removeUser(QString  username);
    
signals:
    
    
private:
    QSqlDatabase m_db;
};

#endif // STUDENTSQL_H
