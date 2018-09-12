#pragma once
#define SPEEDL 3
#define MAX_DIRECTION_ITERATION 200
#include "moveable.h"
#include "bullet.h"

//Enemy Light Tank

class EnemyL : public Moveable {

    Q_OBJECT

public:
    int health = 2;

private:
    int m_direction;
    int m_curDirectionIteration;
    int m_rotation = 0;
    int damage = 2;
    int dir = 0;
    QTimer* shot_recharge;

public:
    EnemyL();
    ~EnemyL();

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
