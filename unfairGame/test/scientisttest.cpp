//
// Created by Sebastiaan on 24/12/2019.
//

#include "gtest/gtest.h"
#include "../src/renderable/Scientist.h"

class ScientistSuite : public ::testing::Test {
public:
    std::unique_ptr<Scientist> scientist = std::unique_ptr<Scientist>(new Scientist(0,100));
    std::vector<std::unique_ptr<Testtube>> tubes;
protected:
    virtual void TearDown()
    {

    }

    virtual void SetUp()
    {

    }
};

TEST_F(ScientistSuite, AssertionWorks)
{
    ASSERT_TRUE(true);
}

//Verify that it gives 5 tubes
TEST_F(ScientistSuite, Verify_Tubes_Size)
{
    tubes = scientist->tubeBomb(-1);
    ASSERT_EQ(tubes.size(), 5);
}

//Verify that random x coordinates work
TEST_F(ScientistSuite, Verify_X_Coordinate)
{
    int currentXDestination = scientist->getXDestination();
    int randomX = scientist->generateXDestination();
    scientist->setXDestination(randomX);
    int newXDestination = scientist->getXDestination();
    ASSERT_NE(currentXDestination, newXDestination);

    //We also need to check that the new generated pos is at decent distance from the previous one
    ASSERT_TRUE(abs(currentXDestination - newXDestination ) >= 50);
}

TEST_F(ScientistSuite, Verify_Sprite)
{
    Sprite *s = scientist->getSprite();

    ASSERT_EQ(s->getWidth(), 32);
    ASSERT_EQ(s->getHeight(), 32);

    ASSERT_EQ(s->isAnimating(), true);
}
