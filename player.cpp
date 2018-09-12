#include "player.h"
#include "bush.h"
#include "bricks.h"


Player::Player():Moveable(){
    shot_recharge = new QTimer(this);
}


QRectF Player::boundingRect() const {
    return QRectF(0,0,50,50);
}


void Player::paint(QPainter *painter,
                   const QStyleOptionGraphicsItem*, QWidget*){
    painter->translate(25,25);
    painter->rotate(m_rotation);
    painter->translate(-25,-25);
    painter->drawPixmap(boundingRect().toRect(), QPixmap(":/Images/player.png"));
    setFlag(QGraphicsItem::ItemIsFocusable);
    setFocus();
}


void Player::keyPressEvent(QKeyEvent *event){
    int changedXSpeed = 0;
    int changedYSpeed = 0;

    switch(event->key()){
    case Qt::Key_Left: changedXSpeed=-TANKSPEED;m_rotation=-90;dir = 1;break;
    case Qt::Key_Right:changedXSpeed=TANKSPEED;m_rotation=90;dir = 2;break;
    case Qt::Key_Up:changedYSpeed=-TANKSPEED;m_rotation=360;dir = 3;break;
    case Qt::Key_Down:changedYSpeed=TANKSPEED;m_rotation=180;dir = 4;break;
    case Qt::Key_Space:createbullet();break;
    default:break;
    }

    if(shooting == false){
        connect(shot_recharge,SIGNAL(timeout()),this,SLOT(shootCooldown()));
    }

    xspeed = changedXSpeed;
    yspeed = changedYSpeed;
}


void Player::keyReleaseEvent(QKeyEvent* event){
    switch(event->key()){
    case Qt::Key_Left:
    case Qt::Key_Right:
    case Qt::Key_Up:
    case Qt::Key_Down:
    case Qt::Key_Space:
        break;
    default:return;
    }
    xspeed = 0;
    yspeed = 0;
}


void Player::createbullet() {
    if(shooting == true){
        Bullet *bullet = new Bullet(dir ,damage , "player"); scene()->addItem(bullet);
        switch(dir)
        {
        case 1:bullet->setPos(x()-20,y()+20); break;
        case 2:bullet->setPos(x()+60,y()+20);break;
        case 3:bullet->setPos(x()+20,y()-20); break;
        case 4:bullet->setPos(x()+20,y()+60);break;
        }
        shooting = false;
        shot_recharge->start(1000);
    }
}


void Player::healthpoints(){
    dmg(health);
}


void Player::shootCooldown(){
    shooting = true;
}


void Player::dmg(int hpoints){
    health -= hpoints;
    if(health <= 0){
        scene()->addItem(new Explosion(this->pos()));
        this->deleteLater();
    }
}


Player::~Player(){}
