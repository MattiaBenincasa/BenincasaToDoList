//
// Created by Mattia Benincasa on 13/07/23.
//
#include <gtest/gtest.h>
#include "../Date.h"

class DateSuite : public::testing::Test{
protected:
     void SetUp() override{
        d.setYear(2024);
        d.setMonth(2);
    }
    Date d;
};

TEST_F(DateSuite, ThrowDayException){
    d.setDay(29);
    d.setYear(2023);
    //EXPECT_THROW(d.setYear(2023), InvalidDate);
    ASSERT_EQ(d.getDay(), 29);
    ASSERT_EQ(d.getMonth(), 2);
    ASSERT_EQ(d.getYear(), 2023);
}

TEST(Date, DefaultConstructor){
    Date d;
    ASSERT_EQ(1, d.getDay());
    ASSERT_EQ(1, d.getMonth());
    ASSERT_EQ(2023, d.getYear());
}

TEST(Date, ThrowDateException){
    Date d;
    EXPECT_THROW(d.setDay(-1), InvalidDate);
    EXPECT_THROW(d.setMonth(-1), InvalidDate);
    EXPECT_THROW(d.setYear(-1), InvalidDate);
}