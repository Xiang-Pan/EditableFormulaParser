#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->numButton_1, SIGNAL(clicked()), this, SLOT(digitClicked()));
    connect(ui->numButton_2, SIGNAL(clicked()), this, SLOT(digitClicked()));
    connect(ui->numButton_3, SIGNAL(clicked()), this, SLOT(digitClicked()));
    connect(ui->numButton_4, SIGNAL(clicked()), this, SLOT(digitClicked()));
    connect(ui->numButton_5, SIGNAL(clicked()), this, SLOT(digitClicked()));
    connect(ui->numButton_6, SIGNAL(clicked()), this, SLOT(digitClicked()));
    connect(ui->numButton_7, SIGNAL(clicked()), this, SLOT(digitClicked()));
    connect(ui->numButton_8, SIGNAL(clicked()), this, SLOT(digitClicked()));
    connect(ui->numButton_9, SIGNAL(clicked()), this, SLOT(digitClicked()));
    connect(ui->numButton_0, SIGNAL(clicked()), this, SLOT(digitClicked()));
    connect(ui->varButton_A, SIGNAL(clicked()), this, SLOT(varClicked()));
    connect(ui->varButton_B, SIGNAL(clicked()), this, SLOT(varClicked()));
    connect(ui->varButton_C, SIGNAL(clicked()), this, SLOT(varClicked()));
    connect(ui->varButton_D, SIGNAL(clicked()), this, SLOT(varClicked()));
    connect(ui->varButton_E, SIGNAL(clicked()), this, SLOT(varClicked()));
    connect(ui->varButton_F, SIGNAL(clicked()), this, SLOT(varClicked()));
    connect(ui->varButton_G, SIGNAL(clicked()), this, SLOT(varClicked()));
    connect(ui->varButton_X, SIGNAL(clicked()), this, SLOT(varClicked()));
    connect(ui->varButton_Y, SIGNAL(clicked()), this, SLOT(varClicked()));
    connect(ui->varButton_Z, SIGNAL(clicked()), this, SLOT(varClicked()));


    connect(ui->funButton_sin, SIGNAL(clicked()), this, SLOT(funClicked()));
    connect(ui->funButton_cos, SIGNAL(clicked()), this, SLOT(funClicked()));
    connect(ui->funButton_tan, SIGNAL(clicked()), this, SLOT(funClicked()));
    connect(ui->funButton_arctan, SIGNAL(clicked()), this, SLOT(funClicked()));
    /*此处进行
       QRegExp rx("^(-?[0]|-?[1-9][0-9]{0,5})(?:\\.\\d{1,4})?$|(^\\t?$)");
       QRegExpValidator *pReg = new QRegExpValidator(rx, this);
       lineEdit->setValidator(pReg);
    //设置*/



}


void MainWindow::digitClicked()
{
    QPushButton *clickedButton = qobject_cast<QPushButton *>(sender());
    int digitValue = 0;
    QString digitValue16;
    double Pi;
    if(clickedButton->text() == "Pi")
    {
        Pi = 3.1415926535;
        ui->lineEdit_display->clear();
    }
    else
    {
            digitValue = clickedButton->text().toInt();
    }

    if (ui->lineEdit_display->text() == "0" && digitValue == 0.0)
        return;


    else
    {
       // if(ui->radioButton_16->isChecked())
       //     ui->lineEdit_display->setText(ui->lineEdit_display->text() + digitValue16);
       // else
            ui->lineEdit_display->setText(ui->lineEdit_display->text() + QString::number(digitValue));
    }
}


void MainWindow::varClicked()
{
    QPushButton *clickedButton = qobject_cast<QPushButton *>(sender());
    QString varChar;
    varChar=clickedButton->text();
    ui->lineEdit_display->setText(ui->lineEdit_display->text() + varChar);
       // if(ui->radioButton_16->isChecked())
       //     ui->lineEdit_display->setText(ui->lineEdit_display->text() + digitValue16);
       // else
       //ui->lineEdit_display->setText(ui->lineEdit_display->text() + QString::number(digitValue));
}

void MainWindow::funClicked()
{
    QPushButton *clickedButton = qobject_cast<QPushButton *>(sender());
    QString funString;
    funString=clickedButton->text();
    ui->lineEdit_display->setText(ui->lineEdit_display->text() + funString+"(");
}


void MainWindow::saveFileSlot()
{
    if(saveFileName.isEmpty())//如果为空执行另存为操作
    {
        this->saveAsFileSlot();
    }
    else                      //如果不为空 则保存
    {
        QFile *file=new QFile;
        file->setFileName(saveFileName);
        bool ok=file->open(QIODevice::WriteOnly);
        if(ok)
        {
            QTextStream out(file);
            out<<ui->textEdit->toPlainText();//去除textEdit当中的纯文本 重定向到流中 放入磁盘
            file->close();
            this->setWindowTitle(saveFileName+"---------");
            delete file;
        }
        else
        {
            QMessageBox::information(this,"Error Message","Save File Error");
            return;
        }
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}



