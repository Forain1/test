#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class QPaintEvent;
QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
protected:
    void paintEvent(QPaintEvent*);

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
