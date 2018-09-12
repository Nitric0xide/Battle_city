#include "moveable.h"
#include "bush.h"


Moveable::Moveable() : Object(){}


void Moveable::advance(int phase){
    if (phase && !isCollision(QPointF(xspeed, yspeed))){
        moveBy(xspeed,yspeed);
    }
}


bool Moveable::isCollision(const QPointF& changedPos) {
    QPointF newPos = pos() + changedPos;
    QRectF newRect = QRectF(newPos, boundingRect().size());
    QList<QGraphicsItem*> listItems = scene()->items(newRect);

    foreach(QGraphicsItem * i , listItems){
        Bush* bush = dynamic_cast<Bush*>(i);
        if(i == bush){return listItems.size() > 2;}
    }

    return listItems.size() > 1;
}


Moveable::~Moveable(){}
