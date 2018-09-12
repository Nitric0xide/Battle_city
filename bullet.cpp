#include "bullet.h"
#include "enemyl.h"
#include "enemym.h"
#include "enemyh.h"
#include "player.h"
#include "bush.h"
#include "eaglebase.h"


Bullet::Bullet(int dir, int damage, QString tanktype) : Moveable(){  
    direction = dir;
    temp = tanktype;
    hit = damage;

}


QRectF Bullet::boundingRect() const {
    return QRectF(0,0,15,15);
}


void Bullet::paint(QPainter* painter,
                   const QStyleOptionGraphicsItem *, QWidget *){
    painter->translate(7.5,7.5);
    painter->rotate(m_rotation);
    painter->translate(-7.5,-7.5);
    painter->drawPixmap(0,0,15,15,QPixmap(":/Images/bullet.png"));
}


void Bullet::advance(int phase){
    xspeed = yspeed = BULLETSPEED;
    if (phase){
        switch (direction){
        case 1:m_rotation=-180;moveBy(-xspeed,0);break;
        case 2:m_rotation=360;moveBy(xspeed,0);break;
        case 3:m_rotation=-90;moveBy(0,-yspeed);break;
        case 4:m_rotation=90;moveBy(0,yspeed);break;
        default:break;
        }
    }

    QList<QGraphicsItem *> list = collidingItems();
    foreach(QGraphicsItem * i , list){
        Bricks* wall = dynamic_cast<Bricks *>(i);
        EnemyL* lighttank = dynamic_cast<EnemyL*>(i);
        EnemyM* mediumtank = dynamic_cast<EnemyM*>(i);
        EnemyH* heavytank = dynamic_cast<EnemyH*>(i);
        Player* player = dynamic_cast<Player*>(i);
        EagleBase* base = dynamic_cast<EagleBase*>(i);
        Bush* bush = dynamic_cast<Bush*>(i);

        if (wall){
            wall->deleteLater();
        }
        if(lighttank  && temp == "player"){
            lighttank->dmg(hit);
        }
        if(mediumtank  && temp == "player"){
            mediumtank->dmg(hit);
        }
        if(heavytank  && temp == "player"){
            heavytank->dmg(hit);
        }
        if(player){
            player->dmg(hit);
        }
        if(base){
            base->dmg(hit);
        }
        if(i != bush){
            this->deleteLater();
        }
    }
}


Bullet::~Bullet(){scene()->addItem(new Explosion(this->pos()));}
