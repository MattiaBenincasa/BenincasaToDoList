//
// Created by Mattia Benincasa on 11/07/23.
//

#ifndef BENINCASATODOLIST_LIST_H
#define BENINCASATODOLIST_LIST_H
#include <iostream>
#include <map>
#include <string>
#include "Task.h"
#include <fstream>

class List {
public:
    List();
    explicit List(std::string& n);

    std::map<std::string, Task> getTasks() const {
        return tasks;
    }

    int getSize() const {
        return tasks.size();
    }

    std::string getName() const{
        return name;
    }

    void readFile();
    void addTask(const Task& newTask);
    void removeTask(std::string& n);
    void markCompleted(std::string& n);
    void markNotCompleted(std::string& n);
    void saveTasks() const;

    bool operator == (const std::string& right);
    bool operator == (const List& list) const;
    void printTasks() const;

private:
    std::string name;
    std::map<std::string, Task> tasks;
};




#endif //BENINCASATODOLIST_LIST_H
