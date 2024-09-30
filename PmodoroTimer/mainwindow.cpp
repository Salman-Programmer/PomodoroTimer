#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    QPushButton *start = new QPushButton("Start", this);
    QPushButton *pause = new QPushButton("Pause", this);
    QPushButton *reset = new QPushButton("Reset",this);
    QPushButton *restart = new QPushButton("Restart",this);

    QPushButton *settings = new QPushButton("Settings",this);

    label = new QLabel("other content goes here",this);
    timer = new QTimer(this);

    QHBoxLayout *buttonLayout = new QHBoxLayout;


    study = new QProgressBar(this);
    enjoy = new QProgressBar(this);

    study_check = 10;
    enjoy_check = 500;
    study->setValue(0);
    enjoy->setValue(0);

    buttonLayout -> addWidget(start);
    buttonLayout->addWidget(pause);
    buttonLayout->addWidget(reset);
    buttonLayout->addWidget(restart);
    QWidget *centralWidget = new QWidget(this);
    setCentralWidget(centralWidget);
    QVBoxLayout *mainLayout = new QVBoxLayout(centralWidget);


    QHBoxLayout *study_progress = new QHBoxLayout;
    QHBoxLayout *break_progress = new QHBoxLayout;
    study_label = new QLabel("Study Time",this);
    break_label = new QLabel("Break Time", this);

    study_progress ->addWidget(study_label);
    study_progress ->addWidget(study);

    break_progress ->addWidget(break_label);
    break_progress ->addWidget(enjoy);

    mainLayout->addWidget(settings);
    mainLayout->addLayout(study_progress);
     mainLayout->addLayout(break_progress);
    mainLayout->addWidget(label);
    mainLayout->addLayout(buttonLayout);
    update = 0;
    connect(start,&QPushButton::clicked, this , &MainWindow::startTimer);
    connect(timer, &QTimer::timeout, this, &MainWindow::updateTimer);
    connect(pause,&QPushButton::clicked,this,&MainWindow::pauseTimer);
    connect(reset,&QPushButton::clicked,this,&MainWindow::resetTimer);
    connect(restart, &QPushButton::clicked,this,&MainWindow::restart);
    connect(settings, &QPushButton::clicked,this, &MainWindow::showsettings );
}


MainWindow::~MainWindow() {}

void MainWindow::startTimer(){
    timer->start(1000);
    study->setRange(0,study_check);
    enjoy->setRange(0,enjoy_check);


}
void MainWindow::updateTimer(){
    ++update;
    study_value = study->value();
    enjoy_value = enjoy->value();
    if(study_value <= study_check){

        study->setValue(study_value+1);

        int seconds_study = study_value + 1;
        int minutes_study = seconds_study /60;
        int remaining_seconds_study = seconds_study % 60;
        if(seconds_study < 60){
            label->setText(QString::number(seconds_study) + " Seconds Study Time");}
        else if(seconds_study > 60 && seconds_study < 120){
            label -> setText(QString::number(minutes_study) + " Minute " + (QString::number(remaining_seconds_study)) + " Seconds");
        }else{
            label -> setText(QString::number(minutes_study) + " Minutes " + (QString::number(remaining_seconds_study)) + " Seconds");
        }

         if(study_value == study_check){

            if( enjoy_value <= enjoy_check)

            enjoy ->setValue(enjoy_value+1);

            int seconds_break = enjoy_value + 1;
            int minutes_break = seconds_break /60;
            int remaining_seconds_break = seconds_break % 60;
            if(seconds_break < 60){
                label->setText(QString::number(seconds_break) + " Seconds Break Time");}
            else if(seconds_break > 60 && seconds_break < 120){
                label -> setText(QString::number(minutes_break) + " Minute " + (QString::number(remaining_seconds_break)) + " Seconds");
            }else{
                label -> setText(QString::number(minutes_break) + " Minutes " + (QString::number(remaining_seconds_break)) + " Seconds");
            }

         }
    }

       else{ timer->stop();
    }
}


void MainWindow::pauseTimer(){
    timer->stop();
    study_value = study_value +1;
    enjoy_value = enjoy_value;


}

void MainWindow::resetTimer(){
    if(study_value < study_check){
        study->setValue(0);}
    else{
    enjoy->setValue(0);
    }

}
void MainWindow::restart(){
    study->setValue(0);
    enjoy->setValue(0);
}

void MainWindow::showsettings(){
    QDialog setting(this);
    setting.setWindowTitle("Settings");
    QVBoxLayout *settingLayout = new QVBoxLayout(&setting);
    QLabel *studyTime = new QLabel("Enter the Study Time", &setting);
    QLabel *breaktime = new QLabel("Enter the Break Time", &setting);
    QLineEdit *studyInput = new QLineEdit(&setting);
    QLineEdit *breakInput = new QLineEdit(&setting);
    QPushButton *acceptButton = new QPushButton("OK", &setting);

    settingLayout -> addWidget(studyTime);
    settingLayout ->addWidget(studyInput);
    settingLayout -> addWidget(breaktime);
    settingLayout -> addWidget(breakInput);

    settingLayout ->addWidget(acceptButton);

    connect(acceptButton, &QPushButton::clicked, &setting, &QDialog::accept);

    if(setting.exec() == QDialog::Accepted){
    QString study = studyInput ->text();
        study_check = study.toInt();
    QString enjoy = breakInput ->text();
        enjoy_check = enjoy.toInt();
}

}
