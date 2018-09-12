#pragma once
#include"object.h"


class Steelblock : public Object {

public:
    Steelblock();
    ~Steelblock();

public:
    virtual void paint(QPainter* painter,
                       const QStyleOptionGraphicsItem* option,
                       QWidget* widget) override;
    virtual QRectF boundingRect() const override;
};
