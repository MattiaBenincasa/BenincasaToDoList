//
// Created by Mattia Benincasa on 11/07/23.
//

#ifndef BENINCASATODOLIST_USER_H
#define BENINCASATODOLIST_USER_H
#include <iostream>
#include <map>
#include <string>
#include "Task.h"
#include <fstream>

class User {
public:
    User();

    std::map<std::string, Task> getTasks() const {
        return tasks;
    }
    void readFile();
    void addTask(const Task& newTask);
    void removeTask(std::string& n);
    void markCompleted(std::string& n);
    void markNotCompleted(std::string& n);

    void printTasks() const;
    ~User();

private:
    std::map<std::string, Task> tasks;
};

#endif //BENINCASATODOLIST_USER_H
