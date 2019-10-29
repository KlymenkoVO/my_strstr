#pragma once

class Painter {
public:
    enum class TurnDirection {
        RIGHT,
        LEFT
    };
    
public:
    Painter();
    virtual void moveTo(int x, int y);
    virtual void lineForward(int length);
    virtual void turn(TurnDirection direction, int angle);
    virtual void close();
};
