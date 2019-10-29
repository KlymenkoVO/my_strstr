#include <iostream>

#include "Painter.h"


Painter::Painter() {
    std::cout << "Painter::Painter()" << std::endl;
}

void Painter::moveTo(int x, int y) {
    std::cout << "Painter::moveTo(" << x << ", " << y << ")" << std::endl;
}

void Painter::lineForward(int length) {
    std::cout << "Painter::lineForward(" << length << ")" << std::endl;
}

void Painter::turn(Painter::TurnDirection direction, int angle) {
    std::cout << "Painter::turn("
              << (direction == Painter::TurnDirection::RIGHT ? "RIGHT" : (direction == Painter::TurnDirection::LEFT ? "LEFT" : "INCORRECT DIRECTION"))
              << ", " << angle << ")" << std::endl;
}

void Painter::close() {
    std::cout << "Painter::close()" << std::endl;
}
