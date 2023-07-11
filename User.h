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
    void addTask(std::string& n, std::string& desc, Date d, Clock t);
    void removeTask(std::string& n);
    void markCompleted(std::string& n);
    void markNotCompleted(std::string& n);

private:
    std::map<std::string, Task> tasks;
};

#endif //BENINCASATODOLIST_USER_H
