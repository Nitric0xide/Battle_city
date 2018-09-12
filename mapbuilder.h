#pragma once
#include <QDir>

#include "QObject"
#include "player.h"
#include "steelblock.h"
#include "bricks.h"
#include "enemyl.h"
#include "enemyh.h"
#include "enemym.h"
#include "bush.h"
#include "eaglebase.h"


class QGraphicsScene;

class MapBuilder : public QObject{

    Q_OBJECT

public:
    MapBuilder(QGraphicsScene* mapscene);
    ~MapBuilder();

private:
    QFileInfo readir;
    QStringList levels;
    QStringList filters;
    QGraphicsScene* scene;
    QTimer* createEnemy;
    QGraphicsRectItem* rect;
    QList<QGraphicsRectItem*> count_list;
    QList<QGraphicsItem*> list;
    QLabel* label;
    QList<QGraphicsItem*> map_enteties;
    QTimer* spawnwave;

    Player* player;
    EagleBase* base;

    int totalenemies = 0;
    int lighttank = 0;
    int mediumtank = 0;
    int heavytank = 0;
    int deadenemies = 0;


    int spawnpos = 0;
    int current_level = 0;
    bool nextlevel = true;

private:
    void nextmap();

public:
    void buildMapOnScene();

private slots:
    void checkspawnareas();
    void countdead();
};
