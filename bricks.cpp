#include "bricks.h"


Bricks::Bricks() : Object() {}


QRectF Bricks :: boundingRect() const {
    return QRectF(0,0,30,30);
}


void Bricks::paint(QPainter* painter,
                   const QStyleOptionGraphicsItem *,
                   QWidget *) {
    painter->drawPixmap(0,0,30,30,QPixmap(":/Images/brick1.png"));
}


Bricks::~Bricks(){}
