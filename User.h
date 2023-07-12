//
// Created by Mattia Benincasa on 11/07/23.
//

#ifndef BENINCASATODOLIST_USER_H
#define BENINCASATODOLIST_USER_H
#include <map>
#include <string>
#include "Task.h"

class User {
public:

    std::map<std::string, Task> getTasks() const {
        return tasks;
    }

    void addTask(const Task& newTask);
    void removeTask(std::string& n);
    void markCompleted(std::string& n);
    void markNotCompleted(std::string& n);

private:
    std::map<std::string, Task> tasks;
};

#endif //BENINCASATODOLIST_USER_H
