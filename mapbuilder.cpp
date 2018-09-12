#include "mapbuilder.h"
#include "player.h"
#include "steelblock.h"
#include "bricks.h"
#include "enemyl.h"
#include "enemyh.h"
#include "enemym.h"
#include "bush.h"
#include "eaglebase.h"


MapBuilder::MapBuilder(QGraphicsScene* mapscene) : QObject(){
    this->scene = mapscene;
    spawnwave = new QTimer(this);
}


void MapBuilder::buildMapOnScene(){
    filters << "*.txt";
    QDir dir(":/Maps");
    dir.setNameFilters(filters);

    foreach(readir,dir.entryInfoList()) {

        levels.push_back(readir.absoluteFilePath()); 
    }

    QFile map(levels[current_level]);

    if(!map.exists()) {
        qDebug() << "File not exists";
        return;
    }

    if(!map.open(QFile::ReadOnly | QFile::Text)){
        qDebug() << "Cannot load map";
        return;
    }

    QTextStream in(&map);
    QByteArray line;
    int SIZE = 22;
    char** MAP = new char* [SIZE];

    //load map
    for (int i = 0; i < SIZE; i++) {
        MAP[i] = new char[SIZE];
        line = in.readLine().toLatin1();
        for (int j = 0; j < SIZE; j++)
        MAP[i][j] = line.at(j);
    }

    //read count of enemies
    for (int i = 0; i < SIZE; i++) {
        switch(i){
        case 1: in >> lighttank;break;
        case 2: in >> mediumtank;break;
        case 3: in >> heavytank;break;
        }
    }

    totalenemies = lighttank + mediumtank + heavytank;

    for (int i = 0; i < SIZE; i++) {
      for (int j = 0; j < SIZE; j++) {
        if(MAP[i][j]=='1') {
           Bricks* bricks = new Bricks; bricks->setPos(j*30,i*30);scene->addItem(bricks);          
          }
        if(MAP[i][j]=='B') {
           Bush* bush = new Bush; bush->setPos(j*30,i*30);scene->addItem(bush);  bush->setZValue(1);
        }
        if(MAP[i][j]=='E') {
           base = new EagleBase; base->setPos(j*30,i*30);scene->addItem(base);
          }
        if(MAP[i][j]=='4') {
           Steelblock* steel = new Steelblock; steel->setPos(j*30,i*30);scene->addItem(steel);
          }
        if(MAP[i][j]=='P') {
           player = new Player; player->setPos(j*30,i*30);scene->addItem(player);
          }
      }
    }

    spawnwave -> start(500);
    connect(spawnwave,SIGNAL(timeout()),this,SLOT(checkspawnareas()));


    scene->addRect(0,0,800,-1,QPen(Qt::NoPen),QBrush(Qt::black));//top
    scene->addRect(-1,0,0,800,QPen(Qt::NoPen),QBrush(Qt::black));//left
    scene->addRect(0,660,660,0,QPen(Qt::NoPen),QBrush(Qt::black));//botton
    scene->addRect(660,0,220,660,QPen(Qt::NoPen),QBrush(Qt::darkGray));//rightside

    for(int i = 0 ; i < totalenemies; i++){
        int column = i%2;
        rect = new QGraphicsRectItem;
        count_list.push_front(rect = scene->addRect(750+column*30, 100+(30*(i/2)), 20, 20,QPen(Qt::black),QBrush(Qt::red)));
    }
}


void MapBuilder::checkspawnareas(){
    QList<QGraphicsItem*>itemList;
    QPointF position;
    spawnpos = 1 + qrand()%3;

    switch(spawnpos){
    case 1: itemList = scene->items(0,0,60,60,Qt::IntersectsItemShape,Qt::AscendingOrder);
        position.setX(0),position.setY(0);break;
    case 2: itemList = scene->items(300,0,60,60,Qt::IntersectsItemShape,Qt::AscendingOrder);
        position.setX(300),position.setY(0);break;
    case 3: itemList = scene->items(600,0,60,60,Qt::IntersectsItemShape,Qt::AscendingOrder);
        position.setX(600),position.setY(0);break;
    }


    if(itemList.size()  == 0 && lighttank > 0){
       EnemyL* light_Tank = new EnemyL;
       light_Tank->setPos(position);
       scene->addItem(light_Tank);
       connect(light_Tank,SIGNAL(destroyed()),this,SLOT(countdead()));
       lighttank--;
    }

    if(itemList.size()  == 0 &&  deadenemies > 2 && mediumtank > 0){
       EnemyM* medium_Tank = new EnemyM;
       medium_Tank->setPos(position);
       scene->addItem(medium_Tank);
       connect(medium_Tank,SIGNAL(destroyed()),this,SLOT(countdead()));
       mediumtank--;
    }

    if(itemList.size()  == 0 && deadenemies > 4 && heavytank > 0){
       EnemyH* heavy_Tank = new EnemyH;
       heavy_Tank->setPos(position);
       scene->addItem(heavy_Tank);
       connect(heavy_Tank,SIGNAL(destroyed()),this,SLOT(countdead()));
       heavytank--;
    }

    if(current_level == levels.size()-1 && totalenemies == 0){
       spawnwave->stop();
       scene->clear();
       QPixmap pix(":/Images/victory.png");
       QPixmap scaled = pix.scaled(QSize(800, 250));
       QGraphicsPixmapItem* item = this->scene->addPixmap(scaled);
       item->setPos(50, 20);
    }

    if(player->health <= 0 || base->health <= 0){
       nextlevel = false;
       spawnwave->stop();
       scene->clear();
       QPixmap pix(":/Images/defeat.png");
       QPixmap scaled = pix.scaled(QSize(800, 250));
       QGraphicsPixmapItem* item = scene->addPixmap(scaled);
       item->setPos(50, 20);
    }


    if(totalenemies == 0 && current_level != levels.size()-1 && nextlevel == true){
       current_level++;
       deadenemies = 0;
       scene->clear();
       levels.clear();
       buildMapOnScene();
    }
}


void MapBuilder::countdead(){
    deadenemies++;
    totalenemies--;

    if(deadenemies++ && count_list.size() != 0){
       scene->removeItem(count_list.takeFirst());
    }
}


MapBuilder::~MapBuilder(){}
