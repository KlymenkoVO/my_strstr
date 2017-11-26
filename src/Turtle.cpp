#include <cassert>

#include "Turtle.h"


Turtle::Turtle(Painter* painter) : m_painter(painter) {
    assert(m_painter != nullptr);
}

void Turtle::rightSquare(int x, int y, int length) {
    square(Painter::TurnDirection::RIGHT, x, y, length);
}

void Turtle::leftSquare(int x, int y, int length) {
    square(Painter::TurnDirection::LEFT, x, y, length);
}

void Turtle::square(Painter::TurnDirection direction, int x, int y, int length) {
    m_painter->moveTo(x, y);
    m_painter->lineForward(length);
    m_painter->turn(direction, 90);
    m_painter->lineForward(length);
    m_painter->turn(direction, 90);
    m_painter->lineForward(length);
    m_painter->turn(direction, 90);
    m_painter->lineForward(length);
    m_painter->close();
}
