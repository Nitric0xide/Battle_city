#include "enemyh.h"
#include "explosion.h"
//Enemy Heavy Tank


EnemyH::EnemyH() : Moveable() {
    randomizeDirection();
    shot_recharge = new QTimer(this);
    shot_recharge->start(3500);
    connect(shot_recharge,SIGNAL(timeout()),this,SLOT(fire()));
}


QRectF EnemyH::boundingRect() const {
    return QRectF(0,0,55,55);}


void EnemyH::paint(QPainter* painter,
                   const QStyleOptionGraphicsItem *,
                   QWidget *){
    painter->translate(27.5,27.5);
    painter->rotate(m_rotation);
    painter->translate(-27.5,-27.5);
    painter->drawPixmap(0,0,55,55,QPixmap(":/Images/HeavyTank.png"));
}


void EnemyH::advance(int) {
    int changedX = 0;
    int changedY = 0;

    switch(m_direction) {
    case 1: changedX = -0.5 * SPEEDH;dir = 1;break;
    case 2: changedX = 0.5 * SPEEDH;dir = 2;break;
    case 3: changedY = -0.5 * SPEEDH;dir = 3;break;
    case 4: changedY = 0.5 * SPEEDH;dir = 4;break;
    default: return;
    }

    if (isCollision(QPointF(changedX, changedY)) || m_curDirectionIteration > MAX_DIRECTION_ITERATION) {
        randomizeDirection();
    } else {
        m_curDirectionIteration++;
        moveBy(changedX,changedY);
    }
}


void EnemyH::randomizeDirection() {
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


void EnemyH::dmg(int hpoints){
    health -= hpoints;
    if(health <= 0){
        scene()->addItem(new Explosion(this->pos()));
        this->deleteLater();
    }
}


void EnemyH::fire(){
    Bullet* bullet = new Bullet(dir, damage ,"enemyh"); scene()->addItem(bullet);
    switch(dir)
    {
    case 1:bullet->setPos(x()-20,y()+20); break;
    case 2:bullet->setPos(x()+60,y()+20);break;
    case 3:bullet->setPos(x()+20,y()-20); break;
    case 4:bullet->setPos(x()+20,y()+60);break;
    }
}


EnemyH::~EnemyH(){}
