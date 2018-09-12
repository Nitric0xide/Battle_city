#include "enemym.h"
//Enemy Medium Tank


EnemyM::EnemyM() : Moveable() {
    randomizeDirection();
    shot_recharge = new QTimer(this);
    shot_recharge->start(2000);
    connect(shot_recharge,SIGNAL(timeout()),this,SLOT(fire()));
}


QRectF EnemyM::boundingRect() const {
    return QRectF(0,0,50,50);
}


void EnemyM::paint(QPainter *painter,
                   const QStyleOptionGraphicsItem*, QWidget*){
    painter->translate(25,25);
    painter->rotate(m_rotation);
    painter->translate(-25,-25);
    painter->drawPixmap(0,0,50,50,QPixmap(":/Images/MediumTank.png"));
}


void EnemyM::advance(int) {  
    int changedX = 0;
    int changedY = 0;

    switch(m_direction) {
    case 1: changedX = -0.5 * SPEEDM; dir = 1;break;
    case 2: changedX = 0.5 * SPEEDM; dir = 2;break;
    case 3: changedY = -0.5 * SPEEDM;dir = 3;break;
    case 4: changedY = 0.5 * SPEEDM; dir = 4;break;
    default: return;
    }

    if (isCollision(QPointF(changedX, changedY)) || m_curDirectionIteration > MAX_DIRECTION_ITERATION) {
        randomizeDirection();
    } else {
        m_curDirectionIteration++;
        moveBy(changedX,changedY);
    }
}


void EnemyM::randomizeDirection() {
    m_curDirectionIteration = 0;
    m_direction = rand()%4+1;
    switch(m_direction) {
    case 1: m_rotation = -90; break;
    case 2: m_rotation = 90; break;
    case 3: m_rotation = 360; break;
    case 4: m_rotation = 180; break;
    default: return;
    }
}


void EnemyM::dmg(int hpoints){
    health -= hpoints;
    if(health <= 0){
        scene()->addItem(new Explosion(this->pos()));
        this->deleteLater();
    }
}


void EnemyM::fire(){
    Bullet* bullet = new Bullet(dir, damage ,"enemym"); scene()->addItem(bullet);
    switch(dir){
    case 1:bullet->setPos(x()-20,y()+20); break;
    case 2:bullet->setPos(x()+60,y()+20);break;
    case 3:bullet->setPos(x()+20,y()-20); break;
    case 4:bullet->setPos(x()+20,y()+60);break;
    }
}


EnemyM::~EnemyM(){}
