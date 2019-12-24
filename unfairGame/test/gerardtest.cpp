//
// Created by Sebastiaan on 24/12/2019.
//

#include "gtest/gtest.h"
#include "../src/Gerard.h"

class GerardSuite : public ::testing::Test {
public:
    std::unique_ptr<Gerard> gerard = std::unique_ptr<Gerard>(new Gerard(0,100, NOT_MOVING));
protected:
    virtual void TearDown() {
    }

    virtual void SetUp() {
    }
};

TEST_F(GerardSuite, AssertionWorks)
{
    ASSERT_TRUE(true);
}

TEST_F(GerardSuite, Verify_Gerard_Health)
{
    ASSERT_EQ(gerard->getHealth(), 4);
}

TEST_F(GerardSuite, Verify_Velocity)
{
    gerard->setVelocity(5,-2);
    VECTOR velocity = gerard->getSprite()->getVelocity();
    ASSERT_EQ(velocity.x, 5);
    ASSERT_EQ(velocity.y, -2);
}

TEST_F(GerardSuite, Verify_Direction)
{
    gerard->setDirection(UP);

    ASSERT_EQ(gerard->getDirection(),UP);
    gerard->setCharacterDirection(5,5);
    ASSERT_EQ(gerard->getDirection(),RIGHT_DOWN);
}

