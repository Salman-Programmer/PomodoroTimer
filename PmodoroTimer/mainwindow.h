#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QTimer>
#include <QProgressBar>
#include <QDialog>
#include <QLineEdit>
#include <QMediaPlayer>


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    int update,study_value,enjoy_value,study_check,enjoy_check;
    QProgressBar *study;
    QProgressBar *enjoy;





private:
    QTimer *timer;
    QLabel *label;
    QLabel *study_label;
    QLabel *break_label;


private slots:
    void startTimer();
    void updateTimer();
    void pauseTimer();
    void resetTimer();
    void restart();
    void showsettings();

};
#endif // MAINWINDOW_H
