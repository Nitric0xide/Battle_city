#pragma once
#include "stdafx.h"

class Explosion: public QObject, public QGraphicsItem
{
    Q_OBJECT

public:
    explicit Explosion(QPointF point, QObject *parent = 0);

private slots:
    void nextFrame();

private:
    void paint(QPainter *painter,
               const QStyleOptionGraphicsItem *option, QWidget *widget);
    QRectF boundingRect() const;

private:
    QTimer *timer;
    QPixmap *spriteImage;
    int currentFrame;
};
