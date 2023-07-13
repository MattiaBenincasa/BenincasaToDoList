//
// Created by Mattia Benincasa on 13/07/23.
//
#include "Task.h"

Task::Task(std::string &n, std::string &desc, Date &d, Clock &t) : name(n), description(desc), day(d), time(t) {}

void Task::isCompleted() {
    completed = true;
}

void Task::notCompleted() {
    completed = false;
}

bool Task::operator==(const Task &right) const {
    if(name == right.name)
        return true;
    else
        return false;
}

std::ostream& operator << (std::ostream& os, const Task& task) {
    os << "TASK NAME: " << task.name << " | -> " << task.description << " | DATE: " << task.day << " | TIME: " << task.time << " | ";
    if(!task.completed)
        os << "NOT COMPLETED |" << std::endl;
    else
        os << "COMPLETED |" << std::endl;

    return os;
}

std::ofstream& operator << (std::ofstream& ofs, const Task& task){
    ofs << task.name;
    ofs << task.description;
    ofs << task.day;
    ofs << task.time;
    return ofs;
}

std::ifstream& operator >> (std::ifstream& ifs, Task& task){
    ifs >> task.name;
    ifs >> task.description;
    ifs >> task.day;
    ifs >> task.time;
    return ifs;
}