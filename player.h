#pragma once
#define TANKSPEED 3
#include "moveable.h"
#include "bullet.h"


class Player : public Moveable {

    Q_OBJECT

public:
    Player();
    ~Player() final;

public:
    int health = 4;

private:
    int dir = 0;
    int damage = 2;
    bool shooting = true;
    QMediaPlayer *movement;
    QMediaPlaylist *movementlist;
    QGraphicsRectItem* rect;
    QList<QGraphicsRectItem*> health_points;
    QTimer* shot_recharge;

public:
    void dmg(int hpoints);

protected:
    void keyPressEvent(QKeyEvent *event) final;
    void keyReleaseEvent(QKeyEvent* event) final;
    void paint(QPainter* painter, const QStyleOptionGraphicsItem*, QWidget*) final;
    QRectF boundingRect() const final;
    void createbullet();

public:
    void healthpoints();

private slots:
    void shootCooldown();
};
