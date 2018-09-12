#include "bush.h"


Bush::Bush(): Object() {qDebug() << this->parentObject();}


QRectF Bush :: boundingRect() const {
    return QRectF(0,0,60,60);
}


void Bush::paint(QPainter* painter,
                 const QStyleOptionGraphicsItem *,
                 QWidget *) {
    painter->drawPixmap(0,0,60,60,QPixmap(":/Images/bush.png"));
}


Bush::~Bush(){}
