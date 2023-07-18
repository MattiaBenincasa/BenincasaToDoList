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
    void addList(const List& list);
    void removeList(std::string& name);

    List& getList(std::string& name);

    void save() const;
private:
    std::list<List> lists;
    int total {0};
    int notCompleted {0};
};

#endif //BENINCASATODOLIST_TASKSLIST_H
