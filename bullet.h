#pragma once
#define BULLETSPEED 7
#include "moveable.h"
#include "explosion.h"
#include "bricks.h"


class Bullet : public Moveable{

public:
    Bullet(int dir, int damage, QString tanktype);
    ~Bullet() final;

private:
    QTimer* bulletTimer;
    QString temp;
    int hit = 0;
    int direction;

private:
    virtual void paint(QPainter* painter,const QStyleOptionGraphicsItem* option,QWidget* widget) final;
    virtual QRectF boundingRect()const final;
    virtual void advance(int phase) final;
};
