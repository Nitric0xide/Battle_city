#pragma once
#include "object.h"


class Bricks : public Object{

public:
    Bricks();
    ~Bricks();

protected:
    virtual void paint(QPainter* painter,
                       const QStyleOptionGraphicsItem*,
                       QWidget*)override;
    virtual QRectF boundingRect()const override;
};

