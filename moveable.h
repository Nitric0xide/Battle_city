#pragma once
#include "object.h"


//Here is general options for moveable objects

class Moveable : public Object {

public:
    Moveable();
    virtual ~Moveable();

protected:
    int m_direction;
    int m_curDirectionIteration;
    int m_rotation = 0;
    int m_currentX;
    int m_currentY;
    int xspeed = 0;
    int yspeed = 0;

protected:
    bool isCollision(const QPointF&changedPos);
    virtual void advance(int phase);
};
