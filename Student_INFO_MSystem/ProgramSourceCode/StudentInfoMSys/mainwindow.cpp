#include "mainwindow.h"
#include "./ui_mainwindow.h"



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    ,m_ptrStudentSQL(nullptr)
{
    ui->setupUi(this);

    loginWindow.show();

    auto s = [&]()
    {
        this->show();
    };
    connect(&loginWindow, &LoginWindow::sg_sendLoginSuccess, this, s);

    ui->tree_leftTreePanel->clear();
    ui->tree_leftTreePanel->setColumnCount(1); //1行
    QStringList treelist;
    treelist << "StudentInfoManagerSystem";

    QTreeWidgetItem *treeItem_A = new QTreeWidgetItem(ui->tree_leftTreePanel, QStringList("PageManagement"));
    QTreeWidgetItem *treeItem_a1 = new QTreeWidgetItem(treeItem_A, QStringList("Student"));
    QTreeWidgetItem *treeItem_a2 = new QTreeWidgetItem(treeItem_A, QStringList("Administrator"));

    ui->tree_leftTreePanel->addTopLevelItem(treeItem_A);
    treeItem_A->addChild(treeItem_a1);
    treeItem_A->addChild(treeItem_a2);
    ui->tree_leftTreePanel->expandAll();//默认展开

    /*设置tablewidget等宽*/
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    //禁用tablewidget直接编辑，改为选中当行，点击修改按钮，弹出...
    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows); //只允许选择行
    //ui->tableWidget->setSelectionMode(QAbstractItemView::SingleSelection);//单选
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);//不允许直接触发修改

    m_ptrStudentSQL = StudentSQL::getInstance();

    updateTable();


    QFile qss(QString(":/QSS/MacOS.qss"));
    qss.open(QFile::ReadOnly);
    qApp->setStyleSheet(qss.readAll());
    qss.close();


}

MainWindow::~MainWindow()
{
    delete ui;
}

/*按键动态刷新加载样式（修改css文件按键就能刷新，不用重新编译）*/
void MainWindow::keyPressEvent(QKeyEvent *e)
{
    /*
    if(e->key() == Qt::Key_F6)
    {
        QFile f;
        auto exePath = QCoreApplication::applicationDirPath();
        f.setFileName(exePath + "//" + "MacOS.qss");

        f.open(QIODevice::ReadOnly);
        QString sheet = f.readAll();
        this->setStyleSheet(sheet);
        loginWindow.setStyleSheet(sheet);
    }
    */
}


void MainWindow::on_btn_exit_clicked()
{
    exit(0);
}


//模拟数据（测试）
void MainWindow::on_btn_simulation_clicked()
{
    QList<StudentInfo> l;

    m_ptrStudentSQL->clearStudentTable();
    for(int i = 0; i < 1000; i++)
    {
        StudentInfo info;
        info.student_name = QString("Deng%1").arg(i);
        l.append(info);
    }
    m_ptrStudentSQL->addStudent(l);
    updateTable();
}


void MainWindow::on_btn_add_clicked()
{
    m_dialog_AddStudent.setType(true); //属于添加模式
    m_dialog_AddStudent.exec();//模态对话框阻塞弹出
    updateTable();
}


void MainWindow::on_btn_clearUpStudent_clicked()
{
    m_ptrStudentSQL->clearStudentTable();
    updateTable();
}

/*刷新Table*/
void MainWindow::updateTable()
{
    //Init
    ui->tableWidget->clear();
    ui->tableWidget->setColumnCount(9); //important!!!  0-8

    //Table Header
    QStringList l;
    l << "Index" <<  "ID" << "Name" << "Age" << "Grade" << "Class" << "SID" << "Phone" << "Wechat";
    ui->tableWidget->setHorizontalHeaderLabels(l);

    //Table Items
    auto db_student_count = m_ptrStudentSQL->getStudentCount();
    QList<StudentInfo> db_student_list =  m_ptrStudentSQL->getPageStudent(0, db_student_count);
    ui->lb_totalCount->setText(QString("%1").arg(db_student_count));

    ui->tableWidget->setRowCount(db_student_count);
    for(int i = 0; i< db_student_list.size(); i++)
    {
        ui->tableWidget->setItem(i, 0, new QTableWidgetItem(QString::number(i)));
        ui->tableWidget->setItem(i, 1, new QTableWidgetItem(QString::number(db_student_list[i].id)));
        ui->tableWidget->setItem(i, 2, new QTableWidgetItem(db_student_list[i].student_name));
        ui->tableWidget->setItem(i, 3, new QTableWidgetItem(QString::number(db_student_list[i].student_age)));
        ui->tableWidget->setItem(i, 4, new QTableWidgetItem(QString::number(db_student_list[i].student_grade)));
        ui->tableWidget->setItem(i, 5, new QTableWidgetItem(QString::number(db_student_list[i].student_class)));
        ui->tableWidget->setItem(i, 6, new QTableWidgetItem(QString::number(db_student_list[i].student_id)));
        ui->tableWidget->setItem(i, 7, new QTableWidgetItem(db_student_list[i].student_phoneNum));
        ui->tableWidget->setItem(i, 8, new QTableWidgetItem(db_student_list[i].student_wechat));
    }

}


void MainWindow::on_btn_remove_clicked()
{
    int seletedRowIndex = ui->tableWidget->currentRow();
    if(seletedRowIndex>=0) //当前选择的行有效（有选择）
    {
        int id = ui->tableWidget->item(seletedRowIndex,1)->text().toUInt();
        bool ret = m_ptrStudentSQL->removeStudent(id);
        updateTable();
        if(ret)
            QMessageBox::information(nullptr, "Information", "Remove Success!");
        else
            QMessageBox::warning(nullptr, "Warning", "Remove Error!");
    }

}


void MainWindow::on_btn_modify_clicked()
{
    //    StudentInfo s;
    //    s.id = 1;
    //    s.student_name = "我爱你";
    //    m_ptrStudentSQL-> updateStudentInfo(s);


    StudentInfo info;
    int seletedRowIndex = ui->tableWidget->currentRow();
    if(seletedRowIndex>=0) //当前选择的行有效（有选择）
    {
        info.id = ui->tableWidget->item(seletedRowIndex,1)->text().toUInt();
        info.student_name = ui->tableWidget->item(seletedRowIndex,2)->text();
        info.student_age = ui->tableWidget->item(seletedRowIndex,3)->text().toUInt();
        info.student_grade= ui->tableWidget->item(seletedRowIndex,4)->text().toUInt();
        info.student_class = ui->tableWidget->item(seletedRowIndex,5)->text().toUInt();
        info.student_id= ui->tableWidget->item(seletedRowIndex,6)->text().toLong();
        info.student_phoneNum = ui->tableWidget->item(seletedRowIndex,7)->text();
        info.student_wechat = ui->tableWidget->item(seletedRowIndex,8)->text();

        m_dialog_AddStudent.setType(false, info);//not Add mode
        m_dialog_AddStudent.exec();//模态对话框阻塞弹出

    }
    updateTable();

}


void MainWindow::on_btn_serach_clicked()
{
    QString nameFilter = ui->ld_serach->text(); //筛选的名字
    if(nameFilter.isEmpty())
    {
        QMessageBox::warning(nullptr, "Warning", "Not allowed to be empty!");
        updateTable();
        return;
    }

    //Init
    ui->tableWidget->clear();
    ui->tableWidget->setColumnCount(9); //important!!!  0-8

    //Table Header
    QStringList l;
    l << "Index" <<  "ID" << "Name" << "Age" << "Grade" << "Class" << "SID" << "Phone" << "Wechat";
    ui->tableWidget->setHorizontalHeaderLabels(l);

    //Table Items
    auto db_student_count = m_ptrStudentSQL->getStudentCount();
    QList<StudentInfo> db_student_list =  m_ptrStudentSQL->getPageStudent(0, db_student_count);
    ui->lb_totalCount->setText(QString("%1").arg(db_student_count));


    int index = 0; //行号

    for(int i = 0; i< db_student_list.size(); i++)
    {
        if(!db_student_list[i].student_name.contains(nameFilter))//不包含
        {
            continue;
        }
        ui->tableWidget->setItem(index, 0, new QTableWidgetItem(QString::number(index+1)));
        ui->tableWidget->setItem(index, 1, new QTableWidgetItem(QString::number(db_student_list[i].id)));
        ui->tableWidget->setItem(index, 2, new QTableWidgetItem(db_student_list[i].student_name));
        ui->tableWidget->setItem(index, 3, new QTableWidgetItem(QString::number(db_student_list[i].student_age)));
        ui->tableWidget->setItem(index, 4, new QTableWidgetItem(QString::number(db_student_list[i].student_grade)));
        ui->tableWidget->setItem(index, 5, new QTableWidgetItem(QString::number(db_student_list[i].student_class)));
        ui->tableWidget->setItem(index, 6, new QTableWidgetItem(QString::number(db_student_list[i].student_id)));
        ui->tableWidget->setItem(index, 7, new QTableWidgetItem(db_student_list[i].student_phoneNum));
        ui->tableWidget->setItem(index, 8, new QTableWidgetItem(db_student_list[i].student_wechat));
        index++;
    }
    ui->tableWidget->setRowCount(index);
}

