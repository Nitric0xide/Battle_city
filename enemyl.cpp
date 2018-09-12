#include "enemyl.h"
//Enemy Light Tank


EnemyL::EnemyL() : Moveable() {
    randomizeDirection();
    shot_recharge = new QTimer(this);
    shot_recharge->start(1000);
    connect(shot_recharge,SIGNAL(timeout()),this,SLOT(fire()));
}


QRectF EnemyL::boundingRect() const {
    return QRectF(0,0,48,48);
}


void EnemyL::paint(QPainter *painter,
                   const QStyleOptionGraphicsItem*, QWidget*){
    painter->translate(23.5,23.5);
    painter->rotate(m_rotation);
    painter->translate(-23.5,-23.5);
    painter->drawPixmap(0,0,48,48,QPixmap(":/Images/LightTank.png"));
}


void EnemyL::advance(int) {
    int changedX = 0;
    int changedY = 0;

    switch(m_direction) {
    case 1: changedX = -0.5 * SPEEDL; dir = 1;break;
    case 2: changedX = 0.5 * SPEEDL; dir = 2;break;
    case 3: changedY = -0.5 * SPEEDL;dir = 3;break;
    case 4: changedY = 0.5 * SPEEDL; dir = 4;break;
    default: return;
    }

    if (isCollision(QPointF(changedX, changedY)) || m_curDirectionIteration > MAX_DIRECTION_ITERATION) {
        randomizeDirection();
    } else {
        m_curDirectionIteration++;
        moveBy(changedX,changedY);
    }
}


void EnemyL::randomizeDirection() {
    m_curDirectionIteration = 0;
    m_direction = rand()%4+1;
    switch(m_direction) {
    case 1: m_rotation = -90 ; break;
    case 2: m_rotation =  90 ; break;
    case 3: m_rotation =  360; break;
    case 4: m_rotation =  180; break;
    default: return;
    }
}


void EnemyL::dmg(int hpoints){
    health -= hpoints;
    if(health <= 0){
        scene()->addItem(new Explosion(this->pos()));
        this->deleteLater();
    }
}


void EnemyL::fire(){
    Bullet* bullet = new Bullet(dir, damage ,"enemyl"); scene()->addItem(bullet);
    switch(dir)
    {
    case 1:bullet->setPos(x()-20,y()+20); break;
    case 2:bullet->setPos(x()+60,y()+20);break;
    case 3:bullet->setPos(x()+20,y()-20); break;
    case 4:bullet->setPos(x()+20,y()+60);break;
    }
}


EnemyL::~EnemyL(){}
