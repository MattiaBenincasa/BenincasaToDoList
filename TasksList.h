//
// Created by Mattia Benincasa on 18/07/23.
//

#ifndef BENINCASATODOLIST_TASKSLIST_H
#define BENINCASATODOLIST_TASKSLIST_H
#include <list>
#include "List.h"
#include <string>

class TasksList {
public:

    int getTotal() const{
        return total;
    }

    int getNotCompleted() const {
        return notCompleted;
    }

    List& getList(std::string& name);

    void addList(const List& list);
    void removeList(std::string& name);
    void addTask(std::string& listName, const Task& task);
    void printLists() const;
    void printTasks(std::string& listName);
    void save() const;
private:
    std::list<List> lists;
    int total {0};
    int notCompleted {0};
};

#endif //BENINCASATODOLIST_TASKSLIST_H
