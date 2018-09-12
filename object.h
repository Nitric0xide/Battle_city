#pragma once
#include"stdafx.h"


class Object : public QGraphicsItem,  public QObject{

protected:
    virtual void paint(QPainter*, const QStyleOptionGraphicsItem*, QWidget*) = 0;
    virtual QRectF boundingRect()const = 0;
};
