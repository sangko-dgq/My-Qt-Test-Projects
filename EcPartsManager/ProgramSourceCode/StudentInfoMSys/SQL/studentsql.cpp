#include "studentsql.h"
#include <QDebug>


StudentSQL *StudentSQL::ptr_studentSQL = nullptr;

StudentSQL::StudentSQL(QObject *parent)
    : QObject{parent}
{

    initSQL();

    /*student*/
    //    QSqlQuery q("", m_db);
    //    q.exec("insert into student values (NULL, 'SangkoDeng', 12, 3, 2, 1, 18848362737, 'Sangko');");

    //    StudentInfo s1;
    //    s1.student_name = "jay";
    //    s1.id = 0;

    //    clearStudentTable();
    //    StudentInfo s1;
    //    s1.student_name = "jay";
    //    addStudent(s1);
    //    addStudent(s1);
    //    addStudent(s1);
    //    addStudent(s1);
    //    removeStudent(3);

    //        StudentInfo s;
    //        s.id = 1;
    //        s.student_name = "HuaWei2022";
    //        qDebug() << updateStudentInfo(s);

    /*user*/
    //    UserInfo info;
    //    info.username = "Sax";
    //    info.password = "220122";
    //    info.aut = "admin";
    //    addUser(info);
    //    addUser(info);

    //    auto l = getAllUser();
    //    qDebug() << "[isExit]" << isExit("Sax");

    //    info.password = "666666";
    //    updateUser(info);
    //    removeUser("Sax");

}

void StudentSQL::initSQL()
{
    if (QSqlDatabase::drivers().isEmpty())
        QMessageBox::information(nullptr, tr("No database drivers found"),
                                 tr("This demo requires at least one Qt database driver. "
                                    "Please check the documentation how to build the "
                                    "Qt SQL plugins."));

    if(QSqlDatabase::contains("qt_sql_default_connection"))
        m_db = QSqlDatabase::database("qt_sql_default_connection");
    else
        m_db = QSqlDatabase::addDatabase("QSQLITE");



    auto exePath = QCoreApplication::applicationDirPath(); //exe所在目录
    auto databasePath = exePath + "\\data.db";

    m_db.setDatabaseName(databasePath); //配置数据库的路径

    if (!m_db.open())
        qDebug() << "[ERROR]unable open database!";


    QSqlQuery sql(m_db);
    sql.exec("create table student (id integer NOT NULL PRIMARY KEY AUTOINCREMENT,name TEXT,age integer,grade integer,class integer,studentid integer,phone TEXT, wechat TEXT);");

}

/*Student*/
quint32 StudentSQL::getStudentCount()
{
    QSqlQuery sql(m_db);
    sql.exec("select count(id) from student;");
    quint32 count;
    while(sql.next())
    {
        count = sql.value(0).toUInt();
    }
    return count;
}

QList<StudentInfo> StudentSQL::getPageStudent(quint32 pageIndex, quint32 count)
{
    QList<StudentInfo> l;
    QSqlQuery sql(m_db);
    QString sql_getPageStudent = QString("select * from student order by id limit %1 offset %2;")
            .arg(count)
            .arg(pageIndex*count);
    sql.exec(sql_getPageStudent);

    StudentInfo info;
    while(sql.next())
    {
        info.id = sql.value(0).toUInt();
        info.student_name = sql.value(1).toString();
        info.student_age = sql.value(2).toUInt();
        info.student_grade= sql.value(3).toUInt();
        info.student_class = sql.value(4).toUInt();
        info.student_id = sql.value(5).toUInt();
        info.student_phoneNum = sql.value(6).toString();
        info.student_wechat = sql.value(7).toString();
        l.push_back(info);
    }
    return l;
}

/*
bool StudentSQL::addStudent(StudentInfo info)
{
    QSqlQuery sql(m_db);
    QString sql_AddStudent = QString("insert into student values(null, '%1', %2, %3, %4, %5, '%6', '%7');")
            .arg(info.student_name)
            .arg(info.student_age)
            .arg(info.student_grade)
            .arg(info.student_class)
            .arg(info.student_id)
            .arg(info.student_phoneNum)
            .arg(info.student_wechat);
    return sql.exec(sql_AddStudent);
}
*/

bool StudentSQL::addStudent(QList<StudentInfo> l)
{

    bool ret;
    QSqlQuery sql(m_db);
    m_db.transaction();
    for(auto info:l)
    {
        QString sql_AddStudent = QString("insert into student values(null, '%1', %2, %3, %4, %5, '%6', '%7');")
                .arg(info.student_name)
                .arg(info.student_age)
                .arg(info.student_grade)
                .arg(info.student_class)
                .arg(info.student_id)
                .arg(info.student_phoneNum)
                .arg(info.student_wechat);
      ret  = sql.exec(sql_AddStudent);
    }
    m_db.commit();
    return ret;
}


bool StudentSQL::removeStudent(int id)
{
    QSqlQuery sql(m_db);
    QString sql_RemoveStudent = QString("delete from student where id = %1;").arg(id);
    return sql.exec(sql_RemoveStudent);
}

bool StudentSQL::clearStudentTable()
{
    QSqlQuery sql(m_db);
    QString sql_clearStudentTable = QString("delete from student;");
    sql.exec("delete from sqlite_sequence where name = 'student';"); //清除ID自增
    return sql.exec(sql_clearStudentTable);
}

bool StudentSQL::updateStudentInfo(StudentInfo info)
{
    qDebug() << info.id;
    qDebug() << info.student_name;

    QSqlQuery sql(m_db);
    QString Sql_UpdateStudentInfo = QString("update student set name='%1',age=%2,grade=%3,class=%4,studentid=%5,phone='%6',wechat='%7' where id=%8;")
            .arg(info.student_name)
            .arg(info.student_age)
            .arg(info.student_grade)
            .arg(info.student_class)
            .arg(info.student_id)
            .arg(info.student_phoneNum)
            .arg(info.student_wechat)
            .arg(info.id);
    bool ret = sql.exec(Sql_UpdateStudentInfo);

    qDebug() << Sql_UpdateStudentInfo;

    QSqlError e = sql.lastError();
    if(e.isValid()) //sql不可用
    {
        qDebug() << e.text();
    }
    return ret;
}

/*User*/
QList<UserInfo> StudentSQL::getAllUser()
{
    QSqlQuery sql(m_db);
    QList<UserInfo> l;
    QString sql_GetAllUser = QString("select * from user;");
    sql.exec(sql_GetAllUser);

    UserInfo info;
    while(sql.next())
    {
        info.username = sql.value(0).toString();
        info.password = sql.value(1).toString();
        info.aut = sql.value(2).toString();
        l.push_back(info);
    }
    return l;
}

bool StudentSQL::isExit(QString username)
{
    QSqlQuery sql(m_db);
    QString sql_IsExit = QString("select *from user where username='%1';").arg(username);
    sql.exec(sql_IsExit);
    return sql.next();
}

bool StudentSQL::updateUser(UserInfo info)
{
    QSqlQuery sql(m_db);
    QString Sql_UpdateUserInfo = QString("update user set password='%1',auth='%2' where username='%3';")
            .arg(info.password)
            .arg(info.aut)
            .arg(info.username);
    return sql.exec(Sql_UpdateUserInfo);
}

bool StudentSQL::addUser(UserInfo info)
{
    QSqlQuery sql(m_db);
    QString sql_AddUser = QString("insert into user values('%1', '%2', '%3');")
            .arg(info.username)
            .arg(info.password)
            .arg(info.aut);
    return sql.exec(sql_AddUser);

}

bool StudentSQL::removeUser(QString username)
{
    QSqlQuery sql(m_db);
    QString sql_RemoveUser = QString("delete from user where username = '%1';").arg(username);
    return sql.exec(sql_RemoveUser);
}








