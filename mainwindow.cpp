#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QSqlQuery>

//#include <QRegExp>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    qDebug()<<"init result = "<<InitDatabase("./ConnectorDB.db");

}



MainWindow::~MainWindow()
{
    delete ui;
}

//数据库神奇数字
bool MainWindow::CheckMagicNumber()
{
    QSqlQuery query; //以下执行相关QSL语句
    query.exec("select * from MagicTable");
    if(query.isSelect())
    {
        query.first();
        QString magicNumber = query.value(0).toString();
        if(magicNumber!=QString("6969DDDD"))
        {
            return false;
        }
    }
    else
    {
        return false;
    }
}

//初始化数据库连接
bool MainWindow::InitDatabase(QString path)
{
    db = QSqlDatabase::addDatabase("QSQLITE"); //添加数据库驱动
    db.setDatabaseName(path); //数据库连接命名
    if(!db.open()) //打开数据库
    {
        return false;
    }

    QSqlQuery query; //以下执行相关QSL语句
    //query.exec("create table student(id int primary key,name varchar)");
    //新建student表，id设置为主键，还有一个name项
    //query.exec("insert into student values(1,'xiaogang')");

    //数据库不正确
    if(!CheckMagicNumber()) return false;

    query.exec("select * from J30J");
    if(!query.isSelect())
    {
        qDebug()<<"[shincky]something goes wrong with query at: "<<__FILE__<<" Line:"<<__LINE__;
    }
    //查找表中id >=2 的记录的id项和name项的值
    while(query.next())       //query.next()指向查找到的第一条记录，然后每次后移一条记录
    {
        int ele0 = query.value(0).toInt();        //query.value(0)是id的值，将其转换为int型
        //QString ele1 =query.value(1).toString();
        QString queryResult;
        for(int i=1;i<5;i++)
        {
            queryResult+=query.value(i).toString();
        }
        qDebug() << ele0 <<queryResult;       //输出两个值
    }

    return true;
}
