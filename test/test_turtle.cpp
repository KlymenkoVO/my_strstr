#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include "MockPainter.hpp"
#include "Turtle.h"


using ::testing::_;
using ::testing::Sequence;

TEST(Turtle, TurtleCreate)
{
    MockPainter painter;
    Turtle turtle(&painter);
    
    Sequence s;
    
    EXPECT_CALL(painter, moveTo(0, 0)).InSequence(s);
    EXPECT_CALL(painter, lineForward(100)).InSequence(s);
    EXPECT_CALL(painter, turn(Painter::TurnDirection::RIGHT, 90)).InSequence(s);
    EXPECT_CALL(painter, lineForward(100)).InSequence(s);
    EXPECT_CALL(painter, turn(Painter::TurnDirection::RIGHT, 90)).InSequence(s);
    EXPECT_CALL(painter, lineForward(100)).InSequence(s);
    EXPECT_CALL(painter, turn(Painter::TurnDirection::RIGHT, 90)).InSequence(s);
    EXPECT_CALL(painter, lineForward(100)).InSequence(s);
    EXPECT_CALL(painter, close()).InSequence(s);
    
    turtle.square(0, 0, 100);

    ASSERT_EQ(&turtle, &turtle);
}
