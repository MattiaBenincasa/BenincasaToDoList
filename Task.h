//
// Created by Mattia Benincasa on 11/07/23.
//

#ifndef BENINCASATODOLIST_TASK_H
#define BENINCASATODOLIST_TASK_H
#include <string>
#include "Clock.h"
#include "Date.h"
#include <fstream>

class Task {
public:
    Task(std::string& n, std::string& desc, Date& d, Clock& t);

    std::string getName() const{
        return name;
    }

    bool getCompleted() const{
        return completed;
    }

    std::string getDescription() const{
        return description;
    }

    Date getDate() const {
        return day;
    }

    Clock getTime() const {
        return time;
    }

    void isCompleted();
    void notCompleted();
    bool operator == (const Task& right) const;
    friend std::ostream& operator << (std::ostream& os, const Task& task);

private:
    std::string name;
    std::string description;
    Date day;
    Clock time;
    bool completed {false};
};

#endif //BENINCASATODOLIST_TASK_H
