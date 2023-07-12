//
// Created by Mattia Benincasa on 11/07/23.
//

#ifndef BENINCASATODOLIST_TASK_H
#define BENINCASATODOLIST_TASK_H
#include <string>
#include "Clock.h"
#include "Date.h"

class Task {
public:
    Task(std::string& n, std::string& desc, Date d, Clock t) : name(n), description(desc), day(d), time(t){}

    std::string getName() const{
        return name;
    }

    void isCompleted() {
        completed = true;
    }

    void notCompleted() {
        completed = false;
    }

    bool getCompleted() const{
        return completed;
    }

    bool operator == (const Task& right) const{
        if(name == right.name)
            return true;
        else
            return false;
    }

private:
    std::string name;
    std::string description;
    Date day;
    Clock time;
    bool completed {false};
};

#endif //BENINCASATODOLIST_TASK_H
