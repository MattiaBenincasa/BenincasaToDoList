//
// Created by Mattia Benincasa on 13/07/23.
//
#include <gtest/gtest.h>
#include "../Task.h"

TEST(Task, GetterSetterTest){
    std::string name = "name";
    std::string description = "description";
    Date d;
    Clock t;
    Task task(name, description, d, t);
    ASSERT_EQ(task.getName(), name);
    ASSERT_EQ(task.getDescription(), description);
    ASSERT_EQ(task.getCompleted(), false);
    task.isCompleted();
    ASSERT_EQ(task.getCompleted(), true);
    task.notCompleted();
    ASSERT_EQ(task.getCompleted(), false);
}