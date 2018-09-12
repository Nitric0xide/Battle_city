#pragma once
#include "object.h"


class Bush : public Object{

public:
    Bush();
    ~Bush();

protected:
    virtual void paint(QPainter* painter,
                       const QStyleOptionGraphicsItem*,
                       QWidget*)final;
    virtual QRectF boundingRect()const final;
};
