#pragma once
#include "Painter.h"


class Turtle {
public:
    Turtle(Painter* painter);
    virtual void rightSquare(int x, int y, int length);
    virtual void leftSquare(int x, int y, int length);

protected:
    virtual void square(Painter::TurnDirection direction, int x, int y, int length);

private:
    Painter* m_painter;
};
