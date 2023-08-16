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

    void setName(std::string& n) {
        name = n;
    }

    void readFile();
    void addTask(const Task& newTask, const std::string& n);
    void removeTask(const std::string& taskName, const std::string& listName);
    void markCompleted(const std::string& taskName, const std::string& listName);
    void markNotCompleted(const std::string& taskName, const std::string& listName);
    void saveTasks() const;

    bool operator == (const std::string& right);
    bool operator == (const List& list) const;
    friend std::ifstream& operator >> (std::ifstream& ifs, List& list);

    void printTasks(const std::string& n) const;
    bool findTask(const std::string& name);

private:
    std::string name;
    std::map<std::string, Task> tasks;
};




#endif //BENINCASATODOLIST_LIST_H
