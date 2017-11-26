#include <cassert>

#include "Turtle.h"
#include "Painter.h"


Turtle::Turtle(Painter* painter) : m_painter(painter) {;}

void Turtle::square(int x, int y, int length) {
    assert(m_painter != nullptr);
    m_painter->moveTo(x, y);
    m_painter->lineForward(length);
    m_painter->turn(Painter::TurnDirection::RIGHT, 90);
    m_painter->lineForward(length);
    m_painter->turn(Painter::TurnDirection::RIGHT, 90);
    m_painter->lineForward(length);
    m_painter->turn(Painter::TurnDirection::RIGHT, 90);
    m_painter->lineForward(length);
    m_painter->close();
}
