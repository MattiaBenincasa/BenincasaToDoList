//
// Created by Mattia Benincasa on 19/07/23.
//
#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "../TasksList.h"

int TasksList::total = 0;

TEST(TasksList, addRemoveLists){
    TasksList system;
    std::string name = "User";
    List list(name);
    system.addList(list);
    ASSERT_THAT(system.getList(), ::testing::Contains(list));
    system.removeList(name);
    ASSERT_THAT(system.getList(), ::testing::IsEmpty());
}

