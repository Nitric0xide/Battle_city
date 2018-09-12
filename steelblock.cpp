#include "steelblock.h"


Steelblock::Steelblock() : Object(){}


QRectF Steelblock::boundingRect()const{
    return QRectF(0,0,30,30);
}


void Steelblock::paint(QPainter *painter,
                       const QStyleOptionGraphicsItem *, QWidget *){
    painter->drawPixmap(0,0,30,30,QPixmap(":/Images/Steel.png"));
}


Steelblock::~Steelblock(){}
