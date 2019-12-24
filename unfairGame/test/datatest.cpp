//
// Created by Sebastiaan on 24/12/2019.
//
#include "gtest/gtest.h"
#include "../src/Data.h"

class DataSuite : public ::testing::Test {
public:
    Data *d = new Data();

protected:
    virtual void TearDown()
    {

    }

    virtual void SetUp()
    {

    }
};

TEST_F(DataSuite, InitialDeaths)
{
    ASSERT_EQ(d->getAmountOfDeaths(), 0);
}

TEST_F(DataSuite, IncreaseDeaths)
{
    ASSERT_EQ(d->getAmountOfDeaths(), 0);
    d->increaseAmountOfDeaths();
    ASSERT_EQ(d->getAmountOfDeaths(), 1);
    d->increaseAmountOfDeaths();
    d->increaseAmountOfDeaths();
    ASSERT_EQ(d->getAmountOfDeaths(), 3);
}

TEST_F(DataSuite, SetDeaths)
{
    ASSERT_EQ(d->getAmountOfDeaths(), 0);
    d->setAmountOfDeaths(5);
    ASSERT_EQ(d->getAmountOfDeaths(), 5);
}
