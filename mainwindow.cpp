#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QMainWindow *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow){

    ui->setupUi(this);
    setFixedSize(QSize(880,662)) ;
    view = new QGraphicsView(this);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    scene = new QGraphicsScene(0,0,880,660,this);
    scene->setBackgroundBrush(QBrush(Qt::black));
    scene->setStickyFocus(true);

    view->setScene(scene);
    view->setFixedSize(880,662);
    view->setSceneRect(0,0,880,660);

    scene->setSceneRect(scene->sceneRect());

    label = new QLabel(this);
    label->setGeometry(QRect(QPoint(100, 20),QSize(1000,300)));
    QPixmap pix(":/Images/title.png");
    label->setPixmap(pix);

    singleBtn = new QPushButton(this);
    exitBtn = new QPushButton(this);

    singleBtn->setGeometry(QRect(QPoint(330, 360),QSize(200,40)));
    exitBtn->setGeometry(QRect(QPoint(330, 410),QSize(200, 40)));

    connect(singleBtn, SIGNAL(pressed()), SLOT(singleBtnPressed()));
    connect(exitBtn, SIGNAL(pressed()), SLOT(exitBtnPressed()));

    singleBtn->setStyleSheet(
                "QPushButton {"
                "border-image:url(:/Images/singleBtn_disable.png)"
                "}"

                "QPushButton:hover {"
                "border-image:url(:/Images/singleBtn_enable.png)"
                "}"
                );

    exitBtn->setStyleSheet(
               "QPushButton {"
               "border-image:url(:/Images/exitBtn_disable.png)"
                "}"

                "QPushButton:hover {"
                "border-image:url(:/Images/exitBtn_enable.png)"
                "}"
                );
}


void MainWindow::singleBtnPressed(){
    label->hide();
    singleBtn->hide();
    exitBtn->hide();
    scene->setStickyFocus(true);
    animationTimer = new QTimer(this);
    connect(animationTimer,SIGNAL(timeout()),scene,SLOT(advance()));
    animationTimer->start(1000/60);
    MapBuilder* map = new MapBuilder(scene);
    map->buildMapOnScene();
}


void MainWindow::exitBtnPressed(){
    this->close();
}


MainWindow::~MainWindow() {
    delete ui;
}
