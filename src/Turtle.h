#pragma once


class Painter;

class Turtle {
public:
    Turtle(Painter* painter);
    virtual void square(int x, int y, int length);

private:
    Painter* m_painter;
};
