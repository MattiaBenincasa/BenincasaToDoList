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
    os << "|TASK NAME: " << task.getName() << " -> " << task.getDescription() << " |DATE: " << task.getDate() << " |TIME: " << task.getTime();
    if(!task.getCompleted())
        os << "\t|NOT COMPLETED|" << std::endl;
    else
        os << "\t|COMPLETED|" << std::endl;

    return os;
}

std::ofstream& operator << (std::ofstream& ofs, const Task& task){
    ofs << task.name << std::endl;
    ofs << task.description << std::endl;
    ofs << task.day.getDay() << std::endl;
    ofs << task.day.getMonth() << std::endl;
    ofs << task.day.getYear() << std::endl;
    ofs << task.time.getHour() << std::endl;
    ofs << task.time.getMinute() << std::endl;
    ofs << task.completed << std::endl;
    return ofs;
}

std::ifstream& operator >> (std::ifstream& ifs, Task& task){
    ifs >> task.name;
    ifs.ignore();
    std::getline(ifs, task.description);
    ifs >> task.day;
    ifs >> task.time;
    ifs >> task.completed;
    return ifs;
}