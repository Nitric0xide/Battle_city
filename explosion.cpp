#include "explosion.h"


QRectF Explosion::boundingRect() const{
    return QRectF(-15,-15,40,40);
}


Explosion::Explosion(QPointF point, QObject *parent) :
    QObject(parent), QGraphicsItem(){
    this->setPos(point);
    currentFrame = 0;
    spriteImage = new QPixmap(":/Images/Explosion.png");
    timer = new QTimer();
    connect(timer, &QTimer::timeout, this, &Explosion::nextFrame);
    timer->start(50);
}


void Explosion::paint(QPainter *painter,
                      const QStyleOptionGraphicsItem *option, QWidget *widget){
    painter->drawPixmap(-15,-15, *spriteImage, currentFrame, 0, 40,40);
    Q_UNUSED(option);
    Q_UNUSED(widget);
}


void Explosion::nextFrame(){    
    currentFrame += 40;
    if (currentFrame >= 75 ) {
        this->deleteLater();
    } else {
        this->update(-15,-15,40,40);
    }
}
