#include "gtest/gtest.h"
#include "Turtle.h"

TEST(Turtle, TurtleCreate)
{
    Turtle turtle(nullptr);
    ASSERT_EQ(&turtle, &turtle);
}
