//
// Created by Mattia Benincasa on 12/07/23.
//
#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include "../List.h"

TEST(User, AddRemoveTasks){
    List user;
    std::string n;
    std::string desc;
    Date d;
    Clock t;
    Task task(n, desc, d, t);
    user.addTask(task);
    ASSERT_THAT(user.getTasks(), ::testing::Contains(std::make_pair(n, task)));
    user.removeTask(n);
    ASSERT_THAT(user.getTasks(),::testing::IsEmpty());
}