//
// Created by Mattia Benincasa on 11/07/23.
//

#ifndef BENINCASATODOLIST_TASK_H
#define BENINCASATODOLIST_TASK_H
#include <string>
#include "time.h"
#include "Date.h"

class Task {
public:
    Task(std::string& n, std::string& desc, Date d, Time t) : name(n), description(desc), day(d), time(t){}

    std::string getName() {
        return name;
    }

    void isCompleted() {
        completed = true;
    }

    void notCompleted() {
        completed = false;
    }

private:
    std::string name;
    std::string description;
    Date day;
    Time time;
    bool completed {false};
};

#endif //BENINCASATODOLIST_TASK_H
