//
// Created by Mattia Benincasa on 11/07/23.
//

#include "User.h"

void User::addTask(const Task& newTask) {
    tasks.insert(std::make_pair(newTask.getName(), newTask));
}

void User::removeTask(std::string &n) {
    auto findTask = tasks.find(n);
    tasks.erase(findTask);
}

void User::markCompleted(std::string &n) {
    auto findTask = tasks.find(n);
    findTask->second.isCompleted();
}

void User::markNotCompleted(std::string &n) {
    auto findTask = tasks.find(n);
    findTask->second.notCompleted();
}