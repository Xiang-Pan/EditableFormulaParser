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

void MainWindow::funClicked()
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


MainWindow::~MainWindow()
{
    delete ui;
}



