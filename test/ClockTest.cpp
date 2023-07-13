//
// Created by Mattia Benincasa on 13/07/23.
//
#include <gtest/gtest.h>
#include "../Clock.h"

TEST(Clock, DefaultConstructor) {
    Clock c;
    ASSERT_EQ(0, c.getHour());
    ASSERT_EQ(0, c.getMinute());
}

TEST(Clock, ThrowClockException) {
    Clock c;
    EXPECT_THROW(c.setMinute(60), InvalidTime);
    EXPECT_THROW(c.setHour(24), InvalidTime);
}