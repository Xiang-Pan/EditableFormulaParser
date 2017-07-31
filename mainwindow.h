#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QtDebug>
#include<QString>
#include<QMessageBox>
#include<QFile>
#include<QFileDialog>
#include<QDir>
#include<QTextStream>
#include<QFont>
#include<QFontDialog>
#include<QColor>
#include<QColorDialog>
#include<QDateTime>
#include<QUrl>
#include<QDesktopServices>//用于访问桌面服务
#include<QCloseEvent>
//程序需要关闭 处理的内容 所有的事件protected 子类可以继承
namespace Ui
{
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QString saveFileName;
private slots:
    void digitClicked();
    void funClicked();
    void varClicked();

    //void newFileSlot();
    //void openFileSlot();//打开一个已经存在的文本文件
    //void saveFileSlot();//保存文件到磁盘
    //void on_saveButton_clicked();
    //void on_saveAsButton_clicked();
    void on_saveButton_clicked();
    void on_saveAsButton_clicked();
    void on_calculateButton_clicked();
    void on_loadButton_clicked();
};

#endif // MAINWINDOW_H
