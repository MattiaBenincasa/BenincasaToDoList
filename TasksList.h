//
// Created by Mattia Benincasa on 18/07/23.
//

#ifndef BENINCASATODOLIST_TASKSLIST_H
#define BENINCASATODOLIST_TASKSLIST_H
#include <list>
#include "List.h"
#include <string>
#include <fstream>

class TasksList {
public:

    TasksList();
    explicit TasksList(const std::string& nameFile);

    static int getTotal() {
        return total;
    }

    static void incTotal(){
        total++;
    }

    static void decrTotal(){
        total--;
    }

    void read(const std::string& nameFile);
    void addList(const List& list);
    bool removeList(const std::string& name);
    void removeListFile();
    void printLists() const;
    void save() const;

    bool printTasks(const std::string& listName);
    bool addTask(const std::string& listName, const Task& task);
    bool removeTask(const std::string& taskName, const std::string& listName);
    bool markTaskCompleted(const std::string& taskName, const std::string& listName);
    bool markTaskNotCompleted(const std::string& taskName, const std::string& listName);

    bool findList(const std::string& listName);

private:
    std::list<List> lists;
    static int total;
};

#endif //BENINCASATODOLIST_TASKSLIST_H
