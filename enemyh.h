#pragma once
#define SPEEDH 2
#define MAX_DIRECTION_ITERATION 200
#include "moveable.h"
#include "bullet.h"

//Enemy Heavy Tank


class EnemyH : public Moveable {

    Q_OBJECT

public:
    int health = 6;

private:
    int m_direction;
    int m_curDirectionIteration;
    int m_rotation = 0;
    int damage = 4;
    int dir = 0;
    QTimer* shot_recharge;

public:
    EnemyH();
    ~EnemyH();

private:
    void paint(QPainter* painter, const QStyleOptionGraphicsItem*, QWidget*)final;
    QRectF boundingRect() const final;
    void advance(int)final;
    void randomizeDirection();

public:
    void dmg(int hpoints);

private slots:
    void fire();
};
