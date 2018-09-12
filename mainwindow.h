#pragma once
#include "stdafx.h"
#include "mapbuilder.h"
#include <QThread>


namespace Ui {
class MainWindow;
}
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QMainWindow *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QTimer* animationTimer;
    QGraphicsView* view;
    QGraphicsScene* scene;
    QPushButton* singleBtn;
    QPushButton* exitBtn;
    QLabel* label;

private slots:
    void singleBtnPressed();
    void exitBtnPressed();
};
