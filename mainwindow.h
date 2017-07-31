#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QtDebug>
#include<QString>
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
private slots:
    void digitClicked();
    void funClicked();
    void varClicked();

    //void newFileSlot();
    //void openFileSlot();//打开一个已经存在的文本文件
    //void saveFileSlot();//保存文件到磁盘
};

#endif // MAINWINDOW_H
