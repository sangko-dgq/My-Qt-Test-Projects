#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    ,m_ptrStudentSQL(nullptr)
{
    ui->setupUi(this);

    m_loginWindow.show();

    auto s = [&]()
    {
        this->show();
    };
    connect(&m_loginWindow, &LoginWindow::sg_sendLoginSuccess, this, s);

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


    QFile qss(QString("://QSS/MacOS.qss"));
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
        m_loginWindow.setStyleSheet(sheet);
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

if (1)
{
   m_lNames<<" 凌俊豪";
   m_lNames<<" 裘从蕾";
   m_lNames<<" 盈梅花";
   m_lNames<<" 树同化";
   m_lNames<<" 邝问蕊";
   m_lNames<<" 让哲圣";
   m_lNames<<" 钱明旭";
   m_lNames<<" 饶青曼";
   m_lNames<<" 夫俏丽";
   m_lNames<<" 所鸿志";
   m_lNames<<" 恽兰若";
   m_lNames<<" 闫鸿煊";
   m_lNames<<" 斯明轩";
   m_lNames<<" 周初兰";
   m_lNames<<" 乘振翱";
   m_lNames<<" 法采珊";
   m_lNames<<" 梅傲安";
   m_lNames<<" 励乐蕊";
   m_lNames<<" 戈曼青";
   m_lNames<<" 卿菱华";
   m_lNames<<" 晁雪巧";
   m_lNames<<" 原安安";
   m_lNames<<" 针涵梅";
   m_lNames<<" 甫之云";
   m_lNames<<" 郗雪晴";
   m_lNames<<" 经梦蕊";
   m_lNames<<" 楚一嘉";
   m_lNames<<" 戊恺乐";
   m_lNames<<" 苗初柳";
   m_lNames<<" 达瀚海";
   m_lNames<<" 梁盼芙";
   m_lNames<<" 悉以蕊";
   m_lNames<<" 弘梦秋";
   m_lNames<<" 慕虹彩";
   m_lNames<<" 僪新之";
   m_lNames<<" 守令枫";
   m_lNames<<" 栋胤雅";
   m_lNames<<" 储新儿";
   m_lNames<<" 芮承恩";
   m_lNames<<" 宁玄静";
   m_lNames<<" 载子昂";
   m_lNames<<" 殳秋阳";
   m_lNames<<" 万映天";
   m_lNames<<" 仆飞阳";
   m_lNames<<" 夔飞珍";
   m_lNames<<" 怀婉娜";
   m_lNames<<" 谯香桃";
   m_lNames<<" 成靖柔";
   m_lNames<<" 阮文林";
   m_lNames<<" 卓修远";
   m_lNames<<" 危博实";
   m_lNames<<" 闵雅美";
   m_lNames<<" 郝暄和";
   m_lNames<<" 可隽雅";
   m_lNames<<" 愈珠玉";
   m_lNames<<" 惠慕山";
   m_lNames<<" 琴长平";
   m_lNames<<" 士夏旋";
   m_lNames<<" 隗谷玉";
   m_lNames<<" 天凌春";
   m_lNames<<" 茹傲之";
   m_lNames<<" 诗雪羽";
   m_lNames<<" 姬语丝";
   m_lNames<<" 摩天慧";
   m_lNames<<" 甘弘新";
   m_lNames<<" 伯向笛";
   m_lNames<<" 独代玉";
   m_lNames<<" 裔琴雪";
   m_lNames<<" 牢春柏";
   m_lNames<<" 实春华";
   m_lNames<<" 漆莹白";
   m_lNames<<" 益华清";
   m_lNames<<" 桓和暖";
   m_lNames<<" 陈梦旋";
   m_lNames<<" 厚会雯";
   m_lNames<<" 星古韵";
   m_lNames<<" 劳柳思";
   m_lNames<<" 大忆雪";
   m_lNames<<" 兰永元";
   m_lNames<<" 柴秋荣";
   m_lNames<<" 丰芷荷";
   m_lNames<<" 余元冬";
   m_lNames<<" 逮家馨";
   m_lNames<<" 习冷梅";
   m_lNames<<" 以长运";
   m_lNames<<" 泥景胜";
   m_lNames<<" 友梓洁";
   m_lNames<<" 素芷文";
   m_lNames<<" 迮绿柏";
   m_lNames<<" 关睿姿";
   m_lNames<<" 苌欣愉";
   m_lNames<<" 邬慧丽";
   m_lNames<<" 左嘉澍";
   m_lNames<<" 养熙柔";
   m_lNames<<" 通欢欣";
   m_lNames<<" 似安萱";
   m_lNames<<" 寸瑜璟";
   m_lNames<<" 桑梓敏";
   m_lNames<<" 莘流婉";
   m_lNames<<" 翦浩言";
   m_lNames<<" 多书语";
   m_lNames<<" 班晨曦";
   m_lNames<<" 生振海";
   m_lNames<<" 敏沛凝";
   m_lNames<<" 有惠丽";
   m_lNames<<" 森妙柏";
   m_lNames<<" 鄞昕昕";
   m_lNames<<" 次修谨";
   m_lNames<<" 嘉以晴";
   m_lNames<<" 仇若枫";
   m_lNames<<" 衡谷蕊";
   m_lNames<<" 奕冬亦";
   m_lNames<<" 薄骏英";
   m_lNames<<" 简玉怡";
   m_lNames<<" 常忻愉";
   m_lNames<<" 朱冠玉";
   m_lNames<<" 革兴修";
   m_lNames<<" 繁慧颖";
   m_lNames<<" 修修真";
   m_lNames<<" 陀云蔚";
   m_lNames<<" 幸含蕊";
   m_lNames<<" 翠玲琅";
   m_lNames<<" 刑舒兰";
   m_lNames<<" 淡建树";
   m_lNames<<" 塔英武";
   m_lNames<<" 郏曼珍";
   m_lNames<<" 荀夜梦";
   m_lNames<<" 史乐成";
   m_lNames<<" 于田田";
   m_lNames<<" 紫朝雨";
   m_lNames<<" 剧英博";
   m_lNames<<" 汉觅山";
   m_lNames<<" 改双玉";
   m_lNames<<" 宇寻双";
   m_lNames<<" 铎雨安";
   m_lNames<<" 声悠雅";
   m_lNames<<" 斋依心";
   m_lNames<<" 连韶阳";
   m_lNames<<" 阎春雪";
   m_lNames<<" 朋云溪";
   m_lNames<<" 才念梦";
   m_lNames<<" 理怀梦";
   m_lNames<<" 奇如馨";
   m_lNames<<" 蓬彦露";
   m_lNames<<" 布文星";
   m_lNames<<" 邰向山";
   m_lNames<<" 崇梓萱";
   m_lNames<<" 从新烟";
   m_lNames<<" 白孤兰";
   m_lNames<<" 位音韵";
   m_lNames<<" 乌兴朝";
   m_lNames<<" 巢永宁";
   m_lNames<<" 丹弘方";
   m_lNames<<" 裴若云";
   m_lNames<<" 善俊捷";
   m_lNames<<" 綦悦乐";
   m_lNames<<" 洛亦云";
   m_lNames<<" 庾晓筠";
   m_lNames<<" 蹉承业";
   m_lNames<<" 庄宏峻";
   m_lNames<<" 智和平";
   m_lNames<<" 祢梦山";
   m_lNames<<" 邛广君";
   m_lNames<<" 闾吉星";
   m_lNames<<" 仉寒梦";
   m_lNames<<" 悟博学";
   m_lNames<<" 诸蔚星";
   m_lNames<<" 姒依秋";
   m_lNames<<" 赛海融";
   m_lNames<<" 郁可心";
   m_lNames<<" 双幼枫";
   m_lNames<<" 巩晗玥";
   m_lNames<<" 辉婉秀";
   m_lNames<<" 纳天蓝";
   m_lNames<<" 卫秋荷";
   m_lNames<<" 银佳悦";
   m_lNames<<" 止采柳";
   m_lNames<<" 郯若兰";
   m_lNames<<" 完歌韵";
   m_lNames<<" 茅丽文";
   m_lNames<<" 抄清昶";
   m_lNames<<" 霜飞双";
   m_lNames<<" 冉香岚";
   m_lNames<<" 性驰丽";
   m_lNames<<" 邗茂材";
   m_lNames<<" 酒燕桦";
   m_lNames<<" 肥昭昭";
   m_lNames<<" 缪雪曼";
   m_lNames<<" 汪翠茵";
   m_lNames<<" 謇嘉悦";
   m_lNames<<" 昌半双";
   m_lNames<<" 冠嘉福";
   m_lNames<<" 台欣艳";
   m_lNames<<" 府沛容";
   m_lNames<<" 是思琳";
   m_lNames<<" 英布凡";
   m_lNames<<" 颜和雅";
   m_lNames<<" 军月桃";
   m_lNames<<" 袭盼晴";
   m_lNames<<" 师怜晴";
   m_lNames<<" 曲安和";
   m_lNames<<" 沃妍歌";
   m_lNames<<" 蒿朝雨";
   m_lNames<<" 赖景同";
   m_lNames<<" 禽青旋";
   m_lNames<<" 祁尔风";
   m_lNames<<" 休思山";
   m_lNames<<" 矫天瑞";
   m_lNames<<" 毕语海";
   m_lNames<<" 盛和玉";
   m_lNames<<" 壬南琴";
   m_lNames<<" 吾梅英";
   m_lNames<<" 仲翠桃";
   m_lNames<<" 倪笑柳";
   m_lNames<<" 扬雨莲";
   m_lNames<<" 仙涵易";
   m_lNames<<" 门碧菡";
   m_lNames<<" 曹世敏";
   m_lNames<<" 靳惜梦";
   m_lNames<<" 菅白玉";
   m_lNames<<" 圭旎旎";
   m_lNames<<" 卜笑卉";
   m_lNames<<" 巫小凝";
   m_lNames<<" 出绿蕊";
   m_lNames<<" 锺佩杉";
   m_lNames<<" 云代巧";
   m_lNames<<" 爱嘉祥";
   m_lNames<<" 闽思烟";
   m_lNames<<" 旁泰鸿";
   m_lNames<<" 严又莲";
   m_lNames<<" 芒痴香";
   m_lNames<<" 笃向梦";
   m_lNames<<" 戚星宇";
   m_lNames<<" 唐新晴";
   m_lNames<<" 堂念雁";
   m_lNames<<" 狄悦欣";
   m_lNames<<" 锐梦菡";
   m_lNames<<" 仝烨然";
   m_lNames<<" 牵庆生";
   m_lNames<<" 呼安莲";
   m_lNames<<" 在芸茗";
   m_lNames<<" 居彭泽";
   m_lNames<<" 谌含巧";
   m_lNames<<" 楼凌春";
   m_lNames<<" 锁元彤";
   m_lNames<<" 甄文赋";
   m_lNames<<" 东宏大";
   m_lNames<<" 石安吉";
   m_lNames<<" 遇千亦";
   m_lNames<<" 祝智菱";
   m_lNames<<" 贲尔槐";
   m_lNames<<" 车安平";
   m_lNames<<" 绪明远";
   m_lNames<<" 尉远骞";
   m_lNames<<" 律妮娜";
   m_lNames<<" 毛含桃";
   m_lNames<<" 典柔洁";
   m_lNames<<" 斐元亮";
   m_lNames<<" 滕思菱";
   m_lNames<<" 须香卉";
   m_lNames<<" 计和畅";
   m_lNames<<" 时雁桃";
   m_lNames<<" 绍意远";
   m_lNames<<" 江志勇";
   m_lNames<<" 义幻露";
   m_lNames<<" 湛南霜";
   m_lNames<<" 初鸿飞";
   m_lNames<<" 卯玉环";
   m_lNames<<" 董思云";
   m_lNames<<" 不飞燕";
   m_lNames<<" 坚馨香";
   m_lNames<<" 畅俊彦";
   m_lNames<<" 高曼云";
   m_lNames<<" 舜和怡";
   m_lNames<<" 告骏哲";
   m_lNames<<" 后紫琼";
   m_lNames<<" 线丹亦";
   m_lNames<<" 利歌吹";
   m_lNames<<" 蛮晨朗";
   m_lNames<<" 褚竹月";
   m_lNames<<" 户鸿风";
   m_lNames<<" 世斌蔚";
   m_lNames<<" 暴蕴藉";
   m_lNames<<" 贾锐智";
   m_lNames<<" 开乐安";
   m_lNames<<" 汗新月";
   m_lNames<<" 顾夏兰";
   m_lNames<<" 拜曼雁";
   m_lNames<<" 圣梓彤";
   m_lNames<<" 竺芸静";
   m_lNames<<" 陶夏青";
   m_lNames<<" 葛平卉";
   m_lNames<<" 闳浩涆";
   m_lNames<<" 褒翠梅";
   m_lNames<<" 宣寻雪";
   m_lNames<<" 丁俊侠";
   m_lNames<<" 伟哲妍";
   m_lNames<<" 容香桃";
   m_lNames<<" 衣晴曦";
   m_lNames<<" 莫绮露";
   m_lNames<<" 嵇康健";
   m_lNames<<" 丙晓瑶";
   m_lNames<<" 尚之卉";
   m_lNames<<" 钟宏爽";
   m_lNames<<" 稽景辉";
   m_lNames<<" 邓忆南";
   m_lNames<<" 厍白秋";
   m_lNames<<" 腾如之";
   m_lNames<<" 进从霜";
   m_lNames<<" 寒新荣";
   m_lNames<<" 景冷之";
   m_lNames<<" 营谷菱";
   m_lNames<<" 衷锐立";
}  

    
    QRandomGenerator g,c;
    g.seed(0);
    c.seed(0);
    QList<StudentInfo> l;
    for(int i=0;i<m_lNames.size();i++){
        auto grade = g.bounded(7,10);//随机生成年级 左闭右开 随机生成 7 8 9这三个数
        auto uiclass = g.bounded(1,9);//随机生成班级
        StudentInfo info;
        info.student_name=m_lNames[i];
        if(i%3)
            info.student_age=17;
        if(i%7)
            info.student_age=18;
        if(i%2)
            info.student_age=20;
        info.student_grade=grade;
        info.student_class=uiclass;
        info.student_id=i;
        info.student_phoneNum="123321";
        info.student_wechat="123321";
        //将模拟的数据放入容器，增加效率
        l.append(info);
    }
     m_ptrStudentSQL->addStudent(l);//调用增加函数
     updateTable();//界面刷新
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

