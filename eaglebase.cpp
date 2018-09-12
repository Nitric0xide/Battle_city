#include "eaglebase.h"


EagleBase::EagleBase(): Object() {}


QRectF EagleBase :: boundingRect() const {
    return QRectF(0,0,60,60);
}


void EagleBase::paint(QPainter* painter,
                      const QStyleOptionGraphicsItem *,
                      QWidget *) {
    painter->drawPixmap(0,0,60,60,QPixmap(":/Images/eagle.png"));

}


int EagleBase::dmg(int hpoints){
    health -= hpoints;

    if(health == 0 || health < 0){
        this->deleteLater();
    }
    return health;
}


EagleBase::~EagleBase(){}
