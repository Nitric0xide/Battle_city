#pragma once
#include "object.h"

class EagleBase : public Object{

public:
    int health = 4;

public:
    EagleBase();
    ~EagleBase();

public:
    int dmg(int hpoints);

protected:
    virtual void paint(QPainter* painter,
                       const QStyleOptionGraphicsItem*,
                       QWidget*)final;
    virtual QRectF boundingRect()const final;
};
