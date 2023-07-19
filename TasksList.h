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

    int getTotal() const{
        return total;
    }

    void addList(const List& list);
    void removeList();
    void printLists() const;
    void save() const;

private:
    std::list<List> lists;
    int total {0};
};

#endif //BENINCASATODOLIST_TASKSLIST_H
