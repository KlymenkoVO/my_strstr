#include <sstream>

#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include "MockPainter.hpp"
#include "Turtle.h"


using ::testing::_;
using ::testing::Sequence;

TEST(Turtle, TurtlePaintRight)
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

    turtle.rightSquare(0, 0, 100);
}

TEST(Turtle, TurtlePaintLeft)
{
    MockPainter painter;
    Turtle turtle(&painter);

    Sequence s;

    EXPECT_CALL(painter, moveTo(0, 0)).InSequence(s);
    EXPECT_CALL(painter, lineForward(100)).InSequence(s);
    EXPECT_CALL(painter, turn(Painter::TurnDirection::LEFT, 90)).InSequence(s);
    EXPECT_CALL(painter, lineForward(100)).InSequence(s);
    EXPECT_CALL(painter, turn(Painter::TurnDirection::LEFT, 90)).InSequence(s);
    EXPECT_CALL(painter, lineForward(100)).InSequence(s);
    EXPECT_CALL(painter, turn(Painter::TurnDirection::LEFT, 90)).InSequence(s);
    EXPECT_CALL(painter, lineForward(100)).InSequence(s);
    EXPECT_CALL(painter, close()).InSequence(s);

    turtle.leftSquare(0, 0, 100);
}

#if !defined(NDEBUG)
TEST(Turtle, NullPainter)
{
    ASSERT_DEATH({ Turtle turtle(nullptr); }, "");
}
#endif

TEST(Turtle, PainterRight)
{
    std::stringstream buffer;
    std::streambuf *sbuf = std::cout.rdbuf();
    std::cout.rdbuf(buffer.rdbuf());

    Painter painter;
    Turtle turtle(&painter);

    std::string str = "Painter::Painter()\n"
                      "Painter::moveTo(0, 0)\n"
                      "Painter::lineForward(100)\n"
                      "Painter::turn(RIGHT, 90)\n"
                      "Painter::lineForward(100)\n"
                      "Painter::turn(RIGHT, 90)\n"
                      "Painter::lineForward(100)\n"
                      "Painter::turn(RIGHT, 90)\n"
                      "Painter::lineForward(100)\n"
                      "Painter::close()\n";

    turtle.rightSquare(0, 0, 100);

    std::string result = buffer.str();
    std::cout.rdbuf(sbuf);

    ASSERT_EQ(result, str);
}

TEST(Turtle, PainterLeft)
{
    std::stringstream buffer;
    std::streambuf *sbuf = std::cout.rdbuf();
    std::cout.rdbuf(buffer.rdbuf());

    Painter painter;
    Turtle turtle(&painter);

    std::string str = "Painter::Painter()\n"
                      "Painter::moveTo(0, 0)\n"
                      "Painter::lineForward(100)\n"
                      "Painter::turn(LEFT, 90)\n"
                      "Painter::lineForward(100)\n"
                      "Painter::turn(LEFT, 90)\n"
                      "Painter::lineForward(100)\n"
                      "Painter::turn(LEFT, 90)\n"
                      "Painter::lineForward(100)\n"
                      "Painter::close()\n";

    turtle.leftSquare(0, 0, 100);

    std::string result = buffer.str();
    std::cout.rdbuf(sbuf);

    ASSERT_EQ(result, str);
}

TEST(Turtle, PainterIncorrectDirection)
{
    std::stringstream buffer;
    std::streambuf *sbuf = std::cout.rdbuf();
    std::cout.rdbuf(buffer.rdbuf());

    Painter painter;

    std::string str = "Painter::Painter()\n"
                      "Painter::turn(INCORRECT DIRECTION, 0)\n";
    
    painter.turn(Painter::TurnDirection(999), 0);

    std::string result = buffer.str();
    std::cout.rdbuf(sbuf);

    ASSERT_EQ(result, str);
}
