#pragma once

#include "Painter.h"
#include "gmock/gmock.h"


class MockPainter : public Painter {
public:
    MockPainter() {;}
    MOCK_METHOD2(moveTo, void(int, int));
    MOCK_METHOD1(lineForward, void(int));
    MOCK_METHOD2(turn, void(Painter::TurnDirection, int));
    MOCK_METHOD0(close, void());
};
